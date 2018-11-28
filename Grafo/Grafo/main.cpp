// Grafo.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "MinhaInfo.h"
#include "Grafo.h"
using namespace std;

int main()
{
	MinhaInfo* valorPadrao = new MinhaInfo(0);
	Grafo g(*valorPadrao);
	int opcao;
	cout << "O que deseja fazer ?" << '\n';
	cout << " 0 - SAIR" << '\n';
	cout << " 1 - INSERIR VÉRTICE" << '\n';
	cout << " 2 - INSERIR ARESTA" << '\n';
	cout << " 3 - REMOVER ARESTA" << '\n';
	cout << " 4 - REMOVER VÉRTICE" << '\n';
	cin >> opcao;
	string nomeV1("");
	string nomeV2("");
	while (opcao) {
		switch (opcao) {
		case 1:
			nomeV1 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vértice:";
				cin >> nomeV1;
			}
			g.novoVertice(nomeV1);
			break;
		case 2:
			nomeV1 = "";
			nomeV2 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vértice de origem:";
				cin >> nomeV1;
			}
			while (nomeV2 == "") {
				cout << "Digite o nome do vértice de destino:";
				cin >> nomeV2;
			}
			int dist = -1;
			cout << "Digite a distância:";
			cin >> dist;
			MinhaInfo* d = new MinhaInfo(dist);
			g.novaAresta(nomeV1, nomeV2, *d);

			break;
		case 3:
			nomeV1 = "";
			nomeV2 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vértice de origem:";
				cin >> nomeV1;
			}
			while (nomeV2 == "") {
				cout << "Digite o nome do vértice de destino:";
				cin >> nomeV2;
			}
			g.removerAresta(nomeV1, nomeV2);
			break;
		case 4:
			nomeV1 = "";
			cout << "Digite o nome do vértice desejado para remover :";
			cin >> nomeV1;
			g.removerVertice(nomeV1);
			break;
		}
		cout << "O que deseja fazer ?" << '\n';
		cout << " 0 - SAIR" << '\n';
		cout << " 1 - INSERIR VÉRTICE" << '\n';
		cout << " 2 - INSERIR ARESTA" << '\n';
		cout << " 3 - REMOVER ARESTA" << '\n';
		cout << " 4 - REMOVER VÉRTICE" << '\n';
		cin >> opcao;
	}

	if (!valorPadrao)
		return -1;
	//delete valorPadrao;
	return -2;
}

