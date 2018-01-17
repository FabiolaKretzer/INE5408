#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Registro.h"
#include "binary_tree.h"


class Sistema {
	public:
		Sistema() {}

		Sistema(int tamanho, char **manpage) : _tamanho(tamanho) {
			for (int i = 0; i < _tamanho; i++) {
				_manpage.push_back(manpage[i]);
			}
		}

		~Sistema() {}

		void criarRegistro() {
			for (int i = 1; i < _tamanho; i++) {
				// Abre arquivo para leitura
				std::ifstream ifs (_manpage[i], ios::binary);
				//pega o comprimento do arquivo
				ifs.seekg (0, ifs.end);
				int ultimo = ifs.tellg();
				ifs.seekg (0, ifs.beg);
				//inicializa um buffer temporario de caracteres com o comprimento do arquivo
				char *buffer = new char[ultimo];
				//lê o arquivo
				ifs.read(buffer, ultimo);
				std::string descricao(buffer);
			  //insere manpage na posição i da lista
				_registro.push_back(new Registro(i, buffer, conteudo));
				//fecha o arquivo e deleta o buffer
				ifs.close();
				delete buffer;
			}
		}

		void criarManpage() {
			//lê o arquivo
			std::ofstream ofs("manpages.dat", ios:binary);
			//coloca as principais caracteristicas dentro da mapage
			for (int i = 0; i < _registro.size(); i++) {
				ofs << _registro[i]->indice();
				ofs << " ";
				ofs << _registro[i]->comando();
				ofs << " ";
				ofs << _registro[i]->conteudo();
				ofs << "\3";
			}

			ofs.close();
		}

		void criarLista() {
			//inicializa a lista
			_array = new BinaryTree<std::string>(_registro[0]->comando(), _registro[0]->conteudo());
			for (int i = 1; i < _registro.size(); i++)
				_array = _array->insert(_registro[i]->comando(), _array, _registro[i]->conteudo());
		}

		void criarIndicePrimario() {
			//coloca em na variavel temp os indices em ordem
			std::vector<BinaryTree<std::string>*> temp = in_order();
			//lê o arquivo com indices primarios
			std::ofstream ofs("ind_primario.dat");
			for (int i = 0; i < temp.size(); i++) {
				ofs << *temp[i]->root();
				ofs << " ";
				ofs << temp[i]->dado();
				ofs << "\3";
			}

			ofs.close();
		}

		std::string lerIndicePrimario(std::string comando) {
			std::ifstream ifs("ind_primario.dat");
			std::string comando_tmp;
			std::string conteudo_tmp;
			bool encontrou = false;

			while(!ifs.eof()) {
				ifs >> comando_tmp;
				if(comando.compare(comando_tmp) == 0) {
					encontrou = true;
					getline(ifs, conteudo_tmp, '\3');
					break;
				} else {
					ifs.ignore(std::numeric_limits<std::streamsize>::max(),'\3');
				}
			}
			ifs.close();
			if (!encontrou)
				return "Comando não existe na base!";
			return conteudo_tmp;

	public:
		int _tamanho;
		std::vector<std::string> _manpage;
		std::vector<Registro*> _registro;
		structures::BinaryTree<std::string> *_array;
};



#endif
