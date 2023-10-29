#include "inventario.hpp"
#include "item.cpp"

void Inventario::adicionarItem(Item item){

// Verifica se já existe um item com o mesmo nome no inventário antes de adicionar
    auto it = estoque.find(item.getNome());
    if (it == estoque.end()) {
      estoque.insert(std::make_pair(item.getNome(), item));
    } else {
      std::cout << "O item já existe no inventário";
    }
}

void Inventario::adicionarItem(Item item){

// Verifica se já existe um item com o mesmo nome no inventário antes de adicionar
    auto it = estoque.find(item.getNome());
    if (it != estoque.end()) {
       estoque.erase(it);
    } else {
      std::cout << "O item não existe no inventário";
    }
}