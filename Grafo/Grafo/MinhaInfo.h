#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreEsparsa.h"
#include <iostream>
using namespace std;
class MinhaInfo : public InfoArvoreEsparsa
{
public:
	MinhaInfo();
	MinhaInfo(int);
	MinhaInfo(int, InfoArvoreEsparsa*) throw();
	MinhaInfo(const InfoArvoreEsparsa&) throw();
	~MinhaInfo();
	friend ostream& operator<< (ostream&, const MinhaInfo&) throw();
	int getChave() const throw();
	void setChave(int) throw();
	InfoArvoreEsparsa* getInfo() const throw();
	void setInfo(const InfoArvoreEsparsa&) const throw();
	char operator<(const InfoArvoreEsparsa&)const throw();
	char operator>(const InfoArvoreEsparsa&)const throw();
	char operator==(const InfoArvoreEsparsa&)const throw();
	char operator<=(const InfoArvoreEsparsa&)const throw();
	char operator>=(const InfoArvoreEsparsa&)const throw();
	InfoArvoreEsparsa& operator=(const InfoArvoreEsparsa&)throw();
	ostream& print(ostream&) const throw();

private:
	int chave;
	InfoArvoreEsparsa* info;

};
#endif

