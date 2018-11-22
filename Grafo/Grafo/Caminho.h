#pragma once
#include "Vertice.h"
#include "MinhaInfo.h"
#ifndef CAMINHO_H_INCLUDED
#define CAMINHO_H_INCLUDED
class Caminho
{
private:
	Vertice cidOrigem;
	Vertice cidDestino;
	InfoArvoreEsparsa* custo;
	const int menorCusto = 1;
public:
	Caminho(Vertice, Vertice, InfoArvoreEsparsa* custo);

	~Caminho();
};

#endif