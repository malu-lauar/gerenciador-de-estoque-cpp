#include "Item.hpp"
#include <iostream>

// Implementação do construtor da classe Item
Item::Item(const std::string& nome, double valor, int quantidade) {
    this->nome = nome;
    this->valor = valor;
    this->quantidade = quantidade;
    
// Tratamento de excessões
}

// Implementação dos métodos getter
std::string Item::getNome() const {
    return nome;
}

double Item::getValor() const {
    return valor;
}

int Item::getQuantidade() const {
    return quantidade;
}
