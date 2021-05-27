#define m 1549

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.c"

Word *newWord;
List map[m];
List test;
char *labelCode;

#include "parser.c"


#include <gtk/gtk.h>
#include <sys/time.h>

GtkWidget *window;
GtkWidget *vbox;
GtkWidget *image; //por fazer, tava a pensar num logo da fcup
GtkWidget *label;
GtkWidget *label2;
GtkWidget *checkbutton;
GtkWidget *sugestoes; //spot para as caixinhas, tira que ser disabled se t9 unchecked
GtkWidget *grid;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *button3;
GtkWidget *button4;
GtkWidget *button5;
GtkWidget *button6;
GtkWidget *button7;
GtkWidget *button8;
GtkWidget *button9;
GtkWidget *buttonNext;
GtkWidget *button0;
GtkWidget *buttonDelete;
GTimeZone *utc;
long last_click;
int count_click;
int flag = -9;
GString str;
int clickCount=0;

int t9Active;

List handleNext;
List handleNextRoot;



void printRecomendedWords(void){
    List aux = createList();
    
    if(map[hash(labelCode, m)]->next != NULL){
        aux = map[hash(labelCode, m)]->next;
    }else{
        //printf("Empty list\n");
    }

    while (aux != NULL && aux->word != NULL){
        if(strlen(labelCode) <= strlen(aux->word->code))
            printf("%s |", aux->word->text);
        
        aux = aux->next;
    }
    printf("\n");


}


// 1.!?
void button1_clicked(GtkWidget *widget, gpointer data, GdkEventButton *event){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        //strcat(labelCode, "2", 1);
        //g_print("%s\n", labelCode);\nprintRecomendedWords();

    }else{

        if((now-last_click) > 900000 || flag != 1) {
        
            str2=".";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == '.'){
                str1[strlen(str1)-1] = '!';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == '!'){
                str1[strlen(str1)-1] = '?';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == '?'){
                str1[strlen(str1)-1] = '.';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }

    }

    

    last_click = now;
    flag = 1;
}

void button2_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "2");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{

        if((now-last_click) > 900000 || flag != 2) {
            str2="a";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'a'){
                str1[strlen(str1)-1] = 'b';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'b'){
                str1[strlen(str1)-1] = 'c';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'c'){
                str1[strlen(str1)-1] = 'a';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }

    last_click = now;
    flag = 2;
}

void button3_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "3");
        g_print("%s\n", labelCode);
        printRecomendedWords();


    }else{
        if((now-last_click) > 900000 || flag != 3) {
            str2="d";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'd'){
                str1[strlen(str1)-1] = 'e';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'e'){
                str1[strlen(str1)-1] = 'f';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'f'){
                str1[strlen(str1)-1] = 'd';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }
    last_click = now;
    flag = 3;
}

void button4_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "4");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 4) {
            str2="g";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'g'){
                str1[strlen(str1)-1] = 'h';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'h'){
                str1[strlen(str1)-1] = 'i';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'i'){
                str1[strlen(str1)-1] = 'g';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }
    last_click = now;
    flag = 4;
}

void button5_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "5");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 5) {
            str2="j";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'j'){
                str1[strlen(str1)-1] = 'k';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'k'){
                str1[strlen(str1)-1] = 'l';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'l'){
                str1[strlen(str1)-1] = 'j';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }
    
    last_click = now;
    flag = 5;
}

void button6_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "6");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 6) {
            str2="m";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'm'){
                str1[strlen(str1)-1] = 'n';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'n'){
                str1[strlen(str1)-1] = 'o';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'o'){
                str1[strlen(str1)-1] = 'm';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }    
    
    last_click = now;
    flag = 6;
}

void button7_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "7");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 7) {
            str2="p";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'p'){
                str1[strlen(str1)-1] = 'q';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'q'){
                str1[strlen(str1)-1] = 'r';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'r'){
                str1[strlen(str1)-1] = 's';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 's'){
                str1[strlen(str1)-1] = 'p';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }
    
    last_click = now;
    flag = 7;
}

void button8_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "8");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 8) {
            str2="t";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 't'){
                str1[strlen(str1)-1] = 'u';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'u'){
                str1[strlen(str1)-1] = 'v';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'v'){
                str1[strlen(str1)-1] = 't';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
        
    }
    last_click = now;
    flag = 8;
}

