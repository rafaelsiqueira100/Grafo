#include "stdafx.h"
#include "Grafo.h"




Grafo::Grafo(int n)
{
	this->vertices = new int[n];
	this->matAdjacencia();

}

void Grafo::novoVertice(string)
{
}

void Grafo::novaAresta(string, string, InfoArvoreEsparsa *)
{
}

void Grafo::removerVertice(string)
{
}

void Grafo::removerAresta(string, string)
{
}

Grafo::~Grafo()
{
	if (this->vertices != nullptr)
		delete[] this->vertices;
}
