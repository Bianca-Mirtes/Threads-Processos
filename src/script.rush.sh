#! /bin/bash
# echo "Digite o nome o programa que sera executado repetidas vezes:"
# read file
# echo "Quantas vezes $file sera executado?"
# read j
for i in 1 2 3 4 5 6 7 8 9 10; do 
    # ./sequencial "../data/matrizGerada1.txt" "../data/matrizGerada2.txt"
    ./threads "../data/matrizGerada1.txt" "../data/matrizGerada2.txt" 125000
	echo "Teste $i"
done