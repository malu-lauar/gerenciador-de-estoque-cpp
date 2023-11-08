#include "Inventario.hpp"
#include <iostream>

void Inventario::cadastrarItem(){

    std::string nome;
    double valor;

    std::cout << "Digite o nome do item:" << std::endl;
    std::cin >> nome;
    std::cout << "Digite o valor do item:" << std::endl;
    std::cin >> valor;

    // Verifica se já existe um item com o mesmo nome no inventário antes de adicionar
    auto it = estoque.find(nome);
    if (it == estoque.end()) {
      // Se o Item não existe, adiciona ao inventário ------- +++++++++v
      Item newItem = Item(nome, valor);
      estoque.insert(std::make_pair(newItem.getNome(), newItem));
      std::cout << "O item foi cadastrado no inventario!";
    } else {
      std::cout << "O item já está cadastrado no inventário";
    }
}

void Inventario::removerItem(){

    std::string nome;

    std::cout << "Digite o nome do item que deseja remover:" << std::endl;
    std::cin >> nome;

    // Verifica se já existe o item no inventário
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      // Se o Item existe, o remove do inventário ------- +++++++++v
      estoque.erase(it);
    } else {
      std::cout << "O item não está cadastrado no inventário";
    }
}

void Inventario::atualizarValor(){

    std::string nome;
    std::cout << "Digite o nome do item que deseja atualizar:" << std::endl;
    std::cin >> nome;

    // Verifica se já existe o item no inventário
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      // Se o Item existe,  ------- +++++++++v
       int valor;
       std::cout << "Digite o novo valor:" << std::endl;
       std::cin >> valor;
       
       it->second.setValor(valor);
       std::cout << "O valor do item foi autualizado";

    } else {
      std::cout << "O item não está cadastrado no inventário";
    }
}

void Inventario::adicionarItens(){

  std::string nome;
  int quantidade;

  std::cout << "Digite o nome do item:" << std::endl;
  std::cin >> nome;
  std::cout << "Digite a quantidade de itens:" << std::endl;
  std::cin >> quantidade;
// Verifica se o item está no inventário -------= = = = = = 
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      int sum = it->second.getQuantidade() + quantidade;
      it->second.setQuantidade(sum);
    } else {
      std::cout << "O item não existe no inventário";
    }
}

void Inventario::retirarItens(){

            std::string nome;
            int quantidade;

            std::cout << "Digite o nome do item:" << std::endl;
            std::cin >> nome;
            std::cout << "Digite a quantidade de itens:" << std::endl;
            std::cin >> quantidade;
// Verifica se o item está no inventário -------= = = = = = 
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
       int dif = it->second.getQuantidade() - quantidade;
       if(dif < 0){
          std::cout << "Retirada não realizada. Restam apenas " << it->second.getQuantidade() << "unidades no inventário";
       }
       if(dif == 0){
          it->second.setQuantidade(dif);
          std::cout << "Atenção! Todas as unidades foram retiradas. " << std::endl;
       } else {
          it->second.setQuantidade(dif);
          std::cout << dif << " itens foram retirados";
       }
    } else {
      std::cout << "O item não existe no inventário";
    }
}

void Inventario::listarItens(const Inventario& inventario) {
    std::cout << "Itens no inventário:" << std::endl;
    for (const auto& par : inventario.estoque) {
        std::cout << "Nome: " << par.first << ", Valor: " << par.second.getValor() << ", Quantidade: " << par.second.getQuantidade() << std::endl;
    }
}