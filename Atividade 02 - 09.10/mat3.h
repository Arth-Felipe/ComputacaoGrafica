/**
 * @file mat3.h
 * @author Arthur Felipe Bravo Pita
 * @brief Código de definição da classe mat3, para tratar de operações com matrizes de tamanho 3x3.
 * @version 1.0
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAT3_H
#define MAT3_H

#include "vec3.h"
#include <cmath>
#include <iostream>

class mat3 {
public:

    /**
     * @brief Matriz 3x3 para armazenamento dos elementos.
     * 
     */
    double e[3][3];

    /**
     * @brief Construtor padrão, inicializa a matriz com zeros.
     * 
     */
    mat3() : e{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} {}

    /**
     * @brief Construtor personalizado, permite especificar os elementos da matriz.
     * 
     * @param e00 
     * @param e01 
     * @param e02 
     * @param e10 
     * @param e11 
     * @param e12 
     * @param e20 
     * @param e21 
     * @param e22 
     */
    mat3(double e00, double e01, double e02,
         double e10, double e11, double e12,
         double e20, double e21, double e22)
        : e{{e00, e01, e02}, {e10, e11, e12}, {e20, e21, e22}} {}

    /**
     * @brief Operação de acesso aos elementos da matriz.
     * 
     * @param i 
     * @param j 
     * @return double 
     */
    double operator()(int i, int j) const { return e[i][j]; }

    /**
     * @brief Operação com permissão de atribuição aos elementos da matriz.
     * 
     * @param i 
     * @param j 
     * @return double& 
     */
    double& operator()(int i, int j) { return e[i][j]; }

    /**
     * @brief Operação de negação, que inverte todos os elementos da matriz.
     * 
     * @return mat3 
     */
    mat3 operator-() const {
        return mat3(-e[0][0], -e[0][1], -e[0][2],
                    -e[1][0], -e[1][1], -e[1][2],
                    -e[2][0], -e[2][1], -e[2][2]);
    }

    /**
     * @brief Operação de adição, que adiciona outra matriz à matriz atual.
     * 
     * @param m 
     * @return mat3& 
     */
    mat3& operator+=(const mat3 &m) {
        e[0][0] += m.e[0][0];
        e[0][1] += m.e[0][1];
        e[0][2] += m.e[0][2];
        e[1][0] += m.e[1][0];
        e[1][1] += m.e[1][1];
        e[1][2] += m.e[1][2];
        e[2][0] += m.e[2][0];
        e[2][1] += m.e[2][1];
        e[2][2] += m.e[2][2];
        return *this;
    }

    /**
     * @brief Operação de multiplicação por escalar, que multiplica todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat3& 
     */
    mat3& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[0][2] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        e[1][2] *= t;
        e[2][0] *= t;
        e[2][1] *= t;
        e[2][2] *= t;
        return *this;
    }

    /**
     * @brief Operação de divisão por escalar, que divide todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat3& 
     */
    mat3& operator/=(double t) {
        return *this *= 1 / t;
    }

    /**
     * @brief Retorno do determinante da matriz.
     * 
     * @return double 
     */
    double determinant() const {
        return e[0][0] * (e[1][1] * e[2][2] - e[1][2] * e[2][1]) -
               e[0][1] * (e[1][0] * e[2][2] - e[1][2] * e[2][0]) +
               e[0][2] * (e[1][0] * e[2][1] - e[1][1] * e[2][0]);
    }

    /**
     * @brief Retorno da soma dos elementos da diagonal principal da matriz.
     * 
     * @return double 
     */
    double trace() const {
        return e[0][0] + e[1][1] + e[2][2];
    }
};


// Funções de Operações de Matriz


/**
 * @brief Operação de saída, para impressão da matriz.
 * 
 * @param out 
 * @param m 
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream &out, const mat3 &m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            out << m.e[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

/* EQUIVALENTE À:
 * inline std::ostream& operator<<(std::ostream &out, const mat3 &m) {
 *     return out << m.e[0][0] << ' ' << m.e[0][1] << ' ' << m.e[0][2] << '\n'
 *                << m.e[1][0] << ' ' << m.e[1][1] << ' ' << m.e[1][2] << '\n'
 *                << m.e[2][0] << ' ' << m.e[2][1] << ' ' << m.e[2][2];
 * }
 */


/**
 * @brief Operação de adição, para somar duas matrizes.
 * 
 * @param a 
 * @param b 
 * @return mat3 
 */
inline mat3 operator+(const mat3 &a, const mat3 &b) {
    return mat3(a.e[0][0] + b.e[0][0],
                a.e[0][1] + b.e[0][1],
                a.e[0][2] + b.e[0][2],
                a.e[1][0] + b.e[1][0],
                a.e[1][1] + b.e[1][1],
                a.e[1][2] + b.e[1][2],
                a.e[2][0] + b.e[2][0],
                a.e[2][1] + b.e[2][1],
                a.e[2][2] + b.e[2][2]);
}

