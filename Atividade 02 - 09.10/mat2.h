/**
 * @file mat2.h
 * @author Arthur Felipe Bravo Pita
 * @brief Código de definição da classe mat2, para manipular matrizes de tamanho 2x2.
 * @version 1.0
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

class mat2 {
public:

    /**
     * @brief Vetor bidimensional de 2x2 para armazenamento dos elementos da matriz.
     * 
     */
    double e[2][2];

    /**
     * @brief Construtor padrão, que inicializa a matriz com todos os elementos iguais a zero.
     * 
     */
    mat2() : e{{0, 0}, {0, 0}} {}

    /**
     * @brief Construtor personalizado, que permite especificar os elementos da matriz.
     * 
     * @param e00 
     * @param e01 
     * @param e10 
     * @param e11 
     */
    mat2(double e00, double e01, double e10, double e11) : e{{e00, e01}, {e10, e11}} {}

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
     * @return mat2 
     */
    mat2 operator-() const {
        return mat2(-e[0][0], -e[0][1], -e[1][0], -e[1][1]);
    }

    /**
     * @brief Operação de adição, que adiciona outra matriz à matriz atual.
     * 
     * @param m 
     * @return mat2& 
     */
    mat2& operator+=(const mat2 &m) {
        e[0][0] += m.e[0][0];
        e[0][1] += m.e[0][1];
        e[1][0] += m.e[1][0];
        e[1][1] += m.e[1][1];
        return *this;
    }

    /**
     * @brief Operação de multiplicação por escalar, que multiplica todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat2& 
     */
    mat2& operator*=(double t) {
        e[0][0] *= t;
        e[0][1] *= t;
        e[1][0] *= t;
        e[1][1] *= t;
        return *this;
    }

    /**
     * @brief Operação de divisão por escalar, que divide todos os elementos da matriz pelo escalar.
     * 
     * @param t 
     * @return mat2& 
     */
    mat2& operator/=(double t) {
        return *this *= 1 / t;
    }

    /**
     * @brief Retorno do determinante da matriz.
     * 
     * @return double 
     */
    double determinant() const {
        return e[0][0] * e[1][1] - e[0][1] * e[1][0];
    }

    /**
     * @brief Retorno da soma dos elementos da diagonal da matriz.
     * 
     * @return double 
     */
    double trace() const {
        return e[0][0] + e[1][1];
    }
};


// Matrix Utility Functions

/**
 * @brief Operação de saída, para impressão da matriz.
 * 
 * @param out 
 * @param m 
 * @return std::ostream& 
 */
inline std::ostream& operator<<(std::ostream &out, const mat2 &m) {
    return out << m.e[0][0] << ' ' << m.e[0][1] << '\n' << m.e[1][0] << ' ' << m.e[1][1];
}

/**
 * @brief Operação de adição, para somar duas matrizes.
 * 
 * @param a 
 * @param b 
 * @return mat2 
 */
inline mat2 operator+(const mat2 &a, const mat2 &b) {
    return mat2(a.e[0][0] + b.e[0][0], a.e[0][1] + b.e[0][1],
                a.e[1][0] + b.e[1][0], a.e[1][1] + b.e[1][1]);
}

/**
 * @brief Operação de subtração, para subtrair uma matriz de outra.
 * 
 * @param a 
 * @param b 
 * @return mat2 
 */
inline mat2 operator-(const mat2 &a, const mat2 &b) {
    return mat2(a.e[0][0] - b.e[0][0], a.e[0][1] - b.e[0][1],
                a.e[1][0] - b.e[1][0], a.e[1][1] - b.e[1][1]);
}

/**
 * @brief Operação de multiplicação de matriz por matriz.
 * 
 * @param a 
 * @param b 
 * @return mat2 
 */
inline mat2 operator*(const mat2 &a, const mat2 &b) {
    return mat2(a.e[0][0] * b.e[0][0] + a.e[0][1] * b.e[1][0],
                a.e[0][0] * b.e[0][1] + a.e[0][1] * b.e[1][1],
                a.e[1][0] * b.e[0][0] + a.e[1][1] * b.e[1][0],
                a.e[1][0] * b.e[0][1] + a.e[1][1] * b.e[1][1]);
}

/**
 * @brief Operação de multiplicação de matriz por escalar.
 * 
 * @param t 
 * @param m 
 * @return mat2 
 */
inline mat2 operator*(double t, const mat2 &m) {
    return mat2(t * m.e[0][0], t * m.e[0][1], t * m.e[1][0], t * m.e[1][1]);
}

/**
 * @brief Sobrecarga da operação de multiplicação de matriz por escalar (ordem alternativa).
 * 
 * @param m 
 * @param t 
 * @return mat2 
 */
inline mat2 operator*(const mat2 &m, double t) {
    return t * m;
}

/**
 * @brief Operador de divisão de matriz por escalar.
 * 
 * @param m 
 * @param t 
 * @return mat2 
 */
inline mat2 operator/(mat2 m, double t) {
    return (1 / t) * m;
}

#endif
