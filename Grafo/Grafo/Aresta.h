#pragma once
#include "InfoArvoreEsparsa.h"
using namespace std;
class Aresta
{
private:
    string origem;
	string destino;
	InfoArvoreEsparsa* custo;
public:
	Aresta(string, string, InfoArvoreEsparsa*);
	~Aresta();
	string getOrigem();
	string getDestino();
	InfoArvoreEsparsa* getCusto();
};

