#include "stdafx.h"
#include "MatrizEsparsa.h"


MatrizEsparsa::MatrizEsparsa(InfoArvoreEsparsa* valorPadrao) :
	arvoreLinhas(),
	valorPadrao(valorPadrao),
	menorLinha(0),
	menorColuna(0),
	maiorLinha(-1),
	maiorColuna(-1),
	vazia(1),
	numElementos(0)
{}


MatrizEsparsa::~MatrizEsparsa()
{
	if (this->valorPadrao != nullptr)
		delete this->valorPadrao;
}
InfoArvoreEsparsa* MatrizEsparsa::pegar(int linha, int coluna) {
	MinhaInfo li(linha);//chave=linha
	MinhaInfo col(coluna);//chave=coluna
	if (this->arvoreLinhas.haInfo(&li)) {
		MinhaInfo* infoLinha = (MinhaInfo*)(this->arvoreLinhas.pegar(li));
		ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)((*infoLinha).getInfo());
		if ((*arvoreColunas).haInfo(&col)) {
			MinhaInfo* infoColuna = (MinhaInfo*)((*arvoreColunas).pegar(col));
			return (*infoColuna).getInfo();
		}
		else {//não existe essa coluna na árvore
			
			return valorPadrao;
		}
	}
	else {//não existe essa linha na árvore
		return valorPadrao;
	}
}
void MatrizEsparsa::inserir(int linha, int coluna, InfoArvoreEsparsa*valor) throw(char*){
	if (vazia) {
		this->menorLinha = linha;
		this->maiorLinha = linha;
		this->menorColuna = coluna;
		this->maiorColuna = coluna;
	}
	else {
		if (linha < this->menorLinha) {
			this->menorLinha = linha;
		}
		if (linha > this->maiorLinha) {
			this->maiorLinha = linha;
		}
		if (coluna < this->menorColuna) {
			this->menorColuna = coluna;
		}
		if (coluna > this->maiorColuna) {
			this->maiorColuna = coluna;
		}
	}
	//vazia = 0;

	MinhaInfo* li = new MinhaInfo(linha);//chave=linha
		if (this->arvoreLinhas.haInfo(li)) {
			//alterar
			
			MinhaInfo* infoLinha = (MinhaInfo*)(this->arvoreLinhas.pegar(*li));
			ArvoreEsparsa* arvoreColunas = (ArvoreEsparsa*)((*infoLinha).getInfo());
			if (arvoreColunas == nullptr) {
				//throw("árvore de colunas nula!");
				return;
			}
			MinhaInfo* col = new MinhaInfo(coluna);//chave=coluna
			if ((*arvoreColunas).haInfo(col)) {
				//alterar
				if (*valor == *valorPadrao) {
				//remover

					(*arvoreColunas).remover(col);
					col = nullptr;
					this->numElementos--;
					if ((*arvoreColunas).isVazia()) {
						arvoreColunas = nullptr;
						this->arvoreLinhas.remover(infoLinha);
						infoLinha = nullptr;
					}
					if (this->numElementos == 0)
						this->vazia = 1;
					else {
						calcularMaiorLinha();
						calcularMenorLinha();
						this->maiorColuna = calcularMaiorColuna(this->arvoreLinhas.getRaiz());
						this->menorColuna = calcularMenorColuna(this->arvoreLinhas.getRaiz());
					}

				}
				else {
					//altera o valor
					MinhaInfo* infoColuna = (MinhaInfo*)((*arvoreColunas).pegar(*col));
					(*infoColuna).setInfo(*valor);
				}
			}
			else {//não existe essa coluna nessa linha da árvore
				//inserir outro nó
				if (*valor == *valorPadrao) {
				//não faz nada
				}
				else {
					//insere essa coluna e valor na árvore
					
					MinhaInfo* col = new MinhaInfo(coluna, valor);
					//linha-coluna tem um valor
					(*arvoreColunas).inserir(col);
					this->numElementos++;
				}
			}
		}
		else {//não existe essa linha na árvore
		//inserir outro nó
			if (*valor == *valorPadrao) {
				//não faz nada
			}
			else{
				//insere essa linha, coluna e valor na árvore
		
				MinhaInfo* col = new MinhaInfo(coluna, valor);//linha-coluna tem um valor
				ArvoreEsparsa* arvoreColunas = new ArvoreEsparsa();
				(*arvoreColunas).inserir(col);
				MinhaInfo* novaLi = new MinhaInfo(linha, arvoreColunas);
				//linha tem uma info
				this->arvoreLinhas.inserir(novaLi);
				this->numElementos++;
			
			}
		}
		if (this->numElementos > 0)
			this->vazia = 0;
	}

void MatrizEsparsa::calcularMenorLinha() throw(char *)
{
	if (this->vazia)
		throw("Tentativa de calcular menor linha de uma matriz vazia");
	NoArvoreEsparsa* noAtual = this->arvoreLinhas.getRaiz();
	NoArvoreEsparsa* noAnterior = nullptr;
	while (noAtual != nullptr) {
		noAnterior = noAtual;
		noAtual = noAtual->getPtrNoFilho(0);
	}
	this->menorLinha =
	((MinhaInfo*)(noAnterior->getInfo()))->getChave();
}

