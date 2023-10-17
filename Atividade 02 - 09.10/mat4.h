/**
 * @file mat4.h
 * @author Arthur Felipe Bravo Pita
 * @brief Código de definição da classe mat4, para operar com matrizes de tamanho 4x4.
 * @version 1.0
 * @date 2023-10-16
 * @todo Cálculo do determinante da matriz a ser feito no futuro (tentar expansão de Laplace ou regra de Sarrus para submatrizes 3x3.
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAT4_H
#define MAT4_H

#include "vec4.h"
#include <cmath>
#include <iostream>

class mat4 {
public:

    /**
     * @brief Matriz 4x4 para armazenamento dos elementos.
     * 
     */
    double e[4][4];

    /**
     * @brief Construtor padrão, inicializa a matriz com zeros.
     * 
     */
    mat4() : e{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}} {}

    /**
     * @brief Construtor personalizado, permite especificar os elementos da matriz.
     * 
     * @param e00 
     * @param e01 
     * @param e02 
     * @param e03 
     * @param e10 
     * @param e11 
     * @param e12 
     * @param e13 
     * @param e20 
     * @param e21 
     * @param e22 
     * @param e23 
     * @param e30 
     * @param e31 
     * @param e32 
     * @param e33 
     */
    mat4(double e00, double e01, double e02, double e03,
         double e10, double e11, double e12, double e13,
         double e20, double e21, double e22, double e23,
         double e30, double e31, double e32, double e33)
        : e{{e00, e01, e02, e03}, {e10, e11, e12, e13}, {e20, e21, e22, e23}, {e30, e31, e32, e33}} {}

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
     * @return mat4 
     */
    mat4 operator-() const {
        return mat4(-e[0][0], -e[0][1], -e[0][2], -e[0][3],
                    -e[1][0], -e[1][1], -e[1][2], -e[1][3],
                    -e[2][0], -e[2][1], -e[2][2], -e[2][3],
                    -e[3][0], -e[3][1], -e[3][2], -e[3][3]);
    }

    /**
     * @brief Operação de adição, que adiciona outra matriz à matriz atual.
     * 
     * @param m 
     * @return mat4& 
     */
    mat4& operator+=(const mat4 &m) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                e[i][j] += m.e[i][j];
        }   }
        return *this;
    }

    /* EQUIVALENTE À:
     * mat4& operator+=(const mat4 &m) {
     *     e[0][0] += m.e[0][0]; e[0][1] += m.e[0][1]; e[0][2] += m.e[0][2]; e[0][3] += m.e[0][3];
     *     e[1][0] += m.e[1][0]; e[1][1] += m.e[1][1]; e[1][2] += m.e[1][2]; e[1][3] += m.e[1][3];
     *     e[2][0] += m.e[2][0]; e[2][1] += m.e[2][1]; e[2][2] += m.e[2][2]; e[2][3] += m.e[2][3];
     *     e[3][0] += m.e[3][0]; e[3][1] += m.e[3][1]; e[3][2] += m.e[3][2]; e[3][3] += m.e[3][3];
     *     return *this;
     * }
     */

    /**
     * @brief Operação de multiplicação por escalar, que multiplica todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat4& 
     */
    mat4& operator*=(double t) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                e[i][j] *= t;
        }   }
        return *this;
    }

    /* EQUIVALENTE À:
     * mat4& operator*=(double t) {
     *     e[0][0] *= t; e[0][1] *= t; e[0][2] *= t; e[0][3] *= t;
     *     e[1][0] *= t; e[1][1] *= t; e[1][2] *= t; e[1][3] *= t;
     *     e[2][0] *= t; e[2][1] *= t; e[2][2] *= t; e[2][3] *= t;
     *     e[3][0] *= t; e[3][1] *= t; e[3][2] *= t; e[3][3] *= t;
     *     return *this;
     * }
     */

    /**
     * @brief Operação de divisão por escalar, que divide todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat4& 
     */
    mat4& operator/=(double t) {
        return *this *= 1 / t;
    }

    /**
     * @brief Cálculo do determinante da matriz a ser feito no futuro (tentar expansão de Laplace ou regra de Sarrus para submatrizes 3x3).
     * 
     * @return double 
     */
    double determinant() const {
        return 0.0;
    }

    /**
     * @brief Retorno da soma dos elementos da diagonal principal (traço da matriz).
     * 
     * @return double 
     */
    double trace() const {
        return e[0][0] + e[1][1] + e[2][2] + e[3][3];
    }

};

// Funções de operações de matriz

/**
 * @brief Operação de saída, para impressão da matriz.
 * 
 * @param out 
 * @param m 
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream &out, const mat4 &m) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out << m.e[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

/**
 * @brief Operação de adição, para somar duas matrizes.
 * 
 * @param a 
 * @param b 
 * @return mat4 
 */
inline mat4 operator+(const mat4 &a, const mat4 &b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = a(i, j) + b(i, j);
    }   }
    return result;
}

/* EQUIVALENTE À:
 * inline mat4 operator+(const mat4 &a, const mat4 &b) {
 *     return mat4(a.e[0][0] + b.e[0][0], a.e[0][1] + b.e[0][1], a.e[0][2] + b.e[0][2], a.e[0][3] + b.e[0][3],
 *                 a.e[1][0] + b.e[1][0], a.e[1][1] + b.e[1][1], a.e[1][2] + b.e[1][2], a.e[1][3] + b.e[1][3],
 *                 a.e[2][0] + b.e[2][0], a.e[2][1] + b.e[2][1], a.e[2][2] + b.e[2][2], a.e[2][3] + b.e[2][3],
 *                 a.e[3][0] + b.e[3][0], a.e[3][1] + b.e[3][1], a.e[3][2] + b.e[3][2], a.e[3][3] + b.e[3][3]);
 * }
 */

