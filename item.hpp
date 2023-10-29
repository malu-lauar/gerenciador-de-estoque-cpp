#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& nome, double valor, int quantidade);

    // Métodos getters e setters para os atributos do Item
    std::string getNome() const;
    double getValor() const;
    int getQuantidade() const;
    void setQuantidade(int quantidade);

private:
    std::string nome;
    double valor;
    int quantidade;
};


#endif // ITEM_H