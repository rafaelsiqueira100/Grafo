#pragma once
#include <string>
using namespace std;
#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
class Vertice
{
private:
	string nome;
public:
	Vertice();
	string getNome();
	~Vertice();
};
#endif
