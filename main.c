#include <gtk/gtk.h>

static void button_clicked(GtkWidget *widget, gpointer data){

    if(gtk_widget_get_name(widget) == " 1\n,!?"){ //nao funciona ainda
        g_print("1\n");
    }

}

static void activate (GtkApplication *app, gpointer data){

    GtkWidget *window; //gere o ciclo de vida, os estados e o estilo do widget
    GtkWidget *grid;
    GtkWidget *button;

    gchar *values[16] = {" 1\n,!?", " 2\nabc", " 3\ndef",
                         " 4\nghi", " 5\njkl", " 6\nmno",
                         " 7\npqrs", " 8\ntuv", " 9\nwxyz",
                         " *\nnext", " 0\nspace", " #\ndelete",};

    window = gtk_application_window_new(app); //cria a janela do tipo GTK_WINDOW_TOPLEVEL (janela com barra de titulo e borda)
    gtk_window_set_title(GTK_WINDOW(window), "GtkGrid"); //dá o nome à janela. caso contrario atribui o nome do ficheiro
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 180); //define tamanho da janela
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); //centra a janela
    gtk_container_set_border_width(GTK_CONTAINER(window), 5); //largura da margem

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid),2);
    gtk_grid_set_column_spacing(GTK_GRID(grid),2);

    int pos=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            button = gtk_button_new_with_label(values[pos]);
            g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), NULL);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            pos++;
        }
    }

    gtk_container_add(GTK_CONTAINER(window), grid); //adiciona novo container à window

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL); //nao percebi

    gtk_widget_show_all(window); //sinaliza todos os widget para serem exibido

    gtk_main(); //entra no ciclo principal do GTK+ e espera por eventos
}

int main(int argc, char *argv[]){
    GtkApplication *app;
    int status;

    gtk_init(&argc, &argv); //inicializa o GTK+ e analiza opçoes da linha de comando. Deve ser chamada antes de usar qualquer outra funçao
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
