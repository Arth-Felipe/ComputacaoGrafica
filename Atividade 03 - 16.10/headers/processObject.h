/**
 * @file processObject.h
 * @author Arthur Felipe Bravo Pita
 * @brief Definição da classe 'processObject', dedicada a leitura de arquivos OBJ.
 * @version 1.0
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PROCESSOBJECT_H
#define PROCESSOBJECT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = //


/**
 * @brief Definição das estruturas de dados para armazenamento de informações de arquivos OBJ.
 * 
 */
struct Vertex {
    float x, y, z;

    // Conversão dos objetos Vertex em pontos (para a atv05, onde código tenta usar objetos do tipo Vertex como pontos point3).
    operator point3() const {
        return point3(x, y, z);
    }
};

struct TextureCoordinate {
    float u, v;
};

struct Normal {
    float x, y, z;
};

struct Face {
    int vertexIndex, textureCoordIndex, normalIndex;
};


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = //


/**
 * @brief Declaração da classe processObject.
 * 
 */
class processObject {
public:

    /**
     * @brief Vetores de armazenamento dos dados lidos de arquivos OBJ.
     * 
     */
    std::vector<Vertex> vertexClass;
    std::vector<TextureCoordinate> textureCoordClass;
    std::vector<Normal> normalClass;
    std::vector<Face> faceClass;

    /**
     * @brief Função de carregamento de dados de arquivos OBJ.
     * 
     * @param fileName 
     * @return true 
     * @return false 
     */
    bool loadFileOBJ(const std::string& fileName) {

        // Leitura de arquivo
        std::ifstream file(fileName);

        // Verificação para o caso de o arquivo não conseguir ser aberto
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o seguinte arquivo: " << fileName << std::endl;
            return false;
        }

        std::string lineRead;

        // Leitura de cada linha do arquivo OBJ
        while (std::getline(file, lineRead)) {

            std::istringstream iss(lineRead);
            std::string token;
            iss >> token;

            // Se a linha começa com 'v', é um vértice
            if (token == "v") {
                Vertex vertexLocal;

                // Leitura das coordenadas x, y e z do vértice
                if (iss >> vertexLocal.x >> vertexLocal.y >> vertexLocal.z)
                    vertexClass.push_back(vertexLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de vértice: " << lineRead << std::endl;
            }

            // Se a linha começa com 'vt', são coordenadas de textura
            else if (token == "vt") {
                TextureCoordinate textureCoordLocal;

                // Leitura das coordenadas de textura u e v
                if (iss >> textureCoordLocal.u >> textureCoordLocal.v)
                    textureCoordClass.push_back(textureCoordLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de coordenadas de textura: " << lineRead << std::endl;
            }

            // Se a linha começa com 'vn', são normais
            else if (token == "vn") {
                Normal normalLocal;

                // Leitura das componentes x, y e z da normal
                if (iss >> normalLocal.x >> normalLocal.y >> normalLocal.z)
                    normalClass.push_back(normalLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de normal: " << lineRead << std::endl;
            }

            // Se a linha começa com 'f', é uma face
            else if (token == "f") {
                Face faceLocal;

                // Leitura dos índices do vértice, coordenada de textura e normal
                if (iss >> faceLocal.vertexIndex >> token >> faceLocal.textureCoordIndex >> token >> faceLocal.normalIndex)
                    faceClass.push_back(faceLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de face: " << lineRead << std::endl;
        }   }

        file.close();
        return true;
}   };

#endif /* PROCESSOBJECT_H */