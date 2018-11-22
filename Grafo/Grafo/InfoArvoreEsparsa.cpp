#include "InfoArvoreEsparsa.h"


InfoArvoreEsparsa::InfoArvoreEsparsa()
{
}


InfoArvoreEsparsa::~InfoArvoreEsparsa()
{
}

ostream& operator<< (ostream& os, InfoArvoreEsparsa& info) throw() {
	return((info).print(os));
}