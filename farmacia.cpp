#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include "farmacia.hpp"

using namespace std;

map<string, double> remedios_valores;
map<string, double> carrinho;

void lerArquivo(){
  //declarando e abrindo arquivo
  ifstream arquivo("remedios.txt");
  string nome_med;
  double valor;

  if(arquivo.is_open()){
    while(arquivo >> nome_med >> valor){
      remedios_valores[nome_med] = valor;
    }
  }else{
    cout << "Erro ao abrir arquiv para ler.";
  }

  arquivo.close();
}

void cadastraMed(){
  ofstream arquivo_armazenar;
  string nome_med = " ";
  double valor; 
  // abrir o arquivo 
  arquivo_armazenar.open("remedios.txt", ios::out | ios::app);

  //receber nome do medicamento e seu valor
  cout << "Digite a nomenclatura do produto: ";
  cin.ignore(); //limpando buffer 
  getline(cin, nome_med);
  cout << "Digite o valor do produto: ";
  cin >> valor;

//armazenar em um map
  remedios_valores[nome_med] = valor; 
  
  arquivo_armazenar << nome_med << endl << valor << endl;
  arquivo_armazenar.close();

}

void listarValores(){
 // Percorre o mapa e imprime cada par chave-valor
        cout << "\n\n--------------------\nLista de Remedios no deposito:\n-------------------- " << endl;
    for (auto const& nome_med : remedios_valores) {
        cout << nome_med.first << ": R$ " << nome_med.second << endl;
    }
  
}

bool verificaVazio(){
  if(!remedios_valores.empty()){
      return true;
  }else{
     return false;
  }
  
}

void buscaProduto(){
string produto;
  cout << "Digite o produto a ser buscado: " ;
  cin >> produto;
  
  auto it = remedios_valores.find(produto);

  if(it != remedios_valores.end()){
    cout << "Produto encontrado: "<< it -> first << ", R$" << it -> second << endl;
  }else{
    cout << "Produto não encontrado!" << endl;
  }

}

void atualizaValor(){
  string produto, linha;
  double valor;
  ifstream arquivo_ler;
  ofstream arquivo_escrever;
  bool produto_encontrado = false;

   cout << "Digite o produto a ser buscado: " ;
  cin >> produto;
  
  auto it = remedios_valores.find(produto);

  if(it != remedios_valores.end()){
    cout << "Produto encontrado: "<< it -> first << ", R$" << it -> second << endl;
  }else{
    cout << "Produto não encontrado!" << endl;
  }

  //atualizar o valor
  cout << "Digite o novo valor do " << produto << ": ";
  cin >> valor;

  remedios_valores[produto] = valor;

  cout << "Valor atualizado." << endl;
  for (auto const& nome_med : remedios_valores) {
        cout << nome_med.first << ": R$ " << nome_med.second << endl;
    }
  
  //atualizando no arquivo
  //abrindo para leitura
  arquivo_ler.open("remedios.txt", ios::app);
  
   if(arquivo_ler.is_open()){
     arquivo_escrever.open("temp.txt");

    while(getline(arquivo_ler, linha)){
      if(linha == produto){
        getline(arquivo_ler, linha);
        arquivo_escrever << produto << endl << valor << endl;
        produto_encontrado = true;
      }
      else{
        arquivo_escrever << linha << endl;
      }
       
    }

     // Fechar os arquivos
    arquivo_ler.close();
    arquivo_escrever.close();

    remove("remedios.txt");
    rename("temp.txt", "remedios.txt");

   }else{
     cout << "Erro ao abrir arquivo" << endl;
   }

}

void deletaItem(){
  string produto, linha;
  int opt;
  char op;
  cout << "Digite o produto a ser deletado: " ;
  cin >> produto;

  auto it = remedios_valores.find(produto);
  if(it != remedios_valores.end()){
    cout<< "Produto encontrado: "<< it -> first << ", R$" << it -> second << endl;
  }
  else{
    cout << "Produto não encontrado!" << endl;
  }

  cout << "Tem certeza? [y/n] ";
  cin >> op;
  if(op == 'y' || op == 'Y'){
  remedios_valores.erase(produto);
  cout << "Produto deletado com sucesso!!";
  }

  //exluir do arquivo
  ifstream arquivo_ler("remedios.txt");
  ofstream arquivo_temp("remedios_temp.txt");

  while(getline(arquivo_ler, linha)){
    if(linha == produto){
      getline(arquivo_ler, linha);//le o valor
    }else{
      arquivo_temp << linha << endl;
    }
  }

  //fechando e renomeando arquivos
  arquivo_ler.close();
  arquivo_temp.close();

  remove("remedios.txt");
  rename("remedios_temp.txt", "remedios.txt");
  
  
}

void listaRemedios(){
  // Percorre o mapa e imprime cada par chave-valor
        cout << "\n\n--------------------\nLista de Remedios disponiveis:\n-------------------- " << endl;
    for (auto const& nome_med : remedios_valores) {
        cout << nome_med.first << ": R$ " << nome_med.second << endl;
    }
}

void adicionaCarrinho(){
  string produto, item;
  double valor;
  int opt;
  char op;
  //funcao buscar
  cout << "Digite o produto a ser buscado: " ;
  cin >> produto;
  
  auto it = remedios_valores.find(produto);

  if(it != remedios_valores.end()){
    cout << "Produto encontrado: "<< it -> first << ", R$" << it -> second << endl;
  }else{
    cout << "Produto não encontrado!" << endl;
  }

  //addicionando
  cout << "Deseja adicionar no carrinho? [y/n] ";
  cin >> op;

  if(op == 'y' || op == 'Y'){
    carrinho[produto] = remedios_valores[produto];
  }
  
}

void calculaTotal(){
  double soma = 0.0;

  if(!carrinho.empty()){
    for(auto const& produto : carrinho){
      soma += produto.second;
    }
  }else{
    cout << "O carrinho esta vazio. Vamos as compras! ";
  }


  cout << "\n\n--------------------\nLista de Remedios no carrinho:\n-------------------- " << endl;
    for (auto const& produto : carrinho) {
        cout << produto.first << ": R$ " << produto.second << endl;
    }
  cout << "Total: "<<fixed << setprecision(2) << soma << endl;
}

void DeletaItemCarrinho(){
  string produto, linha;
  char opt;

  if(!carrinho.empty()){
    cout << "\n\n--------------------\nCARRINHO DE COMPRAS:\n-------------------- " << endl;
    for (auto const& produto : carrinho) {
        cout << produto.first << ": R$ " << produto.second << endl;
    }
  
  cout << "Digite o produto a ser deletado do carrinho: " ;
  cin >> produto;

  auto it = carrinho.find(produto);
  if(it != carrinho.end()){
    cout<< "Produto encontrado: "<< it -> first << ", R$" << it -> second << endl;
  }
  else{
    cout << "Produto não encontrado!" << endl;
  }

  cout << "Tem certeza? [y/n]" << endl;
  cin >> opt;
  if(opt == 'y' || opt == 'Y'){
  carrinho.erase(produto);
  cout << "Produto deletado com sucesso!!";
  }

   cout << "\n\n--------------------\nCARRINHO DE COMPRAS:\n-------------------- " << endl;
    for (auto const& produto : carrinho) {
        cout << produto.first << ": R$ " << produto.second << endl;
    }
  }else{
    cout << "\n\n--------------------\nCARRINHO DE COMPRAS:\n-------------------- " << endl;
    cout << "O Carrinho esta vazio." << endl;
  }
  
  
}