#include <time.h>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

/* Dúvida (oq é melhor? Tem o mesmo efeito?):
    - semente pro srand() vir no argv[]
    - semente ser gerada automaticamente pelo time(0)
*/

/* Não consegui compilar/executar pelo terminal pra usar o argv[] */
/* O time(0) tá funcionando bem pra gerar os números aleatorios, as vezes gera algumas repetições sucessivas, mas não acho
   que importe para o projeto.
*/

/* Acha uma boa ideiar criar uma classe para fazer a multiplicação? */

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    srand(time(0));

    /* Matriz 1 */
    // int linha_m1 = atoi(argv[1]), coluna_m1 = atoi(argv[2]);
    vector<vector<int>> matriz1;
    int linha = 3, coluna = 3;
    for (int bb = 0; bb < linha; bb++) {
        vector<int> auxiliar1;
        for (int dd = 0; dd < coluna; dd++) {
            auxiliar1.push_back(rand() % 30);
        }
        matriz1.push_back(auxiliar1);
    }

    /* Matriz 2 */
    // int linha_m2 = atoi(argv[3]), coluna_m2 = atoi(argv[4]);
    vector<vector<int>> matriz2;

    for (int bb = 0; bb < linha; bb++) {
        vector<int> auxiliar2;
        for (int dd = 0; dd < coluna; dd++) {
            auxiliar2.push_back(rand() % 50);
        }
        matriz2.push_back(auxiliar2);
    }

    /* Vendo se preencheu a matriz direitinho*/
    for (vector<int> gg : matriz1) {
        for (int ii = 0; ii < gg.size(); ii++) {
            if (ii == gg.size() - 1) {
                cout << gg[ii] << endl;
            } else {
                cout << gg[ii] << " ";
            }
        }
    }
    cout << endl;
    for (vector<int> gg : matriz2) {
        for (int ii = 0; ii < gg.size(); ii++) {
            if (ii == gg.size() - 1) {
                cout << gg[ii] << endl;
            } else {
                cout << gg[ii] << " ";
            }
        }
    }

    /*Pelo video de Julio a multiplicação é dot, aquele dermantelo! kkkkkkkkk */
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

    /*Vendo se multiplicou certo*/
    cout << endl;
    for (vector<int> gg : resultado_dot) {
        for (int ii = 0; ii < gg.size(); ii++) {
            if (ii == gg.size() - 1) {
                cout << gg[ii] << endl;
            } else {
                cout << gg[ii] << " ";
            }
        }
    }

    // Muitos prints para descobrir como o resultado e os variáveis resultados a depender da syntax.
    auto elapsed = end - start;
    cout << "TEMPO DE PROCESSAMENTO EM MICROSEGUNDOS --> ";
    cout << duration_cast<microseconds>(elapsed).count() << "ns" << endl;
    cout << "PONTO FLUTUANTE --> " << duration<double>(elapsed).count() << "ns" << endl;
    cout << "\nTEMPO DE PROCESSAMENTO EM NANOSEGUNDOS --> ";
    cout << duration_cast<nanoseconds>(elapsed).count() << "ns" << endl;
    cout << "PONTO FLUTUANTE --> " << duration<double>(elapsed).count() << "ns" << endl;

    // Criando arquivo para gravar o resultado, provavelmente será formatado quando o código estiver pronto.
    auto gravarResultado = (double)duration_cast<nanoseconds>(elapsed).count();
    fstream arquivo;
    arquivo.open("../data/dados.txt", ios::app);
    arquivo << gravarResultado << '\n';
    arquivo.close();

    /* Multiplicou certinho!!!*/
    /* São 3 loops aninhados, quero nem imaginar o custo computacional disso aí. Não sei se dá pra otimizar.*/
}
