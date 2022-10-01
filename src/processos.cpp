#include <sys/wait.h>
#include <unistd.h>

#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

void multiplicacao(int id_proc, int qnt_elementos, vector<vector<int>> &matriz1, vector<vector<int>> &matriz2) {
    int elem = 0, count_elem = 0;
    int inicio, fim;
    inicio = (qnt_elementos * id_proc) / matriz2[0].size();
    fim = (qnt_elementos * (id_proc + 1)) / matriz2[0].size();

    ofstream dadosProcesso;
    string arq_base = "../data/processo";
    string arq = arq_base.append(to_string(id_proc + 1)).append(".txt");
    dadosProcesso.open(arq);
    if (!dadosProcesso.is_open()) {
        dadosProcesso.open(arq);
    }
    dadosProcesso << matriz2.size() << " " << matriz2[0].size() << endl;
    for (int ii = inicio; ii <= (id_proc == 0) ? fim : fim - 1; ii++) {
        int count = ((id_proc + 1) % 2 == 0 && ii == inicio && qnt_elementos % matriz1.size() != 0) ? matriz1.size() / 2 : 0;
        while (count < matriz2.size()) {
            for (int jj = 0; jj < matriz2.size(); jj++) {
                elem += matriz1[ii][jj] * matriz2[jj][count];
            }
            if (count == matriz1.size() - 1) {
                dadosProcesso << elem << endl;
            } else {
                dadosProcesso << elem << " ";
            }
            count_elem++;
            elem = 0;
            count++;
            if (count_elem == qnt_elementos) {
                return;
            }
        }
    }
    dadosProcesso.close();
}

int main(int argc, char *argv[]) {
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

    int NUM_PROCESS = (m1_linha * m2_coluna / atoi(argv[3]));

    int numProcessos = NUM_PROCESS;
    pid_t pidArray[numProcessos];

    steady_clock::time_point start = steady_clock::now();
    for (int ii = 0; ii < numProcessos; ii++) {
        pidArray[ii] = fork();
        if (pidArray[ii] == 0) {
            multiplicacao(ii, atoi(argv[3]), Matriz1, Matriz2);
            return 0;
        }
    }
    wait(NULL);
    steady_clock::time_point end = steady_clock::now();

    auto elapsed = end - start;
    auto milisegundos = (double)duration_cast<milliseconds>(elapsed).count();

    /*Abre o arquivo para leitura a fim de que os dados armazenados não ultrapassem 10 amostras*/
    // fstream dados_leitura;
    // dados_leitura.open("../data/dadosProcessos.txt", ios::in);

    /*Abre o arquivo para escrita a fim de armazenar o tempo de processamento da execução atual*/
    ofstream dados_escrita;
    dados_escrita.open("../data/dadosProcessos.txt", ios::app);
    dados_escrita << milisegundos << "  ";

    dados_escrita.close();

    // string linhas;
    // int qnt_espacos=0;
    // vector<int> qnt_limite;

    // while(!dados_leitura.eof()){
    //     getline(dados_leitura, linhas);
    //     if(linhas.size() == 0 || linhas.size() == 1){
    //         dados_escrita << m1_linha << "x" << m2_coluna << " " << milisegundos << " ";
    //     }
    //     if(linhas.size() > 1){
    //         for(int jj=0; jj < linhas.size(); jj++){
    //             if(isspace(linhas[jj])){
    //                 qnt_espacos++;
    //             }
    //         }
    //         qnt_limite.push_back(qnt_espacos);
    //         if(qnt_espacos >= 2 && qnt_espacos < 10){
    //             dados_escrita << milisegundos << " ";
    //         }
    //     }
    //     qnt_limite.push_back(qnt_espacos);
    //     qnt_espacos=0;
    // }
    // dados_leitura.close();

    // if(!qnt_limite.empty()){
    //     if(qnt_limite[qnt_limite.size()-1] == 10){
    //         dados_escrita << milisegundos << endl;
    //     }
    // }
    // dados_escrita.close();

    return 0;
}