#include "Inventario.hpp"
#include "Interface.hpp"
#include <iostream>

void Inventario::cadastrarItem(){

    std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja cadastrar:");
    double valor = Interface::lerValor<double>("Digite o valor do item:");

    // Verifica se já existe um item com o mesmo nome no inventário antes de adicionar
    auto it = estoque.find(nome);
    if (it == estoque.end()) {
      // Se o Item não existe, adiciona ao inventário ------- +++++++++v
      Item newItem = Item(nome, valor);
      estoque.insert(std::make_pair(newItem.getNome(), newItem));
      Interface::exibirMensagem("O item foi cadastrado no inventario!");
    
    } else {
      Interface::exibirMensagem("Erro: Item ja esta cadastrado no sistema");
    }
}

void Inventario::removerItem(){

    std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja remover");

    // Verifica se já existe o item no inventário
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      // Se o Item existe, o remove do inventário ------- +++++++++v
      estoque.erase(it);
      Interface::exibirMensagem("O item foi Removido do inventario!");
    } else {
      Interface::exibirMensagem("Erro: O item não está cadastrado no inventário.");
    }
}

void Inventario::atualizarValor(){

    std::string nome = Interface::lerValor<std::string>("Digite o nome do item");


    // Verifica se já existe o item no inventário
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      // Se o Item existe,  ------- +++++++++v
       double valor = Interface::lerValor<int>("Digite o valor do item:");
       it->second.setValor(valor);
       Interface::exibirMensagem("O valor do item foi autualizado");

    } else {
      Interface::exibirMensagem("O item não está cadastrado no inventário");
    }
}

void Inventario::adicionarItens(){

  std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja adicionar");
  int quantidade = Interface::lerValor<int>("Digite a quantidade de itens");

// Verifica se o item está no inventário -------= = = = = = 
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
      int sum = it->second.getQuantidade() + quantidade;
      it->second.setQuantidade(sum);
      Interface::exibirMensagem("A quantidade de itens foi atualizada");
    } else {
      Interface::exibirMensagem("O item não existe no inventário");
    }
}

void Inventario::retirarItens(){

  std::string nome = Interface::lerValor<std::string>("Nome do item");
  int quantidade = Interface::lerValor<int>("quantidade");

// Verifica se o item está no inventário -------= = = = = = 
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
       int dif = it->second.getQuantidade() - quantidade;
       if(dif < 0){
          std::cout << "Retirada não realizada. Restam apenas " << it->second.getQuantidade() << "unidades no inventário";
       }
       if(dif == 0){
          it->second.setQuantidade(dif);
          Interface::exibirMensagem("Atenção! Todas as unidades foram retiradas!");
       } else {
          it->second.setQuantidade(dif);
          std::cout << dif << " itens foram retirados";
       }
    } else {
      Interface::exibirMensagem("O item não existe no inventário");
    }
}

const std::map<std::string, Item>& Inventario::obterEstoque() const {
      return estoque;
}

