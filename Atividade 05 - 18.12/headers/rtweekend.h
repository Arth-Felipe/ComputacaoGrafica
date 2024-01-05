/**
 * @file rtweekend.h
 * @brief Arquivo de cabeçalho geral com constantes matemáticas úteis (como infinito e pi) e funções utilitárias para o futuro. Também é capaz de gerar e retornar números aleatórios reais.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>


// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

// Common Headers

#include "interval.h"
#include "../../Atividade 04 - 30.10/headers/ray.h"
#include "../../Atividade 02 - 09.10/vec3.h"

#endif
