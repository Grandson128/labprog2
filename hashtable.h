
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct node* List;

typedef struct node{
    int info;
    List next;
}Node;


typedef char *string;

typedef struct{
    int key;
    int occurrences;
    string text;
} Word;







#endif