#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "str.h"

int main(int argc, char** argv){
   /*t_hashmap* map=hashmap_create(100,0.7,2.1);
    t_hashmap_entry* entry= hashmap_entry_create("bonjour","hashmap");
    hashmap_put(map,entry->key,entry->value);
    hashmap_put(map,"a","bonjour");
    hashmap_put(map,"rate","15");

    t_hashmap* map2=hashmap_create(100,0.7,2.1);
    t_hashmap_entry* entry2= hashmap_entry_create("title","hashmap");
    hashmap_put(map2,entry2->key,entry2->value);
    hashmap_put(map2,"rate","12");
    //t_list_chain* list =list_chain_create(map);
    //list = list_chain_append(list,map2);
    //list_display(list);
    //
    //t_hashmap* map2=hashmap_create(100,0.7,2.1);
    char * string = "{ name : 'Gabriel', rate : 12, group :'AL2'}";
    t_hashmap* map2 = JSON_parse(string);
    hashmap_get(map2,"name");
    hashmap_get(map2,"rate");
    //char* s = hashmap_get_tostring(map2,"name");
//    printf("%s ",s);
    //t_hashmap_keys* mykey = hashmap_keys(map2);
    //unsigned int i;
    //for(i=0;i<mykey->length;i++){
    //char* key = mykey->keys[i];
    //printf("%s",key);
    //}
    //s = hashmap_get_tostring(map2,"name");
    //printf("%s ",s);
    //printf("%s ",tmp);
    //printf("-%u",string_length("retard"));
    char* e = JSON_stringify(map2);
    printf("%s",e);*/
	//Program start
	printf("\n MySqlLite : \n");
	
	
	//Arg count check
	if(2 > argc)
	{
		//Printing the error message with the standard error output
		printf("erreur"); 
		return 0;
	}
	
	//if insert 
	char* commande = extract_commande(argv[2]);

	if(compare(commande,"insert")){
		char * string = malloc((string_length(argv[2])-8)*sizeof(char));
		int i = 9;
		int j = 0;
		while(argv[2][i] != '\0'){
			string[j] = argv[2][i];
			i++;
			j++;
		}
		string[j] = '\0';
		t_hashmap* map2 = JSON_parse(string);
		char* e = JSON_stringify(map2);
		printf("%s",e);
	}
	


    return 0;
}
