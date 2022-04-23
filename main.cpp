// https://codevang.tistory.com/39
// gotoxy �̿��غ���
// https://coding-factory.tistory.com/693
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220874370397
 

#include "headers/essential.h"

// ��ó���� 
#define _CRT_NONSTDC_NO_WARNINGS    // ��ǥ�� �Լ��� ������� �� ���� ����
#define _CRT_SECURE_NO_WARNINGS     // scanf ���� ���� ���� ������ ���� ����

// ����ü 
typedef struct player {
	char name[20];
	int id;
	int inventory[10];
} Player;

typedef struct point {
	short x;
	short y;
} point;

// ���� 
point cursorMain = {0, 0};
point* cursorMainP;
char mainScreen[10][MAX_LENGTH] = {"=================\0", "\0",  "1. ���� ����\0", "2. ����   \0", "3. ������\0", "4. ������\0"};
int lengthMainScreen = sizeof(mainScreen)/(sizeof(char)*MAX_LENGTH);

// �Լ� 
extern void clearScreen(int, int, const char*, char screen[][MAX_LENGTH]);
extern void moveCursor(point*, int, int, int);
extern void movToFunction();
extern int modifyTitle(const char*);
extern int changeScreenSize(int, int);

extern int getScreenSize();
extern int changeScreenSize();

int enterClicked(int, int);
void programEnd();

int main(int argc, char** argv) {

	fflush(stdin);
	GetAsyncKeyState(VK_RETURN); // �ƹ� �ǹ̾���. KeyState�� buffer�� ���� ����. 
		
	printf("\033[0;31m"); // ���ڻ��� ���������� ����(�׽�Ʈ ��)
	printf("Hello\n"); // Hello�� ���������� ����� 
	printf("\033[0m"); // ���ڻ� ������� 
	
	getScreenSize();
	// changeScreenSize(100, 200);
	
	modifyTitle("���ο� �ؽ�Ʈ");
	
	Sleep(1500);

	clearScreen(0, lengthMainScreen, "", mainScreen);
	cursorMainP = &cursorMain;
	
	while (level == 0) {
		if (GetAsyncKeyState(VK_UP)) { // https://coding-factory.tistory.com/693
			moveCursor(cursorMainP, 2, 5, -1);
		} else if (GetAsyncKeyState(VK_DOWN)) {
			moveCursor(cursorMainP, 2, 5, 1);
		} else if (GetAsyncKeyState(VK_RETURN)) {
			// clearScreen(7, lengthMainScreen, "[�˸�] ���õ�", mainScreen);
			enterClicked(cursorMain.x, 2);
		}
		/*
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			clearScreen(7, lengthMainScreen, "[�˸�] ������ �����ϴ�", mainScreen);
			level = -1;
		}
		*/
		Sleep(50); // �ӵ��� ���� 
	}
	
	movToFunction();
	
	programEnd();
	getch(); 
	return 0;
}

void moveCursor(point* cursor, int start, int end, int move) {
	if (((*cursor).x += move) < start) (*cursor).x = end; 
	else if ((*cursor).x > end) (*cursor).x = start;
	
	clearScreen((*cursor).x, lengthMainScreen, "\t��", mainScreen);
}

int enterClicked(int clickedNum, int start) {
	int num = clickedNum-start;
	
	switch (num) {
		case 0:
			clearScreen(7, lengthMainScreen, "[�˸�] ������ �����մϴ�.", mainScreen);
			level = 1;
			break;
		case 1:
			clearScreen(7, lengthMainScreen, "[�˸�] ���� �������� ���� ����Դϴ�.", mainScreen);
			break;
		case 2:
			clearScreen(7, lengthMainScreen, "�ͻ���.", mainScreen);
			break;
		case 3:
			clearScreen(7, lengthMainScreen, "[�˸�] ������ �����ϴ�.", mainScreen);
			level = -1;
			break;
		default:
			break;
	}
}

void programEnd() {
	// free(windowsName);
}

