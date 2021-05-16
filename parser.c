#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <ctype.h>

void fileWordsToKeys(const char *filename){
    FILE* file = fopen(filename, "r");
    int count = 1;
    char line[1024];
    int i;
    char lowerChar;

    while (fgets(line, 1024, file)){
        char *tmp = strdup(line);
        char *tok = tmp, *end = tmp;

        // while (tok != NULL) {
        //     strsep(&end, " \n");
            //printf("%d - %s\n",count, tok);
            
            //if(strcmp(tok, "As") == 0)
          
                
            if(line == '\0' ||  count == 1){
                //printf("ignored\n");
                
                

            }else{
                i = 0;
                while (line[i] != '\0') {       
                    
                    if(isdigit(line[i]) != 0){
                        //printf("ignored number %c", line[i]); 
                        if(line[i+1] == '\0') 
                            printf("\n");
                    }else{
                        
                        lowerChar = tolower(line[i]);

                        if(lowerChar >= 97 && lowerChar <=99){
                            printf("2");
                        }else if(lowerChar >= 100 && lowerChar <=102){
                            printf("3");
                        }if(lowerChar >= 103 && lowerChar <=105){
                            printf("4");
                        }if(lowerChar >= 106 && lowerChar <=108){
                            printf("5");
                        }if(lowerChar >= 109 && lowerChar <=111){
                            printf("6");
                        }if(lowerChar >= 112 && lowerChar <=115){
                            printf("7");
                        }if(lowerChar >= 116 && lowerChar <=118){
                            printf("8");
                        }if(lowerChar >= 119 && lowerChar <=122){
                            printf("9");
                        }
                        if(isspace(line[i]) != 0)
                            printf(" ");

                        // if(isspace(line[i]) != 0)
                        // printf("%d  --->  %c \n", i, line[i]);
                    }
                   
                   
                   
                    i++;
                }
                printf("\n");
            }


            // tok = end;
            // count++;
        // }

      
        free(tmp);
        count++; 
    }

    fclose(file);
}


int main(){

    fileWordsToKeys("test.txt");
  

    return 0;
}