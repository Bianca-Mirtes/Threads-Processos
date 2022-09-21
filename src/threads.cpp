#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;
using namespace std::chrono;


void multiplicacao(int id_thread, int qnt_elementos, vector<vector<int>> &matriz1, vector<vector<int>> &matriz2){
    int elem = 0, count_elem = 0;
    int inicio, fim;
    inicio = (qnt_elementos * id_thread) / matriz2[0].size();
    fim = (qnt_elementos * (id_thread + 1)) / matriz2[0].size();
    
    ofstream arquivoMatriz3;
    string arq_base = "../data/thread";
    string arq = arq_base.append(to_string(id_thread+1)).append(".txt");
    arquivoMatriz3.open(arq);
    if(!arquivoMatriz3.is_open()){
        arquivoMatriz3.open(arq);
    }
    for (int ii = inicio; ii <= (id_thread==0) ? fim : fim-1; ii++) {
        int count = ((id_thread+1) % 2 == 0 && ii == inicio && qnt_elementos % matriz1.size() != 0) ? matriz1.size() / 2 : 0;
        while (count < matriz2.size()) {
            for (int jj = 0; jj < matriz2.size(); jj++) {
                elem += matriz1[ii][jj] * matriz2[jj][count];
            }
            if(count == matriz1.size()-1){
                arquivoMatriz3 << elem << endl;
            }else{
                arquivoMatriz3 << elem << " ";
            }
            count_elem++;
            elem = 0;
            count++;
            if(count_elem == qnt_elementos){
                return;
            }
        }    
    }
    arquivoMatriz3.close();
}

int main(int argc, char* argv[]){
    string linha;

    vector<vector<int>> Matriz1;
    /*Abre o arquivo */
    ifstream matriz1;
    matriz1.open(argv[1]);

    /* Armazena as dimensões das matrizes */
    int m1_linha, m1_coluna;
    getline(matriz1, linha, ' ');
    m1_linha = atoi(linha.c_str());
    getline(matriz1, linha);
    m1_coluna = atoi(linha.c_str());

    vector<int> aux;
    while (!matriz1.eof()) {
        getline(matriz1, linha, '\n');
        stringstream ss(linha);

        while (getline(ss, linha, ' ')) {
            aux.push_back(stoi(linha));
        }
        Matriz1.push_back(aux);
        aux.clear();
    }
    matriz1.close();

    vector<vector<int>> Matriz2;
    ifstream matriz2;
    matriz2.open(argv[2]);

    /* Armazena as dimensões da matriz 2 */
    int m2_linha, m2_coluna;
    getline(matriz2, linha, ' ');
    m2_linha = atoi(linha.c_str());
    getline(matriz2, linha);
    m2_coluna = atoi(linha.c_str());

    while (!matriz2.eof()) {
        getline(matriz2, linha, '\n');
        stringstream ss(linha);
        while (getline(ss, linha, ' ')) {
            aux.push_back(stoi(linha));
        }
        Matriz2.push_back(aux);
        aux.clear();
    }
    matriz2.close();

    int NUM_THREADS = (m1_linha*m2_coluna / atoi(argv[3]));

    ofstream arq_threads;
    arq_threads.open("../data/dadosThreads.txt");
    thread threads[NUM_THREADS];
    steady_clock::time_point start = steady_clock::now();
    for(int ii=0; ii < NUM_THREADS; ii++){
        threads[ii] = thread(multiplicacao, ii, atoi(argv[3]), ref(Matriz1), ref(Matriz2));
    }

    for(int jj=0; jj < NUM_THREADS; jj++){
        threads[jj].join();
    }
    steady_clock::time_point end = steady_clock::now();
    auto elapsed = end - start;
    auto milisegundos = (double)duration_cast<milliseconds>(elapsed).count();
    arq_threads << milisegundos << " ";
    arq_threads.close();

    return 0;
}