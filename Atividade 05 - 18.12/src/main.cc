/**
 * @file main.cc
 * @brief Quase tudo da antiga main() foi movido para a nova classe de câmera. O que restou foram a construção do mundo, criação da câmera, definição dos valores padrão e, por fim, chamada do método render(), que prepara a câmera e executa o loop de renderização.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../headers/rtweekend.h"
#include "../headers/camera.h"
#include "../headers/hittable_list.h"
#include "../headers/sphere.h"

int main() {
    hittable_list world;

    // auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    // auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    // auto material_left   = make_shared<dielectric>(1.5);
    // auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0 /*, material_ground*/ ));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5 /*, material_center*/ ));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5 /*, material_left*/ ));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4 /*, material_left*/ ));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5 /*, material_right*/ ));

/*************************************************/
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;

    cam.vfov     = 60;
    cam.lookfrom = point3(-2,2,1);  // x = de 0 para 1 foi pra direita, y = de 0 para 1 foi pra cima, z = de 0 para 1 foi mais pra trás, tirou o zoom
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.render(world, "result-cam1.ppm");

/*************************************************/
    camera cam2;

    cam2.aspect_ratio      = 16.0 / 9.0;
    cam2.image_width       = 400;
    cam2.samples_per_pixel = 100;
    cam2.max_depth         = 50;

    cam2.vfov     = 60;
    cam2.lookfrom = point3(2,1,0);
    cam2.lookat   = point3(-1,-1,-2);
    cam2.vup      = vec3(0,1,0);

    cam2.render(world, "result-cam2.ppm");
}