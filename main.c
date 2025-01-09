#include <hagl_hal.h>
#include <hagl.h>
#include <mipi_dcs.h>
#include <mipi_display.h>
#include <font6x9.h>
#include <string.h>
#include <wchar.h>

int main() {
	hagl_backend_t *display = hagl_init();
	hagl_color_t color = hagl_color(display, 255, 0, 0);

	int x = 5;
	int y = 5;

	float speed = 1;

	float size = 5;

	float dx = 1;
	float dy = 1;

	

	while (1) {
		hagl_put_text(display, (wchar_t*) "text", 7, 7, color, font6x9);

		x += dx*speed;
		y += dy*speed;

		if(x < size){
			dx = 1;
			size += 0.5;
		}else if (x>160-size) {
			dx = -1;
			size += 0.5;
		}

		if(y < size) {
			dy = 1;
			size += 0.5;
		}else if (y > 128-size){
			dy = -1;
			size += 0.5;
		}

    	hagl_clear(display);
    	hagl_fill_ellipse(display, x, y, size, size, color);

    	hagl_flush(display);
	};

	hagl_close(display);

	return 0;
}
