#include <iostream>
#include <fstream>
#include "cadastro.hpp"

using namespace std;

void editarCadastro(){

  string cpf;
  char opcao;

  cout << "Buscar cliente pelo CPF: " << endl;
  cin >> cpf;

  for(Cliente& c : listaClientes){
    if(c.CPF == cpf){

      cout << "Voce deseja realmente editar o cadastro de: " << c.nome << "?" << endl;

      cout << "\nSelecione uma opcao: [S] / [N]" << endl;
      cin >> opcao;

      opcao = toupper(opcao);

      if(opcao == 'S'){

      cout << "=====Editar Cadastro de Cliente=====" << endl;

      cout << "Novo Nome: " << endl;
      cin.ignore();
      getline(cin, c.nome);

      cout << "Novo Telefone: " << endl;
      getline(cin, c.contato.tel);

      cout << "Novo E-mail: " << endl;
      getline(cin, c.contato.email);

      cout << "Salario atual: " << endl;
      cin >> c.dadosCadastro.salario;
      cin.ignore();

      cout << "Dados atualizados com sucesso!" << endl;

      salvarClientes();
      return;

      }else if(opcao == 'N'){
        return;

      }else{
        cout << "Digite uma opcao valida!" << endl;
      }
    }

    cout << "Cadastro nao encontrado!" << endl;

  }

}

void salvarClientes(){
  ofstream arquivo("clientes.txt");
  if(!arquivo.is_open()){
    cout << "Arquivo nao encontrado!" << endl;
    return;
  }

    for(const Cliente& c : listaClientes){
      arquivo << "Nome: " << c.nome << endl;
      arquivo << "CPF: " << c.CPF << endl;
      arquivo << "RG: " << c.RG << endl;
      arquivo << "Telefone: " << c.contato.tel << endl;
      arquivo << "Email: " << c.contato.email << endl;
      arquivo << "Nome da mae: " << c.dadosCadastro.mae << endl;
      arquivo << "Idade: " << c.dadosCadastro.idade << endl;
      arquivo << "Sexo: " << c.dadosCadastro.sexo << endl;
      arquivo << "Salario: " << c.dadosCadastro.salario << endl;
      arquivo << "Limite: " << c.dadosCadastro.limite << endl;
      arquivo << "-----------------------" << endl;
  }
  arquivo.close();
}

void deletarCadastro(){

  string cpf;
  char opcao;
  cout << "Buscar cliente pelo CPF: " << endl;
  cin >> cpf;

  for(auto it = listaClientes.begin(); it != listaClientes.end(); it++){
    if(it -> CPF == cpf){

      cout << "Voce deseja realmente deletar o cadastro de: " << it -> nome << "?" << endl;

      cout << "\nSelecione uma opcao: [S] / [N]" << endl;
      cin >> opcao;

      opcao = toupper(opcao);

      if(opcao == 'S'){
      listaClientes.erase(it);
      salvarClientes();

      cout << "Cadastro deletado com sucesso!" << endl;

      return;
      }

    }else if(opcao == 'N'){
      return;

    }else{
      cout << "Digite uma opcao valida!" << endl;
      break;
    }

    cout << "Cadastro nao encontrado!" << endl;

  }

}