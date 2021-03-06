// Grafo.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "MinhaInfo.h"
#include "Grafo.h"
using namespace std;

int main()
{
	int ehDuploSentido = 0;
	cout << "As arestas sempre sao duplo sentido?" <<'\n';
	cout << "0=NAO, OUTRO=SIM" << '\n';
	cin >> ehDuploSentido;
	MinhaInfo* valorPadrao = new MinhaInfo(0);
	Grafo g(*valorPadrao, (char)ehDuploSentido);
	int opcao;
	cout << "O que deseja fazer ?" << '\n';
	cout << " 0 - SAIR" << '\n';
	cout << " 1 - INSERIR VERTICE" << '\n';
	cout << " 2 - INSERIR ARESTA" << '\n';
	cout << " 3 - REMOVER ARESTA" << '\n';
	cout << " 4 - REMOVER VERTICE" << '\n';
	cout << " 5 - PRINTAR GRAFO" << '\n';
	cin >> opcao;
	string nomeV1("");
	string nomeV2("");
	while (opcao) {
		MinhaInfo* d = nullptr;
		int dist = -1;
		switch (opcao) {
		case 1:
			nomeV1 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vertice:";
				cin >> nomeV1;
			}
			g.novoVertice(nomeV1);
			break;
		case 2:
			nomeV1 = "";
			nomeV2 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vertice de origem:";
				cin >> nomeV1;
			}
			while (nomeV2 == "") {
				cout << "Digite o nome do vertice de destino:";
				cin >> nomeV2;
			}
			cout << "Digite a distancia:";
			cin >> dist;
			d = new MinhaInfo(dist);
			try {
				g.novaAresta(nomeV1, nomeV2, *d);
			}
			catch (string msg) {
				cout << msg;
			}
			break;
		case 3:
			nomeV1 = "";
			nomeV2 = "";
			while (nomeV1 == "") {
				cout << "Digite o nome do vertice de origem:";
				cin >> nomeV1;
			}
			while (nomeV2 == "") {
				cout << "Digite o nome do vertice de destino:";
				cin >> nomeV2;
			}
			try {
				g.removerAresta(nomeV1, nomeV2);
			}
			catch (string msg) {
				cout << msg;
			}
			break;
		case 4:
			nomeV1 = "";
			cout << "Digite o nome do vertice desejado para remover :";
			cin >> nomeV1;
			try {
				g.removerVertice(nomeV1);
			}
			catch (string msg) {
				cout << msg;
			}
			break;
		case 5:
			cout << '\n' << g << '\n';
			break;
		}
		cout << '\n';
		cout << "O que deseja fazer ?" << '\n';
		cout << " 0 - SAIR" << '\n';
		cout << " 1 - INSERIR VERTICE" << '\n';
		cout << " 2 - INSERIR ARESTA" << '\n';
		cout << " 3 - REMOVER ARESTA" << '\n';
		cout << " 4 - REMOVER VERTICE" << '\n';
		cout << " 5 - PRINTAR GRAFO" << '\n';
		cin >> opcao;
	}

	if (!valorPadrao)
		return -1;
	//delete valorPadrao;
	return -2;
}

