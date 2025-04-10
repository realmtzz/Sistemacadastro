#include <iostream>
#include "cadastro.hpp"

using namespace std;

int opcao;

int main() {

    buscarClientes();

    cout << "========Arbor System=========="<< endl;

    do {
        cout << "\nEscolha uma opcao:\n" << endl;
        cout << "1 - Cadastrar Cliente" <<endl;
        cout << "2 - Listar Cliente" <<endl;
        cout << "3 - Editar Cadastro" <<endl;
        cout << "4 - Deletar Cadastro" <<endl;
        cout << "0 - Sair" <<endl;
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                editarCadastro();
                break;
            case 4:
                deletarCadastro();
                break;
            case 0:
                cout << "Saindo.." << endl;
                break;
            default:
                cout << "opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}