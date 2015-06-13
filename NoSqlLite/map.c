#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int main(){
   /*t_hashmap* map=hashmap_create(100,0.7,2.1);
    t_hashmap_entry* entry= hashmap_entry_create("bonjour","hashmap");
    hashmap_put(map,entry->key,entry->value);
    hashmap_put(map,"a","bonjour");
    hashmap_put(map,"rate","15");

    t_hashmap* map2=hashmap_create(100,0.7,2.1);
    t_hashmap_entry* entry2= hashmap_entry_create("title","hashmap");
    hashmap_put(map2,entry2->key,entry2->value);
    hashmap_put(map2,"rate","12");*/
    //t_list_chain* list =list_chain_create(map);
    //list = list_chain_append(list,map2);
    //list_display(list);
    JSON_parse("{ name : gabriel }");
    /*char * string = "{ name : gabriel }";
    printf("%c",string[17]);
    printf("%s",string);
    int i = 0;
        while(i<17){
            if((string[i]>='a' && string[i]<='z' )||(string[i]>='A' && string[i]<='Z')){
                printf("%c",string[i]);
            }
            i++;
        }*/
    return 0;
}

t_hashmap* hashmap_create(unsigned int slots, double load_factor, double growth_factor){
    t_hashmap* map = (t_hashmap*)malloc(sizeof(t_hashmap));
    map->initial_slot = slots;
    map->load_factor = load_factor;
    map->growth_factor = growth_factor;
    map->slots=slots;
    map->size=0;
    map->entries=(t_hashmap_entry**)malloc(sizeof(t_hashmap_entry*)*slots);
    int i;
    for(i=0;i<slots;i++){
        map->entries[i]=NULL;
    }
    return map;
}

t_list_chain* list_chain_create(t_hashmap* value)
{
	t_list_chain* list = (t_list_chain*)malloc(sizeof(t_list_chain));
	list->value = value;
	list->next = NULL;
	return list;
}

void list_display(t_list_chain* list)
{
	if (NULL != list)
	{
		for (; NULL != list->next; list = list->next)
		{
			 hashmap_get(list->value,"rate");
		}
		hashmap_get(list->value,"rate");
	}
}

t_hashmap_entry* hashmap_entry_create(char* key,void* value){
    t_hashmap_entry* entry = (t_hashmap_entry*)malloc(sizeof(t_hashmap_entry));
    entry->key=key;
    entry->value=value;
    entry->next=NULL;
    return entry;
}

void hashmap_put(t_hashmap* map, char* key, void* value){
    if(map->size >= map->slots*map->load_factor){
        map->slots = (map->slots*map->growth_factor);
        map = (t_hashmap_entry**)malloc(sizeof(t_hashmap_entry*)*map->slots);

    }
    if(map->entries[hashmap_hash(key,map->slots)]==key){
        map->entries[hashmap_hash(key,map->slots)]->value=value;
    }
    else{
        t_hashmap_entry* newhash = hashmap_entry_create(key,value);
        if(map->entries[hashmap_hash(key,map->slots)]==NULL){
            map->entries[hashmap_hash(key,map->slots)] = newhash;
        }
        else{
            map->entries[hashmap_hash(key,map->slots)]->next = newhash;
        }
    }
}

void JSON_parse(char* string){
    t_hashmap* map=hashmap_create(100,0.7,2.1);

    char* key=NULL;
    char* value;
    char* tmp;
    int i;
        while(string[i] != ':' && string[i] != ',' && string[i] != '}' ){
            if((string[i]>='a' && string[i]<='z' )||(string[i]>='A' && string[i]<='Z')){
                tmp += string[i];
            }
            i++;
        }
        if(key==NULL){
            key = tmp;
            tmp = NULL;
            printf("%s",key);
        }else{
            value = tmp;
            hashmap_put(map,key,value);
            t_list_chain* list =list_chain_create(map);
            list_display(list);
            key = NULL;
            value = NULL;
            tmp = NULL;
        }
}


t_list_chain* list_chain_append(t_list_chain* list,t_hashmap* value)
{
	t_list_chain* new_node = list_chain_create(value);

	if (NULL == list)
	{
		return new_node;
	}

	t_list_chain* tmp;
	for (tmp = list; NULL != tmp->next; tmp = tmp->next);
	tmp->next = new_node;

	return list;
}

void hashmap_get(t_hashmap* map,char* key){
    printf("cle : %s valeur : %s ",map->entries[hashmap_hash(key,map->slots)]->key,map->entries[hashmap_hash(key,map->slots)]->value);
}

unsigned int hashmap_hash(char*key,int slots){
    unsigned int code=0;
    unsigned int i=0;
    for(;i<strlen(key);i++){
        code += (unsigned int)key[i];
    }
    return (unsigned int)code%slots;
}
