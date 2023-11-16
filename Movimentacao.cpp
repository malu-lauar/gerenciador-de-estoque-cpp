#include "Movimentacao.hpp"

Movimentacao::Movimentacao(const std::string& n, std::string& t, int q) : nome(n), tipo(t), quantidade(q) {
    data = std::time(0); // Obtém a data e hora atuais
}

std::string Movimentacao::getNome() const {
    return nome;
}

std::string Movimentacao::getTipo() const {
    return tipo;
}

int Movimentacao::getQuantidade() const {
    return quantidade;
}

std::time_t Movimentacao::getData() const {
    return data;
}