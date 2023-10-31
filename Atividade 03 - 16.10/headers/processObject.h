/**
 * @file processObject.h
 * @author Arthur Felipe Bravo Pita
 * @brief 
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

struct Vertex {
    float x, y, z;
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

class processObject {
public:

    std::vector<Vertex> vertexClass;
    std::vector<TextureCoordinate> textureCoordClass;
    std::vector<Normal> normalClass;
    std::vector<Face> faceClass;

    bool loadFileOBJ(const std::string& fileName) {

        std::ifstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o seguinte arquivo: " << fileName << std::endl;
            return false;
        }

        std::string lineRead;

        while (std::getline(file, lineRead)) {

            std::istringstream iss(lineRead);
            std::string token;
            iss >> token;

            if (token == "v") {
                Vertex vertexLocal;

                if (iss >> vertexLocal.x >> vertexLocal.y >> vertexLocal.z)
                    vertexClass.push_back(vertexLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de vértice: " << lineRead << std::endl;
            }

            else if (token == "vt") {
                TextureCoordinate textureCoordLocal;

                if (iss >> textureCoordLocal.u >> textureCoordLocal.v)
                    textureCoordClass.push_back(textureCoordLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de coordenadas de textura: " << lineRead << std::endl;
            }

            else if (token == "vn") {
                Normal normalLocal;

                if (iss >> normalLocal.x >> normalLocal.y >> normalLocal.z)
                    normalClass.push_back(normalLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de normal: " << lineRead << std::endl;
            }

            else if (token == "f") {
                Face faceLocal;

                if (iss >> faceLocal.vertexIndex >> token >> faceLocal.textureCoordIndex >> token >> faceLocal.normalIndex)
                    faceClass.push_back(faceLocal);
                else
                    std::cerr << "Erro na análise da seguinte linha de face: " << lineRead << std::endl;
            }

            else
                std::cerr << "Erro na leitura de linha: não se encaixou em 'v', 'vt', 'vn' ou 'f'" << std::endl;
        }

        file.close();
        return true;
}   };

#endif /* PROCESSOBJECT_H */