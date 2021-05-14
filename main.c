#include <gtk/gtk.h>

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    g_print("GTK+ version: %d.%d.%d\n", gtk_major_version, gtk_minor_version, gtk_micro_version);
    g_print("Glib version: %d.%d.%d\n", glib_major_version, glib_minor_version, glib_micro_version);
    return 0;
}
