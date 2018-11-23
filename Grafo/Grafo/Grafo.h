#pragma once
#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Vertice.h"
#include "MatrizEsparsa.h"
#include <list>
class Grafo
{
private:
	int numVertices;
	list<Vertice> listaVertices;
	MatrizEsparsa matAdjacencia;
	const InfoArvoreEsparsa& valorPadrao;
public:
	Grafo(const InfoArvoreEsparsa&);
	void novoVertice(string);
	void novaAresta(string, string,const InfoArvoreEsparsa&)throw(char*);
	void removerVertice(string);
	void removerAresta(string, string);


	~Grafo();
};
#endif
