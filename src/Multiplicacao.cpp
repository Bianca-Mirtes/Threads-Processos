#include "Multiplicacao.hpp"
using namespace std;
using namespace std::chrono;

Multiplicacao::Multiplicacao() {}

vector<vector<int>> Multiplicacao::multSequencial(vector<vector<int>> &matriz1, vector<vector<int>> &matriz2) {
    vector<vector<int>> resultado_dot;
    int elem = 0;

    // Medindo tempo de processamento com a lib std::chrono.
    auto start = steady_clock::now();

    for (int ii = 0; ii < matriz1.size(); ii++) {
        vector<int> resultado_dot_linha;
        int count = 0;
        while (count < matriz2.size()) {
            for (int jj = 0; jj < matriz2[0].size(); jj++) {
                elem += matriz1[ii][jj] * matriz2[jj][count];
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

    // Atribuindo o tempo de processamento em double para variável da classe
    TempoSequencial = (double)duration_cast<nanoseconds>(elapsed).count();
    return resultado_dot;
}

double Multiplicacao::getTempoSequencial() {
    return TempoSequencial;
}
