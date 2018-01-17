#ifndef REGISTRO_H
#define REGISTRO_H

class Registro {
	public:
		Registro() {}

		Registro(int indice, std::string comando, std::string conteudo)
				: _indice(indice), _comando(comando), _conteudo(conteudo) {}

		~Registro() {}

		int indice() {
			return _indice;
		}

		std::string comando() {
			return _comando;
		}

		std::string conteudo() {
			return _conteudo;
		}

	private:
		int _indice;
		std::string _comando;
		std::string _conteudo;
};
#endif
