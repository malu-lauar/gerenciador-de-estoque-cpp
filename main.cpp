#include "Item.cpp"
#include "Inventario.cpp"
#include "Interface.cpp"
#include "Movimentacao.cpp"
#include <iostream>

int main() {
    Inventario meuInventario;
    meuInventario.carregarDados("Inventario.json", "Historico.json");
    
    while (true) {

        Interface::exibirMenu();
        // Leitura da escolha do usuário
        int n = Interface::lerValor<int>("Opssaum");

        if (n == 1) {
            meuInventario.cadastrarItem();
            // Cadastrar itemor();
        } else if (n == 2) {
            // remover itens ao inventario
            meuInventario.removerItem();
        } else if (n == 3) {
            // artualizarvalor itens ao inventario
            meuInventario.atualizarValor();
        } else if (n == 4) {
            // Adicionar itens ao inventario
            meuInventario.adicionarItens();
        } else if (n == 5) {
            // Retirar itens do inventário
            meuInventario.retirarItens();
        } else if (n == 6) {
            // Listar Itens
            Interface::exibirItens(meuInventario);
        } else if (n == 7) {
            // 
            Interface::exibirHistorico(meuInventario);
        } else if (n == 8){
            meuInventario.salvarDados("Inventario.json", "Historico.json"); 
            break;  // Sai do loop para encerrar o programa bosta
        } else {
            Interface::exibirMensagem("Erro: Escolha invalida");
        }
    }
    return 0;
}