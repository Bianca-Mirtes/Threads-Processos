#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <time.h>

/* Dúvida:
    - semente pro srand() vir no argv[]
    - semente ser gerada automaticamente pelo time(0)
*/

using namespace std;

int main(int agc, char* argv[]){
    srand(time(0));

    /* Matriz 1 */
    int linha_m1 = atoi(argv[1]), coluna_m1 = atoi(argv[2]);
    vector<vector<int>> matriz1;

    for(int bb=0; bb < linha_m1; bb++){
        vector<int> auxiliar1;
        for(int dd=0; dd < coluna_m1; dd++){
            int elem1 = rand();
            auxiliar1.push_back(elem1);
        }
        matriz1.push_back(auxiliar1);
    }

    /* Matriz 2 */
    int linha_m2 = atoi(argv[3]), coluna_m2 = atoi(argv[4]);
    vector<vector<int>> matriz2;

    for(int bb=0; bb < linha_m2; bb++){
        vector<int> auxiliar2;
        for(int dd=0; dd < coluna_m2; dd++){
            int elem2 = rand();
            auxiliar2.push_back(elem2);
        }
        matriz2.push_back(auxiliar2);
    }
    

    

    
}