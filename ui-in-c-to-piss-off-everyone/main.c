#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer data) {
    GtkWidget *window = gtk_application_window_new(app);
    GtkWidget *label  = gtk_label_new("Hello, i3!");
    gtk_window_set_title(GTK_WINDOW(window), "My App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_window_set_child(GTK_WINDOW(window), label);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.example.hello", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}
