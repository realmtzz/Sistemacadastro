#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <string>
#include <vector>

using namespace std;

class Cliente {

public:
    string nome;
    string CPF;
    string RG;

    struct Cadastro {
        string mae;
        int idade;
        char sexo;
        double salario;
        double limite;
    };

    Cadastro dadosCadastro;

    struct Contato {
        string tel;
        string email;
    };

    Contato contato;

};

extern vector<Cliente> listaClientes;

bool dadosNumericos(const string& str);
void cadastrarCliente();
void listarClientes();
void buscarClientes();
void editarCadastro();
void salvarClientes();
void deletarCadastro();

#endif