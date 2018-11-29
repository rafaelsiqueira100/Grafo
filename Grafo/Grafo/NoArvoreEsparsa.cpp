#include "NoArvoreEsparsa.h"


NoArvoreEsparsa::NoArvoreEsparsa()
{
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
}


NoArvoreEsparsa::~NoArvoreEsparsa()
{
	if (this->info != nullptr)
		delete info;
	if (this->esq != nullptr)
		delete esq;
	if (this->dir != nullptr)
		delete dir;

}
NoArvoreEsparsa::NoArvoreEsparsa(const NoArvoreEsparsa& noBase) throw(char*) {
	this->esq = nullptr;
	this->dir = nullptr;
	this->info = nullptr;
	this->equilibrio = 0;

	this->equilibrio = noBase.getEquilibrio();
	if (noBase.info != nullptr) {
		this->info = noBase.info;
	}
	if (noBase.getPtrNoFilho(0) != nullptr) {//esq não é nulo
		this->esq = new NoArvoreEsparsa(*(noBase.getPtrNoFilho(0)));
	}
	if (noBase.getPtrNoFilho(1) != nullptr) {//dir não é nulo
		this->dir = new NoArvoreEsparsa(*(noBase.getPtrNoFilho(1)));
	}
	//balancear();

}

NoArvoreEsparsa* NoArvoreEsparsa::getPtrNoFilho(unsigned char indicePtr) const throw(char*) {
	switch (indicePtr)
	{
	case 0:
		return (this->esq);
		break;
	case 1:
		return (this->dir);
		break;
	default:
		throw("Índice maior que 1 em árvore binária !!");
		break;
	}
}
void NoArvoreEsparsa::setPtrNoFilho(NoArvoreEsparsa* novoNo, unsigned char indFilho) throw(char*) {
	if (novoNo == nullptr)
		throw("Novo nó é nulo!");
	switch (indFilho) {
	case 0:
		if (this->esq == nullptr)
			this->esq = new NoArvoreEsparsa(*novoNo);
		else
			*(this->esq) = *novoNo;
		//balancear();
		break;
	case 1:
		if (this->dir == nullptr)
			this->dir = new NoArvoreEsparsa(*novoNo);
		else
			*(this->dir) = *novoNo;
		//balancear();
		break;
	default:
		throw("Índice maior que 1 em árvore binária !!");
		break;
	}
}
InfoArvoreEsparsa*  NoArvoreEsparsa::getPtrInfo() const throw() {
	return this->info;
}
char NoArvoreEsparsa::inserirVetorOrdem(InfoArvoreEsparsa* info)throw() {
	if (info == nullptr)
		return -1;
	//supondo árvore está ordenada

	if ((this->info) != nullptr) {
		if (*info < *(this->info)) {
			if (this->esq == nullptr) {
				this->esq = new NoArvoreEsparsa();
				this->esq->info = info;
				balancear();
				return 1;
			}
			else
				this->esq->inserirVetorOrdem(info);
		}
		if (*info > *(this->info)) {
			if (this->dir == nullptr) {
				this->dir = new NoArvoreEsparsa();
				this->dir->info = info;
				balancear();
				return 1;
			}
			else
				this->dir->inserirVetorOrdem(info);

		}
		if (*(this->info) == *info) {
			return 0;
		}
	}
	else {
		this->info = /*new InfoArvoreEnaria(**/info/*)*/;
		balancear();
		return 1;
	}

}
char NoArvoreEsparsa::removerVetorOrdem(InfoArvoreEsparsa* info, NoArvoreEsparsa* ant)throw() {
	if (info == nullptr)
		return -1;

	if (this->isFolha()) {
		if (*info == *(this->info)) {
			this->info = nullptr;
			/*NoArvoreEsparsa* no = this;
			no = nullptr;*/
			if (ant != nullptr) {
				if (*info > *(ant->info)) {
					ant->dir = nullptr;
				}
				if (*info < *(ant->info)) {
					ant->esq = nullptr;
				}
			}
			else {
				//árvore está vazia
				this->info = nullptr;
			}

			//balancear();
			return 1;
		}
		else {
			balancear();
			return 0;
		}
	}
	//se o fluxo de execução chegou aqui, então não é folha
	if (*info == *(this->info)) {
		//tem que achar info pra por no lugar
		*(this->info) = *(acharInfoPorLugar());
		return 2;
	}
	if (*info < *(this->info)) {
		if (this->esq == nullptr) {
			balancear();
			return -2;
		}
		else
			this->esq->removerVetorOrdem(info, this);
	}
	if (*info > *(this->info)) {
		if (this->dir == nullptr) {
			balancear();
			return -3;
		}
		else
			this->dir->removerVetorOrdem(info, this);
	}

}
char NoArvoreEsparsa::isCheio() const throw() {
	return this->info != nullptr;
}
char NoArvoreEsparsa::isVazio() const throw() {
	return (this->info) == nullptr;
}
char NoArvoreEsparsa::isFolha() const throw() {

	return (this->esq == nullptr && this->dir == nullptr);
}
char NoArvoreEsparsa::haInfo(const InfoArvoreEsparsa& info) const throw() {
	NoArvoreEsparsa* noRel = (NoArvoreEsparsa*)(this);

loop:while (1) {
	if (noRel == nullptr)
		return 0;
	if ((noRel->info) != nullptr) {
		if (*(noRel->info) == info) {
			return true;
		}
		if (*(noRel->info) > info) {
			//ir pro ponteiro de nó i-1
			noRel = (noRel->esq);
			goto loop;
		}
		if (*(noRel->info) < info) {
			noRel = (noRel->dir);
			goto loop;
		}

	}
	else {
		return 0;
	}

}
}
/*	InfoArvoreEsparsa * info;
	NoArvoreEsparsa* esq;
	NoArvoreEsparsa* dir;*/
