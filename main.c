#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.c"
#include "parser.c"

//const int m=20;
int nWords=0;
List map[m];

void initMap(){
    for(int i =0; i<20; i++){
        map[i] = createList();
    }
}




int main(){


    initMap();




    return 0;
}