/**
 * @brief Operação de subtração, para subtrair uma matriz de outra.
 * 
 * @param a 
 * @param b 
 * @return mat3 
 */
inline mat3 operator-(const mat3 &a, const mat3 &b) {
    return mat3(a.e[0][0] - b.e[0][0],
                a.e[0][1] - b.e[0][1],
                a.e[0][2] - b.e[0][2],
                a.e[1][0] - b.e[1][0],
                a.e[1][1] - b.e[1][1],
                a.e[1][2] - b.e[1][2],
                a.e[2][0] - b.e[2][0],
                a.e[2][1] - b.e[2][1],
                a.e[2][2] - b.e[2][2]);
}

/**
 * @brief Operação de multiplicação de matriz por matriz.
 * 
 * @param a 
 * @param b 
 * @return mat3 
 */
inline mat3 operator*(const mat3 &a, const mat3 &b) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result(i, j) = a(i, 0) * b(0, j) + a(i, 1) * b(1, j) + a(i, 2) * b(2, j);
    }   }
    return result;
}

/**
 * @brief Operação de multiplicação de matriz por escalar.
 * 
 * @param t 
 * @param m 
 * @return mat3 
 */
inline mat3 operator*(double t, const mat3 &m) {
    return mat3(t * m.e[0][0],
                t * m.e[0][1],
                t * m.e[0][2],
                t * m.e[1][0],
                t * m.e[1][1],
                t * m.e[1][2],
                t * m.e[2][0],
                t * m.e[2][1],
                t * m.e[2][2]);
}

/**
 * @brief Sobrecarga da operação de multiplicação de matriz por escalar (ordem alternativa).
 * 
 * @param m 
 * @param t 
 * @return mat3 
 */
inline mat3 operator*(const mat3 &m, double t) {
    return t * m;
}

/**
 * @brief Operador de divisão de matriz por escalar.
 * 
 * @param m 
 * @param t 
 * @return mat3 
 */
inline mat3 operator/(mat3 m, double t) {
    return (1 / t) * m;
}

/**
 * @brief Produto escalar entre matrizes.
 * 
 * @param a 
 * @param b 
 * @return double 
 */
inline double dot(const mat3 &a, const mat3 &b) {
    double result = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result += a(i, j) * b(i, j);
    }   }
    return result;
}

/**
 * @brief Produto vetorial entre matrizes.
 * 
 * @param a 
 * @param b 
 * @return mat3 
 */
inline mat3 cross(const mat3 &a, const mat3 &b) {
    return mat3(a(1, 0) * b(2, 0) - a(2, 0) * b(1, 0),
                a(2, 0) * b(0, 0) - a(0, 0) * b(2, 0),
                a(0, 0) * b(1, 0) - a(1, 0) * b(0, 0),
                a(1, 1) * b(2, 1) - a(2, 1) * b(1, 1),
                a(2, 1) * b(0, 1) - a(0, 1) * b(2, 1),
                a(0, 1) * b(1, 1) - a(1, 1) * b(0, 1),
                a(1, 2) * b(2, 2) - a(2, 2) * b(1, 2),
                a(2, 2) * b(0, 2) - a(0, 2) * b(2, 2),
                a(0, 2) * b(1, 2) - a(1, 2) * b(0, 2));
}

/**
 * @brief Operações de matriz por vetor.
 * 
 * @param m 
 * @param v 
 * @return vec3 
 */
inline vec3 operator*(const mat3 &m, const vec3 &v) {
    return vec3(m(0, 0) * v.x() + m(0, 1) * v.y() + m(0, 2) * v.z(),
                m(1, 0) * v.x() + m(1, 1) * v.y() + m(1, 2) * v.z(),
                m(2, 0) * v.x() + m(2, 1) * v.y() + m(2, 2) * v.z());
}

inline vec3 operator*(const vec3 &v, const mat3 &m) {
    return m * v;
}

/**
 * @brief Matriz de Identidade.
 * 
 * @return mat3 
 */
inline mat3 identity() {
    return mat3(1.0, 0.0, 0.0,
                0.0, 1.0, 0.0,
                0.0, 0.0, 1.0);
}

/**
 * @brief Transposição de matriz.
 * 
 * @param m 
 * @return mat3 
 */
inline mat3 transpose(const mat3 &m) {
    return mat3(m.e[0][0], m.e[1][0], m.e[2][0],
                m.e[0][1], m.e[1][1], m.e[2][1],
                m.e[0][2], m.e[1][2], m.e[2][2]);
}

#endif
