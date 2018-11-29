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
	int codAtual;
	list<Vertice> listaVertices;
	MatrizEsparsa matAdjacencia;
	const InfoArvoreEsparsa& valorPadrao;
	char doisSentidos;
public:
	Grafo(const InfoArvoreEsparsa&, char);
	void novoVertice(string);
	void novaAresta(string, string,const InfoArvoreEsparsa&)throw(char*);
	void removerVertice(string)throw (char*);
	void removerAresta(string, string) throw(char*);

	friend ostream& operator<< (ostream&, const Grafo&) throw();


	~Grafo();
};
#endif
