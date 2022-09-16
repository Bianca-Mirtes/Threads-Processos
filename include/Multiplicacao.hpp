#ifndef Multiplicacao_hpp
#define Multiplicacao_hpp

#include <time.h>

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

class Multiplicacao {
   private:
    double TempoSequencial;  //>! Armazena o tempo em nanosegundos da executação sequencial da mult.

   public:
    /**
     * @brief Construtor vazio para instanciar a classe.
     */
    Multiplicacao();

    /**
     * @brief Multiplicação das 2 matrizes de entrada, também calcula o tempo de processamento e atribui
     * a variável private @a TempoSequencial
     * @return Retorna a matriz resultante da multiplicação
     */
    std::vector<std::vector<int>> multSequencial(std::vector<std::vector<int>> &matriz1, std::vector<std::vector<int>> &matriz2);

    /**
     * @brief Acesso ao valor do tempo de processamento SEQUENCIAl
     */
    double getTempoSequencial();
};

#endif  // Multiplicacao_hpp
