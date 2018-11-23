#include "stdafx.h"
#include "Grafo.h"




Grafo::Grafo(const InfoArvoreEsparsa& vP) :matAdjacencia(&vP),
numVertices(0),
valorPadrao(vP)
{

}

void Grafo::novoVertice(string nomeNovoVertice)
{
	Vertice novoV(nomeNovoVertice, numVertices);
	listaVertices.push_back((novoV);
	numVertices++;
}

void Grafo::novaAresta(string nomeVerticeOrigem, string nomeVerticeDestino,const InfoArvoreEsparsa& custo)throw(char*)
{
	list<Vertice>::iterator it;
	if (listaVertices.empty())
		throw("N�o h� v�rtices para serem relacionados pela aresta");
	int indOrigem = -1, indDestino = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeVerticeOrigem)
			indOrigem = indLista;
		if (it->getNome() == nomeVerticeDestino)
			indDestino = indLista;
	}
	if (indOrigem <0)
		throw("V�rtice de origem n�o existe!");
	if (indDestino<0)
		throw("V�rtice de destino n�o existe!");
	matAdjacencia.inserir(indOrigem, indDestino,(InfoArvoreEsparsa*) &custo);
}

void Grafo::removerVertice(string nomeARemover) 
{

	if (listaVertices.empty())
		throw("N�o h� v�rtices para serem removidos");
	list<Vertice>::iterator it;
	if (listaVertices.empty())
		throw("N�o h� arestas para serem removidas");
	int indVertice = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeARemover){
			/*it =*/ listaVertices.erase(it);
			//it--;
			indVertice = indLista;
		}
	}
	if (indVertice < 0)
		throw("V�rtice n�o existe!");
	
	numVertices--;
}

void Grafo::removerAresta(string nomeOrigemARemover, string nomeDestinoARemover)
{
	list<Vertice>::iterator it;
	if (listaVertices.empty())
		throw("N�o h� arestas para serem removidas");
	int indOrigem = -1, indDestino = -1, indLista = 0;
	for (it = listaVertices.begin(); it != listaVertices.end(); ++it, ++indLista) {
		if (it->getNome() == nomeOrigemARemover)
			indOrigem = indLista;
		if (it->getNome() == nomeDestinoARemover)
			indDestino = indLista;
	}
	if (indOrigem < 0)
		throw("V�rtice de origem n�o existe!");
	if (indDestino < 0)
		throw("V�rtice de destino n�o existe!");
	matAdjacencia.inserir(indOrigem, indDestino, &valorPadrao);
}

Grafo::~Grafo()
{
}
