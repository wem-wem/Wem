int x = 0, y = 0;
int mode = 0;

void setup() {
	size(500, 500);
}

void draw() {
	background(255, 255, 0);
	ellipse(x, y, 20, 20);
	if (x <= 0 || y <= 0){ mode = 0; }
	if (mode == 0){
		x += 5;
		y += 5;
	}
	if (x >= width || y >= height){ mode = 1; }
	if (mode == 1){
		x -= 5;
		y -= 5;
	}
}