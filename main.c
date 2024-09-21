#include <hagl_hal.h>
#include <hagl.h>

hagl_backend_t *display = hagl_init();
hagl_color_t color = hagl_color(display, 255, 0, 0);
int main() {
	int x = 0;
/* Main loop. */
	while (1) {

		x++;
    		hagl_clear(display);
    		hagl_fill_ellipse(display, x, 5, 5, 5, color);

    		hagl_flush(display);
	};

	hagl_close(display);

	return 0;
}
