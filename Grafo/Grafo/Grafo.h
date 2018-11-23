#pragma once
#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Vertice.h"
#include "MatrizEsparsa.h"
class Grafo
{
private:
	int numVertices;
	Vertice* vertices;
	MatrizEsparsa matAdjacencia;
public:
	Grafo(int);
	void novoVertice(string);
	void novaAresta(string, string, InfoArvoreEsparsa*);
	void removerVertice(string);
	void removerAresta(string, string);


	~Grafo();
};
#endif
