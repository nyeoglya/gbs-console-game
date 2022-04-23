#include "../headers/essential.h"

void clearScreen(int value, int line, const char* data, char screen[][MAX_LENGTH]) {
	system("cls");
	// printf("\t\t%20s", "");
	
	puts("\n\n\n\n\n\n\n\n");
	
	int i = 0;
	if (value && value <= line) {
		for(;i<line;i++) {
			printf("\t\t%s", screen[i]);
			if (i == value) {
				printf("%s", data);
			}
			puts("");
		}
	} else if (value && value > line) {
		for(;i<value;i++) {
			printf("\t\t%s\n", screen[i]);
		}
		printf("%s", data);
	} else {
		for(;i<line;i++) printf("\t\t%s\n", screen[i]);
	}
}

// 이거 수정하기 
int changeScreenSize(int wSize, int hSize) {
	if (wSize >= 50 && hSize >= 50) {
		return 1;
	} else {
		system(strcat("mode con cols=", ""));
		return 0;
	}
}

int modifyTitle(const char* title) {
	SetConsoleTitle(title);
}

int getScreenSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);
    return 0;
}

