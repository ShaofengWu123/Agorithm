#include <stdio.h>
#include <stdlib.h>
//#include "SString.h"
#include "HString.h"

int main(){
	/*SString S;
	SString T;
	SString A;
	SString B;*/
	HString S,T,B,A;
	int next[INITIAL_SIZE];
	char* s = "abbaba";
	char* t = "a";
	char* a = "AA";
	//SStrAssign(S, s);
	//SStrAssign(T, t);
	//SStrAssign(A, a);
	/*SStrLength(T);
	SStrPrint(S);
	SStrPrint(T);
	next1(next,T);
	KMP_SString(S, T,5,next);*/
	//StrCompare(S,T);
	//StrCompare(A,T);
	//SStrConcat(S,S,A);
	//Replace_SString(S,T,A);
	//SStrPrint(S);

	HStrAssign(&S,s);
	HStrAssign(&T,t);
	HStrAssign(&B,"");
	HStrAssign(&A, a);
	//HStrPrint(S); HStrPrint(T);
	//next3_hstr(next,T);
    //KMP_HString(S,T,1,next);
	HStrConcat(&B,S,T);
	HStrPrint(B);
	Replace_HString(&S,T,A);
	HStrPrint(S);
	return 0;
}