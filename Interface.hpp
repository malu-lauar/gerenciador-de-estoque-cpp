#pragma once

#include <iostream>
#include "Inventario.hpp"
#include "Item.hpp"

class Interface {
public:
    // Tipo estático para não precisar criar uma instância da classe antes de chamar um método
    static void exibirMenu();
    static void exibirMensagem(const std::string& mensagem);
    static void limparTela();
    static void exibirItens(const Inventario& inventario);
    
};


