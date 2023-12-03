#include "Item.cpp"
#include "Inventario.cpp"
#include "Interface.cpp"
#include "Movimentacao.cpp"
#include <iostream>

/**
 * @brief Função principal do programa.
 *
 * Cria um inventário, exibe um menu de opções para o usuário e realiza as operações escolhidas.
 *
 * @return Retorna 0 em caso de execução bem sucedida.
 */

int main() {
    Inventario meuInventario;
    meuInventario.carregarDados("Inventario.json", "Historico.json");
    
    while (true) {

        Interface::exibirMenu();
        /// Leitura da escolha do usuário
        int n = Interface::lerValor<int>("Opssaum");

        if (n == 1) {
            /// Cadastrar um novo item no inventário
            meuInventario.cadastrarItem();
        } else if (n == 2) {
            /// Remover item do inventário
            meuInventario.removerItem();
        } else if (n == 3) {
            /// Atualizar valor de um item do inventário
            meuInventario.atualizarValor();
        } else if (n == 4) {
            /// Adicionar itens ao inventário
            meuInventario.adicionarItens();
        } else if (n == 5) {
            /// Retirar itens do inventário
            meuInventario.retirarItens();
        } else if (n == 6) {
            /// Listar os itens do inventário
            Interface::exibirItens(meuInventario);
        } else if (n == 7) {
            /// Exibir o histórico de movimentação.
            Interface::exibirHistorico(meuInventario);
        } else if (n == 8){
            /// Salvar os dados do inventário em arquivos JSON e encerrar o programa
            meuInventario.salvarDados("Inventario.json", "Historico.json"); 
            break;  /// Sai do loop para encerrar o programa.
        } else {
            /// Exibir mensagem de erro quando a opção for inválida
            Interface::exibirMensagem("Erro: Escolha invalida");
        }
    }
    return 0;
}