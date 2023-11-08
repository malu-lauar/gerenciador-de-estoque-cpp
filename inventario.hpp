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

  /// @brief Retira uma quantiade de itens do inventario
  ///
  /// @param intventario o inventário a ser listado
  void listarItens(const Inventario& inventario);

  
  
private:

  std::map<std::string, Item> estoque;   

};