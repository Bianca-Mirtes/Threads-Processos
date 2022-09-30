# Threads-Processos

## Gerando binário para matrizes aleatórias
```
g++ gerarMatriz.cpp -o gerarMatriz -Wall  
```
Rodar: _números podem variar dependendo do tamanho da matriz_
```
./gerarMatriz 500 500 500 500
```
<br>

## Sequencial:
```
g++ sequencial.cpp -o sequencial -Wall
```

Rodar manualmente cada teste:
```
./sequencial "../data/matrizGerada1.txt" "../data/matrizGerada2.txt"
```

Rodar o programa x vezes automaticamente:
```
./run.sh
```
<br>

## Multithreads
Compilar: 
```
g++ threads.cpp -o ./threads -pthread -std=c++11
```
Executar:
_O último parâmetro inserido é (n1*m2) / 8_ 

O valor de 31250 é para matriz 500 500 500 500
```
./threads "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 31250
```
<br>

## Processos
Compilar:
```
g++ processos.cpp -o processos
```
Executar:
_O último parâmetro inserido é (n1*m2) / 8_

O valor de 31250 é para matriz 500 500 500 500
```
./processos "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 31250
```
