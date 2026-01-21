#include <stdio.h>
#include <stdlib.h>
#include <wayland-client.h>

static void registry_handler(void *data, struct wl_registry *registry,
                             uint32_t id, const char *interface, uint32_t version) {
    printf("Gefundene Schnittstelle: %s\n", interface);
}

static void registry_remover(void *data, struct wl_registry *registry, uint32_t id) {}

static const struct wl_registry_listener registry_listener = {
    .global = registry_handler,
    .global_remove = registry_remover
};

int main() {
    struct wl_display *display = wl_display_connect(NULL);
    if (!display) {
        fprintf(stderr, "Fehler: Verbindung zu Wayland fehlgeschlagen.\n");
        return -1;
    }

    struct wl_registry *registry = wl_display_get_registry(display);
    wl_registry_add_listener(registry, &registry_listener, NULL);

    wl_display_roundtrip(display);

    wl_display_disconnect(display);
    return 0;
}