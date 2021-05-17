#include <gtk/gtk.h>

  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *btn;
  GtkWidget *grid;
  GtkWidget *display;
  GdkPixbuf *icon;

void button_clicked(GtkWidget *widget, gpointer data){
  g_print("Evento\n");
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


static void activate(GtkApplication *app, gpointer user_data) {

  /* GENERAL SIZING OPTIONS */
  window = gtk_application_window_new(app);
  gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window),"T9");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  gtk_container_set_border_width(GTK_CONTAINER(window),15);


  /* ICON */
  icon = create_pixbuf("logo.png");
  gtk_window_set_icon(GTK_WINDOW(window), icon);

  /* DISPLAY SCREEN */
  display = gtk_label_new (NULL);
  gtk_label_set_text (display,"ola amigos");

  /******************/

  /* TABLE */
  gchar *values[12] = { " 1\n ", " 2\nabc ", " 3\ndef ",
     " 4\nghi ", " 5\njkl ", " 6\nmno ",
     " 7\npqrs ", " 8\ntuv ", " 9\nwxyz ",
     " *\nnext ", " 0\nspace " , " #\ndelete "
  };

  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid),2);
  gtk_grid_set_column_spacing(GTK_GRID(grid),2);

  //The position of child is determined by left and top .
  //The number of “cells” that child will occupy is determined by width and height .
  //ocupa 3 celulas e
  gtk_grid_attach(GTK_GRID(grid), display,0, 1, 3, 1);

  int i = 1;
  int j = 0;
  int pos = 0;

  for (i=1; i < 4 ; i++) {
    for (j=0; j < 3; j++) {
      btn = gtk_button_new_with_label(values[pos]);
      gtk_grid_attach(GTK_GRID(grid), btn, j, i, 1, 1);
      pos++;
    }
  }
  gtk_container_add(GTK_CONTAINER(window), grid);
  /******************/




  g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

  gtk_widget_show_all(window);

  g_object_unref(icon);

  gtk_main();

  return ;

}


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
