
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct node* List;
typedef char *String;
typedef struct node{
    int occurrences;
    String code;
    String text;
    List next;
}Node;



// typedef struct{
//     int key;
//     List *wordList;
// } Dictionary;







#endif