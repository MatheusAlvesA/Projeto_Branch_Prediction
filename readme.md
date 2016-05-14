#Introdução
Este projeto implementa um simulador de predição de salto(Branch Prediction), a predição de salto é uma técnica
usada pelos processadores atuais que visa aumentar a performance do mesmo, uma vez que o processador
encontra uma instrução de jump, em seu pipeline, ele deve decidir se deve ou não toma aquele salto,
se ele tomar a decisão errada, irá encher o pipeline com instruções inúteis e precisará se desfazer delas
para, só então, executar as instruções na ordem correa, é por esse motivo que surgiram as predições.
Com o auxilio dessas técnicas o processador poderá evitar esse tipo de problema e tornar a execução de
algoritmos mais eficiente.

#Autores

[Matheus Alves](https://github.com/MatheusAlvesA)

[Nalbert Gabriel](https://github.com/nalbertg)

#O projeto
Esse projeto está sendo desenvolvido como uma atividade complementar ao semestre 2016.1 da turma
de IOAC da professora Monica Magalhães, uma predição de salto baseada em correlação que usa 
um e dois bits como forma de previsão dinâmica será implementada.

#Como compilar
Um arquivo makefile está disponível no repositório, então apenas execute o comando make em uma
maquina linux com o compilador g++ instalado, o binario será salvo na pasta bin/

#Até agora
Apenas a leitura do arquivo está sendo feita, o projeto ainda não começou.
