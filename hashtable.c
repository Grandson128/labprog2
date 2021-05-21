#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

List createList(){
    List aux;
    aux = (List)malloc(sizeof(Node));

    if (aux != NULL) {
        aux->next = NULL;
        aux->occurrences=0;
        aux->code=NULL;
        aux->text=NULL;
    }
    else {
        printf("No memory available to allocate list");
    }
    return aux;
}


void insertWordInList (List list, int occurrences, String code, String text){
    List previous = list;
    List current = list->next;
    List new = (List)malloc(sizeof(Node));

    new->occurrences = occurrences;
    new->code = code;
    new->text = text;
    
    if(current == NULL){
        new->next = current;
        previous->next = new;
    }else if(current != NULL && current->code!=NULL){
        
        while (list->occurrences < current->occurrences && current->next!=NULL){
            previous = current;
            current = current->next;
        }
        if(list->occurrences > current->occurrences){
            previous->next = new;
            new->next = current;
        }else if(list->occurrences < current->occurrences){
            new->next = current->next;
            current->next = new;
        }
    }
}













int hash(String v, int m){
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


