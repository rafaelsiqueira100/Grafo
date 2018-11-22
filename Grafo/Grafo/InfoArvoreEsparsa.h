#pragma once
#ifndef INFOARVOREESPARSA_H_INCLUDED
#define INFOARVOREESPARSA_H_INCLUDED
#include <iostream>
using namespace std;
class InfoArvoreEsparsa
{
public:
	InfoArvoreEsparsa();
	~InfoArvoreEsparsa();
	//InfoArvoreBinariaAVL(const InfoArvoreBinariaAVL&) throw();
	friend ostream& operator<< (ostream&, InfoArvoreEsparsa&) throw();
	virtual char operator<(const InfoArvoreEsparsa&)const throw() = 0;
	virtual char operator>(const InfoArvoreEsparsa&)const throw() = 0;
	virtual char operator==(const InfoArvoreEsparsa&)const throw() = 0;
	virtual char operator<=(const InfoArvoreEsparsa&)const throw() = 0;
	virtual char operator>=(const InfoArvoreEsparsa&)const throw() = 0;
	virtual InfoArvoreEsparsa& operator=(const InfoArvoreEsparsa&)throw() = 0;
	virtual ostream& print(ostream&)const throw() = 0;

};
#endif
