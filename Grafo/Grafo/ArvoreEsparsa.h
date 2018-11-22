#pragma once
using namespace std;
#include "NoArvoreEsparsa.h"
#include "InfoArvoreEsparsa.h"
#include "NoArvoreEsparsa.h"
#ifndef ARVOREESPARSA_H_INCLUDED
#define ARVOREESPARSA_H_INCLUDED


class ArvoreEsparsa : public InfoArvoreEsparsa
{
public:
	ArvoreEsparsa();
	~ArvoreEsparsa();
	InfoArvoreEsparsa* pegar(const InfoArvoreEsparsa&) const throw();
	void inserir(InfoArvoreEsparsa* );
	void remover(InfoArvoreEsparsa*) throw(char*);
	friend ostream& operator<< (ostream&, const InfoArvoreEsparsa&) throw();
	char operator<(const InfoArvoreEsparsa&)const throw();
	char operator>(const InfoArvoreEsparsa&)const throw();
	char operator==(const InfoArvoreEsparsa&)const throw();
	char operator<=(const InfoArvoreEsparsa&)const throw();
	char operator>=(const InfoArvoreEsparsa&)const throw();
	InfoArvoreEsparsa& operator=(const InfoArvoreEsparsa&)throw();
	ostream& print(ostream&) const throw();
	char haInfo(InfoArvoreEsparsa*) const throw();
	NoArvoreEsparsa* getRaiz() const throw();
	char isVazia() const throw();
	
private:
	NoArvoreEsparsa* raiz;
	void balancear() throw();
};

#endif