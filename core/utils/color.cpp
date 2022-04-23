#include "../../headers/essential.h"

/*
Black 	\033[0;30m
Red 	\033[0;31m
Green 	\033[0;32m
Yellow 	\033[0;33m
Blue 	\033[0;34m
Purple 	\033[0;35m
Cyan 	\033[0;36m
White 	\033[0;37m
Origin	\033[0m
*/

void textBlack() {
	printf("\033[0;30m");
}

void textRed() {
	printf("\033[0;31m");
}

void textGreen() {
	printf("%033[0;32m");
}

void textYellow() {
	printf("%033[0;33m");
}

void textBlue() {
	printf("%033[0;34m");
}

void textPurple() {
	printf("%033[0;35m");
}

void textCyan() {
	printf("%033[0;36m");
}

void textWhite() {
	printf("%033[0;37m");
}

void textOriCol() {
	printf("%033[0m");
}

/*
void cTextColor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
*/

