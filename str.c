#include "str.h"

char* extract_commande(char* com){
	int i;
	char* result;
    if(com[0]=='-'){
        i = 1;
        while(com[i]!='-'){
            i++;
        }
    result = malloc((i+1)*sizeof(char));
        i = 0;
        while(com[i+1]!='-'){
            result[i] = com[i+1];
            i++;
        }
	result[i] = '\0';
    }
    return result;
}

int compare(char* string,char* commande){
    int equals = 1;
    int i=0;	
    while(string[i]!='\0'){
        if(string[i]!=commande[i]){
            equals = 0;
        }
	i++;
    }
    return equals;
}
