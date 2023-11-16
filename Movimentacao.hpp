#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <ctime>

class Movimentacao {
public:
    Movimentacao(const std::string& n, std::string& t, int q);

    std::string getNome() const;
    std::string getTipo() const;
    int getQuantidade() const;
    std::time_t getData() const;

private:
    std::string nome;
    std::string tipo;
    int quantidade;
    std::time_t data;
};



#endif 