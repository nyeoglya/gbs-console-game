
// 프로그램 전반에 걸쳐 사용하는 기본적인 변수들을 담아놓은 헤더파일 

#ifndef _varmain_h
#define _varmain_h

int level = 0;

char* windowsName = NULL;

// 수정하기 
int screenWidth;
int screenHeight;
char* mainScreen; // calloc으로 할당 후(화면 크기 변경 고려) width 기준으로 height까지 쪼개기 

#endif
