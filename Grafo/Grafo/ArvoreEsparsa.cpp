#include "ArvoreEsparsa.h"


ArvoreEsparsa::ArvoreEsparsa()
{
	this->raiz = nullptr;
}


ArvoreEsparsa::~ArvoreEsparsa()
{
	if (this->raiz != nullptr)
		delete raiz;
}

void ArvoreEsparsa::remover(InfoArvoreEsparsa* info) throw(char*) {
	if (this->raiz == nullptr) {
		//árvore está vazia
		throw("Tentativa de remoção em árvore vazia!");
	}
	this->raiz->removerVetorOrdem(info, nullptr);
	if ((this->raiz->isVazio()))
		this->raiz = nullptr;

	this->balancear();
}
char ArvoreEsparsa::isVazia() const throw() {
	if (this->raiz == nullptr)
		return 1;
	if (this->raiz->isVazio())
		return 1;
	return 0;
}
char ArvoreEsparsa::operator<(const InfoArvoreEsparsa& outraInfo) const throw()
{
	return this->getRaiz() < ((ArvoreEsparsa&)outraInfo).getRaiz();
}
char ArvoreEsparsa::operator>(const InfoArvoreEsparsa& outraInfo) const throw()
{
	return this->getRaiz() > ((ArvoreEsparsa&)outraInfo).getRaiz();
}
char ArvoreEsparsa::operator==(const InfoArvoreEsparsa& outraInfo) const throw()
{
	return this->getRaiz() == ((ArvoreEsparsa&)outraInfo).getRaiz();
}
char ArvoreEsparsa::operator<=(const InfoArvoreEsparsa& outraInfo) const throw()
{
	return this->getRaiz() <= ((ArvoreEsparsa&)outraInfo).getRaiz();
}
char ArvoreEsparsa::operator>=(const InfoArvoreEsparsa& outraInfo) const throw()
{
	return this->getRaiz() >= ((ArvoreEsparsa&)outraInfo).getRaiz();
}
InfoArvoreEsparsa& ArvoreEsparsa::operator=(const InfoArvoreEsparsa & outraInfo) throw()
{
	*raiz = *(((const ArvoreEsparsa&)outraInfo).getRaiz());
	return *this;
}
ostream& ArvoreEsparsa::print(ostream& os) const throw()
{
	if (this->raiz == nullptr)
		return os << "{  }" << '\n';
	return	os << '{' << *(this->raiz) << '}' << '\n';
}
char ArvoreEsparsa::haInfo(InfoArvoreEsparsa* info) const throw() {
	if (this->raiz == nullptr)
		return 0;
	return this->raiz->haInfo(info);
}

NoArvoreEsparsa* ArvoreEsparsa::getRaiz() const throw()
{
	return this->raiz;
}

ostream& operator<< (ostream& os, const ArvoreEsparsa& arvore) throw() {
	return arvore.print(os);
}


void ArvoreEsparsa::balancear() throw() {
	if (this->raiz == nullptr)
		return;
	this->raiz->balancear();
}
InfoArvoreEsparsa* ArvoreEsparsa::pegar(const InfoArvoreEsparsa& infoDesejada) const throw(){
	NoArvoreEsparsa* noAtual = this->raiz;
	while (noAtual != nullptr) {
		if ( infoDesejada == *(noAtual->getPtrInfo()) ) {
			return noAtual->getPtrInfo();
		}
		if (infoDesejada < *(noAtual->getPtrInfo())) {
			noAtual = noAtual->getPtrNoFilho(0);
		}
		if (infoDesejada > *(noAtual->getPtrInfo())) {
			noAtual = noAtual->getPtrNoFilho(1);
		}
	}
	return nullptr;
}

void ArvoreEsparsa::inserir(InfoArvoreEsparsa* info)
{
	if (this->raiz == nullptr)
		raiz = new NoArvoreEsparsa();
	if ((this->raiz->isVazio())) {
		this->raiz == nullptr;
		raiz = new NoArvoreEsparsa();
	}
	this->raiz->inserirVetorOrdem(info);

	this->balancear();
}
