#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "set.h"

/*-----------------------------------------------------*/ 
// Spencer Ross											|
// CSE 215				Synopsis:						|
//														|
// Class: Daily			This program asks the user to   |
// January 30, 2018		create two sets of any print    |
// 						character and prints those      |
// PROGRAM 1			sets out, then also prints out  |
//						the cardinality of sets A & B,  |
//						their Union, their intersection |
//						and the compiment of A from B.  |
//______________________________________________________|


int main(void)
{
	char A[LIMIT] = "";		//LIMIT = 120
	char B[LIMIT] = "";
	char buffer[LIMIT] = "";
	int i, j=0, a, b;

	printf("Hello. Put in some stuff into A and hit ENTER:\n>");
	fgets(buffer, LIMIT, stdin);		//take input
	//printf("here\n") ; //debug
	builder(A, buffer);			//get input into A
	//printf("here again\n") ;	//debug
	printf("Put in some stuff into B and hit ENTER:\n>");
	fgets(buffer, LIMIT, stdin);
	
	builder(B, buffer);			//get input into B

	//PRINT A
	printf("Set A = {");
	for(i=0; i<strlen(A); i++) {
		printf("%c,", A[i]);		//cycle through A/ format
	}
	
	printf("}\n");

	//PRINT B
	printf("Set B = {");
	for(i=0; B[i]!='\0'; i++) { 		//loop B for format
		printf("%c,", B[i]);
	}

	printf("}\n");
	a = strlen(A);
	b = strlen(B);

	//PRINT |A|
	printf("|A| = %d\n", a);	//print #of elements
	//PRINT |B|
	printf("|B| = %d\n", b);	//same for B
	

	//PRINT AUB
	char combo[LIMIT] = "";		//temp string

	for(i=0; i<a; i++) {		//dump all of A...
		combo[j++] = A[i];		//...into combo
	}

	for(i=0; i<b; i++) {
		if(!ismember(A, B[i])) {	//If member of B !in A
			combo[j++] = B[i];	//add it to combo
		}
	}

	combo[j] = '\0';
	printf("AUB = {");

	for(i=0; i<strlen(combo); i++) {	//printing new Union
		printf("%c,", combo[i]);	//AKA combo
	}

	printf("}\n");

	//PRINT A/\B
	combo[0] = '\0';			//reset combo
	for(i=0; i<a; i++) {
		if(ismember(B, A[i])) {
			addElement(combo, A[i]);
		}
	}

	printf("A^B = {");

	for(i=0; i<strlen(combo); i++) {        //printing new the !Union
		printf("%c,", combo[i]);        
	}

	printf("}\n");

	//PRINT A\B
	combo[i] = '\0';

	for(i=0; i<a; i++) {
		if(ismember(B, A[i]) == FALSE) {
			addElement(combo, A[i]);
		}
	}

	printf("A-B = {");

	for(i=0; i<strlen(combo); i++) {        //printing new the complementA
		printf("%c,", combo[i]);
	}

	printf("}\n");
	return FALSE;
}
