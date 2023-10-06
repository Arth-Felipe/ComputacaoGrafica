# Atividade 01 - 2 de Outubro

Nesta primeira atividade, a proposta era evoluir o que foi feito no exercício anterior _([Atividade 00](https://github.com/Arth-Felipe/ComputacaoGrafica/tree/main/Atividade%2000%20-%2002.10))_ e criar uma classe própria para o salvamento das imagens. Essa ação deveria salvar os antigos arquivos de formato _`.ppm`_ em imagens propriamente ditas (formato _`.png`_, por exemplo) com a biblioteca [ImageMagick](https://imagemagick.org/index.php). Para tanto, o programa original em _`C++`_ foi dividido e encapsulado em outros 3:

1. _`main.cc`_ - Arquivo principal com a criação do objeto e a chamada dos métodos da classe para salvar as imagens
2. _`MakeImage.h`_ - Arquivo de cabeçalho que contém a declaração da classe e de seus atributos
3. _`MakeImage.cc`_ - Arquivo de implementação dos métodos da classe

Com isso, a compilação, execução e limpeza dos arquivos gerados passaram a precisar de diversos comandos no terminal:

```
g++ -c MakeImage.cc -o MakeImage.o
g++ main.cc MakeImage.o -o main -lMagick++
./main
rm MakeImage.o main
```

Para facilitar, foi criado um arquivo Makefile que centralizou todos esses comandos, permitindo que agora a compilação ocorresse apenas com o comando _`make`_ e a execução com _`./executavel`_. Com o comando _`make clean`_ é possível ainda limpar todo o "lixo" gerado pela compilação, excluindo assim o arquivo _`executavel`_ e todos com terminações _`.o`_, _`.png`_ e _`.ppm`_.

Se observarmos o arquivo Makefile mencionado, perceberemos que a compilação conta com _`-lMagick++`_ para a inclusão da biblioteca utilizada. Contudo, para isso dar certo, **antes** é preciso instalar a biblioteca [ImageMagick](https://imagemagick.org/index.php) através dos comandos:

```
sudo apt install imagemagick
sudo apt install libmagick++-dev
sudo apt install graphicsmagick-libmagick-dev-compat
```

Agora sim, partindo pro cerne da questão, temos que os métodos da classe criada MakeImage são responsáveis por:

- _`drawGradient()`_ - Cria um degradê que começa azul na parte superior e termina em verde na inferior, suavemente
- _`drawRing()`_ - Cria um anel (ou rosquinha) verde num fundo preto
- _`drawTriangle()`_ - Cria um triângulo equilátero azul num fundo preto
- _`saveImage(nomeDoArquivo)`_ - Inicializa o uso da biblioteca e, através de uma de suas funções próprias, converte os arquivos _`.ppm`_ gerados acima em imagens _`.png`_

Com isso, temos os seguintes resultados gerados na própria pasta de execução do programa:

![Imagem Gradiente](/Atividade%2001%20-%2002.10/result-gradiente.png)
![Imagem Anel](/Atividade%2001%20-%2002.10/result-anel.png)
![Imagem Triângulo](/Atividade%2001%20-%2002.10/result-triangulo.png)