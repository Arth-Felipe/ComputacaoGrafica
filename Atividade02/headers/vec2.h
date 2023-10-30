/**
 * @file vec2.h
 * @author Arthur Felipe Bravo Pita
 * @brief Código de definição da classe vec2, feita para lidar com vetores de tamanho 2.
 * @version 1.0
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec2 {
public:

    /**
     * @brief Vetor de dois elementos para armazenamento dos componentes.
     * 
     */
    double e[2];

    /**
     * @brief Construtor padrão, que inicializa o vetor com ambos os elementos iguais a zero.
     * 
     */
    vec2() : e{0,0} {}

    /**
     * @brief Construtor personalizado, que permite especificar os componentes do vetor.
     * 
     * @param e0 
     * @param e1 
     */
    vec2(double e0, double e1) : e{e0, e1} {}

    /**
     * @brief Retornornos individuais de cada respectivo componente do vetor.
     * 
     * @return double 
     */
    double x() const { return e[0]; }
    double y() const { return e[1]; }

    /**
     * @brief Operação de negação, que inverte o vetor.
     * 
     * @return vec2 
     */
    vec2 operator-() const { return vec2(-e[0], -e[1]); }

    /**
     * @brief Operação de acesso aos componentes do vetor
     * 
     * @param i 
     * @return double 
     */
    double operator[](int i) const { return e[i]; }

    /**
     * @brief Operação com permissão de atribuição aos componentes do vetor.
     * 
     * @param i 
     * @return double& 
     */
    double& operator[](int i) { return e[i]; }

    /**
     * @brief Operação de adição, que adiciona outro vetor ao vetor atual.
     * 
     * @param v 
     * @return vec2& 
     */
    vec2& operator+=(const vec2 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    /**
     * @brief Operação de multiplicação por escalar, que multiplica cada componente do vetor pelo escalar.
     * 
     * @param t 
     * @return vec2& 
     */
    vec2& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        return *this;
    }

    /**
     * @brief Operação de divisão por escalar, que divide cada componente do vetor pelo escalar.
     * 
     * @param t 
     * @return vec2& 
     */
    vec2& operator/=(double t) {
        return *this *= 1/t;
    }

    /**
     * @brief Retorno do comprimento do vetor.
     * 
     * @return double 
     */
    double length() const {
        return sqrt(length_squared());
    }

    /**
     * @brief Retorno do quadrado do comprimento do vetor.
     * 
     * @return double 
     */
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1];
    }
};


/**
 * @brief point2 é apenas um apelido para vec2, usado para maior clareza em geometria no código.
 * 
 */
using point2 = vec2;


// Vector Utility Functions

/**
 * @brief Operação de saída, para impressão.
 * 
 * @param out 
 * @param v 
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream &out, const vec2 &v) {
    return out << v.e[0] << ' ' << v.e[1];
}

/**
 * @brief Operação de adição, para somar dois vetores.
 * 
 * @param u 
 * @param v 
 * @return vec2 
 */
inline vec2 operator+(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

/**
 * @brief Operação de subtração, para subtrair dois vetores.
 * 
 * @param u 
 * @param v 
 * @return vec2 
 */
inline vec2 operator-(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

/**
 * @brief Operação de multiplicação componente a componente.
 * 
 * @param u 
 * @param v 
 * @return vec2 
 */
inline vec2 operator*(const vec2 &u, const vec2 &v) {
    return vec2(u.e[0] * v.e[0], u.e[1] * v.e[1]);
}

/**
 * @brief Operação de multiplicação de um vetor por um escalar.
 * 
 * @param t 
 * @param v 
 * @return vec2 
 */
inline vec2 operator*(double t, const vec2 &v) {
    return vec2(t*v.e[0], t*v.e[1]);
}

/**
 * @brief Sobrecarga da operação de multiplicação de um vetor por um escalar (ordem alternativa).
 * 
 * @param v 
 * @param t 
 * @return vec2 
 */
inline vec2 operator*(const vec2 &v, double t) {
    return t * v;
}

/**
 * @brief Operação de divisão de um vetor por um escalar.
 * 
 * @param v 
 * @param t 
 * @return vec2 
 */
inline vec2 operator/(vec2 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Produto escalar entre dois vetores.
 * 
 * @param u 
 * @param v 
 * @return double 
 */
inline double dot(const vec2 &u, const vec2 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1];
}

/**
 * @brief Retorno de um vetor unitário (normalizado) na mesma direção que o vetor de entrada.
 * 
 * @param v 
 * @return vec2 
 */
inline vec2 unit_vector(vec2 v) {
    return v / v.length();
}

#endif