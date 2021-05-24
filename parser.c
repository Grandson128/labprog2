#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include "hashtable.h"
#include "hashtable.c"
#include <unistd.h>


#define m 6449

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
            while ((int)line[i] != '\0') {       
                
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
                    }else if(isspace(line[i]) != 0 || (lowerChar < 97 && lowerChar > 122)){
                        fprintf(codedFile," ");
                    }

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
                //stringLower(tok);

                //printf("nWords: %d  Occurrences: %d   Key: %d  Text: %s\n",nWords, new.occurrences, new.key, new.text);
                //printf("õ ---> %d", 'õ');
                //tok[strcspn(tok, "\n")] = 0;
                printf("%d - %s \n",count, tok);
                



                tok = end;
                count++;
            }
        
        
        }

       
        free(tmp);
        
    }

    

    fclose(file); 
}


void generateMap(const char *wordsFileName, const char *codesFileName){
    FILE* wordsFile = fopen(wordsFileName, "r");
    FILE* codesFile = fopen(codesFileName, "r");


    char *words = (char *)malloc(254*sizeof(char));
    char *codes = (char *)malloc(254*sizeof(char)); 

    int count = 1;
   
    
    while (fgets(words, 1024, wordsFile) && fgets(codes, 1024, codesFile)){
        char *wordsTmp = strdup(words);
        char *codesTmp = strdup(codes);

        char *wordsTok = wordsTmp, *wordsEnd = wordsTmp;
        char *codesTok = codesTmp, *codesEnd = codesTmp;


        while ((wordsTok != NULL && *wordsTok != '\0') && (*codesTok != '\0' && codesTok != NULL)) {
            
            //printf("%d --> word: %s code: %s", count, wordsTok, codesTok);

            if((strcmp(wordsTok,"\n") != 0) && (strcmp(codesTok,"\n") != 0)){
                strsep(&wordsEnd, ";");
                strsep(&codesEnd, ";");

                if((strchr(wordsTok,'\n') != NULL && strlen(wordsTok) == 2) || (strchr(wordsTok,';') != NULL && strlen(wordsTok) == 1) || (strchr(codesTok,'\n') != NULL && strlen(codesTok) == 2) || (strchr(codesTok,';') != NULL && strlen(codesTok) == 1) || strlen(wordsTok) == 0 || strlen(codesTok) == 0){
                   //printf("ignore\n");
                }else{
                    
                    if(strchr(wordsTok,'\n') != NULL){
                        wordsTok[strcspn(wordsTok, "\n")] = 0;
                    }
                    if(strchr(codesTok,'\n') != NULL){
                        codesTok[strcspn(codesTok, "\n")] = 0;
                    }

                    //printf("%d - %s -----> %s\n",count, wordsTok, codesTok);

                    newWord = createWord(strdup(codesTok), strdup(wordsTok));
                    //printf("WORD STRUCT: %s --> %s --> %d \n",newWord->code, newWord->text, hash(codesTok, 20));
                    // printf("%d ---> ", hash(codesTok, m));
                    // printf("%s\n", codesTok);
                    // printf("%s\n", newWord->text);
                    //printf("%d -> HASH: %d -> %s\n", count, hash(codesTok, m), wordsTok);
                    
                    insertWordInList(map[hash(codesTok, m)], newWord);

                }


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

    //fileWordsToKeys("words/lusiadasCleanToCode.txt");
    //countWords("words/test.txt");
    for(int i =0; i<m; i++){
        map[i] = createList();
    }

    generateMap("words/bigWords.txt","words/bigCodes.txt");

    printf("\n\n");
    for(int i =0; i<m; i++){
        printWordList(map[i]);
    }

    return 0;
}