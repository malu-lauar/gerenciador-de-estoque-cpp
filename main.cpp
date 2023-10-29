#include <iostream>


int main() {
    int n;

    std::cout << "O que voce deseja fazer?" << std::endl;
    std::cout << "1: Adicionar item" << std::endl;
    std::cout << "2: Remover item" << std::endl;
    std::cout << "3: Listar itens" << std::endl;
    std::cout << "4: Editar item" << std::endl;
    std::cout << "5: Ver valor total do estoque" << std::endl;

    // Leitura da escolha do usuário
    std::cin >> n;

     if (n == 1) {
        // Adicionar item
    } else if (n == 2) {
        // Remover item
    } else if (n == 3) {
        // Listar itens
    } else if (n == 4) {
        // Editar item
    } else if (n == 5) {
        // Ver valor total do estoque
    } else {
        std::cout << "Escolha invalida. Digite um numero de 1 a 5" << std::endl;
    }

    
    return 0;
}    