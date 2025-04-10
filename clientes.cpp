#include <iostream>
#include <fstream>
#include <string>
#include "cadastro.hpp"

using namespace std;

void buscarClientes(){
    ifstream arquivo("clientes.txt");
    if (!arquivo.is_open()) {
      cout << "Erro ao abrir arquivo clientes." << endl;
      return;
    }

    Cliente cliente;
    string linha;

    while (getline(arquivo, linha)) {
      if(linha.find("Nome: ") == 0){
        cliente.nome = linha.substr(6);
      }else if(linha.find("CPF: ") == 0){
        cliente.CPF = linha.substr(5);
      }else if(linha.find("RG: ") == 0){
        cliente.RG = linha.substr(4);
      }else if(linha.find("Nome da mae: ") == 0){
        cliente.dadosCadastro.mae = linha.substr(13);
      }else if(linha.find("Idade: ") == 0){
        cliente.dadosCadastro.idade = stoi(linha.substr(7));
      }else if(linha.find("Sexo: ") == 0) {
        cliente.dadosCadastro.sexo = linha.substr(6)[0];
      }else if(linha.find("E-mail: ") == 0){
        cliente.contato.email = linha.substr(8);
      }else if(linha.find("Telefone: ") == 0){
        cliente.contato.tel = linha.substr(10);
      }else if(linha.find("Salario: ") == 0){
        cliente.dadosCadastro.salario = stoi(linha.substr(9));
      }else if(linha.find("Limite: ") == 0){
        cliente.dadosCadastro.limite = stoi(linha.substr(8));
      }else if(linha.find("-----") == 0){
         listaClientes.push_back(cliente);
      }
    }

    arquivo.close();
}