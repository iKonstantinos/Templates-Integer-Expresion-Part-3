/*
 * IntExprPart3.hpp
 *
 *  Created on: 11 May 2014
 *      Author: KonstantinosChalkias
 */

#ifndef INTEXPRPART3_HPP_
#define INTEXPRPART3_HPP_

#include <iostream>
#include <stdexcept>

int globalCounter = 0;


template<class A>
struct X{
	static inline int* eval(int x[]){
		int *bounds = A::eval();
		int* valueAndBoundaries = new int[3];
		if(x[globalCounter] >=bounds[0] && x[globalCounter] <=bounds[1]){
			valueAndBoundaries[0] = x[globalCounter] ;
			valueAndBoundaries[1] = bounds[0];
			valueAndBoundaries[2] = bounds[1];
			++globalCounter;
			return valueAndBoundaries;

		}
		else{
			printf("The variable that you gave is outside range\n");
		}
	};
};

template<int V>
struct LIT
{
	static inline int* eval(int x[]) {
		int* litAndBoundaries = new int[3];
		litAndBoundaries[0] =(int)V;
		litAndBoundaries[1] = (int)V;
		litAndBoundaries[2] = (int)V;
		return litAndBoundaries;
	};
};

template<int Low, int High>
struct BOUNDS{
	static inline int* eval(){
		int* bounds =new int[2];
		bounds[0] = Low;
		bounds[1] = High;
		return bounds;
	};
};


template<class A, class B>
struct ADDITION
{
	static inline int* eval(int x[]) {
		printf("Addition\n");
		int* a = A::eval(x);
		int* b = B::eval(x);
		int* res = new int[3];
		res[0] = a[0] +b[0];
		res[1] = a[1] +b[1];
		res[2] = a[2] +b[2];
		return res;

	};
};

template<class A, class B>
struct SUBSTRACTION
{
	static inline int* eval(int x[]) {
		printf("Substraction \n");
		int* a = A::eval(x);
		int* b = B::eval(x);
	    int* res = new int[3];
	    res[0] = a[0] - b[0];
		res[1] = a[1] - b[1];
		res[2] = a[2] - b[2];
		return res;
	};
};

template <class A, class B>
struct MULTIPLICATION
{
    static inline int* eval(int x[]) {
    	printf("Multiplication\n");
    	int* a = A::eval(x);
    	int* b = B::eval(x);
    	int* res = new int[3];
        res[0] = a[0] * b[0];
    	res[1] = a[1] * b[1];
    	res[2] = a[2] * b[2];
    	return res;
	};
};

template<class A, class B>
struct DIVISION
{
	static inline int* eval(int x[]) {
		int* a = A::eval(x);
		int* b = B::eval(x);
		int* res = new int[3];

		if (b[0]>0 || b[0]<0)
		{
			res[0] = a[0] / b[0];
			res[1] = a[1] / b[1];
			res[2] = a[2] / b[2];
			return res;
		}
		else{
			throw std::overflow_error("Divisor is zero exception");
		}
	};
};




#endif /* INTEXPRPART3_HPP_ */
