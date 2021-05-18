#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <locale.h>


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


int main(){
    fileWordsToKeys("lusiadasClean.txt");
    return 0;
}