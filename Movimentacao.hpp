#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <ctime>

/**
 * @brief Classe que representa a movimentação de itens.
 */

class Movimentacao {
public:
    /**
     * @brief Construtor para criar uma movimentação.
     *
     * @param n Nome do item movimentado.
     * @param t Tipo da movimentação (entrada ou saída).
     * @param q Quantidade da movimentação.
     */
    Movimentacao(const std::string& n, std::string& t, int q);

    /**
     * @brief Construtor para criar uma movimentação com data definida.
     *
     * @param n Nome do item movimentado.
     * @param t Tipo da movimentação (entrada ou saída).
     * @param q Quantidade da movimentação.
     * @param d Data da movimentação.
     */
    Movimentacao(const std::string& n, std::string& t, int q, int d);

    /**
     * @brief Construtor para criar uma movimentação a partir de uma string JSON.
     *
     * @param jsonString String JSON representando a movimentação.
     */
    Movimentacao(const std::string& jsonString);

    std::string getNome() const; /// Retorna o nome do item movimentado.
    std::string getTipo() const; /// Retorna o tipo de movimentação (entrada ou saída).
    int getQuantidade() const; /// Retorna a quantidade da movimentação.
    std::time_t getData() const; /// Retorna a data da movimentação.

    /**
     * @brief Converte a movimentação para uma string JSON.
     *
     * @return String JSON representando a movimentação.
     */
    std::string toJson() const;

private:
    std::string nome; 
    std::string tipo; 
    int quantidade;   
    std::time_t data; 
};



#endif 