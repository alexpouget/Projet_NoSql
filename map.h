#include <stdio.h>
#include <stdlib.h>

typedef struct s_hashmap_entry{
    char* key;
    void* value;
    struct s_hashmap_entry* next;
}t_hashmap_entry;

typedef struct s_hashmap{
    double load_factor;//taux de remplissage
    double growth_factor;//taux d'expansion lorsque remplissage atteints
    unsigned int initial_slot;//taille initiale du tableau
    unsigned int slots;//taille actuelle du tableau
    unsigned int size;//nombre d'entrée dans la map
    t_hashmap_entry ** entries;
}t_hashmap;

typedef struct s_list_chain
{
    t_hashmap* value;
    struct s_list_chain* next;
} t_list_chain;

typedef struct s_hashmap_keys{
    char** keys;
    unsigned int length;
}t_hashmap_keys;

t_list_chain* list_chain_create(t_hashmap* value);

t_list_chain* list_chain_append(t_list_chain* list,t_hashmap* value);

void list_display(t_list_chain* list);

t_hashmap* hashmap_create(unsigned int slots, double load_factor, double growth_factor);

t_hashmap_entry* hashmap_entry_create(char* key,void* value);

void hashmap_put(t_hashmap* map, char* key, void* value);

t_hashmap* JSON_parse(char* string);

char* JSON_stringify(t_hashmap* map);

void hashmap_get(t_hashmap* map,char* key);

unsigned int hashmap_hash(char*key,int slots);

t_hashmap_keys* hashmap_keys(t_hashmap* mykey);

unsigned int string_length(char* string);

char* hashmap_get_tostring(t_hashmap* map,char* key);
