/**
 * @file vec4.h
 * @author Arthur Felipe Bravo Pita
 * @brief Código de definição da classe vec4, feita para lidar com vetores de tamanho 4.
 * @version 1.0
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec4 {
public:

    /**
     * @brief Vetor de quatro elementos para armazenamento dos componentes.
     * 
     */
    double e[4];

    /**
     * @brief Construtor padrão, que inicializa o vetor com todos os elementos iguais a zero.
     * 
     */
    vec4() : e{0,0,0,0} {}

    /**
     * @brief Construtor personalizado, que permite especificar os componentes do vetor.
     * 
     * @param e0 
     * @param e1 
     * @param e2 
     * @param e3 
     */
    vec4(double e0, double e1, double e2, double e3) : e{e0, e1, e2, e3} {}

    /**
     * @brief Retornos individuais de cada respectivo componente do vetor.
     * 
     * @return double 
     */
    double w() const { return e[0]; }
    double x() const { return e[1]; }
    double y() const { return e[2]; }
    double z() const { return e[3]; }

    /**
     * @brief Operação de negação, que inverte o vetor.
     * 
     * @return vec4 
     */
    vec4 operator-() const { return vec4(-e[0], -e[1], -e[2], -e[3]); }

    /**
     * @brief Operação de acesso aos componentes do vetor.
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
     * @return vec4& 
     */
    vec4& operator+=(const vec4 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        e[3] += v.e[3];
        return *this;
    }

    /**
     * @brief Operação de multiplicação por escalar, que multiplica cada componente do vetor pelo escalar.
     * 
     * @param t 
     * @return vec4& 
     */
    vec4& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        e[3] *= t;
        return *this;
    }

    /**
     * @brief Operação de divisão por escalar, que divide cada componente do vetor pelo escalar.
     * 
     * @param t 
     * @return vec4& 
     */
    vec4& operator/=(double t) {
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
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3];
    }
};


/**
 * @brief point4 é apenas um apelido para vec4, útil para clareza geométrica no código.
 * 
 */
using point4 = vec4;


// Vector Utility Functions

/**
 * @brief Operação de saída, para impressão.
 * 
 * @param out 
 * @param v 
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

/**
 * @brief Operação de adição, para somar dois vetores.
 * 
 * @param u 
 * @param v 
 * @return vec4 
 */
inline vec4 operator+(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2], u.e[3] + v.e[3]);
}

/**
 * @brief Operação de subtração, para subtrair dois vetores.
 * 
 * @param u 
 * @param v 
 * @return vec4 
 */
inline vec4 operator-(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2], u.e[3] - v.e[3]);
}

/**
 * @brief Operação de multiplicação componente a componente.
 * 
 * @param u 
 * @param v 
 * @return vec4 
 */
inline vec4 operator*(const vec4 &u, const vec4 &v) {
    return vec4(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2], u.e[3] * v.e[3]);
}

/**
 * @brief Operação de multiplicação de um vetor por um escalar.
 * 
 * @param t 
 * @param v 
 * @return vec4 
 */
inline vec4 operator*(double t, const vec4 &v) {
    return vec4(t*v.e[0], t*v.e[1], t*v.e[2], t*v.e[3]);
}

/**
 * @brief Sobrecarga da operação de multiplicação de um vetor por um escalar (ordem alternativa).
 * 
 * @param v 
 * @param t 
 * @return vec4 
 */
inline vec4 operator*(const vec4 &v, double t) {
    return t * v;
}

/**
 * @brief Operação de divisão de um vetor por um escalar.
 * 
 * @param v 
 * @param t 
 * @return vec4 
 */
inline vec4 operator/(vec4 v, double t) {
    return (1/t) * v;
}

/**
 * @brief Produto escalar entre dois vetores.
 * 
 * @param u 
 * @param v 
 * @return double 
 */
inline double dot(const vec4 &u, const vec4 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2]
         + u.e[3] * v.e[3];
}

/**
 * @brief Retorno de um vetor unitário (normalizado) na mesma direção que o vetor de entrada.
 * 
 * @param v 
 * @return vec4 
 */
inline vec4 unit_vector(vec4 v) {
    return v / v.length();
}

#endif