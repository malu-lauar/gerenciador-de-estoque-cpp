#include "Item.cpp"
#include "Inventario.cpp"
#include <iostream>
#include <fstream> // Para manipulação de arquivos

int main() {
    Inventario meuInventario;
    int n;

    while (true) {
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

        // Leitura da escolha do usuário
        std::cin >> n;

        if (n == 1) {
            // Cadastrar item
            meuInventario.cadastrarItem();
        } else if (n == 2) {
            // Remover item
            meuInventario.removerItem();
        } else if (n == 3) {
            // Atualizar valor de item
            meuInventario.atualizarValor();
        } else if (n == 4) {
            // Adicionar itens ao inventario
            meuInventario.adicionarItens();
        } else if (n == 5) {
            // Retirar itens do inventário
            meuInventario.retirarItens();
        } else if (n == 6) {
            // Listar Itens
            meuInventario.listarItens(meuInventario);
        } else if (n == 7) {
            // Ver valor Total
            
        } else if (n == 8) {
            // Encerrar a sessão
            break;  // Sai do loop para encerrar o programa
        } else {
            std::cout << "Escolha inválida. Digite um número válido" << std::endl;
        }
    }

    return 0;
}    