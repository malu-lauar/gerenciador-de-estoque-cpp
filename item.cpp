#include "item.hpp"
#include <iostream>

// Implementação do construtor da classe Item
Item::Item(const std::string& nome, double valor, int quantidade) {
    this->nome = nome;
    this->valor = valor;
    this->quantidade = quantidade;
}

// Implementação dos métodos getter e Setter
std::string Item::getNome() const {
    return nome;
}

double Item::getValor() const {
    return valor;
}

int Item::getQuantidade() const {
    return quantidade;
}

void Item::setQuantidade(int quantidade) {
    // Verifica se a quantidade é não negativa antes de atribuir
    if (quantidade >= 0) {
        this->quantidade = quantidade;
    } else {
        // Se a quantidade for negativa, não atualiza o valor
        std::cout << "A quantidade não pode ser negativa." << std::endl;
    }
}