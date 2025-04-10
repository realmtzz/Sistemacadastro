#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "cadastro.hpp"
#include <fstream>

using namespace std;

vector<Cliente> listaClientes;

bool dadosNumericos(const string& str){
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void cadastrarCliente() {
    Cliente cliente;

    cout << "Digite o nome completo: " << endl;
    getline(cin, cliente.nome);

    do {
        cout << "Digite o CPF: (Somente numeros)" << endl;
        getline(cin, cliente.CPF);

        if (cliente.CPF.length() != 11 || !dadosNumericos(cliente.CPF)){
            cout << "CPF invalido!" << endl;
        }
    } while (cliente.CPF.length() != 11 || !dadosNumericos(cliente.CPF));

    do {
        cout << "Digite o RG: (Somente numeros)" << endl;
        getline(cin, cliente.RG);

        if (cliente.RG.length() < 7 || cliente.RG.length() > 10 || !dadosNumericos(cliente.RG)) {
            cout << "RG invalido!" << endl;
        }
    } while (cliente.RG.length() < 7 || cliente.RG.length() > 10 || !dadosNumericos(cliente.RG));

    cout << "Digite o nome da mae: " << endl;
    getline(cin, cliente.dadosCadastro.mae);

    cout << "Digite a idade: " << endl;
    cin >> cliente.dadosCadastro.idade;
    cin.ignore();

     do {
        cout << "Digite o sexo: [F] / [M]" << endl;
        cin >> cliente.dadosCadastro.sexo;
         cin.ignore();

         cliente.dadosCadastro.sexo = toupper(cliente.dadosCadastro.sexo);

        if (cliente.dadosCadastro.sexo != 'F' && cliente.dadosCadastro.sexo != 'M') {
            cout << "Digite uma opcao valida!" << endl;
        }
    }while(cliente.dadosCadastro.sexo != 'F' && cliente.dadosCadastro.sexo != 'M');

    cout << "Digite o salario: " << endl;
    cin >> cliente.dadosCadastro.salario;
    cin.ignore();

    if (cliente.dadosCadastro.salario >= 5000) {
        cliente.dadosCadastro.limite = 3000;
        cout << "O limite inicial do Cliente e: " << cliente.dadosCadastro.limite << endl;
    }else {
        cliente.dadosCadastro.limite = 1500;
        cout << "O limite inicial do Cliente e: " << cliente.dadosCadastro.limite << endl;
    }

    cout << "\nDigite o telefone: (Somente numeros)" << endl;
    getline(cin , cliente.contato.tel);

    cout << "Digite o email: " << endl;
    getline(cin , cliente.contato.email);

    listaClientes.push_back(cliente);

    ofstream arquivo("clientes.txt", ios::app);

    if (arquivo.is_open()) {
        arquivo << "Nome: " << cliente.nome << endl;
        arquivo << "CPF: " << cliente.CPF << endl;
        arquivo << "RG: " << cliente.RG << endl;
        arquivo << "Telefone: " << cliente.contato.tel << endl;
        arquivo << "Email: " << cliente.contato.email << endl;
        arquivo << "Nome da mae: " << cliente.dadosCadastro.mae << endl;
        arquivo << "Idade: " << cliente.dadosCadastro.idade << endl;
        arquivo << "Sexo: " << cliente.dadosCadastro.sexo << endl;
        arquivo << "Salario: " << cliente.dadosCadastro.salario << endl;
        arquivo << "Limite: " << cliente.dadosCadastro.limite << endl;
        arquivo << "-----------------------" << endl;
        arquivo.close();
    }else {
        cout << "Erro ao abrir arquivo!" << endl;
    }

    cout << "Cliente cadastrado com sucesso!" << endl;

}

void listarClientes() {

    if (listaClientes.empty()) {
        cout << "Nenhum cliente cadastrado!" << endl;
        return;
    }
    cout << "==========Lista de Clientes=========="<< endl;

    for (Cliente c : listaClientes) {
        cout <<"\nNome: " << c.nome
             <<"\nCPF: " << c.CPF
             <<"\nLimite disponivel: " << c.dadosCadastro.limite << endl;
    }

    char inf;

    do {
        cout << "\nDeseja visualizar as informacoes de contato? [S] / [N]" << endl;
        cin >> inf;

        inf = toupper(inf);
        cin.ignore();

        if (inf == 'S') {
            for (Cliente c : listaClientes) {
                cout << "Telefone: " << c.contato.tel
                     << "\nE-mail: " << c.contato.email << endl;
            }
        }else if (inf == 'N') {
            return;
        }else {
            cout << "Digite uma opcao valida!" << endl;
        }
    } while (inf != 'S' && inf != 'N');
}
