#include "WrapperDiag.h"
#include <iostream>


std::set<CWrapperDiag*> CWrapperDiag::sCwpd_;

CWrapperDiag* CWrapperDiag::instance() {
    static CWrapperDiag *i=new CWrapperDiag();
	sCwpd_.insert(i);
    return i;
}


CWrapperDiag::CWrapperDiag() {
	std::cout<< "CWrapperDiag()" <<std::endl;
}

CWrapperDiag::~CWrapperDiag() {
	for( auto i:sCwpd_ )
	{
		std::cout<<"~CWrapperDiag() "<<std::hex<< i<<std::endl;
	}
}




