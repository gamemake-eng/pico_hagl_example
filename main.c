#include <hagl_hal.h>
#include <hagl.h>


int main() {
	hagl_backend_t *display = hagl_init();
	hagl_color_t color = hagl_color(display, 255, 0, 0);

	int x = 0;
	int y = 0;

	int speed = 1;

	int dx = 1;
	int dy = 1;

	while (1) {
		x += dx*speed;
		y += dy*speed;

		if(x < 5){
			dx = 1;
		}else if (x>128-5) {
			dx = -1;
		}

		if(y < 5) {
			dy = 1;
		}else if (y > 160-5){
			dy = -1;
		}

    		hagl_clear(display);
    		hagl_fill_ellipse(display, x, y, 5, 5, color);

    		hagl_flush(display);
	};

	hagl_close(display);

	return 0;
}
