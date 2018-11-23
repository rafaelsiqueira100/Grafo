#include "stdafx.h"
#include "Vertice.h"





char Vertice::operator==(const Vertice& outro) const throw()
{
	return this->nome == ((Vertice&)outro).getNome();
}

Vertice::Vertice(string n, int c):
	nome(n), codigo(c)
{
}

Vertice::Vertice(string n):
	nome(n)
{
}

string Vertice::getNome()
{
	return this->nome;
}

int Vertice::getCodigo()
{
	return this->codigo;
}


Vertice::~Vertice()
{
}
