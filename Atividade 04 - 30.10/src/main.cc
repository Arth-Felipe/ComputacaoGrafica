/**
 * @file main.cc
 * @author Arthur Felipe Bravo Pita
 * @brief Programa usado para criar uma cena virtual, definir parâmetros da câmera e da imagem, e usar ray tracing para determinar as cores dos pixels na imagem final.
 * @version 1.0
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../Atividade 01 - 02.10/MakeImage.h"
#include "../../Atividade 02 - 09.10/color.h"
#include "../../Atividade 02 - 09.10/vec3.h"
#include "../../Atividade 03 - 16.10/headers/processObject.h"
#include "../headers/ray.h"

#include <iostream>
#include <fstream>


/**
 * @brief Verifica se um raio atinge uma esfera. Recebe o centro e raio da esfera, junto com o raio a ser testado. Usa a equação da esfera e a fórmula quadrática para determinar se há uma interseção.
 * 
 * @param center 
 * @param radius 
 * @param r 
 * @return true 
 * @return false 
 */
bool hit_sphere(const point3& center, double radius, const ray& r) {
    /// Vetor do centro da esfera até a origem do raio
    vec3 oc = r.origin() - center;

    /// Coeficientes da equação quadrática para a interseção raio-esfera
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius*radius;

    /// Discriminante da equação quadrática
    auto discriminant = b*b - 4*a*c;

    /// Se o discriminante é não negativo, há interseção
    return (discriminant >= 0);
}


/**
 * @brief Verifica se um raio atinge um triângulo definido por três pontos no espaço 3D. Recebe os vértices do triângulo e o raio a ser testado. Utiliza a fórmula de interseção de plano e testes de coordenadas bariôcentricas para determinar se a interseção está dentro do triângulo.
 * 
 * @param v0 
 * @param v1 
 * @param v2 
 * @param r 
 * @return true 
 * @return false 
 */
bool hit_triangle(const point3& v0, const point3& v1, const point3& v2, const ray& r) {
    /// Vetor normal ao plano do triângulo
    vec3 normal = cross(v1 - v0, v2 - v0);

    /// Verificação se o raio é paralelo ao plano do triângulo
    double denominador = dot(normal, r.direction());
    if (std::fabs(denominador) < 1e-6)
        return false;

    /// Cálculo da distância até plano do triângulo
    double t = dot(normal, v0 - r.origin()) / denominador;

    /// Verificação se a interseção está à frente do raio
    if (t < 0)
        return false;

    /// Cálculo da posição da interseção no plano do triângulo
    point3 intersecao = r.origin() + t * r.direction();

    /// Teste se a interseção está dentro do triângulo usando coordenadas bariôcentricas
    vec3 lado0 = v1 - v0;
    vec3 lado1 = v2 - v1;
    vec3 lado2 = v0 - v2;

    vec3 C0 = intersecao - v0;
    vec3 C1 = intersecao - v1;
    vec3 C2 = intersecao - v2;

    if (dot(cross(lado0, C0), normal) >= 0 &&
        dot(cross(lado1, C1), normal) >= 0 &&
        dot(cross(lado2, C2), normal) >= 0)
        return true;  /// A interseção está dentro do triângulo

    return false;
}


/**
 * @brief Verifica se um raio atinge um objeto .obj.
 * 
 * @param vertices 
 * @param faces 
 * @param r 
 * @return true 
 * @return false 
 */
bool hit_obj(const std::vector<Vertex>& vertices, const std::vector<Face>& faces, const ray& r) {

    /// Itera sobre as faces do objeto .obj
    for (const Face& face : faces) {

        /// Obtém os vértices da face (os índices começam em 1 em .obj)
        const Vertex& v0 = vertices[face.vertexIndex - 1];  /// Índices em .obj começam em 1
        const Vertex& v1 = vertices[face.textureCoordIndex - 1];
        const Vertex& v2 = vertices[face.normalIndex - 1];

        /// Verifica se o raio atinge o triângulo formado pelos vértices
        if (hit_triangle(v0, v1, v2, r))
            return true; /// Há interseção com pelo menos um triângulo
    }
    return false; /// Nenhum triângulo foi atingido pelo raio
}


