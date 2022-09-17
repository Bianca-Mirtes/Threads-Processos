#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char* argv[]) {
    ofstream arquivoMatriz1;

    /* Matriz 1 */
    arquivoMatriz1.open("../data/matrizGerada1.txt");

    int linha_m1 = atoi(argv[1]), coluna_m1 = atoi(argv[2]);
    vector<vector<int>> matriz1;
    arquivoMatriz1 << argv[1] << ' ' << argv[2] << '\n';
    for (int bb = 0; bb < linha_m1; bb++) {
        vector<int> auxiliar1;
        for (int dd = 0; dd < coluna_m1; dd++) {
            int numAleatorio = (rand() % 100);
            auxiliar1.push_back(numAleatorio);
            if (dd == coluna_m1 - 1) {
                arquivoMatriz1 << numAleatorio;
                continue;
            }
            arquivoMatriz1 << numAleatorio << ' ';
        }
        if (bb == linha_m1 - 1) {
            matriz1.push_back(auxiliar1);
            continue;
        }
        arquivoMatriz1 << '\n';
        matriz1.push_back(auxiliar1);
    }
    arquivoMatriz1.close();

    /* Matriz 2 */
    ofstream arquivoMatriz2;
    arquivoMatriz2.open("../data/matrizGerada2.txt");

    int linha_m2 = atoi(argv[3]), coluna_m2 = atoi(argv[4]);
    vector<vector<int>> matriz2;

    arquivoMatriz2 << argv[3] << ' ' << argv[4] << '\n';
    for (int bb = 0; bb < linha_m2; bb++) {
        vector<int> auxiliar2;
        for (int dd = 0; dd < coluna_m2; dd++) {
            int numAleatorio = (rand() % 100);
            auxiliar2.push_back(numAleatorio);
            if (dd == coluna_m2 - 1) {
                arquivoMatriz2 << numAleatorio;
                continue;
            }
            arquivoMatriz2 << numAleatorio << ' ';
        }
        if (bb == linha_m2 - 1) {
            matriz2.push_back(auxiliar2);
            continue;
        }
        arquivoMatriz2 << '\n';
        matriz2.push_back(auxiliar2);
    }

    arquivoMatriz2.close();

    return 0;
}