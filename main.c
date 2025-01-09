#include <hagl_hal.h>
#include <hagl.h>
#include <mipi_dcs.h>
#include <mipi_display.h>
#include <font6x9.h>
#include <string.h>
#include <wchar.h>
#include <pico/float.h>

int main() {
	hagl_backend_t *display = hagl_init();
	hagl_color_t color = hagl_color(display, 255, 0, 0);

	int x = 5;
	int y = 5;

	float speed = 1;

	float size = 5;
	float finalsize = 1;

	float dx = 1;
	float dy = 1;

	float t = 0;

	
	wchar_t text[100];
	while (1) {
		t += 0.1;

		x += dx*speed;
		y += dy*speed;

		if(x < finalsize){
			dx = 1;
			size += 1;
		}else if (x>160-finalsize) {
			dx = -1;
			size += 1;
		}

		if(y < finalsize) {
			dy = 1;
			size += 1;
		}else if (y > 128-finalsize){
			dy = -1;
			size += 1;
		}

		finalsize = finalsize + (size - finalsize) * 0.07;

		if(size > 30){size=1;}

    	hagl_clear(display);
    	hagl_fill_ellipse(display, x, y, finalsize, finalsize, color);

		swprintf(text, sizeof(text), L"size: %f", finalsize);
		hagl_put_text(display, text, 7, 7, color, font6x9);

    	hagl_flush(display);
	};

	hagl_close(display);

	return 0;
}
