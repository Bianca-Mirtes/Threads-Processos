# Threads-Processos
* Repositório do Trabalho 1 da disciplina de Sistemas Operacionais no semestre 2022.2.

## Gerando binário para matrizes aleatórias
```
g++ gerarMatriz.cpp -o gerarMatriz -Wall  
```
Executar: _números podem variar dependendo do tamanho da matriz_
```
./gerarMatriz 100 100 100 100
```
<br>

## Sequencial:
Compilar:
```
g++ sequencial.cpp -o sequencial -Wall
```

Executar:
```
./sequencial "../data/matrizGerada1.txt" "../data/matrizGerada2.txt"
```
<br>

## Multithreads
Compilar: 
```
g++ threads.cpp -o ./threads -pthread -std=c++11
```
Executar:
_O último parâmetro inserido é (n1*m2) / 8_ 

O valor de 1250 é para matriz 100 100 100 100
```
./threads "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 1250
```
<br>

## Processos
Compilar:
```
g++ processos.cpp -o processos
```
Executar:
_O último parâmetro inserido é (n1*m2) / 8_

O valor de 1250 é para matriz 100 100 100 100
```
./processos "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 1250
```
<br>

## Script para executar automaticamente uma quantidade x de testes
Executar:
```
./run.sh
```

Colocar no arquivo .sh o comando para executar e a quantidade de vezes (Ex: for i in 1 2 3; do para rodar 3 vezes);

Sequencial:
```
./sequencial "../data/matrizGerada1.txt" "../data/matrizGerada2.txt"
```

Threads:
```
./threads "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 1250
```

Processos:
```
./processos "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 1250
```