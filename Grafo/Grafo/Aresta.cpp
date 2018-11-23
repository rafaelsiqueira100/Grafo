#include "stdafx.h"
#include "Aresta.h"


Aresta::Aresta(string o, string d, InfoArvoreEsparsa* c)
{
	this->origem = o;
	this->destino = d;
	this->custo = c;
}


Aresta::~Aresta()
{
	if (this->custo != nullptr)
		delete this->custo;
}

string Aresta::getOrigem()
{
	return this->origem;
}

string Aresta::getDestino()
{
	return this->destino;
}

InfoArvoreEsparsa* Aresta::getCusto()
{
	return this->custo;
}