void MatrizEsparsa::calcularMaiorLinha() throw(char *)
{
	if (this->vazia)
		throw("Tentativa de calcular maior linha de uma matriz vazia");
	NoArvoreEsparsa* noAtual = this->arvoreLinhas.getRaiz();
	NoArvoreEsparsa* noAnterior = nullptr;
	while (noAtual != nullptr) {
		noAnterior = noAtual;
		noAtual = noAtual->getPtrNoFilho(1);
	}
	this->maiorLinha =
	((MinhaInfo*)(noAnterior->getInfo()))->getChave();
}

int MatrizEsparsa::calcularMaiorColuna(NoArvoreEsparsa* noAtual/*, NoArvoreEsparsa* noAnterior*/) throw(char*)
{
	NoArvoreEsparsa* esq, *dir;
	esq = noAtual->getPtrNoFilho(0);
	dir = noAtual->getPtrNoFilho(1);
	if (esq == nullptr) {
		if (dir == nullptr) {
			NoArvoreEsparsa* noColAtual = ((ArvoreEsparsa*)(((MinhaInfo*)(noAtual->getInfo()))->getInfo()))->getRaiz();
			NoArvoreEsparsa* noColAnterior = nullptr;
			while (noColAtual != nullptr) {
				noColAnterior = noColAtual;
				noColAtual = noColAtual->getPtrNoFilho(1);
			}
			return	((MinhaInfo*)(noColAnterior->getInfo()))->getChave();

		}
		else {
			return this->calcularMaiorColuna(dir);
		}
	}
	else {
		if (dir == nullptr) {
			return this->calcularMaiorColuna(esq);
		}
		else {
			int maiorColunaEsq = this->calcularMaiorColuna(esq);
			int maiorColunaDir = this->calcularMaiorColuna(dir);
			if (maiorColunaEsq < maiorColunaDir)
				return maiorColunaEsq;
			else
				return maiorColunaDir;
		}
	}
}

int MatrizEsparsa::calcularMenorColuna(NoArvoreEsparsa* noAtual) throw(char*)
{
	NoArvoreEsparsa* esq, *dir;
	esq = noAtual->getPtrNoFilho(0);
	dir = noAtual->getPtrNoFilho(1);
	if (esq == nullptr) {
		if (dir == nullptr) {
			NoArvoreEsparsa* noColAtual = ((ArvoreEsparsa*)(((MinhaInfo*)(noAtual->getInfo()))->getInfo()))->getRaiz();
			NoArvoreEsparsa* noColAnterior = nullptr;
			while (noColAtual != nullptr) {
				noColAnterior = noColAtual;
				noColAtual = noColAtual->getPtrNoFilho(0);
			}
			return	((MinhaInfo*)(noColAnterior->getInfo()))->getChave();

		}
		else {
			return this->calcularMenorColuna(dir);
		}
	}
	else {
		if (dir == nullptr) {
			return this->calcularMenorColuna(esq);
		}
		else {
			int menorColunaEsq = this->calcularMenorColuna(esq);
			int menorColunaDir = this->calcularMenorColuna(dir);
			if (menorColunaEsq < menorColunaDir)
				return menorColunaEsq;
			else
				return menorColunaDir;
		}
	}
}
ostream& operator<<(ostream& os, const MatrizEsparsa& matriz) throw()
{
	os << "{ " << '\n' <<
		"Valor padrao = [ ";
		
	if (matriz.valorPadrao == nullptr)
		os << "null";
	else
		os << (*((MinhaInfo*)(matriz.valorPadrao))).getChave();
	os << ']' << '\n';
	os <<'\n' <<"Matriz = " << '\n';
	int indiceLinhas, indiceColunas;
	char haLinha, haColuna;
	if (matriz.vazia)
		os << "nada" << '\n';
	else {
		for (indiceLinhas = matriz.menorLinha; indiceLinhas <= matriz.maiorLinha; indiceLinhas++) {
			MinhaInfo* infoLinha = new MinhaInfo(indiceLinhas);
			haLinha = (((matriz).arvoreLinhas)).haInfo(infoLinha);
			ArvoreEsparsa* arvoreColunas = nullptr;
			//(ArvoreEsparsa) ((MinhaInfo)(matriz.arvoreLinhas.pegar(*(new MinhaInfo(indiceLinhas))))).getInfo();
			if (haLinha) {
				infoLinha = (MinhaInfo*)((*(ArvoreEsparsa*)(&matriz.arvoreLinhas))).pegar((const InfoArvoreEsparsa&)*infoLinha);
				arvoreColunas = (ArvoreEsparsa*)(infoLinha->getInfo());
			}
			for (indiceColunas = matriz.menorColuna; indiceColunas <= matriz.maiorColuna; indiceColunas++) {
				MinhaInfo* infoColuna = new MinhaInfo(indiceColunas);
				if (!haLinha) {
					os << " [ " << (*((MinhaInfo*)(matriz.valorPadrao))).getChave() << " ] ";
				}
				else {
					haColuna = (*arvoreColunas).haInfo(infoColuna);
					if (!haColuna) {
						os << " [ " << (*((MinhaInfo*)(matriz.valorPadrao))).getChave() << " ] ";
					}
					else {
						infoColuna = (MinhaInfo*)((*arvoreColunas).pegar((const InfoArvoreEsparsa&)*infoColuna));
						os << " [ " << (*(MinhaInfo*)(infoColuna->getInfo())).getChave() << " ] ";
					}
				}
			}
			os << '\n';
		}
	}
	os << "} " << '\n';
	return os;
}
