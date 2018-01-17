#include <iostream>
#include "Sistema.h"

int main(int argc, char **argv) {
	system("clear");
	if (argc == 1) {
		std::cout << "Não existe manpages!! ";
		return 1;
	} else {
		std::cout << "Aguarde...\n\n";
	}

	Sistema sistema = Sistema(argc, argv);
	sistema.criarRegistro();
	sistema.criarManpage();
//	sistema.criarIndice();
	sistema.criarLista();
	sistema.criarIndicePrimario();

	bool controle = true;
	while (controle) {
		std::cout << "Digite a opção que desejar: \n"
				  << "0 - busca por chave primária\n"
				  << "1 - busca por chave secundária\n"
				  << "2 - busca conjuntiva por chave secundária\n"
				  << "3 - sair\n";

		int opcao;
		std::cin >> opcao;

		std::string comando;
		std::string resultado;
		switch(opcao) {
			case 0:
				system("clear");
				std::cout << "Insira o nome do comando para buscar a manpage:"
						  << "\n> ";
				std::cin >> comando;

				std::cout << std::endl << sistema.lerIndicePrimario(comando)
						  << "\n\n";
				break;
			case 1:
				system("clear");
				std::cout << "Não deu tempo.\n" << "\n\n";
				break;
			case 2:
				system("clear");
				std::cout << "Não deu tempo.\n" << "\n\n";
				break;
			case 3:
				controle = false;
				break;
			default:
				system("clear");
				std::cout << "\nInválido!!!\n\n";
		}
	}

	return 0;
}
