#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win), "TestWindow");
    gtk_window_set_default_size(GTK_WINDOW(win), 100, 100);
    gtk_window_set_startup_id(GTK_WINDOW(win), "some-id");
    gtk_window_present (GTK_WINDOW (win));

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(win, "key-press-event", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);

    gtk_main();
    return 0;
}