void button9_clicked(GtkWidget *widget, gpointer data){

    struct timeval temp;
    gettimeofday(&temp, NULL);
    long now = temp.tv_sec * (int)1e6 + temp.tv_usec;

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    gchar *str2;

    char last_char = str1[strlen(str1)-1];
    count_click = 0;

    if(t9Active == 1){
        strcat(labelCode, "9");
        g_print("%s\n", labelCode);
        printRecomendedWords();

    }else{
        if((now-last_click) > 900000 || flag != 9) {
            str2="w";
            strcat(str1,str2);
            gtk_label_set_text((GtkLabel*)label,str1);
        }
        else {
            if(last_char == 'w'){
                str1[strlen(str1)-1] = 'y';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'y'){
                str1[strlen(str1)-1] = 'x';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'x'){
                str1[strlen(str1)-1] = 'z';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
            else if(last_char == 'z'){
                str1[strlen(str1)-1] = 'w';
                gtk_label_set_text((GtkLabel*)label,str1);
            }
        }
    }

    last_click = now;
    flag = 9;
}

void buttonNext_clicked(GtkWidget *widget, gpointer data){
    //gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);
    //gchar *str2 = " ";
    //strcat(str1,str2);
    //gtk_label_set_text((GtkLabel*)label,str1);
    

    if (flag != -1 && strlen(labelCode) > 0){
        if(map[hash(labelCode, m)]->next != NULL){
            handleNextRoot = map[hash(labelCode, m)]->next;
            handleNext = handleNextRoot;
            if(strlen(labelCode) <= strlen(handleNext->word->code)) {
                printf("SLECTION -> %s\n", handleNext->word->text);
                gtk_label_set_text((GtkLabel*)label2,handleNext->word->text);
            }
        }


    }else{

        if(handleNext != NULL && handleNext->next != NULL && strlen(labelCode) > 0){
            handleNext = handleNext->next;
            if(strlen(labelCode) <= strlen(handleNext->word->code)){
                printf("SLECTION -> %s\n", handleNext->word->text);
                gtk_label_set_text((GtkLabel*)label2,handleNext->word->text);
            }

        }else if(strlen(labelCode) > 0){
            handleNext = handleNextRoot;
            if(strlen(labelCode) <= strlen(handleNext->word->code)){
                printf("SLECTION -> %s\n", handleNext->word->text);
                gtk_label_set_text((GtkLabel*)label2,handleNext->word->text);
            }
                
        }

    }
    

    flag = -1;

}

void button0_clicked(GtkWidget *widget, gpointer data){

    gchar *str1 = (gchar *)gtk_label_get_text((GtkLabel*)label);

    gchar *str2 = " ";

    strcat(str1,str2);

    gtk_label_set_text((GtkLabel*)label,str1);

    if(t9Active == 1){
        labelCode[0] = '\0';
        g_print("%s\n", labelCode);
        
    }

    flag = -2;



}

//eliminar ultimo char
void buttonDelete_clicked(GtkWidget *widget, gpointer data){

    gchar *str = (gchar *)gtk_label_get_text((GtkLabel*)label);

    labelCode[strlen(labelCode)-1] = '\0';
    g_print("%s\n", labelCode);
    

    str[strlen(str)-1] = '\0';
    gtk_label_set_text((GtkLabel*)label,str);
    flag = -3;
}

static void toggled_t9 (GtkToggleButton *toggle_button,gpointer user_data){
    GtkWindow *window = user_data;

    //exemplo para activar e desactivar a smart writing
    if (gtk_toggle_button_get_active (toggle_button)){
        gtk_window_set_title (window, "Smart Writing ON");
        t9Active = 1;
    }
    else{
        gtk_window_set_title (window, "Smart Writing OFF");
        t9Active = 0;
    }


}


GdkPixbuf *create_pixbuf(const gchar * filename) {

    GdkPixbuf *pixbuf;
    GError *error = NULL;
    pixbuf = gdk_pixbuf_new_from_file(filename, &error);

    if (!pixbuf) {
        fprintf(stderr, "%s\n", error->message);
        g_error_free(error);
    }

    return pixbuf;
}






void initMap(){
    for(int i =0; i<m; i++){
        map[i] = createList();
    }
}

void initDictionary(){
    initMap();
    generateMap("words/bigWords.txt","words/bigCodes.txt");

    /* printf("\n\n"); */
    /* for(int i =0; i<m; i++){
        printWordList(map[i]);
    } */
}


//int main(){
    //initDictionary();
    //return 0;
//}


int main(int argc, char* argv[]) {
    labelCode = (char *)malloc(50*sizeof(char));
    
    initDictionary();
    t9Active = 1;

    gtk_init(&argc, &argv);

    window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);
    gtk_window_set_title(GTK_WINDOW(window), "T9");

    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    vbox= gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    label=gtk_label_new("");

    last_click = 0;

    checkbutton=gtk_check_button_new_with_label("Smart writing");
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);

    label2=gtk_label_new("TESTE");

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid),2);
    gtk_grid_set_column_spacing(GTK_GRID(grid),2);

    button1 = gtk_button_new_with_label("1\n.!?");
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);
    g_signal_connect(G_OBJECT(button1), "clicked",G_CALLBACK(button1_clicked), NULL);

    button2 = gtk_button_new_with_label("2\nabc");
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);
    g_signal_connect(G_OBJECT(button2), "clicked",G_CALLBACK(button2_clicked), NULL);

    button3 = gtk_button_new_with_label("3\ndef");
    gtk_grid_attach(GTK_GRID(grid), button3, 2, 0, 1, 1);
    g_signal_connect(G_OBJECT(button3), "clicked",G_CALLBACK(button3_clicked), NULL);

    button4 = gtk_button_new_with_label("4\nghi");
    gtk_grid_attach(GTK_GRID(grid), button4, 0, 1, 1, 1);
    g_signal_connect(G_OBJECT(button4), "clicked",G_CALLBACK(button4_clicked), NULL);

    button5 = gtk_button_new_with_label("5\njkl");
    gtk_grid_attach(GTK_GRID(grid), button5, 1, 1, 1, 1);
    g_signal_connect(G_OBJECT(button5), "clicked",G_CALLBACK(button5_clicked), NULL);

    button6 = gtk_button_new_with_label("6\nmno");
    gtk_grid_attach(GTK_GRID(grid), button6, 2, 1, 1, 1);
    g_signal_connect(G_OBJECT(button6), "clicked",G_CALLBACK(button6_clicked), NULL);

    button7 = gtk_button_new_with_label("7\npqrs");
    gtk_grid_attach(GTK_GRID(grid), button7, 0, 2, 1, 1);
    g_signal_connect(G_OBJECT(button7), "clicked",G_CALLBACK(button7_clicked), NULL);

    button8 = gtk_button_new_with_label("8\ntuv");
    gtk_grid_attach(GTK_GRID(grid), button8, 1, 2, 1, 1);
    g_signal_connect(G_OBJECT(button8), "clicked",G_CALLBACK(button8_clicked), NULL);

    button9 = gtk_button_new_with_label("9\nwyxz");
    gtk_grid_attach(GTK_GRID(grid), button9, 2, 2, 1, 1);
    g_signal_connect(G_OBJECT(button9), "clicked",G_CALLBACK(button9_clicked), NULL);

    buttonNext = gtk_button_new_with_label("*\nNext");
    gtk_grid_attach(GTK_GRID(grid), buttonNext, 0, 3, 1, 1);
    g_signal_connect(G_OBJECT(buttonNext), "clicked",G_CALLBACK(buttonNext_clicked), NULL);

    button0 = gtk_button_new_with_label("0\nSpace");
    gtk_grid_attach(GTK_GRID(grid), button0, 1, 3, 1, 1);
    g_signal_connect(G_OBJECT(button0), "clicked",G_CALLBACK(button0_clicked), NULL);

    buttonDelete = gtk_button_new_with_label("#\nDelete");
    gtk_grid_attach(GTK_GRID(grid), buttonDelete, 2, 3, 1, 1);
    g_signal_connect(G_OBJECT(buttonDelete), "clicked",G_CALLBACK(buttonDelete_clicked), NULL);


    gtk_box_pack_start(GTK_BOX(vbox),label,TRUE,TRUE,20);
    gtk_box_pack_start(GTK_BOX(vbox),checkbutton,TRUE,TRUE,20);
    gtk_box_pack_start(GTK_BOX(vbox),label2,TRUE,TRUE,20);
    gtk_box_pack_start(GTK_BOX(vbox),grid,TRUE,TRUE,20);


    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect (GTK_TOGGLE_BUTTON (checkbutton), "toggled", G_CALLBACK (toggled_t9), window);


    gtk_widget_show_all(window);

    
    gtk_main();
    return 0;
}

