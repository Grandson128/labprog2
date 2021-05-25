#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

/*
we calculated approximately 10330 words
10330/10 = 1033
10330/5 = 2066
avg=1549.5  
1549 is a prime number so we choose it
*/
// #define m 1549

// Word *newWord;
// List map[m];
// List test;



void fileWordsToKeys(const char *filename){
    setlocale(LC_CTYPE,"pt_PT.UTF-8");

    FILE* file = fopen(filename, "r");
    FILE* codedFile = fopen("lusiadasCodes.txt", "a");
    int count = 1;
    char *line = (char *)malloc(50*sizeof(char));
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
        if(isdigit(*tok) != 0){

        }else{
            while (tok != NULL && *tok != '\0' && tok != "\n") {
                strsep(&end, " \n");
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
                    newWord = createWord(strdup(codesTok), strdup(wordsTok));
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



// int main(){
//     int count=0;
//     //fileWordsToKeys("words/lusiadasCleanToCode.txt");
//     //countWords("words/test.txt");
//     for(int i =0; i<m; i++){
//         map[i] = createList();
//     }

//     generateMap("words/bigWords.txt","words/bigCodes.txt");

//     printf("\n\n");
//     for(int i =0; i<m; i++){
//         printWordList(map[i]);
//     }

//     // for(int i =0; i<m; i++){

//     //     List aux = createList();

//     //     if(map[i]->next != NULL){
//     //         aux = map[i]->next;
//     //     }else{
//     //         //printf("Empty list\n");
//     //     }

//     //     while (aux != NULL && aux->word != NULL){
//     //         count++;
//     //         aux = aux->next;
//     //     }

//     // }


//     // printf("\n\n Words: %d\n", nWords);
//     // printf("\n\n Unique Words: %d\n", count);

//     return 0;
// }