#include <ctype.h>
#include "set.h"
//#include <stdio.h>

void builder(char *set, char *inString) {
	int i;

	for(i=0; inString[i] != '\0'; i++) {
		//printf("%c  >", inString[i]);
		if(isprint(inString[i])) {
			if(!isspace(inString[i])) {
				if(!ismember(set, inString[i])) {
					addElement(set, inString[i]);
					//printf("%c\n", set[i]);
				}
			}
		}	
	}
}
