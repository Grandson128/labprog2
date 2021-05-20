#include <gtk/gtk.h>
#include <string.h> 

  GtkWidget *window;
  GtkWidget *vbox;

  GtkWidget *image; //por fazer, tava a pensar num logo da fcup
  GtkWidget *label;

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

  GString str;

void button1_clicked(GtkWidget *widget, gpointer data, GdkEventButton *event){
  
  /*
  if(event->type == GDK_TWO_BUTTON_PRESS)
    g_print("doubleckick\n");
    //gtk_label_set_text((GtkLabel*)label,".");
  
  if(event->type == GDK_BUTTON_PRESS)
    g_print("um\n");

    //gtk_label_set_text((GtkLabel*)label,"1");

  
  if(event->type == GDK_TRIPLE_BUTTON_PRESS)
    gtk_label_set_text((GtkLabel*)label,"!");
  if(event->type == GDK_FOURTH_PRESS)
    gtk_label_set_text((GtkLabel*)label,"?");

  GDateTime *now = g_date_time_now_local();
  gchar *my_time = g_date_time_format(now,"%s");
  gtk_label_set_text((GtkLabel *) label, (char *) my_time);


  */


  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "1";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);

}

void button2_clicked(GtkWidget *widget, gpointer data){


  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "2";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button3_clicked(GtkWidget *widget, gpointer data){

  
  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "3";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button4_clicked(GtkWidget *widget, gpointer data){
  
  
  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "4";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button5_clicked(GtkWidget *widget, gpointer data){
  
  
  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "5";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button6_clicked(GtkWidget *widget, gpointer data){

  
  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "6";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button7_clicked(GtkWidget *widget, gpointer data){

  
  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "7";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button8_clicked(GtkWidget *widget, gpointer data){

  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "8";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button9_clicked(GtkWidget *widget, gpointer data){

  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "9";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void buttonNext_clicked(GtkWidget *widget, gpointer data){

  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = " ";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

void button0_clicked(GtkWidget *widget, gpointer data){

  gchar *str1 = gtk_label_get_text((GtkLabel*)label);

  gchar *str2 = "0";

  strcat(str1,str2);

  gtk_label_set_text((GtkLabel*)label,str1);
}

//eliminar ultimo char
void buttonDelete_clicked(GtkWidget *widget, gpointer data){

  gchar *str = gtk_label_get_text((GtkLabel*)label);

  str[strlen(str)-1] = '\0';

  gtk_label_set_text((GtkLabel*)label,str);
}

static void toggled_t9 (GtkToggleButton *toggle_button,gpointer user_data){
  GtkWindow *window = user_data;

  //exemplo para activar e desactivar a smart writing
  if (gtk_toggle_button_get_active (toggle_button))
      gtk_window_set_title (window, "Smart Writing ON");
  else
      gtk_window_set_title (window, "Smart Writing OFF");


}

/* DESLIGAR UMA FUNÇÃO DO CALLBACK
void toogle_signal(GtkWidget *widget, gpointer button){
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget))){
    handler_id=g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(button_clicked),NULL);
  } else {
    g_signal_handler_disconnect(button,handler_id);
  }
}*/

//LOGO
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

int main(int argc, char* argv[]) {

  gtk_init(&argc, &argv);

  window= gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);
  gtk_window_set_title(GTK_WINDOW(window), "T9");

  gtk_container_set_border_width(GTK_CONTAINER(window), 5);

  vbox= gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  label=gtk_label_new("YOUR TEXT HERE");

  checkbutton=gtk_check_button_new_with_label("Smart writing");
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);

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
  gtk_box_pack_start(GTK_BOX(vbox),grid,TRUE,TRUE,20);


  g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect (GTK_TOGGLE_BUTTON (checkbutton), "toggled", G_CALLBACK (toggled_t9), window);


  gtk_widget_show_all(window);

  gtk_main();
  return 0;
}



/*
int main (int argc, char *argv[]) {

    GtkApplication *app;
    int status;

    gtk_disable_setlocale();
    gtk_init(&argc, &argv);

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);

    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
*/