InfoArvoreEsparsa* NoArvoreEsparsa::acharInfoPorLugar() throw(char*) {

	InfoArvoreEsparsa* infoTrocarFilho = nullptr;
	if (this->esq == nullptr) {
		infoTrocarFilho = menorDosMaiores();
	}
	else {
		infoTrocarFilho = maiorDosMenores();
	}
	return infoTrocarFilho;
}
InfoArvoreEsparsa* NoArvoreEsparsa::menorDosMaiores() throw(char*) {
	NoArvoreEsparsa* noAnt = (NoArvoreEsparsa*)this;
	NoArvoreEsparsa* noRel = (NoArvoreEsparsa*)this->dir;
	NoArvoreEsparsa* noAchado;
	char passou = 0;
	while (noRel->esq != nullptr) {
		passou = 1;
		noAnt = noRel;
		noRel = noRel->esq;
	}
	if (noRel->dir == nullptr) {
		noAchado = new NoArvoreEsparsa(*noRel);
		noRel->info = nullptr;
		if (passou)
			noAnt->esq = noRel = nullptr;
		else
			noAnt->dir = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreEsparsa(*noRel);
		noAnt->dir = noRel->dir;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
InfoArvoreEsparsa* NoArvoreEsparsa::maiorDosMenores() throw(char*) {
	NoArvoreEsparsa* noAnt = (NoArvoreEsparsa*)this;
	NoArvoreEsparsa* noRel = (NoArvoreEsparsa*)this->esq;
	NoArvoreEsparsa* noAchado;
	char passou = 0;
	while (noRel->dir != nullptr) {
		passou = 1;
		noAnt = noRel;
		noRel = noRel->dir;
	}
	if (noRel->esq == nullptr) {
		noAchado = new NoArvoreEsparsa(*noRel);
		noRel->info = nullptr;
		if (passou)
			noAnt->dir = noRel = nullptr;
		else
			noAnt->esq = noRel = nullptr;
		return noAchado->info;
	}
	else {
		noAchado = new NoArvoreEsparsa(*noRel);
		noAnt->esq = noRel->esq;
		noRel->info = nullptr;
		noRel = nullptr;
		return noAchado->info;
	}
}
ostream& operator<< (ostream& os, const NoArvoreEsparsa& no) throw() {
	int indicePtr = 0;
	int indiceInfo = 0;
	if (no.getPtrInfo() != nullptr) {
		InfoArvoreEsparsa* info = (no.getPtrInfo());
		os << "  " << (*(info)) << "  ";
	}
	else {
		os << "  **  ";
	}
	os << '[';
	if (no.getPtrNoFilho(0) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(0)) << ')';
	}
	else {
		os << "";
	}
	os << " , ";

	if (no.getPtrNoFilho(1) != nullptr) {
		os << '(' << *(no.getPtrNoFilho(1)) << ')';
	}
	else {
		os << "";
	}
	os << ']';
	return os;
}
char NoArvoreEsparsa::calcularEquilibrio() throw() {
	char niveisEsq(0), niveisDir(0);
	if (this->isFolha()) {
		this->equilibrio = 0;
	}
	if (this->esq == nullptr) {
		this->equilibrio = this->getNiveis();
	}
	if (this->dir == nullptr) {
		this->equilibrio = -(this->getNiveis());
	}
	if (this->esq != nullptr && this->dir != nullptr) {
		equilibrio = this->dir->getNiveis() - this->esq->getNiveis();
	}
	return this->equilibrio;
}
char NoArvoreEsparsa::getNiveis()const throw() {
	if (this->isFolha())
		return 0;
	if (this->esq == nullptr && this->dir != nullptr)
		return this->dir->getNiveis() + 1;
	if (this->dir == nullptr && this->esq != nullptr)
		return this->esq->getNiveis() + 1;
	char niveisEsq(0), niveisDir(0);
	if (this->esq != nullptr && this->esq != (NoArvoreEsparsa*)0xdddddddddddddddd)
		niveisEsq = this->esq->getNiveis();
	if (this->dir != nullptr && this->dir != (NoArvoreEsparsa*)0xdddddddddddddddd)
		niveisDir = this->dir->getNiveis();
	return niveisEsq > niveisDir ? niveisEsq + 1 : niveisDir + 1;
}
char NoArvoreEsparsa::getEquilibrio() const throw() {
	return this->equilibrio;
}
void NoArvoreEsparsa::balancear() throw() {
	this->calcularEquilibrio();
	if (this->equilibrio <= 1 && this->equilibrio >= -1) {
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();
	}
	if (this->equilibrio > 1) {
		if (this->dir->getEquilibrio() < 0)
			rotacaoDuplaEsquerda();
		else
			rotacaoEsquerda();
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();
	}
	if (this->equilibrio < -1) {
		if (this->esq->getEquilibrio() > 0)
			rotacaoDuplaDireita();
		else
			rotacaoDireita();
		if (this->esq != nullptr)
			this->esq->balancear();
		if (this->dir != nullptr)
			this->dir->balancear();

	}
	if (this->esq != nullptr)
		this->esq->balancear();
	if (this->dir != nullptr)
		this->dir->balancear();
	this->calcularEquilibrio();
}
void NoArvoreEsparsa::rotacaoEsquerda() throw() {
	NoArvoreEsparsa* novaRaiz = new NoArvoreEsparsa(*(this->dir));
	novaRaiz->setPtrNoFilho(new NoArvoreEsparsa(*this), 0);

	novaRaiz->esq->dir = this->dir->esq;
	this->dir->esq = nullptr;
	this->dir = novaRaiz->dir;
	this->esq = novaRaiz->esq;
	this->info = novaRaiz->info;
	//delete novaRaiz;
	this->calcularEquilibrio();

}
void NoArvoreEsparsa::rotacaoDireita() throw() {
	NoArvoreEsparsa* novaRaiz = new NoArvoreEsparsa(*(this->esq));
	novaRaiz->setPtrNoFilho(new NoArvoreEsparsa(*this), 1);
	novaRaiz->dir->esq = this->esq->dir;
	this->esq->dir = nullptr;
	this->dir = novaRaiz->dir;
	this->esq = novaRaiz->esq;
	this->info = novaRaiz->info;
	//delete novaRaiz;

	this->calcularEquilibrio();
}
void NoArvoreEsparsa::setInfo(const InfoArvoreEsparsa& novaInfo) throw()
{
	*this->info = novaInfo;
}
InfoArvoreEsparsa* NoArvoreEsparsa::getInfo() throw()
{
	return this->info;
}
void NoArvoreEsparsa::rotacaoDuplaEsquerda() throw() {
	this->dir->rotacaoDireita();
	this->rotacaoEsquerda();

}
void NoArvoreEsparsa::rotacaoDuplaDireita() throw() {
	this->esq->rotacaoEsquerda();
	this->rotacaoDireita();
}