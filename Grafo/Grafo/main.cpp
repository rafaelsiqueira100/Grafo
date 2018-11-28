// Grafo.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "MinhaInfo.h"
#include "Grafo.h"
using std;

int main()
{
	MinhaInfo* valorPadrao = new MinhaInfo(0);
	Grafo g(*valorPadrao);
	int opcao;
	cout << "O que deseja fazer ?";
	cout << " 0 - SAIR";
	cout << " 1 - INSERIR VÉRTICE";
	cout << " 2 - INSERIR ARESTA";
	cout << " 3 - REMOVER ARESTA";
	cout << " 3 - REMOVER VÉRTICE" << '\n';
	cin >> opcao;
	string nomeV1("");
	string nomeV2("");
	while (opcao) {
		switch (opcao) {
		case 1:
			nomeV1 = "";
			while (nomeV1 != "") {
				cout << "Digite o nome do vértice:";
				cin >> nomeV1;
			}
			g.novoVertice(nomeV1);
			break;
		case 2:
			nomeV1 = "";
			nomeV2 = "";
			while (nomeV1 != "") {
				cout << "Digite o nome do vértice de origem:";
				cin >> nomeV1;
			}
			while (nomeV2 != "") {
				cout << "Digite o nome do vértice:";
				cin >> nomeV2;
			}

			g.novoVertice(nomeV1);

			break;
		case 3:
			cout << "Digite a linha desejada para selecionar :";
			cin >> linha;
			cout << "Digite a coluna desejada para selecionar :";
			cin >> coluna;
			novaInfo = new MinhaInfo(*matriz.pegar(linha, coluna));
			cout << " Elemento [" << linha << "][" << coluna << "] = " << *novaInfo;
			break;
		}
		cout << '\n';
		cout << "O que deseja fazer ?";
		cout << " 0 - SAIR";
		cout << " 1 - PRINTAR A MATRIZ";
		cout << " 2 - INSERIR NA MATRIZ";
		cout << " 3 - OBTER ELEMENTO DA MATRIZ" << '\n';
		cin >> opcao;
	}
	delete valorPadrao;
	/*if (novaInfo != nullptr)
		delete novaInfo;
		*/
}

