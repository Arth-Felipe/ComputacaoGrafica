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

struct FaceVertex {
    int vertexIndex, texCoordIndex, normalIndex;
};

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = //

class processObject {
public:

    std::vector<Vertex> vertices;
    std::vector<TextureCoordinate> textureCoordinates;
    std::vector<Normal> normals;
    std::vector<FaceVertex> faceVertices;

    bool loadFileOBJ(const std::string& nomeDoArquivo) {

        std::ifstream file(nomeDoArquivo);

        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << nomeDoArquivo << std::endl;
            return false;
        }

        std::string line;

        while (std::getline(file, line)) {

            std::istringstream iss(line);
            std::string token;
            iss >> token;

            if (token == "v") {
                Vertex vertex;

                if (iss >> vertex.x >> vertex.y >> vertex.z) {
                    vertices.push_back(vertex);
                }
                else {
                    std::cerr << "Erro ao analisar a linha de vértice: " << line << std::endl;
                }
            }

            else if (token == "vt") {
                TextureCoordinate texCoord;

                if (iss >> texCoord.u >> texCoord.v) {
                    textureCoordinates.push_back(texCoord);
                }
                else {
                    std::cerr << "Erro ao analisar a linha de coordenadas de textura: " << line << std::endl;
                }
            }

            else if (token == "vn") {
                Normal normal;

                if (iss >> normal.x >> normal.y >> normal.z) {
                    normals.push_back(normal);
                }
                else {
                    std::cerr << "Erro ao analisar a linha de normal: " << line << std::endl;
                }
            }

            else if (token == "f") {
                FaceVertex faceVertex;

                if (iss >> faceVertex.vertexIndex >> token >> faceVertex.texCoordIndex >> token >> faceVertex.normalIndex) {
                    faceVertices.push_back(faceVertex);
                }
                else {
                    std::cerr << "Erro ao analisar a linha de face: " << line << std::endl;
                }
            }
        }

        file.close();
        return true;
    }
};

#endif // PROCESSOBJECT_H