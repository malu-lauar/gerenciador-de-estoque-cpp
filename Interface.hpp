#pragma once

#include <iostream>
#include "Inventario.hpp"
#include "Item.hpp"

/**
 * @brief Classe que representa a interface do sistema.
 */
class Interface {
public:

    /**
     * @brief Exibe o menu principal na tela.
     */
    static void exibirMenu();

    /**
     * @brief Exibe uma mensagem na tela.
     *
     * @param mensagem A mensagem a ser exibida.
     */
    static void exibirMensagem(const std::string& mensagem);

    /**
     * @brief Limpa a tela do console.
     */
    static void limparTela();

    /**
     * @brief Exibe a lista de itens presentes no inventário na tela.
     *
     * @param inventario O inventário a ser exibido.
     */
    static void exibirItens(const Inventario& inventario);

    /**
     * @brief Exibe o histórico de movimentações do inventário.
     *
     * @param inventario O inventário do histórico que será exibido.
     */
    static void exibirHistorico(const Inventario& inventario);

    /**
     * @brief Lê e retorna um valor do tipo T a partir da entrada do usuário.
     *
     * @tparam T Tipo do valor a ser lido.
     * @param mensagem A mensagem a ser exibida ao usuário.
     * @return O valor lido do tipo T.
     */
    template <typename T>
    static T lerValor(const std::string& mensagem);
};