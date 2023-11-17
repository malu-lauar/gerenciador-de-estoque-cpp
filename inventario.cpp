#include "Item.hpp"
#include "Inventario.hpp"
#include "Interface.hpp"
#include "Movimentacao.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>  // Para std::setw
#include "Include/json.hpp"


bool Inventario::itemExiste(std::string nome){
    // Itera pelo map e verifica se existe algum item com o nome passado
    auto it = estoque.find(nome);
    if(it == estoque.end()){
      return false;  
    } else {
      return true; 
    }
}

Item& Inventario::getItem(std::string& nome){
    auto it = estoque.find(nome);
      return it->second;
}

void Inventario::cadastrarItem(){
    std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja cadastrar:");
    double valor = Interface::lerValor<double>("Digite o valor do item:");

    // Verifica se já existe um item com o mesmo nome no inventário antes de adicionar
    if(Inventario::itemExiste(nome)){
      // Se o Item existe------- +++++++++v
      Interface::exibirMensagem("Erro: O Item ja esta cadastrado no sistema");
    } else {
      // Se o Item não existe, cria o item e adiciona ao inventário ------- +++++++++v
      Item newItem = Item(nome, valor, 0);
      estoque.insert(std::make_pair(newItem.getNome(), newItem));
      Interface::exibirMensagem("O item foi cadastrado no inventario!");
    }
}

void Inventario::removerItem(){
    std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja remover");

    // Verifica se já existe o item no inventário
    if (Inventario::itemExiste(nome)) {
      // Se o Item existe, o remove do inventário ------- +++++++++v
      estoque.erase(estoque.find(nome));
      Interface::exibirMensagem("O item foi Removido do inventario!");
    } else {
      Interface::exibirMensagem("Erro: O item não está cadastrado no inventário.");
    }
}

void Inventario::atualizarValor(){
    std::string nome = Interface::lerValor<std::string>("Digite o nome do item");

    // Verifica se já existe o item no inventário
    if (Inventario::itemExiste(nome)) {
      // Se o Item existe,  ------- +++++++++v
       double valor = Interface::lerValor<int>("Digite o valor do item:");
       Inventario::getItem(nome).setValor(valor);
       Interface::exibirMensagem("O valor do item foi autualizado");

    } else {
      Interface::exibirMensagem("O item não está cadastrado no inventário");
    }
}

void Inventario::adicionarItens(){
  std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja adicionar");

  // Verifica se o item está no inventário -------= = = = = = 
  if (Inventario::itemExiste(nome)) {
    // se o item está no inventário -------= = = = = = 
    int quantidade = Interface::lerValor<int>("Digite a quantidade de itens");    

    int qtd = Inventario::getItem(nome).getQuantidade();
    
    int sum = qtd + quantidade;
    

    Inventario::getItem(nome).setQuantidade(sum);
    
    Inventario::adicionarMovimentacao(nome, "entrada", quantidade);

    Interface::exibirMensagem("A quantidade de itens foi atualizada");
  } else {
    Interface::exibirMensagem("O item não existe no inventário");
  }
}

void Inventario::retirarItens(){
  std::string nome = Interface::lerValor<std::string>("Digite o nome do item que deseja retirar");

  // Verifica se o item está no inventário -------= = = = = = 
  if (Inventario::itemExiste(nome)) {
  //se o item está no inventário -------= = = = = = 
    int quantidade = Interface::lerValor<int>("Digite a quantidade de itens"); 
    
    int dif = Inventario::getItem(nome).getQuantidade() - quantidade;

    if(dif < 0){
        Interface::exibirMensagem("ERRO: Retirada nao realizada, estoque insuficiente de itens.");
    } else {
        if(dif == 0){
          Interface::exibirMensagem("Atencao!! Todas as unidades foram retiradas");
        }
        Inventario::getItem(nome).setQuantidade(dif);
        Interface::exibirMensagem("itens retirados.");
        Inventario::adicionarMovimentacao(nome, "saida", quantidade);
    }
  } else {
    Interface::exibirMensagem("O item nao existe no inventario");
  }
}

void Inventario::adicionarMovimentacao(const std::string& nome, std::string tipo, int quantidade) {
     Movimentacao movimentacao(nome, tipo, quantidade);
     historico.push_back(movimentacao);
}

void Inventario::salvarDados(const Inventario& inventario, const std::string& nomeArquivo) {

    nlohmann::json jsonInventario;  // Cria um objeto JSON para representar o inventário

    // Itera sobre cada par (nome do item, objeto Item) no inventário
    for (const auto& par : inventario.obterEstoque()) {
        const std::string& nomeItem = par.first;  // Obtém o nome do item
        const Item& item = par.second;  // Obtém uma referência constante ao objeto Item

        nlohmann::json jsonItem;  // Cria um objeto JSON para representar um item

        // Adiciona as propriedades do Item ao objeto JSON do Item
        jsonItem["nome"] = item.getNome();
        jsonItem["valor"] = item.getValor();
        jsonItem["quantidade"] = item.getQuantidade();

        // Adiciona o objeto JSON do Item ao inventário JSON usando o nome como chave
        jsonInventario[nomeItem] = jsonItem;
    }

    // Cria um arquivo para escrita
    std::ofstream arquivo(nomeArquivo);

    // Escreve o inventário JSON no arquivo, com espaçamento para facilitar leitura
    arquivo << std::setw(4) << jsonInventario;
}

void Inventario::carregarDados(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        // Lidar com a falha ao abrir o arquivo, se necessário
        std::cerr << "Erro ao abrir o arquivo JSON para leitura." << std::endl;
        return;
    }

    nlohmann::json jsonInventario;
    arquivo >> jsonInventario;

    for (const auto& par : jsonInventario.items()) {
        //const std::string& nomeItem = par.key();
        const nlohmann::json& jsonItem = par.value();

        std::string nome = jsonItem["nome"];
        double valor = jsonItem["valor"];
        int quantidade = jsonItem["quantidade"];

        // Cria um novo Item e adiciona ao inventário
        Item item = Item(nome, valor, quantidade);
        estoque.insert(std::make_pair(item.getNome(), item));
    }
        Interface::exibirMensagem("Dados do inventario carregados com sucesso");
}

const std::map<std::string, Item>& Inventario::obterEstoque() const {
      return estoque;
}

const std::vector<Movimentacao>& Inventario::obterHistorico() const {
      return historico;
}

