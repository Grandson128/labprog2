
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct node* List;
typedef struct word{
    int occurrences;
    char *code;
    char *text;
} Word;


typedef struct node{
    Word *word;
    List next;
}Node;



// typedef struct{
//     int key;
//     List *wordList;
// } Dictionary;







#endif