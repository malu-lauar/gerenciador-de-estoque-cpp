#pragma once

#include "item.hpp"
#include <map>


class Inventario {
public:
  /// @brief Adiciona um item ao inventario
  ///
  /// @param item O item a ser adicionado
  void adicionar(Item item);

  /// @brief Remove um item ao inventario
  ///
  /// @param item O item a ser removido
  void remover(Item item);

  

  
private:

   std::map<std::string, Item> estoque;   

};