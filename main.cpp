/*
 * main.cpp
 *
 *  Created on: 10 May 2014
 *      Author: KonstantinosChalkias
 */


#include <iostream>
#include "IntExprPart3.hpp"

int main (int argc, const char * argv[])
{

    //typedef NOT<IMP<P, OR<NOT<AND<LIT<true>, P > >, NOT<P> > > > FORM;
	typedef ADDITION<ADDITION<X<BOUNDS<-1,8> >,LIT<1> >, ADDITION<X<BOUNDS<0,5> >,LIT<2> > >  FORM;
	FORM t;
	int* xArray = new int[2];
	xArray[0] = 4;
	xArray[1] = 2;
	int* res = t.eval(xArray);

	printf("%d<=  %d <=%d \n",res[1],res[0],res[2] );
    return 0;

}



