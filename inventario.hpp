#pragma once

#include "Item.hpp"
#include <map>


class Inventario {
public:
  /// @brief Cadastra um item no inventario
  ///
  void cadastrarItem();

  /// @brief Remove um item do inventario
  ///
  void removerItem();
  
  /// @brief Adiciona uma quantiade de itens ao inventario
  ///
  void atualizarValor();

  /// @brief Adiciona uma quantiade de itens ao inventario
  ///
  void adicionarItens();

  /// @brief Retira uma quantiade de itens do inventario
  ///
  void retirarItens();
  
  const std::map<std::string, Item>& obterEstoque() const; 

private:

  std::map<std::string, Item> estoque;   

};