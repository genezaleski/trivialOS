static char* const VGA_MEMORY = (char*) 0xb8000;

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;

void terminal_out(int x, int y, char* c){
	int location = 2 * (x + y * VGA_WIDTH);
	static char* newLocation;
	newLocation = VGA_MEMORY + location;

	unsigned int i = 0;
	unsigned int j = 0;

	while (c[i] != '\0') {
		newLocation[j] = c[i];
		newLocation[j+1] = 0xFF;
		i++;
		j = j + 2;
	}
}

void print_int(int o){
	int i;
	int reverse = 0;

	//reverse the input so
	//it will be reversed to normal
	//while converting to ascii below.	
	while(o != 0){
		i = o%10;
		reverse = reverse*10 + i;
		o /= 10; 
	}
	i = 0;
	unsigned int j = 0;
	while(reverse > 0){
		i = reverse%10;
		VGA_MEMORY[j] = (i + 48);
		VGA_MEMORY[j+1] = 0x07;
		j += 2;
		reverse = reverse/10;
	}
}

void kernel_early(void) {
	print_int(609);
	terminal_out(50,15,"os machine broke");
	terminal_out(10,10,"hello there");
	terminal_out(20,20,"General Kenobi");
}

int main(void) {
	const char* str = "Hello World";
	unsigned int i = 0;
	unsigned int j = 0;

	//while (str[i] != '\0') {
	//	VGA_MEMORY[j] = str[i];
	//	VGA_MEMORY[j+1] = 0x07;
	//	i++;
	//		j = j + 2;
	//}

	return 0;
}
