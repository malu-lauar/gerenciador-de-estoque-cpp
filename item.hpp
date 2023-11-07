#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& nome, double valor, int quantidade);

    // Métodos getters e setters para os atributos do Item
    /// @brief Retorna o nome do item
    ///
    std::string getNome() const;
    /// @brief Retorna o valor do item
    ///
    double getValor() const;
    /// @brief Retorna a quantidade de itens
    ///
    int getQuantidade() const;

    std::string nome;
    double valor;
    int quantidade;
    
private:
    
};


#endif // ITEM_H