/**
 * @brief Determina a cor de um raio de cena a depender do tipo de forma geométrica especificada. Recebe o raio e uma string indicando a forma geométrica. 
 * 
 * @param r 
 * @param geometricForm 
 * @return color 
 */
color ray_color(const ray& r, const std::string& geometricForm, const processObject& objData) {

    /// Renderização de uma esfera vermelha
    if (geometricForm == "sphere") {
        if (hit_sphere(point3(0, 0, -1), 0.5, r))
            return color(1, 0, 0);

    } else if (geometricForm == "triangle") {

        /// Definição dos vértices do triângulo
        point3 v0(-0.5, -0.5, -1.0);
        point3 v1(0.5, -0.5, -1.0);
        point3 v2(0, 0.5, -1.0);

        /// Verificação se o raio atinge o triângulo e respectivo retorno da cor correspondente
        if (hit_triangle(v0, v1, v2, r))
            return color(0, 0, 1);

    } else if (geometricForm == "obj") {

        /// Verificação se o raio atinge o objeto .obj
        if (hit_obj(objData.vertexClass, objData.faceClass, r))
            return color(0, 1, 0);
    }

    /// Renderização de um gradiente de azul para branco no fundo
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}


/**
 * @brief Cria uma imagem raytraced com base nos parâmetros fornecidos. Itera pelos pixels da imagem, calcula a direção do raio para cada pixel e, por fim, determina a cor do raio usando a função ray_color.
 * 
 * @param geometricForm 
 * @param fileName 
 * @param image_width 
 * @param image_height 
 * @param pixel00_loc 
 * @param camera_center 
 * @param viewport_u 
 * @param viewport_v 
 * @param pixel_delta_u 
 * @param pixel_delta_v 
 */
void renderScene(
    const std::string& geometricForm,
    const char* fileName,
    const int image_width,
    const int image_height,
    const vec3& pixel00_loc,
    const vec3& camera_center,
    const vec3& viewport_u,
    const vec3& viewport_v,
    const vec3& pixel_delta_u,
    const vec3& pixel_delta_v,
    const processObject& objData) {

    /// Objeto para criação da imagem
    MakeImage myImage = MakeImage(image_width, image_height);

    /// Abertura do arquivo PPM para escrita
    std::ofstream file(fileName);
    file << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {

            /// Cálculo da localização do centro do pixel no espaço 3D
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            /// Determinação da cor do raio e escrita no arquivo
            color pixel_color = ray_color(r, geometricForm, objData);
            write_color(file, pixel_color);
    }   }

    /// Fechamento do arquivo PPM e salvamento da imagem
    std::cout << std::endl;
    file.close();
    myImage.saveImage(fileName);

    std::clog << "\rDone.                 \n";
}


int main() {

    /// Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    /// Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    /// Camera

    /// Viewport widths less than one are ok since they are real valued.
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);

    /// Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    /// Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    /// Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    /// Render

    processObject objData;
    objData.loadFileOBJ("/mnt/c/Users/Archie/Desktop/ComputacaoGrafica/Atividade 04 - 30.10/images/cube.obj");

    /// Esfera
    renderScene("sphere", "sphere.ppm", image_width, image_height, pixel00_loc, camera_center, viewport_u, viewport_v, pixel_delta_u, pixel_delta_v, objData);

    /// Triângulo
    renderScene("triangle", "triangle.ppm", image_width, image_height, pixel00_loc, camera_center, viewport_u, viewport_v, pixel_delta_u, pixel_delta_v, objData);

    /// Arquivo OBJ
    renderScene("obj", "obj.ppm", image_width, image_height, pixel00_loc, camera_center, viewport_u, viewport_v, pixel_delta_u, pixel_delta_v, objData);
}