#include "WrapperDiag.h"
#include <iostream>

int main()
{
	for(int i=0;i<5;i++)
	{
		auto *pCwpd = CWrapperDiag::instance();
		std::cout<<"pCwpd:"<< pCwpd <<std::endl;
	}	
	return 0;	
}
