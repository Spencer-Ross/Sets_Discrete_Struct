#include "set.h"

int ismember(char *set, char element) {
	for(int i=0; set[i] != '\0'; i++) {
		if(element == set[i]) {
			return TRUE;
		}
	}	
	
	return FALSE;
}
