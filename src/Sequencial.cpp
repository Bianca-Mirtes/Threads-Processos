#include <chrono>
#include <cstdlib>
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
    ifstream matriz1;
    matriz1.open(argv[1]);

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

    /* Vendo se preencheu a matriz direitinho*/
    // cout << " PRINT DA MATRIZ 1 " << endl;
    // for (vector<int> gg : Matriz1) {
    //     for (int ii = 0; ii < (int)gg.size(); ii++) {
    //         if (ii == (int)gg.size() - 1) {
    //             cout << gg[ii] << endl;
    //         } else {
    //             cout << gg[ii] << " ";
    //         }
    //     }
    // }
    // cout << "\n PRINT DA MATRIZ 2 " << endl;
    // for (vector<int> gg : Matriz2) {
    //     for (int ii = 0; ii < (int)gg.size(); ii++) {
    //         if (ii == (int)gg.size() - 1) {
    //             cout << gg[ii] << endl;
    //         } else {
    //             cout << gg[ii] << " ";
    //         }
    //     }
    // }

    // Multiplicando matrizes
    vector<vector<int>> resultado_dot;
    int elem = 0;
    // Medindo tempo de processamento com a lib std::chrono.
    auto start = steady_clock::now();

    for (int ii = 0; ii < (int)Matriz1.size(); ii++) {
        vector<int> resultado_dot_linha;
        int count = 0;
        while (count < (int)Matriz2.size()) {
            for (int jj = 0; jj < (int)Matriz2[0].size(); jj++) {
                elem += Matriz1[ii][jj] * Matriz2[jj][count];
            }
            resultado_dot_linha.push_back(elem);
            elem = 0;
            count++;
        }
        resultado_dot.push_back(resultado_dot_linha);
    }
    // Finalizando tempo de processamento com a lib std::chrono.
    auto end = steady_clock::now();
    auto elapsed = end - start;

    cout << "\nTEMPO DE PROCESSAMENTO EM NANOSEGUNDOS --> ";
    cout << (double)duration_cast<nanoseconds>(elapsed).count() << "us" << endl;
    cout << "TEMPO DE PROCESSAMENTO EM MICROSEGUNDOS --> ";
    cout << (double)duration_cast<microseconds>(elapsed).count() << "ns" << endl;
    // cout << "PONTO FLUTUANTE --> " << duration<double>(elapsed).count() << "ns" << endl;
    cout << "TEMPO DE PROCESSAMENTO EM MILISEGUNDOS --> ";
    auto milisegundos = (double)duration_cast<milliseconds>(elapsed).count();
    cout << milisegundos << "ms" << endl;

    cout << "\n PRINT DA MATRIZ RESULTANTE: " << endl;
    for (vector<int> gg : resultado_dot) {
        for (int ii = 0; ii < (int)gg.size(); ii++) {
            if (ii == (int)gg.size() - 1) {
                cout << gg[ii] << endl;
            } else {
                cout << gg[ii] << " ";
            }
        }
    }
}
