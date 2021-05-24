#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"
#include <unistd.h>

int MAX_SIZE=254;
int nWords=0;
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
            
            while (current != NULL){
                
                if(current->word != NULL && strcmp(current->word->text, text) == 0){
                    return current->word;
                }else{
                    previous = current;
                    current = current->next;
                }
 
            }
            
            if (current != NULL && current->word != NULL && strcmp(current->word->text, text) != 0 ){
                /* Se elemento não encontrado*/
                return NULL;
            }
        }

    }else{
        return NULL;
    }
    
    if(current == NULL){
        return NULL;
    }
    else if(current->word != NULL){
        return current->word;
    }
    else{
        return NULL;
    }
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
        //printf("\n%s --> %d\n", word->text, word->occurrences);
        //printf("\nSEARCHED: %s --> %d\n", aux->text, aux->occurrences);
        //printf("ARGUMENT: %s --> %d\n", word->text, word->occurrences);
        if(word != NULL){
            new->word = word;
            new->word->occurrences += 1;
        }

        if(current == NULL){
            new->next = current;
            previous->next = new;
        }else if(current != NULL && current->word != NULL){
            
            while (current != NULL && current->next!=NULL && word->occurrences < current->word->occurrences){
                previous = current;
                current = current->next;
            }
            if(word->occurrences > current->word->occurrences){
                previous->next = new;
                new->next = current;
            }else if(word->occurrences < current->word->occurrences){
                new->next = current->next;
                current->next = new;
            }else if(word->occurrences == current->word->occurrences){
                new->next = current->next;
                current->next = new;
            }
        }

    }else{
        word->occurrences = aux->occurrences;

        //printf("\nSEARCHED: %s --> %d\n", aux->text, aux->occurrences);
        //printf("\nARGUMENT: %s --> %d\n", word->text, word->occurrences);
        deleteWord(list, aux->text); //remove word with old occurrences 

        insertWordInList(list, word);

        /*add word with new occurrences*/
        // if(current == NULL){
        //     new->next = current;
        //     previous->next = new;
        // }else if(current != NULL && current->word->code!=NULL){
            
        //     while (list->word->occurrences < current->word->occurrences && current->next!=NULL){
        //         previous = current;
        //         current = current->next;
        //     }
        //     if(list->word->occurrences > current->word->occurrences){
        //         previous->next = new;
        //         new->next = current;
        //     }else if(list->word->occurrences < current->word->occurrences){
        //         new->next = current->next;
        //         current->next = new;
        //     }
        // }
    }
}


void printWordList(List list){
    List aux = createList();

    if(list->next != NULL){
        aux = list->next;
    }else{
        //printf("Empty list\n");
    }

    while (aux != NULL && aux->word != NULL){
        printf("Occurrences:%d\n", aux->word->occurrences);
        printf("Key:%s\n", aux->word->code);
        printf("Text:%s\n", aux->word->text);
        printf("Text Length: %ld\n", strlen(aux->word->text));
        nWords += aux->word->occurrences;
        printf("\n");
        
        aux = aux->next;
    }
}



// int hash(char *v, int mNumber){
//     int i, h=v[0];
    
//     for(i=0;v[i] != '\0'; i++){
//         h = (h * 7 + v[i]) % mNumber;
//     }
//     return h;
// }



int hash(char *v, int mNumber){
    int i, h=v[0];

    for(i=0;i<=5; i++){
        if(v[i] != '\0'){
            h = (h * 7 + v[i]) % mNumber;
        }else{
            break;
        }
    }
    return h;
}




void printMap(){

    // for(int i=0; i<nWords;i++){
    //     //printf("Occurrences: %d   Key: %d  Text: %s\n", table[i]->occurrences, table[i]->key, table[i]->text);
    // }
}


