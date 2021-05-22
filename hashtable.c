#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

int MAX_SIZE=254;

List createList(){
    List aux;
    aux = (List)malloc(sizeof(Node));

    if (aux != NULL) {
        aux->next = NULL;
        aux->word = NULL;
    }
    else {
        printf("No memory available to allocate list");
    }
    return aux;
}


Word *createWord(char *wordCode, char *wordText){
    Word *new = (Word *)malloc(sizeof(Word));

    new->code = (char *)malloc(MAX_SIZE*sizeof(char)); 
    new->code = wordCode;

    new->text = (char *)malloc(MAX_SIZE*sizeof(char)); 
    new->text = wordText;

    new->occurrences = 0;

    return new;
}

Word *searchList(List list, char *text){
    int occurrences;
    List previous = list;
    List current = list->next;

    if(current != NULL){
        if(current->word != NULL){
            while ((current) != NULL && strcmp(current->word->text, text) != 0 ){
                previous = current;
                current = (current)->next;
            }

            if ((current) != NULL && current->word != NULL && strcmp(current->word->text, text) != 0 ){
                current = NULL;
                /* Se elemento não encontrado*/
                return NULL;
            }
        }

    }else{
        return NULL;

    }

    return current->word;
}


void deleteWord(List list, char *text){
    List previous = list;
    List current = list->next;

    if (current != NULL && strcmp(current->word->text, text) == 0){
        previous->next = current->next;
        free(current);
        return;
    }else{

        while ((current) != NULL && strcmp(current->word->text, text) != 0 ){
            previous = current;
            current = (current)->next;
        }

        if(current == NULL){
            return;
        }else{
            previous->next = current->next;
            free(current);
        }
    }
}


void insertWordInList (List list, Word *word){
    List previous = list;
    List current = list->next;
    List new = (List)malloc(sizeof(Node));

    Word *aux = searchList(list, word->text);
    
    if(aux == NULL){
        new->word = word;
        new->word->occurrences += 1;

        if(current == NULL){
            new->next = current;
            previous->next = new;
        }else if(current != NULL && current->word->code!=NULL){
            
            while (list->word->occurrences < current->word->occurrences && current->next!=NULL){
                previous = current;
                current = current->next;
            }
            if(list->word->occurrences > current->word->occurrences){
                previous->next = new;
                new->next = current;
            }else if(list->word->occurrences < current->word->occurrences){
                new->next = current->next;
                current->next = new;
            }
        }

    }else{

        new->word->occurrences = aux->occurrences + 1;
        new->word->code = word->code;
        new->word->text = word->text;
        
        deleteWord(list, aux->text); //remove word with old occurrences 

        /*add word with new occurrences*/
        if(current == NULL){
            new->next = current;
            previous->next = new;
        }else if(current != NULL && current->word->code!=NULL){
            
            while (list->word->occurrences < current->word->occurrences && current->next!=NULL){
                previous = current;
                current = current->next;
            }
            if(list->word->occurrences > current->word->occurrences){
                previous->next = new;
                new->next = current;
            }else if(list->word->occurrences < current->word->occurrences){
                new->next = current->next;
                current->next = new;
            }
        }
    }
}


void printWordList(List list){
    List aux = createList();

    if(list->next != NULL){
        aux = list->next;
    }else{
        printf("Empty list\n");
    }

    while (aux != NULL && aux->word != NULL){
        printf("--- Occurrences:%d ---> Key:%s ---> Text:%s ---\n", aux->word->occurrences, aux->word->code, aux->word->text);
        aux = aux->next;
    }
}



int hash(char *v, int m){
    int i, h=v[0];

    for(i=0;v[i] != '\0'; i++){
        h = (h * 7 + v[i]) % m;
    }
    return h;
}








void printMap(){

    // for(int i=0; i<nWords;i++){
    //     //printf("Occurrences: %d   Key: %d  Text: %s\n", table[i]->occurrences, table[i]->key, table[i]->text);
    // }
}


