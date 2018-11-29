#include "stdafx.h"
#include "Grafo.h"




Grafo::Grafo(const InfoArvoreEsparsa& vP, char duploSentido) :matAdjacencia((InfoArvoreEsparsa*)&vP),
numVertices(0),
valorPadrao(vP),
codAtual(0),
doisSentidos(duploSentido)
{

}

void Grafo::novoVertice(string nomeNovoVertice)
{
	list<Vertice>::iterator it;
	if (!listaVertices.empty()) {

		int codAtual = -1;
		for (it = listaVertices.begin(); it != listaVertices.end(); ++it) {
			if (it->getNome() == nomeNovoVertice)
				codAtual = it->getCodigo();
		}
		if (codAtual >= 0)
			return;
	}
	Vertice novoV(nomeNovoVertice, codAtual);
	listaVertices.push_back(novoV);
	numVertices++;
	codAtual++;
}

void Grafo::novaAresta(string nomeVerticeOrigem, string nomeVerticeDestino,const InfoArvoreEsparsa& custo)throw(string)
{
	list<Vertice>::iterator it;
	string msg;
	if (listaVertices.empty()) {
		msg = ("Nao ha vertices para serem relacionados pela aresta");
		throw msg;
	}
	int indOrigem = -1, indDestino = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeVerticeOrigem)
			indOrigem = it->getCodigo();
		if (it->getNome() == nomeVerticeDestino)
			indDestino = it->getCodigo();
	}
	if (indOrigem < 0) {
		msg = "Vertice de origem não existe!";
		throw msg;
	}
	if (indDestino < 0) {
		msg = "Vertice de destino não existe!";
		throw msg;
	}
	matAdjacencia.inserir(indOrigem, indDestino,(InfoArvoreEsparsa*) &custo);
	if(doisSentidos!=0)
		matAdjacencia.inserir(indDestino, indOrigem, (InfoArvoreEsparsa*)&custo);

}

void Grafo::removerVertice(string nomeARemover) throw(string)
{
	string excecao;
	if (listaVertices.empty()) {
		excecao = "Nao ha vertices para serem removidos";
		throw excecao;
	}
	list<Vertice>::iterator it;
	if (listaVertices.empty()) {
		excecao = "Nao ha arestas para serem removidas";
		throw excecao;
	}
	int indVertice = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeARemover){

			indVertice = it->getCodigo();
			listaVertices.erase(it);
			
			break;
		}
	}
	if (indVertice < 0) {
		excecao = "Vertice não existe!";
		throw excecao;
	}
	//remover todas as arestas desse vértice
	if (!matAdjacencia.isVazia()) {
		int menorLinha(matAdjacencia.getMenorLinha());
		int maiorLinha(matAdjacencia.getMaiorLinha());
		int menorColuna(matAdjacencia.getMenorColuna());
		int maiorColuna(matAdjacencia.getMaiorColuna());
		for (int i = menorLinha; i <= maiorLinha; i++) {
			matAdjacencia.inserir(i, indVertice, (InfoArvoreEsparsa*)&valorPadrao);
		}
		for (int j = menorColuna; j <= maiorColuna; j++) {
			matAdjacencia.inserir(indVertice, j, (InfoArvoreEsparsa*)&valorPadrao);
		}
	}
	numVertices--;
}

void Grafo::removerAresta(string nomeOrigemARemover, string nomeDestinoARemover) throw(string)
{
	list<Vertice>::iterator it;
	string msg;
	if (listaVertices.empty()) {
		msg = "Nao ha arestas para serem removidas";
		throw msg;
	}
	int indOrigem = -1, indDestino = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeOrigemARemover)
			indOrigem = it->getCodigo();
		if (it->getNome() == nomeDestinoARemover)
			indDestino = it->getCodigo();
	}
	if (indOrigem < 0) {
		msg = ("Vertice de origem nao existe!");
		throw msg;
	}
	if (indDestino < 0) {
		msg = ("Vertice de destino nao existe!");
		throw msg;
	}
	matAdjacencia.inserir(indOrigem, indDestino, ((InfoArvoreEsparsa*)&valorPadrao));
	if(doisSentidos!=0)
		matAdjacencia.inserir(indDestino, indOrigem, ((InfoArvoreEsparsa*)&valorPadrao));

}

Grafo::~Grafo()
{

}

ostream& operator<<(ostream& os, const Grafo& g) throw()
{
	os << "{ " << '\n' <<
		"Numero de vertices = " << g.numVertices << '\n';
	os << "Codigo do proximo vertice = " << g.codAtual << '\n';
	os << "Vertices = "<< '\n';
	list<Vertice>::iterator it;
	list<Vertice>::iterator itLinha;

	list<Vertice>::iterator itColuna;
	if (g.listaVertices.empty())
		cout << "nada";
	else {
		int indOrigem = -1, indDestino = -1, indLista = 0;
		cout << "[" << '\n';
		for (it = ((Grafo&)g).listaVertices.begin(); it != g.listaVertices.end(); ++it) {
			os << " Codigo =  " << it->getCodigo() << "  " << '\n';
			os << " Nome   =  " << it->getNome() << "  " << '\n';
			os << '\n';
		}
		os << ']' << '\n';
	}
	os << '\n' << "Arestas = " << '\n';

	if (((Grafo&)g).matAdjacencia.isVazia())
		os << "nada" << '\n';
	else {
		os << ((Grafo&)g).matAdjacencia;
		
	
	}
	os << "} " << '\n';
	return os;
}
