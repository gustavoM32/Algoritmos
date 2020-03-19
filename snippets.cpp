#include <iostream>
#include <dirent.h>
#include <vector>
#include <map>
#include <typeinfo>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

const char ALGORITMOS_PATH[] = "/home/gustavo/Dropbox/Maratona/Algoritmos/Lista";
const char SNIPPETS_PATH[] = "/home/gustavo/.config/Code/User/snippets/cpp.json";

vector<string> files;

struct Snippet {
	string nome;
	string atalho;
	string descricao;
	string codigo;
	string json;
};

void pegaArquivos() {
	DIR *dir = opendir(ALGORITMOS_PATH);
	struct dirent *ent;
	if (dir != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			string nome = ent->d_name;
			if (nome.size() > 3 && nome.substr(nome.size() - 4, 4) == ".cpp") {
				files.push_back(nome);
				//cout << nome << endl;
			}
		}
		closedir(dir);
	} else {
		cerr << "Couldn't open directory" << endl;
		exit(1);
	}
}

void pegaCodigo(string &code, Snippet &snippet) {
	stringstream header;
	string dump;
	bool pick = false;
	bool started = false;
	bool readHeader = false;
	int i;
	for (i = 0; code.substr(i, 2) != "*/"; i++) {
		header << code[i];
	}
	getline(header, dump);
	getline(header, dump);
	getline(header, dump);
	header >> dump >> quoted(snippet.nome);
	header >> dump >> quoted(snippet.atalho);
	header >> dump >> quoted(snippet.descricao);
	for (; i < code.size(); i++) {
		if (i != code.size() - 3 && code.substr(i, 4) == "//]\n") {
			pick = false;
		} else if (i > 3 && code.substr(i-4, 4) == "//[\n") {
			pick = true;
			if (started) snippet.codigo += '\n';
			started = true;
		}
		if (pick) {
			snippet.codigo += code[i];
		}
	}
}

void criaJSON(Snippet &snippet) {
	stringstream json;
	stringstream codigo(snippet.codigo);
	bool virgula = false;
	string linha;
	json << "\t" << quoted(snippet.nome + " (A)") << ": {\n";
	json << "\t\t" << quoted("prefix") << ": " << quoted(snippet.atalho) << ",\n";
	json << "\t\t" << quoted("body") << ": [\n";
	while (getline(codigo, linha)) {
		if (virgula) json << ",\n";
		virgula = true;
		json << "\t\t\t" << quoted(linha);
	}
	json << "\n";
	json << "\t\t],\n";
	json << "\t\t" << quoted("description") << ": " << quoted(snippet.descricao) << '\n';
	json << "\t}\n";
	snippet.json = json.str();
}

void editSnippetsFile(vector<Snippet> &snippets) {
	ifstream arquivo;
	arquivo.open(SNIPPETS_PATH, ios::app);
	string resultado;
	string texto;
	string nome;
	string dump;
	bool deletando = false;
	bool dentro = false;
	
	for (int i = 1; i <= 14; i++) {
		getline(arquivo, texto);
		resultado += texto + '\n';
	}
	while (!arquivo.eof()) {
		getline(arquivo, texto);
		if (!dentro) {
			dentro = true;
			stringstream header;
			header << texto;
			header >> quoted(nome);
			if (nome.size() >= 3 && nome.substr(nome.size()-3, 3) == "(A)") {
				deletando = true;
			} else {
				resultado += texto + '\n';
			}
		} else {
			if (!deletando) resultado += texto + '\n';
			if (texto.size() >= 2 && texto.substr(0, 2) == "	}") {
				deletando = false;
				dentro = false;
			}
		}
	}
	resultado.erase(resultado.size()-4);
	if (resultado.at(resultado.size()-1) == ',') {
		resultado.erase(resultado.size()-1);
	}
	resultado += "\n";
	for (Snippet snippet : snippets) {
		resultado.erase(resultado.size()-1);
		resultado += ",\n";
		resultado += snippet.json;
	}
	resultado += "}\n";
	arquivo.close();
	ofstream arquivoout;
	arquivoout.open(SNIPPETS_PATH);
	arquivoout << resultado;
	arquivoout.close();
}

int main() {
	vector<Snippet> snippets;
	pegaArquivos();
	ifstream arquivo;
	for (string nomeArquivo : files) {
		string texto;
		arquivo.open("Lista/" + nomeArquivo);
		char c;
		while ((c = arquivo.get()) != EOF) {
			texto += c;
		}
		arquivo.close();
		Snippet snippet;
		pegaCodigo(texto, snippet);
		if (snippet.nome.size() == 0) {
			cout << "Não encontrado campo 'nome' em '" << nomeArquivo << "'" << endl;
			continue;
		} else if (snippet.atalho.size() == 0) {
			cout << "Não encontrado campo 'atalho' em '" << nomeArquivo << "'" << endl;
			continue;
		} else if (snippet.codigo.size() == 0) {
			cout << "Não encontrado código em '" << nomeArquivo << "'" << endl;
			continue;
		} else {
			cout << "Adicionado de '" << nomeArquivo << "'" << endl;
		}
		criaJSON(snippet);
		snippets.push_back(snippet);
	}
	editSnippetsFile(snippets);
	cout << "Finalizado" << endl;
	return 0;
}