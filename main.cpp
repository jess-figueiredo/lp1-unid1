#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "farmacia.hpp"

using namespace std;
//variavel global, declarada antes do mai

int main() {
  string produto;
  int opt = -1;
  char op;
  char res;

  //lendo arquivo antes
  lerArquivo();
  
  cout << "Digite a opção:\n[1] - Sou cliente\n[2] - Sou Administrador"<< endl;
  cin >> opt;


  //deseja entrar no sistema ?
  do{
// cliente ou admin?
    if(opt == 1){
cout << "\n\n------------------------------\n    SEJA BEM VINDO(a)!!!\n------------------------------\nO que você deseja fazer?\n" << endl;

      cout << "[1] - Listar medicamentos"<< endl;
      cout << "[2] - Buscar"<< endl;
      cout << "[3] - Selecionar produto"<< endl;
      cout << "[4] - Calcular total"<< endl;
      cout << "[5] - Excluir medicamento do carrinho"<< endl;
      cout << "[0] - Sair"<< endl;

      cin >> opt;
      //switch com cada número e sua respectiva função funcionando
      switch(opt){
        case 1:           
          listarValores();
          break;
        case 2:
          do{
            buscaProduto();

            cout << "\n--------------------\nDeseja pesquisar novamente? [y/n]" << endl;
            cin >> op;

            (op == 'y' || op == 'Y') ? opt = 2 : opt = 1;
            
          }while(opt == 2);
          break;
        case 3:
          do{
            adicionaCarrinho();

            cout << "Deseja adicionar outro?[y/n] ";
            cin >> op;

            (op == 'y' || op == 'Y')  ? opt = 3 : opt = 1;
          }while(opt == 3);
          break;
        case 4:
            calculaTotal();
            opt = 1;
          break;
        case 5:
          DeletaItemCarrinho();
          opt = 1;
          break;
        default:
          cout << "Opção invalida." << endl;

        
      }

  }
    else if(opt == 2){
string login = "admin";
      string senha = "admin";
      string pass = " ";
      string log = " ";
      
      //entrar com senha
      cout << "\n[AREA ADMIN]" << endl;
      cout << "LOGIN: ";
      cin >> log;
      cout << "SENHA: ";
      cin >> pass;

      if(log == login && pass == senha){
      //apresentar opções após login validado
        cout << "\n\n--------------------\nSeja bem vindo " << login << "!\n--------------------\nO que deseja fazer hoje ?\n" << endl;
        
      cout << "[1] - Adicionar novo produto"<< endl;
      cout << "[2] - Listar medicamentos e valores"<< endl;
      cout << "[3] - Buscar produto"<< endl;
      cout << "[4] - Atualiar valores"<< endl;
      cout << "[5] - Excluir medicamento buscado"<< endl;
      cout << "[0] - Sair"<< endl;

        //entrada da escolha ^^
        cin >> opt;
      //switch case com funções em cada opção
        switch(opt){
          case 1: //cadastrar rem
            do{
            cadastraMed();
              opt = -1;
              cout << "\nDeseja cadastrar mais um produto? [y/n]: " ;
              cin >> op;
              (op == 'y' || op == 'Y') ? opt = 1 : opt = 2;
            }while(opt == 1);
            break;
          case 2: // listar
            if(verificaVazio()){ // chama a função que verifica se ta vazio
              listarValores();
            }
            else{
              cout << "O deposito esta vazio! Adicione algum produto."<< endl;
            }
            break;
          case 3: //buscar 
            do{
              if(verificaVazio()){ // chama a função que verifica se ta vazio
                buscaProduto();
  
                cout << "\nDeseja buscar outro produto? [y/n]: " ;
                cin >> op;
                (op == 'y' || op == 'Y') ? opt = 3 : opt = 2;
              }
              else{
                cout << "O deposito esta vazio! Adicione algum produto."<< endl;
              }
            }while(opt == 3);
            break;
          case 4: //atualizar valor 
            do{
              if(verificaVazio()){ // chama a função que verifica se ta vazio
                atualizaValor();
  
                cout << "\n\nDeseja atualizar outro produto? [y/n]: " ;
                cin >> op;
                (op == 'y' || op == 'Y') ? opt = 4 : opt = 2;
              }
              else{
                cout << "O deposito esta vazio! Adicione algum produto."<< endl;
              }
            }while(opt == 4);
            break;
          case 5://deletar um item
             do{
              if(verificaVazio()){ // chama a função que verifica se ta vazio
                deletaItem();
  
                cout << "\n\nDeseja outro produto? [y/n]: " ;
                cin >> op;
                (op == 'y' || op == 'Y') ? opt = 5 : opt = 2;
              }
              else{
                cout << "O deposito esta vazio! Adicione algum produto."<< endl;
              }
            }while(opt == 5);
            break;
          case 0:
            break;
          default:
            cout << "Opção invalida lek! Para de graça ou vai ser raqueado!" << endl;
          cin >> opt; 
        }
        
      }else{
        cout << "Senha invalida! Tente novamente! "<< endl;
      }

  }
    else {
    cout << "Opção invalida. Tente novamente: ";
      cin >> opt;
    }

    
  }while(opt!=0);

  
  return 0;
}