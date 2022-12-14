#include <cctype>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
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

    vector<vector<int>> resultado_dot;
    int elem = 0;

    // Medindo tempo de processamento com a lib std::chrono.
    steady_clock::time_point start = steady_clock::now();

    // Multiplicando matrizes
    for (int ii = 0; ii < m1_linha; ii++) {
        vector<int> resultado_dot_linha;
        int count = 0;
        while (count < m2_linha) {
            for (int jj = 0; jj < m2_coluna; jj++) {
                elem += Matriz1[ii][jj] * Matriz2[jj][count];
            }
            resultado_dot_linha.push_back(elem);
            elem = 0;
            count++;
        }
        resultado_dot.push_back(resultado_dot_linha);
    }
    // Finalizando tempo de processamento com a lib std::chrono.
    steady_clock::time_point end = steady_clock::now();
    auto elapsed = end - start;

    cout << "\nTEMPO DE PROCESSAMENTO EM NANOSEGUNDOS --> ";
    cout << (double)duration_cast<nanoseconds>(elapsed).count() << "us" << endl;
    cout << "TEMPO DE PROCESSAMENTO EM MICROSEGUNDOS --> ";
    cout << (double)duration_cast<microseconds>(elapsed).count() << "ns" << endl;
    // cout << "PONTO FLUTUANTE --> " << duration<double>(elapsed).count() << "ns" << endl;
    cout << "TEMPO DE PROCESSAMENTO EM MILISEGUNDOS --> ";
    auto milisegundos = (double)duration_cast<milliseconds>(elapsed).count();
    cout << milisegundos << "ms" << endl;


    /*Abre o arquivo para escrita a fim de armazenar o tempo de processamento da execução atual*/
    ofstream dados_escrita;
    dados_escrita.open("../data/dadosSequencial.txt", ios::app);
    dados_escrita << milisegundos << " ";
}
