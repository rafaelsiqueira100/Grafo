
#include "MinhaInfo.h"
MinhaInfo::MinhaInfo() : chave(0) {}

MinhaInfo::MinhaInfo(int vlr) {
	this->chave = vlr;
}
MinhaInfo::MinhaInfo(int chave, InfoArvoreEsparsa* info) throw()
{
	this->chave = chave;
	this->info = info;
}
MinhaInfo::MinhaInfo(const InfoArvoreEsparsa& outra) :
	MinhaInfo(((const MinhaInfo&)outra).chave)
{}
MinhaInfo::~MinhaInfo() {
	if (this->info != nullptr)
		delete this->info;
}
ostream& operator<< (ostream& os, const MinhaInfo& info) throw() {
	return info.print(os);
}
ostream& MinhaInfo::print(ostream& os)const throw() {
	
	if (this->info != nullptr)
		return os << "{ chave = [ " << this->chave << " ] " << '\n' << " info = [ " << this->info << " ] } ";
	else
		return os << " { " << this->chave << " } " << '\n';
}
int MinhaInfo::getChave()const throw() {
	return this->chave;
}
void MinhaInfo::setChave(int novaChave) throw() {
	this->chave = (novaChave);
}
InfoArvoreEsparsa* MinhaInfo::getInfo() const throw() {
	return this->info;
}
void MinhaInfo::setInfo(const InfoArvoreEsparsa& novaInfo) const throw() {
	if (this->info == nullptr) {
		MinhaInfo* inf = new MinhaInfo(0);
		((MinhaInfo*)(this))->info =(InfoArvoreEsparsa*) &novaInfo;
		return;
	}
	*(this->info) = novaInfo;
}
char MinhaInfo::operator<(const InfoArvoreEsparsa& outra)const throw() {
	return this->chave <((const MinhaInfo&)outra).getChave();
}
char MinhaInfo::operator>(const InfoArvoreEsparsa& outra)const throw() {
	return this->chave > ((const MinhaInfo&)outra).getChave();
}
char MinhaInfo::operator==(const InfoArvoreEsparsa& outra)const throw() {
	return this->chave == ((const MinhaInfo&)outra).getChave();
}
char MinhaInfo::operator<=(const InfoArvoreEsparsa& outra)const throw() {
	return this->chave <= ((const MinhaInfo&)outra).getChave();
}
char MinhaInfo::operator>=(const InfoArvoreEsparsa& outra)const throw() {
	return this->chave >= ((const MinhaInfo&)outra).getChave();
}
InfoArvoreEsparsa& MinhaInfo::operator=(const InfoArvoreEsparsa& outra)throw() {
	chave = (((const MinhaInfo&)outra).chave);
	info = (((const MinhaInfo&)outra).info);
	return *this;
}
