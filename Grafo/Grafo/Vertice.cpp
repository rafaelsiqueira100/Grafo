#include "stdafx.h"
#include "Vertice.h"



Vertice::Vertice(string n)
{
	this->nome = n;
}

string Vertice::getNome()
{
	return this->nome;
}


Vertice::~Vertice()
{
}
