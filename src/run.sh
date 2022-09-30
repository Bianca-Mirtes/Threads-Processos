#! /bin/bash

for i in 1 2 3 4 5 6 7 8 9 10; do 
    ./sequencial "../data/matrizGerada1.txt" "../data/matrizGerada2.txt"
    ./processos "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 320000
    ./threads "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 320000

	echo "Teste $i"
done

