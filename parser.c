#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include "hashtable.h"

int m = 100000;
int nWords=0;
Word* table[10000];
Word* empty;
Word* item;

int hash(string v, int m){
    int i, h=v[0];

    for(i=0;v[i] != '\0'; i++){
        h = (h * 251 + v[i]) % m;
    }

    return h;
}



void printMap(){

    for(int i=0; i<nWords;i++){
        printf("Occurrences: %d   Key: %d  Text: %s\n", table[i]->occurrences, table[i]->key, table[i]->text);
    }
}




void fileWordsToKeys(const char *filename){
    setlocale(LC_CTYPE,"pt_PT.UTF-8");

    FILE* file = fopen(filename, "r");
    FILE* codedFile = fopen("lusiadasCodes.txt", "a");
    int count = 1;
    char *line = (char *)malloc(50*sizeof(char));;
    int i;
    char lowerChar;


    while (fgets(line, 1024, file)){

        if(*line == '\0' ||  count == 1){
            
        }else{
            i = 0;
            while (line[i] != '\0') {       
                
                if(isdigit(line[i]) != 0){
                }else{
                    
                    lowerChar = tolower(line[i]);

                    if(lowerChar >= 97 && lowerChar <=99){
                        fprintf(codedFile,"2");
                    }else if(lowerChar >= 100 && lowerChar <=102){
                        fprintf(codedFile,"3");
                    }if(lowerChar >= 103 && lowerChar <=105){
                        fprintf(codedFile,"4");
                    }if(lowerChar >= 106 && lowerChar <=108){
                        fprintf(codedFile,"5");
                    }if((lowerChar >= 109 && lowerChar <=111)){
                        fprintf(codedFile,"6");
                    }if(lowerChar >= 112 && lowerChar <=115){
                        fprintf(codedFile,"7");
                    }if(lowerChar >= 116 && lowerChar <=118){
                        fprintf(codedFile,"8");
                    }if(lowerChar >= 119 && lowerChar <=122){
                        fprintf(codedFile,"9");
                    }
                    if(isspace(line[i]) != 0)
                        fprintf(codedFile," ");

                }
                
                i++;
            }
            fprintf(codedFile,"\n");
        }
        count++; 
    }

    fclose(file);
    fclose(codedFile);
}


void stringLower(char *str){
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

/**
 * 
 * TODO: Populate hashtable
*/
void countWords(const char *filename){
    FILE* file = fopen(filename, "r");
    int count = 1;
    int nTasks=0, lastID=0;
    char line[1024];
    

    while (fgets(line, 1024, file)){
        char *tmp = strdup(line);
        char *tok = tmp, *end = tmp;

        if(isdigit(*tok) != 0){

        }else{
            while (tok != NULL && *tok != '\0' && tok != "\n") {
                strsep(&end, " \n");
                stringLower(tok);

                //printf("nWords: %d  Occurrences: %d   Key: %d  Text: %s\n",nWords, new.occurrences, new.key, new.text);
                printf("%d - %s\n",count, tok);
                
                tok = end;
                count++;
            }
        
        
        }

       
        free(tmp);
        count++; // and delete this too at your own risk
    }

    

    fclose(file);

    //printMap();
 
}




int main(){
    //fileWordsToKeys("lusiadasClean.txt");
    countWords("test.txt");

    return 0;
}