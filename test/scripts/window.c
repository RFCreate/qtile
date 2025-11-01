#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(win), "TestWindow");
    gtk_window_set_default_size(GTK_WINDOW(win), 100, 100);

    g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(win, "key-press-event", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(win);

    GdkEvent *event = gdk_event_new(GDK_BUTTON_PRESS);
    event->button.window = g_object_ref(gtk_widget_get_window(win));
    event->button.x = 50;
    event->button.y = 50;
    event->button.button = 1;
    event->button.time = GDK_CURRENT_TIME;
    gdk_event_put(event);
    gdk_event_free(event);

    // Set startup notification ID and present the window
    GdkDisplay *display = gtk_widget_get_display(win);
    GdkAppLaunchContext *context = gdk_display_get_app_launch_context(display);
    const gchar *notify_id = g_app_launch_context_get_startup_notify_id((GAppLaunchContext *) context, NULL, NULL);
    printf("Startup Notify activation ID: %s\n", notify_id);

    gtk_window_set_startup_id(GTK_WINDOW(win), notify_id);
    gtk_window_present(GTK_WINDOW(win));

    gtk_main();
    return 0;
}
