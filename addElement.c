#include "set.h"

void addElement(char *set, char newChar)
{
	int i;

	for(i=0; set[i] != '\0'; i++); 

	set[i]	 = newChar;
	set[++i] = '\0';
}
