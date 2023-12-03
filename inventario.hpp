#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Movimentacao.hpp"
#include "Item.hpp"
#include <map>
#include <vector>

/**
 * @brief Classe que representa um inventário de itens.
 */
class Inventario {
public:

  /**
   * @brief Cadastra um item no inventário.
   */
  void cadastrarItem();

  /**
   * @brief Remove um item no inventário.
   */
  void removerItem();
  
  /**
   * @brief Atualiza o valor de um item no inventário.
   */
  void atualizarValor();

  /**
   * @brief Adiciona uma quantidade de itens ao estoque.
   */
  void adicionarItens();

  /**
   * @brief Retira uma quantidade de itens do estoque.
   */
  void retirarItens();

  /**
   * @brief Retorna uma referência para o item no inventário pelo nome.
   *
   * @param nome Nome do item a ser retornado.
   * @return Referência para o item correspondente ao nome fornecido.
   */
  Item& getItem(std::string& nome);

  /**
   * @brief Verifica se um item existe no inventário.
   * 
   * @param nome Nome do item a ser verificado.
   * @return True se o item existir no inventário eou False se não existir.
  */
  bool itemExiste(std::string nome);

  /**
   * @brief Adiciona uma movimentação ao histórico.
   *
   * @param nome Nome do item movimentado.
   * @param tipo Tipo de movimentação (entrada ou saída).
   * @param quantidade Quantidade movimentada.
   */
  void adicionarMovimentacao(const std::string& nome, std::string tipo, int quantidade);

  /**
   * @brief Salva os dados do inventário em arquivos JSON.
   *
   * @param nomeArquivo1 Nome do arquivo para o estoque.
   * @param nomeArquivo2 Nome do arquivo para o histórico.
   */
  void salvarDados(const std::string& nomeArquivo1, const std::string& nomeArquivo2);

  /**
   * @brief Carrega os dados do inventário a partir de arquivos JSON.
   *
   * @param nomeArquivo1 Nome do arquivo para o estoque.
   * @param nomeArquivo2 Nome do arquivo para o histórico.
   */
  void carregarDados(const std::string& nomeArquivo1, const std::string& nomeArquivo2);
  
  /**
   * @brief Retorna o estoque atual.
   *
   * @return Mapa contendo o estoque atual.
   */
  const std::map<std::string, Item>& obterEstoque() const;

  /**
   * @brief Retorna o histórico de movimentações.
   *
   * @return Vetor contendo o histórico de movimentações.
   */
  const std::vector<Movimentacao>& obterHistorico() const;


private:
  std::map<std::string, Item> estoque;   
  std::vector<Movimentacao> historico;    
};

#endif