/**
 * @file main.cc
 * @author Arthur Felipe Bravo Pita
 * @brief 
 * @version 1.0
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "processObject.h"

int main() {
    processObject model;
    if (model.loadFileOBJ("../tests/example-sword.obj")) {
        // Agora você pode acessar as informações do modelo
        // model.vertices contém os vértices
        // model.textureCoordinates contém as coordenadas de textura
        // model.normals contém as normais
        // model.faces contém as informações das faces
        return true;
    }

    else {
        return false;
    }

    return 0;
}
