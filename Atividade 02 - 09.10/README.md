# Atividade 02 - 9 de Outubro

<!-- ## Tutorial "Ray Tracing in One Weekend" -->

Nesta segunda atividade, foram seguidos os passos da Seção 3 de _"Ray Tracing in One Weekend"_. Estes passos recriam o programa em _`C++`_ e geram a mesma imagem _`.ppm`_ da _[Atividade 00](https://github.com/Arth-Felipe/ComputacaoGrafica/tree/main/Atividade%2000%20-%2002.10)_, mas dessa vez utilizando-se de dois novos arquivos:

1. _`vec3.h`_ - Definição de uma classe para trabalhar com um vetor geométrico de tamanho 3, bem como seu conjunto de funções e operações.
2. _`color.h`_ - Usa a nova classe _`vec3.h`_ para definir uma função que grava a cor de um único pixel no fluxo de saída padrão.

Para tanto, o arquivo _`main.cc`_ passou a ter em seu cabeçalho a inclusão de ambos, mas sem alterar muito a sua compilação e devida transformação do arquivo de execução em imagem, como pode ser conferido a seguir:

```
g++ -Wall -o executavel main.cc
./executavel > image.ppm
```

Ao abrir o arquivo de saída gerado num visualizador de _`ppm`_ online _([acesso aqui](https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html))_, obteve-se o mesmo resultado da _[Atividade 00](https://github.com/Arth-Felipe/ComputacaoGrafica/tree/main/Atividade%2000%20-%2002.10)_:

![Imagem de Resultado da Atividade 00](/Atividade%2000%20-%2002.10/image-result.png)

## Atividade Proposta

Agora sim, seguindo a proposta da ___Atividade 02___, foram criadas classes próprias para a manipulação de vetores e matrizes de diversos tamanhos, expandidos para:

- _`vec2.h`_ - Classe responsável por lidar com vetores de tamanho 2.
- _`vec4.h`_ - Classe responsável por lidar com vetores de tamanho 4.
- _`mat2.h`_ - Classe responsável por manipular matrizes de tamanho 2x2.
- _`mat3.h`_ - Classe responsável por tratar de operações com matrizes de tamanho 3x3.
- _`mat4.h`_ - Classe responsável por operar com matrizes de tamanho 4x4.

Tais classes incluem diversas operações de manipulação de vetores e matrizes, tais como adição, subtração, multiplicação por escalar, de matriz por matriz, de matriz por vetor, produto escalar, produto vetorial, negação, impressão, matriz de identidade, transposição, determinante, inversão, entre outras funcionalidades úteis.

## Testes Unitários

## Documentação no Doxygen (?)