/**
 * @brief Operação de subtração, para subtrair uma matriz de outra.
 * 
 * @param a 
 * @param b 
 * @return mat4 
 */
inline mat4 operator-(const mat4 &a, const mat4 &b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = a(i, j) - b(i, j);
    }   }
    return result;
}

/* EQUIVALENTE À:
 * inline mat4 operator-(const mat4 &a, const mat4 &b) {
 *     return mat4(a.e[0][0] - b.e[0][0], a.e[0][1] - b.e[0][1], a.e[0][2] - b.e[0][2], a.e[0][3] - b.e[0][3],
 *                 a.e[1][0] - b.e[1][0], a.e[1][1] - b.e[1][1], a.e[1][2] - b.e[1][2], a.e[1][3] - b.e[1][3],
 *                 a.e[2][0] - b.e[2][0], a.e[2][1] - b.e[2][1], a.e[2][2] - b.e[2][2], a.e[2][3] - b.e[2][3],
 *                 a.e[3][0] - b.e[3][0], a.e[3][1] - b.e[3][1], a.e[3][2] - b.e[3][2], a.e[3][3] - b.e[3][3]);
 * }
 */

/**
 * @brief Operação de multiplicação de matriz por matriz.
 * 
 * @param a 
 * @param b 
 * @return mat4 
 */
inline mat4 operator*(const mat4 &a, const mat4 &b) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = a(i, 0) * b(0, j) +
                           a(i, 1) * b(1, j) +
                           a(i, 2) * b(2, j) +
                           a(i, 3) * b(3, j);
    }   }
    return result;
}

/**
 * @brief Operação de multiplicação de matriz por escalar.
 * 
 * @param t 
 * @param m 
 * @return mat4 
 */
inline mat4 operator*(double t, const mat4 &m) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = t * m(i, j);
    }   }
    return result;
}

/* EQUIVALENTE À:
 * inline mat4 operator*(double t, const mat4 &m) {
 *     return mat4(t * m.e[0][0], t * m.e[0][1], t * m.e[0][2], t * m.e[0][3],
 *                 t * m.e[1][0], t * m.e[1][1], t * m.e[1][2], t * m.e[1][3],
 *                 t * m.e[2][0], t * m.e[2][1], t * m.e[2][2], t * m.e[2][3],
 *                 t * m.e[3][0], t * m.e[3][1], t * m.e[3][2], t * m.e[3][3]);
 * }
 */

/**
 * @brief Sobrecarga da operação de multiplicação de matriz por escalar (ordem alternativa).
 * 
 * @param m 
 * @param t 
 * @return mat4 
 */
inline mat4 operator*(const mat4 &m, double t) {
    return t * m;
}

/**
 * @brief Operação de divisão de matriz por escalar.
 * 
 * @param m 
 * @param t 
 * @return mat4 
 */
inline mat4 operator/(mat4 m, double t) {
    return (1 / t) * m;
}

/**
 * @brief Produto escalar entre matrizes.
 * 
 * @param a 
 * @param b 
 * @return double 
 */
inline double dot(const mat4 &a, const mat4 &b) {
    double result = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result += a(i, j) * b(i, j);
    }   }
    return result;
}

/**
 * @brief Operações de matriz por vetor.
 * 
 * @param m 
 * @param v 
 * @return vec4 
 */
inline vec4 operator*(const mat4 &m, const vec4 &v) {
    vec4 result;
    for (int i = 0; i < 4; i++) {
        result[i] = 0;
        for (int j = 0; j < 4; j++) {
            result[i] += m(i, j) * v[j];
    }   }
    return result;
}

/* EQUIVALENTE À:
 * inline vec4 operator*(const mat4 &m, const vec4 &v) {
 *     return vec4(m(0, 0) * v.x() + m(0, 1) * v.y() + m(0, 2) * v.z() + m(0, 3) * v.w(),
 *                 m(1, 0) * v.x() + m(1, 1) * v.y() + m(1, 2) * v.z() + m(1, 3) * v.w(),
 *                 m(2, 0) * v.x() + m(2, 1) * v.y() + m(2, 2) * v.z() + m(2, 3) * v.w(),
 *                 m(3, 0) * v.x() + m(3, 1) * v.y() + m(3, 2) * v.z() + m(3, 3) * v.w());
 * }
 */

inline vec4 operator*(const vec4 &v, const mat4 &m) {
    return m * v;
}

/**
 * @brief Matriz de Identidade.
 * 
 * @return mat4 
 */
inline mat4 identity4() {
    return mat4(1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                0.0, 0.0, 0.0, 1.0);
}

/**
 * @brief Transposição de matriz.
 * 
 * @param m 
 * @return mat4 
 */
inline mat4 transpose(const mat4 &m) {
    mat4 result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result(i, j) = m(j, i);
    }   }
    return result;
}

/* EQUIVALENTE À:
 * inline mat4 transpose(const mat4 &m) {
 *     return mat4(m(0, 0), m(1, 0), m(2, 0), m(3, 0),
 *                 m(0, 1), m(1, 1), m(2, 1), m(3, 1),
 *                 m(0, 2), m(1, 2), m(2, 2), m(3, 2),
 *                 m(0, 3), m(1, 3), m(2, 3), m(3, 3));
 * }
 */

#endif
