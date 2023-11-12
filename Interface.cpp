// Interface.cpp
#include "Interface.hpp"

void Interface::exibirMenu() {
    // Implementação do menu
     std::cout << "O que voce deseja fazer?" << std::endl;
        //Item
            std::cout << "1: Cadastrar novo item" << std::endl;
            std::cout << "2: Remover um item" << std::endl;
            std::cout << "3: Atualizar Valor do item" << std::endl;
        //Inventário
            std::cout << "4: Adicionar itens" << std::endl;
            std::cout << "5: Retiradr itens" << std::endl;
            std::cout << "6: Listar itens" << std::endl;
            std::cout << "7: Ver valor total do estoque" << std::endl;
        //
        std::cout << "8: Encerrar sessao" << std::endl;
}


void Interface::exibirMensagem(const std::string& mensagem) {
    std::cout << mensagem << std::endl;
}

void Interface::exibirItens(const Inventario& inventario) {
    std::cout << "Itens no inventário:" << std::endl;
    for (const auto& par : inventario.obterEstoque()) {
        std::cout << "Nome: " << par.first << ", Valor: " << par.second.getValor() << ", Quantidade: " << par.second.getQuantidade() << std::endl;
    }
}

void Interface::limparTela() {
    #ifdef _WIN32
        system("cls"); // Comando para limpar tela no Windows
    #else
        system("clear"); // Comando para limpar tela em sistemas Unix
    #endif
}

// Função genérica para ler um valor do usuário
template <typename T>
T Interface::lerValor(const std::string& mensagem) {
    T valor;
    std::cout << mensagem << ": ";
    std::cin >> valor;
    return valor;
}