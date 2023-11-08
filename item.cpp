#include "Item.hpp"
#include <iostream>

// Implementação do construtor da classe Item
Item::Item(const std::string& nome, double valor) {
    this->nome = nome;
    this->valor = valor;
    this->quantidade = 0;

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

void Item::setValor(double valor){
     this->valor = valor;
}

void Item::setQuantidade(int quantidade){
     this->quantidade = quantidade;
}
