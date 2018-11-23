#pragma once
#include <string>
using namespace std;
#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
class Vertice
{
private:
	string nome;
	int codigo;
public:
	char operator==(const Vertice&)const throw();
	Vertice(string, int);
	Vertice(string);
	string getNome();
	int getCodigo();
	~Vertice();
};
#endif
