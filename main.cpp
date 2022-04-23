// https://codevang.tistory.com/39
// gotoxy 이용해보기
// https://coding-factory.tistory.com/693
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220874370397
 

#include "headers/essential.h"

// 전처리문 
#define _CRT_NONSTDC_NO_WARNINGS    // 비표준 함수를 사용했을 때 에러 방지
#define _CRT_SECURE_NO_WARNINGS     // scanf 보안 경고로 인한 컴파일 에러 방지

// 구조체 
typedef struct player {
	char name[20];
	int id;
	int inventory[10];
} Player;

typedef struct point {
	short x;
	short y;
} point;

// 변수 
point cursorMain = {0, 0};
point* cursorMainP;
char mainScreen[10][MAX_LENGTH] = {"=================\0", "\0",  "1. 게임 시작\0", "2. 설정   \0", "3. 만든이\0", "4. 나가기\0"};
int lengthMainScreen = sizeof(mainScreen)/(sizeof(char)*MAX_LENGTH);

// 함수 
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
	GetAsyncKeyState(VK_RETURN); // 아무 의미없음. KeyState의 buffer를 비우기 위함. 
		
	printf("\033[0;31m"); // 글자색을 빨간색으로 설정(테스트 중)
	printf("Hello\n"); // Hello를 빨간색으로 출력함 
	printf("\033[0m"); // 글자색 원래대로 
	
	getScreenSize();
	// changeScreenSize(100, 200);
	
	modifyTitle("새로운 텍스트");
	
	Sleep(1500);

	clearScreen(0, lengthMainScreen, "", mainScreen);
	cursorMainP = &cursorMain;
	
	while (level == 0) {
		if (GetAsyncKeyState(VK_UP)) { // https://coding-factory.tistory.com/693
			moveCursor(cursorMainP, 2, 5, -1);
		} else if (GetAsyncKeyState(VK_DOWN)) {
			moveCursor(cursorMainP, 2, 5, 1);
		} else if (GetAsyncKeyState(VK_RETURN)) {
			// clearScreen(7, lengthMainScreen, "[알림] 선택됨", mainScreen);
			enterClicked(cursorMain.x, 2);
		}
		/*
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			clearScreen(7, lengthMainScreen, "[알림] 게임을 끝냅니다", mainScreen);
			level = -1;
		}
		*/
		Sleep(50); // 속도를 낮춤 
	}
	
	movToFunction();
	
	programEnd();
	getch(); 
	return 0;
}

void moveCursor(point* cursor, int start, int end, int move) {
	if (((*cursor).x += move) < start) (*cursor).x = end; 
	else if ((*cursor).x > end) (*cursor).x = start;
	
	clearScreen((*cursor).x, lengthMainScreen, "\t■", mainScreen);
}

int enterClicked(int clickedNum, int start) {
	int num = clickedNum-start;
	
	switch (num) {
		case 0:
			clearScreen(7, lengthMainScreen, "[알림] 게임을 시작합니다.", mainScreen);
			level = 1;
			break;
		case 1:
			clearScreen(7, lengthMainScreen, "[알림] 아직 구현되지 않은 기능입니다.", mainScreen);
			break;
		case 2:
			clearScreen(7, lengthMainScreen, "와샌즈.", mainScreen);
			break;
		case 3:
			clearScreen(7, lengthMainScreen, "[알림] 게임을 끝냅니다.", mainScreen);
			level = -1;
			break;
		default:
			break;
	}
}

void programEnd() {
	// free(windowsName);
}

