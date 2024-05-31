//============================================================================
// Name        : Fibonacci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

unsigned int fibonacci(unsigned int n){
	if (n==0||n==1){
		return n;
	}else{
		return fibonacci(n-2)+fibonacci(n-1);
	}
}

int main(void) {

		for(unsigned int n=0;n<=25;n++){
		cout<<"fibonacci("<<n<<") "<<fibonacci(n)<<endl;
	}

	return 0;
}
