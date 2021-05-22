#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include "hashtable.h"
#include "hashtable.c"

#define m 20

Word *newWord;

int nWords=0;
List map[m];
List test;



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
    int i=0;

    char line[1024];
    

    while (fgets(line, 1024, file)){
        char *tmp = strdup(line);
        char *tok = tmp, *end = tmp;
        i=0;
        /*
        debugging char by char int value
        while (line[i] != '\0') {       
                if(isdigit(line[i]) != 0){
                }else{
                    printf("õ ---> %d", 'õ');
                    printf("%d - %d\n",count, line[i]);
                }
                i++;
        }
        */


        if(isdigit(*tok) != 0){

        }else{
            while (tok != NULL && *tok != '\0' && tok != "\n") {
                strsep(&end, " \n");
                stringLower(tok);

                //printf("nWords: %d  Occurrences: %d   Key: %d  Text: %s\n",nWords, new.occurrences, new.key, new.text);
                //printf("õ ---> %d", 'õ');
                printf("%d - %s\n",count, tok);
                


                tok = end;
                count++;
            }
        
        
        }

       
        free(tmp);
        count++; // and delete this too at your own risk
    }

    

    fclose(file); 
}


void generateMap(const char *wordsFileName, const char *codesFileName){
    FILE* wordsFile = fopen(wordsFileName, "r");
    FILE* codesFile = fopen(codesFileName, "r");


    char words[1024];
    char codes[1024];

    int count = 1;
   
    
    while (fgets(words, 1024, wordsFile) && fgets(codes, 1024, codesFile)){
        char *wordsTmp = strdup(words);
        char *codesTmp = strdup(codes);

        char *wordsTok = wordsTmp, *wordsEnd = wordsTmp;
        char *codesTok = codesTmp, *codesEnd = codesTmp;


        while (wordsTok != NULL && codesTok != NULL) {
            
            if((*wordsTok != '\0' && wordsTok != "\n") && ( *codesTok != '\0' && codesTok != "\n")){
                strsep(&wordsEnd, " \n");
                strsep(&codesEnd, " \n");

                
                printf("%d - %s  -----> %s ---> hash %d \n",count, wordsTok, codesTok, hash(codesTok, 20));
                
                newWord = createWord(codesTok, wordsTok);

                //printf("WORD STRUCT: %s  -----> %s  \n",newWord->code, newWord->text);


                insertWordInList(map[hash(codesTok, 20)], newWord);


                wordsTok = wordsEnd;
                codesTok = codesEnd;

                count++;
            }
        }
        
        
        

       
        free(wordsTmp);
        free(codesTmp);
        count++; // and delete this too at your own risk
    }

    

    fclose(wordsFile); 
    fclose(codesFile);
}



int main(){

    //fileWordsToKeys("lusiadasClean.txt");
    //countWords("words/test.txt");
    for(int i =0; i<20; i++){
        map[i] = createList();
    }

    printf("\n\n");

    


    generateMap("words/test.txt","words/testCodes.txt");

    return 0;
}