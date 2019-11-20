#include "Revolt.h"

int map[2][12][12] = { {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 2, 9, 9, 9, 0 },
	{ 0, 9, 2, 1, 0, 0, 1, 9, 9, 9, 2, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 2, 9, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 2, 9, 9, 9, 0 },
	{ 0, 9, 2, 1, 0, 0, 1, 9, 9, 9, 2, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 2, 9, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } };
int tmp[2][12][12] = { {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 2, 9, 9, 9, 0 },
	{ 0, 9, 2, 1, 0, 0, 1, 9, 9, 9, 2, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 2, 9, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 2, 9, 9, 9, 0 },
	{ 0, 9, 2, 1, 0, 0, 1, 9, 9, 9, 2, 0 },
	{ 0, 9, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 2, 9, 1, 0, 0, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } } };
int trace[3][100];
int temp_wallx, temp_wally;
int see_man[3][3];
int red_row[3], red_col[3];//빨간 블록의 인덱스 저장하는 배열
int green_row, green_col, green_face;
int gamer_row, gamer_col, gamer_face;
int com_row, com_col, com_face;
int StartTime = GetTickCount();
int NowTime = GetTickCount();
void shadow_map_print();
char ch;//방향키
int x1, y1, z1;//게이머의 좌표
int x2, y2, z2;//com의 좌표
int x3, y3, z3;//공의 좌표
int sec;
int sec1;
int cnt = 0;
int Endflag = 0;
int tracefalg = 0;

int main(){
	int yn = 1;
	unsigned Threadid1;//sec_set실행시키는 
	unsigned Threadid2;//pro_man
	unsigned Threadid3;//por_com	


	while (yn == 1){
		printf("게임 시간을 입력하세요.(단위:초)\n");
		scanf("%d", &sec);
		fflush(stdin);
		srand(time(NULL));

		rand_appear();
		find_ball();

		HANDLE hThread1 = (HANDLE)_beginthreadex(NULL, 0, sec_set, NULL, 0, &Threadid1);//시간 지정

		HANDLE hThread2 = (HANDLE)_beginthreadex(NULL, 0, pro_man, NULL, 0, &Threadid2);//게이머의 연산
		HANDLE hThread3 = (HANDLE)_beginthreadex(NULL, 0, pro_com, NULL, 0, &Threadid3);//com의 연산

		while (NowTime <= StartTime + sec1 + 5){
			if (cnt % 2 == 0){
				map_print();
			}//관리자 모드
			else if (cnt % 2 == 1){
				printf("\n\n\n");
				shadow_map_print();
				printf("\n\n\n");
			}//가려진 모드
			Sleep(100);
			system("cls");
		}
		//WaitForSingleObject((HANDLE)hThread1, INFINITE);

		system("cls");
		if (map[z1][x1][y1] == 15 || map[z1][x1][y1] == 16 || map[z1][x1][y1] == 17) printf("게이머 승\n");
		if (map[z1][x1][y1] == 18 || map[z1][x1][y1] == 19 || map[z1][x1][y1] == 20) printf("게이머 승\n");

		printf("계속 하시겠습니까?\n");
		printf("1) yes 2) no\n");
		scanf("%d", &yn);
		if (yn == 2)
			Endflag = 1;
		fflush(stdin);
		sec1 = 0;
		sec = 0;

		StartTime = GetTickCount();
		NowTime = GetTickCount();

		for (int k = 0; k < 2; k++){
			for (int i = 0; i < 12; i++){
				for (int j = 0; j < 12; j++){
					map[k][i][j] = tmp[k][i][j];
				}
			}
		}
	}
}


unsigned __stdcall sec_set(void* arg){
	sec1 = sec * 1000;
	while (NowTime - StartTime <= sec1){
		NowTime = GetTickCount();
	}
	return 0;
}//시간 입력함수
unsigned __stdcall pro_man(void* arg){

	while (Endflag != 1 && NowTime <= StartTime + sec1 + 2){
		ch = _getch();
		switch (ch){
		case 72:
			Man_Up();
			break;
		case 80:
			Man_Down();
			break;
		case 75:
			Man_Left();
			break;
		case 77:
			Man_Right();
			break;
		case 97:
			cnt++;
			break;
		case 32:
			if (x1<x2){
				map[z1][x1 + 1][y1] = 0;
				Sleep(2000);
				map[z1][x1 + 1][y1] = tmp[z1][x1 + 1][y1];
			}
			else if (x1>x2){
				map[z1][x1 - 1][y1] = 0;
				Sleep(2000);
				map[z1][x1 - 1][y1] = tmp[z1][x1 - 1][y1];
			}
			else if (y1<y2){
				map[z1][x1][y1 + 1] = 0;
				Sleep(2000);
				map[z1][x1][y1 + 1] = tmp[z1][x1][y1 + 1];
			}
			else if (y1>y2){
				map[z1][x1][y1 - 1] = 0;
				Sleep(2000);
				map[z1][x1][y1 - 1] = tmp[z1][x1][y1 - 1];
			}
			break;
		}
	}
	return 0;
}
unsigned __stdcall pro_com(void* arg){

	int ch2;
	while (Endflag != 1 && NowTime <= StartTime + sec1 + 2){
		ch2 = rand() % 4 + 1;
		switch (ch2){
		case 1: Com_Up(); break;
		case 2: Com_Down(); break;
		case 3: Com_Left(); break;
		case 4: Com_Right(); break;
		}
		Sleep(100);
	}
	return 0;
}


void rand_appear(){
	red_appear();
	greed_appear();
	gamer_appear();
	com_appear();
}


void red_appear(){
	for (int p = 0; p < 3; ++p){
		red_row[p] = rand() % 10 + 1;
		red_col[p] = rand() % 10 + 1;
		if (map[0][red_col[p]][red_row[p]] != 0) p -= 1;//난수 받은 인덱스가 0이 아니면 포문 한번더 돌림
		if (map[0][red_col[p]][red_row[p]] == 0) {
			map[0][red_col[p]][red_row[p]] = 3;
			map[1][red_col[p]][red_row[p]] = 3;
		}//난수받은 배열의 인덱스가 0이면 그 곳이 3이 되어 엘레베이터 형성
	}
}//엘레베이터를 출력하는 함수
void greed_appear(){
	for (int p = 0; p < 1; p++){
		green_row = rand() % 10 + 1;
		green_col = rand() % 10 + 1;
		green_face = rand() % 2;
		if (map[green_face][green_col][green_row] != 1) p -= 1;
		if (map[green_face][green_col][green_row] == 1){
			map[green_face][green_col][green_row] = 6;
		}
	}
}//별을 출력하는 함수

void map_print(){
	for (int k = 0; k < 2; k++){
		printf("----------%d층-----------\n", k + 1);
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (map[k][i][j] == 0) printf("▦");//벽
				else if (map[k][i][j] == 1) printf("  ");//길
				else if (map[k][i][j] == 2) printf("@@");//언덕입구
				else if (map[k][i][j] == 3) printf("##");//엘레베이터
				else if (map[k][i][j] == 4) printf("姜");//게이머
				else if (map[k][i][j] == 5)	printf("朴");//com
				else if (map[k][i][j] == 6){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("★");//녹색박스
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if (map[k][i][j] == 9) printf("■");//언덕
				else if (map[k][i][j] == 11) printf("姜");//게이머가 언덕 입구위에 있을때
				else if (map[k][i][j] == 12)printf("姜");//게이머가 언덕 위에 있을때
				else if (map[k][i][j] == 13) printf("朴");//com가 언덕 입구위에 있을때
				else if (map[k][i][j] == 14)printf("朴");//언덕입구위 com
				else if (map[k][i][j] == 15){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("姜");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//게이머가 공을 갖고 있을때
				else if (map[k][i][j] == 16)	{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("姜");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//게이머가 공을 갖고 언덕입구 위에 있을때
				else if (map[k][i][j] == 17)	{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("姜");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}//게이머가 공을 갖고 언덕 위에 있을때
				else if (map[k][i][j] == 18){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("朴");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if (map[k][i][j] == 19){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("朴");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else if (map[k][i][j] == 20){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					printf("朴");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}


			}
			printf("\n");
		}
		printf("\n");
	}
}//맵을 출력하는 함수
void shadow_map_print(){
	for (int k = 0; k < 2; k++){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if ((map[k][i][j] == 4 || map[k][i][j] == 11 || map[k][i][j] == 12 || map[k][i][j] == 15 || map[k][i][j] == 16 || map[k][i][j] == 17)){

					see_man[0][0] = map[k][i - 1][j - 1];
					see_man[1][0] = map[k][i][j - 1];
					see_man[2][0] = map[k][i + 1][j - 1];
					see_man[0][1] = map[k][i - 1][j];
					see_man[1][1] = map[k][i][j];
					see_man[2][1] = map[k][i + 1][j];
					see_man[0][2] = map[k][i - 1][j + 1];
					see_man[1][2] = map[k][i][j + 1];
					see_man[2][2] = map[k][i + 1][j + 1];
				}
			}
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (see_man[i][j] == 0) printf("▦");//벽
			else if (see_man[i][j] == 1) printf("  ");//길
			else if (see_man[i][j] == 2) printf("@@");//언덕입구
			else if (see_man[i][j] == 3) printf("##");//엘레베이터
			else if (see_man[i][j] == 4) printf("姜");//게이머
			else if (see_man[i][j] == 5)	printf("朴");//com
			else if (see_man[i][j] == 6){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("★");//녹색박스
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (see_man[i][j] == 9) printf("■");//언덕
			else if (see_man[i][j] == 11) printf("姜");//게이머가 언덕 입구위에 있을때
			else if (see_man[i][j] == 12)printf("姜");//게이머가 언덕 위에 있을때
			else if (see_man[i][j] == 13) printf("朴");//com가 언덕 입구위에 있을때
			else if (see_man[i][j] == 14)printf("朴");//언덕입구위 com
			else if (see_man[i][j] == 15){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("姜");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}//게이머가 공을 갖고 있을때
			else if (see_man[i][j] == 16)	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("姜");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}//게이머가 공을 갖고 언덕입구 위에 있을때
			else if (see_man[i][j] == 17)	{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("姜");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}//게이머가 공을 갖고 언덕 위에 있을때
			else if (see_man[i][j] == 18){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("朴");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (see_man[i][j] == 19){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("朴");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (see_man[i][j] == 20){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				printf("朴");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		}
		printf("\n");
	}
}

//맵을 출력하는 함수


void gamer_appear(){
	srand(time(NULL) + rand());
	for (int p = 0; p < 1; p++){
		gamer_row = rand() % 12;
		gamer_col = rand() % 12;
		gamer_face = rand() % 2;
		if (map[gamer_face][gamer_col][gamer_row] != 1) p -= 1;
		if (map[gamer_face][gamer_col][gamer_row] == 1){
			map[gamer_face][gamer_col][gamer_row] = 4;
		}
	}

}
void com_appear(){
	for (int p = 0; p < 1; p++){
		com_row = rand() % 12;
		com_col = rand() % 12;
		com_face = rand() % 2;
		if (map[com_face][com_col][com_row] != 1) p -= 1;
		if (map[com_face][com_col][com_row] == 1){
			map[com_face][com_col][com_row] = 5;
		}
	}
}
void find_man(){
	for (int k = 0; k < 2; k++){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (map[k][i][j] == 4){
					x1 = i;
					y1 = j;
					z1 = k;
				}
			}
		}
	}
}
void find_man1(){
	for (int k = 0; k < 2; k++){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (map[k][i][j] == 18 || map[k][i][j] == 20 || map[k][i][j] == 19){
					x1 = i;
					y1 = j;
					z1 = k;
				}
			}
		}
	}
}
void find_com(){
	for (int k = 0; k < 2; k++){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (map[k][i][j] == 5){
					x2 = i;
					y2 = j;
					z2 = k;
				}
			}
		}
	}
}
void find_ball(){
	for (int k = 0; k < 2; k++){
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				if (map[k][i][j] == 6){
					x3 = i;
					y3 = j;
					z3 = k;
				}
			}
		}
	}
}
void wall_appear(){
	void find_man1();

	for (int p = 0; p < 1; ++p){
		temp_wallx = rand() % 10 + 1;
		temp_wally = rand() % 10 + 1;

		//임시 벽 생성

	}
}

void Man_Up(){
	find_man();
	if (x1 > 0 && map[z1][x1 - 1][y1] == 1 && map[z1][x1][y1] == 4){
		map[z1][x1][y1] = 1;
		x1 = x1 - 1;
		map[z1][x1][y1] = 4;
	}//기본이동

	else if (x1 > 0 && map[z1][x1 - 1][y1] == 18&&map[z1][x1][y1]==4){
		map[z1][x1 - 1][y1] = 5;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000); 
		tracefalg = 0;
	}//일반 공뺏기
	else if (x1 > 0 && map[z1][x1 - 1][y1] == 20 && map[z1][x1][y1] == 12){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕을
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 19 && map[z1][x1][y1] == 12){
		map[z1][x1 + 1][y1] = 13;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕입구를
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 20 && map[z1][x1][y1] == 11){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 언덕를
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 20 && map[z1][x1][y1] == 4){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//길에서 언덕입구
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 18 && map[z1][x1][y1] == 11){
		map[z1][x1 + 1][y1] = 5;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 길
	else if (map[z1][x1][y1] == 4 && map[z1][x1 - 1][y1] == 3){
		map[z1][x1][y1] = 1;
		z1 = !z1;
		map[z1][x1][y1] = 4;
	}//엘레베이터 

	/*언덕*/
	else if (x1 > 0 && map[z1][x1 - 1][y1] == 2 && map[z1][x1][y1] == 4){
		map[z1][x1][y1] = 1;
		x1 = x1 - 1;
		map[z1][x1][y1] = 11;//언덕 입구 위에 게이머가 있을때

	}//길에서 언덕 입구로 들어갈때
	else if (x1 > 0 && map[z1][x1 - 1][y1] == 9 && map[z1][x1][y1] == 11){
		map[z1][x1][y1] = 2;
		x1 = x1 - 1;
		map[z1][x1][y1] = 12;//언덕 위에 게이머가 있을때
	}//언덕 입구에서 언덕으로 이동
	else if (x1 > 0 && map[z1][x1 - 1][y1] == 9 && map[z1][x1][y1] == 12){
		map[z1][x1][y1] = 9;
		x1 = x1 - 1;
		map[z1][x1][y1] = 12;//언덕 위에 게이머가 있을때
	}//언덕에서 언덕으로 이동
	else if (x1 > 0 && map[z1][x1 - 1][y1] == 2 && map[z1][x1][y1] == 12){
		map[z1][x1][y1] = 9;
		x1 = x1 - 1;
		map[z1][x1][y1] = 11;
	}//언덕에서 언덕입구로 이동
	/*공*/
	else if (map[z1][x1][y1] == map[z3][x3 + 1][y3]){
		map[z3][x3][y3] = 1;
		map[z1][x1][y1] = 1;
		x1 = x1 - 1;
		map[z1][x1][y1] = 15;
		tracefalg = 1;

	}//공 습득시
	else if (map[z1][x1][y1] == 15 || map[z1][x1][y1] == 17 || map[z1][x1][y1] == 16){
		if (x1 > 0 && map[z1][x1 - 1][y1] == 1 && map[z1][x1][y1] == 15){
			map[z1][x1][y1] = 1;
			x1 = x1 - 1;
			map[z1][x1][y1] = 15;
		}//기본이동
		else if (map[z1][x1 - 1][y1] == 3){
			map[z1][x1][y1] = 1;
			z1 = !z1;
			map[z1][x1][y1] = 15;
		}//엘레베이터 

		/*언덕*/
		else if (x1 > 0 && map[z1][x1 - 1][y1] == 2 && map[z1][x1][y1] == 15){
			map[z1][x1][y1] = 1;
			x1 = x1 - 1;
			map[z1][x1][y1] = 16;//언덕 입구 위에 게이머가 있을때

		}//길에서 언덕 입구로 들어갈때
		else if (x1 > 0 && map[z1][x1 - 1][y1] == 9 && map[z1][x1][y1] == 16){
			map[z1][x1][y1] = 2;
			x1 = x1 - 1;
			map[z1][x1][y1] = 17;//언덕 위에 게이머가 있을때
		}//언덕 입구에서 언덕으로 이동
		else if (x1 > 0 && map[z1][x1 - 1][y1] == 9 && map[z1][x1][y1] == 17){
			map[z1][x1][y1] = 9;
			x1 = x1 - 1;
			map[z1][x1][y1] = 17;//언덕 위에 게이머가 있을때
		}//언덕에서 언덕으로 이동
		else if (x1 > 0 && map[z1][x1 - 1][y1] == 2 && map[z1][x1][y1] == 17){
			map[z1][x1][y1] = 9;
			x1 = x1 - 1;
			map[z1][x1][y1] = 16;
		}//언덕에서 언덕입구로 이동

	}
}
void Man_Down(){
	find_man();
	if (x1 < 12 && map[z1][x1][y1] == 4 && map[z1][x1 + 1][y1] == 1){
		x1 = x1 + 1;
		map[z1][x1 - 1][y1] = 1;
		map[z1][x1][y1] = 4;
	}//기본이동
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 18 && map[z1][x1][y1] == 4){
		map[z1][x1 + 1][y1] = 5;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 20 && map[z1][x1][y1] == 12){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕을
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 19 && map[z1][x1][y1] == 12){
		map[z1][x1 + 1][y1] = 13;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕입구를
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 20 && map[z1][x1][y1] == 11){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 언덕를
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 20 && map[z1][x1][y1] == 4){
		map[z1][x1 + 1][y1] = 14;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//길에서 언덕입구
	else if (x1 > 0 && map[z1][x1 + 1][y1] == 18 && map[z1][x1][y1] == 11){
		map[z1][x1 + 1][y1] = 5;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 길
	else if (map[z1][x1][y1] == 4 && map[z1][x1 + 1][y1] == 3){
		map[z1][x1][y1] = 1;
		z1 = !z1;
		map[z1][x1][y1] = 4;
	}//엘레베이터 
	/*언덕*/
	if (x1 < 12 && map[z1][x1][y1] == 12 && map[z1][x1 + 1][y1] == 9){
		map[z1][x1][y1] = 9;
		x1 = x1 + 1;
		map[z1][x1][y1] = 12;
	}//언덕위에 있고 아래가 언덕일때
	else if (x1 < 12 && map[z1][x1][y1] == 12 && map[z1][x1 + 1][y1] == 2){
		map[z1][x1][y1] = 9;
		x1 = x1 + 1;
		map[z1][x1][y1] = 11;
	}//언덕위에 있고 아래가 언덕입구일때
	else if (x1 < 12 && map[z1][x1][y1] == 11 && map[z1][x1 + 1][y1] == 1){
		map[z1][x1][y1] = 2;
		x1 = x1 + 1;
		map[z1][x1][y1] = 4;
	}//언덕입구 위에 있고 아래가 길일때
	else if (x1 < 12 && map[z1][x1][y1] == 11 && map[z1][x1 + 1][y1] == 9){
		map[z1][x1][y1] = 2;
		x1 = x1 + 1;
		map[z1][x1][y1] = 12;
	}//언덕입구 위에 있고 아래가 언덕일때
	/*공*/
	else if (map[z1][x1][y1] == map[z3][x3 - 1][y3]){
		map[z3][x3][y3] = 1;
		map[z1][x1][y1] = 1;
		x1 = x1 + 1;
		map[z1][x1][y1] = 15;
		tracefalg = 1;
	}//공 습득시
	else if (map[z1][x1][y1] == 15 || map[z1][x1][y1] == 17 || map[z1][x1][y1] == 16){
		if (x1 < 12 && map[z1][x1][y1] == 15 && map[z1][x1 + 1][y1] == 1){
			x1 = x1 + 1;
			map[z1][x1 - 1][y1] = 1;
			map[z1][x1][y1] = 15;
		}//기본이동
		else if (map[z1][x1 + 1][y1] == 3){
			map[z1][x1][y1] = 1;
			z1 = !z1;
			map[z1][x1][y1] = 15;
		}//엘레베이터 
		/*언덕*/
		else if (x1 < 12 && map[z1][x1][y1] == 16 && map[z1][x1 + 1][y1] == 9){
			map[z1][x1][y1] = 2;
			x1 = x1 + 1;
			map[z1][x1][y1] = 17;
		}//언덕입구 위에 있고 아래가 길일때
		else if (x1 < 12 && map[z1][x1][y1] == 16 && map[z1][x1 + 1][y1] == 1){
			map[z1][x1][y1] = 2;
			x1 = x1 + 1;
			map[z1][x1][y1] = 15;
		}//언덕입구 위에 있고 아래가 길일때
		else if (x1 < 12 && map[z1][x1][y1] == 17 && map[z1][x1 + 1][y1] == 9){
			map[z1][x1][y1] = 9;
			x1 = x1 + 1;
			map[z1][x1][y1] = 17;
		}//언덕위에 있고 아래가 언덕일때
		else if (x1 < 12 && map[z1][x1][y1] == 17 && map[z1][x1 + 1][y1] == 2){
			map[z1][x1][y1] = 9;
			x1 = x1 + 1;
			map[z1][x1][y1] = 16;
		}//언덕위에 있고 아래가 언덕입구일때


	}

}
void Man_Left(){
	find_man();
	if (y1 > 0 && map[z1][x1][y1 - 1] == 1 && map[z1][x1][y1] == 4){
		y1 = y1 - 1;
		map[z1][x1][y1 + 1] = 1;
		map[z1][x1][y1] = 4;
	}//기본이동
	else if (x1 > 0 && map[z1][x1][y1 - 1] == 18 && map[z1][x1][y1] == 4){
		map[z1][x1][y1 - 1] = 5;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}
	else if (x1 > 0 && map[z1][x1][y1 - 1] == 19 && map[z1][x1][y1]==12){
		map[z1][x1][y1 - 1] = 13;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕입구위의 공을 뺏을때

	else if (x1 > 0 && map[z1][x1][y1 - 1] == 19 && map[z1][x1][y1] == 4){
		map[z1][x1][y1 - 1] = 13;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//길에서 언덕입구의 공을 뺏을때
	else if (x1 > 0 && map[z1][x1][y1 - 1] == 20 && map[z1][x1][y1] == 12){
		map[z1][x1][y1 - 1] = 14;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕의 공을 뺏을때
	else if (x1 > 0 && map[z1][x1][y1 - 1] == 20 && map[z1][x1][y1] == 11){
		map[z1][x1][y1 - 1] = 14;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 언덕의 공을 뺏을때
	else if (y1 > 0 && map[z1][x1][y1 - 1] == 3 && map[z1][x1][y1] == 4){
		map[z1][x1][y1] = 1;
		z1 = !z1;
		map[z1][x1][y1] = 4;
	}//엘레베이터 
	/*언덕*/
	if (y1 > 0 && map[z1][x1][y1] == 4 && map[z1][x1][y1 - 1] == 2) {
		map[z1][x1][y1] = 1;
		y1 = y1 - 1;
		map[z1][x1][y1] = 11;
	}//길에서 언덕입구로 들어갈때
	else if (y1 > 0 && map[z1][x1][y1] == 11 && map[z1][x1][y1 - 1] == 9){
		map[z1][x1][y1] = 2;
		y1 = y1 - 1;
		map[z1][x1][y1] = 12;

	}//언덕입구 위에 있고 왼쪽이 언덕일때
	else if (y1 > 0 && map[z1][x1][y1] == 12 && map[z1][x1][y1 - 1] == 9) {
		map[z1][x1][y1] = 9;
		y1 = y1 - 1;
		map[z1][x1][y1] = 12;

	}//언덕에서 언덕으로 이동할때
	else if (y1 > 0 && map[z1][x1][y1] == 12 && map[z1][x1][y1 - 1] == 2) {
		map[z1][x1][y1] = 9;
		y1 = y1 - 1;
		map[z1][x1][y1] = 11;

	}//언덕위에서 언덕입구로 갈때
	else if (y1 > 0 && map[z1][x1][y1] == 11 && map[z1][x1][y1 - 1] == 1){
		map[z1][x1][y1] = 2;
		y1 = y1 - 1;
		map[z1][x1][y1] = 4;

	}//언덕 입구에서 길로 나갈때
	/*공*/
	else if (map[z1][x1][y1] == map[z3][x3][y3 + 1]){
		map[z3][x3][y3] = 1;
		map[z1][x1][y1] = 1;
		y1 = y1 - 1;
		map[z1][x1][y1] = 15;
		tracefalg = 1;
	}//공 습득시
	else if (map[z1][x1][y1] == 15 || map[z1][x1][y1] == 17 || map[z1][x1][y1] == 16){
		if (y1 > 0 && map[z1][x1][y1 - 1] == 1 && map[z1][x1][y1] == 15){
			y1 = y1 - 1;
			map[z1][x1][y1 + 1] = 1;
			map[z1][x1][y1] = 15;
		}//기본이동
		else if (y1 > 0 && map[z1][x1][y1 - 1] == 3){
			map[z1][x1][y1] = 1;
			z1 = !z1;
			map[z1][x1][y1] = 15;
		}//엘레베이터 
		/*언덕*/
		if (y1 > 0 && map[z1][x1][y1] == 15 && map[z1][x1][y1 - 1] == 2) {
			map[z1][x1][y1] = 1;
			y1 = y1 - 1;
			map[z1][x1][y1] = 16;
		}//길에서 언덕입구로 들어갈때
		else if (y1 > 0 && map[z1][x1][y1] == 16 && map[z1][x1][y1 - 1] == 9){
			map[z1][x1][y1] = 2;
			y1 = y1 - 1;
			map[z1][x1][y1] = 17;

		}//언덕입구 위에 있고 왼쪽이 언덕일때
		else if (y1 > 0 && map[z1][x1][y1] == 17 && map[z1][x1][y1 - 1] == 9) {
			map[z1][x1][y1] = 9;
			y1 = y1 - 1;
			map[z1][x1][y1] = 17;

		}//언덕에서 언덕으로 이동할때
		else if (y1 > 0 && map[z1][x1][y1] == 17 && map[z1][x1][y1 - 1] == 2) {
			map[z1][x1][y1] = 9;
			y1 = y1 - 1;
			map[z1][x1][y1] = 16;

		}//언덕위에서 언덕입구로 갈때
		else if (y1 > 0 && map[z1][x1][y1] == 16 && map[z1][x1][y1 - 1] == 1){
			map[z1][x1][y1] = 2;
			y1 = y1 - 1;
			map[z1][x1][y1] = 15;

		}//언덕 입구에서 길로 나갈때
	}

}
void Man_Right() {
	find_man();
	if (y1 < 12 && map[z1][x1][y1 + 1] == 1 && map[z1][x1][y1] == 4){
		y1 = y1 + 1;
		map[z1][x1][y1 - 1] = 1;
		map[z1][x1][y1] = 4;
	}//기본이동
	else if (x1 > 0 && map[z1][x1][y1 + 1] == 18){
		map[z1][x1][y1 + 1] = 5;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}
	else if (x1 > 0 && map[z1][x1][y1 + 1] == 19 && map[z1][x1][y1] == 12){
		map[z1][x1][y1 + 1] = 13;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕입구위의 공을 뺏을때

	else if (x1 > 0 && map[z1][x1][y1 + 1] == 19 && map[z1][x1][y1] == 4){
		map[z1][x1][y1 + 1] = 13;

		map[z1][x1][y1] = 15;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//길에서 언덕입구의 공을 뺏을때
	else if (x1 > 0 && map[z1][x1][y1 + 1] == 20 && map[z1][x1][y1] == 12){
		map[z1][x1][y1 + 1] = 14;

		map[z1][x1][y1] = 17;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕에서 언덕의 공을 뺏을때
	else if (x1 > 0 && map[z1][x1][y1 + 1] == 20 && map[z1][x1][y1] == 11){
		map[z1][x1][y1 + 1] = 14;

		map[z1][x1][y1] = 16;
		printf("공을 뺏었습니다.\n");
		Sleep(2000);
		tracefalg = 0;
	}//언덕입구에서 언덕의 공을 뺏을때
	else if (map[z1][x1][y1 + 1] == 3 && map[z1][x1][y1] == 4){
		map[z1][x1][y1] = 1;
		z1 = !z1;
		map[z1][x1][y1] = 4;
	}//엘레베이터 
	/*언덕*/
	if (y1 < 12 && map[z1][x1][y1] == 4 && map[z1][x1][y1 + 1] == 2){
		map[z1][x1][y1] = 1;
		y1 = y1 + 1;
		map[z1][x1][y1] = 11;
	}//길에서 언덕입구로 갈때
	else if (y1 < 12 && map[z1][x1][y1] == 11 && map[z1][x1][y1 + 1] == 1){
		map[z1][x1][y1] = 2;
		y1 = y1 + 1;
		map[z1][x1][y1] = 4;
	}//언덕 입구에서 길로 갈때
	else if (y1 < 12 && map[z1][x1][y1] == 12 && map[z1][x1][y1 + 1] == 2){
		map[z1][x1][y1] = 9;
		y1 = y1 + 1;
		map[z1][x1][y1] = 11;
	}//언덕에서 언덕 입구로 갈떄
	else if (y1 < 12 && map[z1][x1][y1] == 11 && map[z1][x1][y1 + 1] == 9){
		map[z1][x1][y1] = 2;
		y1 = y1 + 1;
		map[z1][x1][y1] = 12;

	}//언덕입구에서 언덕으로 갈때
	else if (y1 < 12 && map[z1][x1][y1] == 12 && map[z1][x1][y1 + 1] == 9){
		map[z1][x1][y1] = 9;
		y1 = y1 + 1;
		map[z1][x1][y1] = 12;

	}//언덕에서 언덕으로 갈때
	/*공*/
	else if (map[z1][x1][y1] == map[z3][x3][y3 - 1]){
		map[z3][x3][y3] = 1;
		map[z1][x1][y1] = 1;
		y1 = y1 + 1;
		map[z1][x1][y1] = 15;
		tracefalg = 1;
	}//공 습득시
	else if (map[z1][x1][y1] == 15 || map[z1][x1][y1] == 17 || map[z1][x1][y1] == 16){
		if (y1 < 10 && map[z1][x1][y1 + 1] == 1 && map[z1][x1][y1] == 15){
			y1 = y1 + 1;
			map[z1][x1][y1 - 1] = 1;
			map[z1][x1][y1] = 15;
		}//기본이동
		else if (map[z1][x1][y1 + 1] == 3){
			map[z1][x1][y1] = 1;
			z1 = !z1;
			map[z1][x1][y1] = 15;
		}//엘레베이터 
		/*언덕*/
		if (y1 < 12 && map[z1][x1][y1] == 15 && map[z1][x1][y1 + 1] == 2){
			map[z1][x1][y1] = 1;
			y1 = y1 + 1;
			map[z1][x1][y1] = 16;
		}//길에서 언덕입구로 갈때
		else if (y1 < 12 && map[z1][x1][y1] == 16 && map[z1][x1][y1 + 1] == 1){
			map[z1][x1][y1] = 2;
			y1 = y1 + 1;
			map[z1][x1][y1] = 15;
		}//언덕 입구에서 길로 갈때
		else if (y1 < 12 && map[z1][x1][y1] == 17 && map[z1][x1][y1 + 1] == 2){
			map[z1][x1][y1] = 9;
			y1 = y1 + 1;
			map[z1][x1][y1] = 16;
		}//언덕에서 언덕 입구로 갈떄
		else if (y1 < 12 && map[z1][x1][y1] == 16 && map[z1][x1][y1 + 1] == 9){
			map[z1][x1][y1] = 2;
			y1 = y1 + 1;
			map[z1][x1][y1] = 17;

		}//언덕입구에서 언덕으로 갈때
		else if (y1 < 12 && map[z1][x1][y1] == 17 && map[z1][x1][y1 + 1] == 9){
			map[z1][x1][y1] = 9;
			y1 = y1 + 1;
			map[z1][x1][y1] = 17;
		}//언덕에서 언덕으로
	}
}
void Com_Up(){
	find_com();
	if (x2 > 0 && map[z2][x2 - 1][y2] == 1 && map[z2][x2][y2] == 5){
		map[z2][x2][y2] = 1;
		x2 = x2 - 1;
		map[z2][x2][y2] = 5;
	}//기본이동
	/*공 뺏는곳*/
	else if (x2 > 0 && map[z2][x2 - 1][y2] == 15){
		map[z2][x2 - 1][y2] = 4;

		map[z2][x2][y2] = 18;
		printf("공을 뺏겼습니다.\n");
		Sleep(2000);
	}
	else if (map[z2][x2][y2] == 5 && map[z2][x2 - 1][y2] == 3){
		map[z2][x2][y2] = 1;
		z2 = !z2;
		map[z2][x2][y2] = 5;
	}//엘레베이터 

	/*언덕*/
	else if (x2 > 0 && map[z2][x2 - 1][y2] == 2 && map[z2][x2][y2] == 5){
		map[z2][x2][y2] = 1;
		x2 = x2 - 1;
		map[z2][x2][y2] = 13;//언덕 입구 위에 게이머가 있을때

	}//길에서 언덕 입구로 들어갈때
	else if (x2 > 0 && map[z2][x2 - 1][y2] == 9 && map[z2][x2][y2] == 13){
		map[z2][x2][y2] = 2;
		x2 = x2 - 1;
		map[z2][x2][y2] = 14;//언덕 위에 게이머가 있을때
	}//언덕 입구에서 언덕으로 이동
	else if (x2 > 0 && map[z2][x2 - 1][y2] == 9 && map[z2][x2][y2] == 14){
		map[z2][x2][y2] = 9;
		x2 = x2 - 1;
		map[z2][x2][y2] = 14;//언덕 위에 게이머가 있을때
	}//언덕에서 언덕으로 이동
	else if (x2 > 0 && map[z2][x2 - 1][y2] == 2 && map[z2][x2][y2] == 12){
		map[z2][x2][y2] = 9;
		x2 = x2 - 1;
		map[z2][x2][y2] = 13;
	}//언덕에서 언덕입구로 이동




	/*공*/
	else if (map[z2][x2][y2] == map[z3][x3 + 1][y3]){
		map[z3][x3][y3] = 1;
		map[z2][x2][y2] = 1;
		x2 = x2 - 1;
		map[z2][x2][y2] = 18;
	}//공 습득시
	else if (map[z2][x2][y2] == 18 || map[z2][x2][y2] == 19 || map[z2][x2][y2] == 20){
		if (x2 > 0 && map[z2][x2 - 1][y2] == 1 && map[z2][x2][y2] == 18){
			map[z2][x2][y2] = 1;
			x2 = x2 - 1;
			map[z2][x2][y2] = 18;
		}//기본이동
		else if (map[z2][x2 - 1][y2] == 3){
			map[z2][x2][y2] = 1;
			z2 = !z2;
			map[z2][x2][y2] = 18;
		}//엘레베이터 

		/*언덕*/
		else if (x2 > 0 && map[z2][x2 - 1][y2] == 2 && map[z2][x2][y2] == 18){
			map[z2][x2][y2] = 1;
			x2 = x2 - 1;
			map[z2][x2][y2] = 19;//언덕 입구 위에 게이머가 있을때

		}//길에서 언덕 입구로 들어갈때
		else if (x2 > 0 && map[z2][x2 - 1][y2] == 9 && map[z2][x2][y2] == 1){
			map[z2][x2][y2] = 2;
			x2 = x2 - 1;
			map[z2][x2][y2] = 20;//언덕 위에 게이머가 있을때
		}//언덕 입구에서 언덕으로 이동
		else if (x2 > 0 && map[z2][x2 - 1][y2] == 9 && map[z2][x2][y2] == 20){
			map[z2][x2][y2] = 9;
			x2 = x2 - 1;
			map[z2][x2][y2] = 20;//언덕 위에 게이머가 있을때
		}//언덕에서 언덕으로 이동
		else if (x2 > 0 && map[z2][x2 - 1][y2] == 2 && map[z2][x2][y2] == 20){
			map[z2][x2][y2] = 9;
			x2 = x2 - 1;
			map[z2][x2][y2] = 19;
		}//언덕에서 언덕입구로 이동

	}
}
void Com_Down(){
	find_com();
	if (x2 < 12 && map[z2][x2][y2] == 5 && map[z2][x2 + 1][y2] == 1){
		x2 = x2 + 1;
		map[z2][x2 - 1][y2] = 1;
		map[z2][x2][y2] = 5;
	}//기본이동
	/*공 뺏는곳*/
	else if (x2 > 0 && map[z2][x2 + 1][y2] == 15){
		map[z2][x2 + 1][y2] = 4;

		map[z2][x2][y2] = 18;
		printf("공을 뺏겼습니다.\n");
		Sleep(2000);

	}
	else if (map[z2][x2][y2] == 5 && map[z2][x2 + 1][y2] == 3){
		map[z2][x2][y2] = 1;
		z2 = !z2;
		map[z2][x2][y2] = 5;
	}//엘레베이터 
	/*언덕*/
	if (x2 < 12 && map[z2][x2][y2] == 14 && map[z2][x2 + 1][y2] == 9){
		map[z2][x2][y2] = 9;
		x2 = x2 + 1;
		map[z2][x2][y2] = 14;
	}//언덕위에 있고 아래가 언덕일때
	else if (x2 < 12 && map[z2][x2][y2] == 14 && map[z2][x2 + 1][y2] == 2){
		map[z2][x2][y2] = 9;
		x2 = x2 + 1;
		map[z2][x2][y2] = 13;
	}//언덕위에 있고 아래가 언덕입구일때
	else if (x2 < 12 && map[z2][x2][y2] == 13 && map[z2][x2 + 1][y2] == 1){
		map[z2][x2][y2] = 2;
		x2 = x2 + 1;
		map[z2][x2][y2] = 5;
	}//언덕입구 위에 있고 아래가 길일때
	else if (x2 < 12 && map[z2][x2][y2] == 13 && map[z2][x2 + 1][y2] == 9){
		map[z2][x2][y2] = 2;
		x2 = x2 + 1;
		map[z2][x2][y2] = 14;
	}//언덕입구 위에 있고 아래가 언덕일때
	/*공*/
	else if (map[z2][x2][y2] == map[z3][x3 - 1][y3]){
		map[z3][x3][y3] = 1;
		map[z2][x2][y2] = 1;
		x2 = x2 + 1;
		map[z2][x2][y2] = 18;
	}//공 습득시
	else if (map[z2][x2][y2] == 18 || map[z2][x2][y2] == 19 || map[z2][x2][y2] == 20){
		if (x2 < 12 && map[z2][x2][y2] == 18 && map[z2][x2 + 1][y2] == 1){
			x2 = x2 + 1;
			map[z2][x2 - 1][y2] = 1;
			map[z2][x2][y2] = 18;
		}//기본이동
		else if (map[z2][x2 + 1][y2] == 3){
			map[z2][x2][y2] = 1;
			z2 = !z2;
			map[z2][x2][y2] = 18;
		}//엘레베이터 
		/*언덕*/
		if (x2 < 12 && map[z2][x2][y2] == 19 && map[z2][x2 + 1][y2] == 1){
			map[z2][x2][y2] = 2;
			x2 = x2 + 1;
			map[z2][x2][y2] = 18;
		}//언덕입구 위에 있고 아래가 길일때
		else if (x2 < 12 && map[z2][x2][y2] == 20 && map[z2][x2 + 1][y2] == 9){
			map[z2][x2][y2] = 9;
			x2 = x2 + 1;
			map[z2][x2][y2] = 20;
		}//언덕위에 있고 아래가 언덕일때
		else if (x2 < 12 && map[z2][x2][y2] == 20 && map[z2][x2 + 1][y2] == 2){
			map[z2][x2][y2] = 9;
			x2 = x2 + 1;
			map[z2][x2][y2] = 19;
		}//언덕위에 있고 아래가 언덕입구일때


	}

}
void Com_Left(){
	find_com();
	if (y2 > 0 && map[z2][x2][y2 - 1] == 1 && map[z2][x2][y2] == 5){
		y2 = y2 - 1;
		map[z2][x2][y2 + 1] = 1;
		map[z2][x2][y2] = 5;
	}//기본이동
	/*공 뺏는곳*/
	else if (x2 > 0 && map[z2][x2][y2 - 1] == 15){
		map[z2][x2][y2 - 1] = 4;

		map[z2][x2][y2] = 18;
		printf("공을 뺏겼습니다.\n");
		Sleep(2000);

	}
	else if (y1 > 0 && map[z2][x2][y2 - 1] == 3 && map[z2][x2][y2] == 5){
		map[z2][x2][y2] = 1;
		z2 = !z2;
		map[z2][x2][y2] = 5;
	}//엘레베이터 
	/*언덕*/
	if (y2 > 0 && map[z2][x2][y2] == 5 && map[z2][x2][y2 - 1] == 2) {
		map[z2][x2][y2] = 1;
		y2 = y2 - 1;
		map[z2][x2][y2] = 13;
	}//길에서 언덕입구로 들어갈때
	else if (y2 > 0 && map[z2][x2][y2] == 13 && map[z2][x2][y2 - 1] == 9){
		map[z2][x2][y2] = 2;
		y2 = y2 - 1;
		map[z2][x2][y2] = 14;

	}//언덕입구 위에 있고 왼쪽이 언덕일때
	else if (y2 > 0 && map[z2][x2][y2] == 14 && map[z2][x2][y2 - 1] == 9) {
		map[z2][x2][y2] = 9;
		y2 = y2 - 1;
		map[z2][x2][y2] = 14;

	}//언덕에서 언덕으로 이동할때
	else if (y2 > 0 && map[z2][x2][y2] == 14 && map[z2][x2][y2 - 1] == 2) {
		map[z2][x2][y2] = 9;
		y2 = y2 - 1;
		map[z2][x2][y2] = 13;

	}//언덕위에서 언덕입구로 갈때
	else if (y2 > 0 && map[z2][x2][y2] == 13 && map[z2][x2][y2 - 1] == 1){
		map[z2][x2][y2] = 2;
		y2 = y2 - 1;
		map[z2][x2][y2] = 5;

	}//언덕 입구에서 길로 나갈때
	/*공*/
	else if (map[z2][x2][y2] == map[z3][x3][y3 + 1]){
		map[z3][x3][y3] = 1;
		map[z2][x2][y2] = 1;
		y2 = y2 - 1;
		map[z2][x2][y2] = 18;
	}//공 습득시
	else if (map[z2][x2][y2] == 18 || map[z2][x2][y2] == 19 || map[z2][x2][y2] == 20){
		if (y2 > 0 && map[z2][x2][y2 - 1] == 1 && map[z2][x2][y2] == 18){
			y2 = y2 - 1;
			map[z2][x2][y2 + 1] = 1;
			map[z2][x2][y2] = 18;
		}//기본이동
		else if (y1 > 0 && map[z2][x2][y2 - 1] == 3){
			map[z2][x2][y2] = 1;
			z2 = !z2;
			map[z2][x2][y2] = 18;
		}//엘레베이터 
		/*언덕*/
		if (y2 > 0 && map[z2][x2][y2] == 18 && map[z2][x2][y2 - 1] == 2) {
			map[z2][x2][y2] = 1;
			y2 = y2 - 1;
			map[z2][x2][y2] = 19;
		}//길에서 언덕입구로 들어갈때
		else if (y2 > 0 && map[z2][x2][y2] == 19 && map[z2][x2][y2 - 1] == 9){
			map[z2][x2][y2] = 2;
			y2 = y2 - 1;
			map[z2][x2][y2] = 20;

		}//언덕입구 위에 있고 왼쪽이 언덕일때
		else if (y2 > 0 && map[z2][x2][y2] == 20 && map[z2][x2][y2 - 1] == 9) {
			map[z2][x2][y2] = 9;
			y2 = y2 - 1;
			map[z2][x2][y2] = 20;

		}//언덕에서 언덕으로 이동할때
		else if (y2 > 0 && map[z2][x2][y2] == 20 && map[z2][x2][y2 - 1] == 2) {
			map[z2][x2][y2] = 9;
			y2 = y2 - 1;
			map[z2][x2][y2] = 19;

		}//언덕위에서 언덕입구로 갈때
		else if (y2 > 0 && map[z2][x2][y2] == 19 && map[z2][x2][y2 - 1] == 1){
			map[z2][x2][y2] = 2;
			y2 = y2 - 1;
			map[z2][x2][y2] = 18;

		}//언덕 입구에서 길로 나갈때
	}

}
void Com_Right() {
	find_com();
	if (y2 < 12 && map[z2][x2][y2 + 1] == 1 && map[z2][x2][y2] == 5){
		y2 = y2 + 1;
		map[z2][x2][y2 - 1] = 1;
		map[z2][x2][y2] = 5;
	}//기본이동
	/*공 뺏는곳*/
	else if (x2 > 0 && map[z2][x2][y2 + 1] == 15){
		map[z2][x2][y2 + 1] = 4;

		map[z2][x2][y2] = 18;
		Sleep(2000);

	}//길에서

	else if (map[z2][x2][y2 + 1] == 3 && map[z2][x2][y2] == 5){
		map[z2][x2][y2] = 1;
		z2 = !z2;
		map[z2][x2][y2] = 5;
	}//엘레베이터 
	/*언덕*/
	if (y2 < 12 && map[z2][x2][y2] == 5 && map[z2][x2][y2 + 1] == 2){
		map[z2][x2][y2] = 1;
		y2 = y2 + 1;
		map[z2][x2][y2] = 13;
	}//길에서 언덕입구로 갈때
	else if (y2 < 12 && map[z2][x2][y2] == 13 && map[z2][x2][y2 + 1] == 1){
		map[z2][x2][y2] = 2;
		y2 = y2 + 1;
		map[z2][x2][y2] = 5;
	}//언덕 입구에서 길로 갈때
	else if (y2 < 12 && map[z2][x2][y2] == 14 && map[z2][x2][y2 + 1] == 2){
		map[z2][x2][y2] = 9;
		y2 = y2 + 1;
		map[z2][x2][y2] = 13;
	}//언덕에서 언덕 입구로 갈떄
	else if (y2 < 12 && map[z2][x2][y2] == 13 && map[z2][x2][y2 + 1] == 9){
		map[z2][x2][y2] = 2;
		y2 = y2 + 1;
		map[z2][x2][y2] = 14;

	}//언덕입구에서 언덕으로 갈때
	else if (y2 < 12 && map[z2][x2][y2] == 14 && map[z2][x2][y2 + 1] == 9){
		map[z2][x2][y2] = 9;
		y2 = y2 + 1;
		map[z2][x2][y2] = 14;

	}//언덕에서 언덕으로 갈때
	/*공*/
	else if (map[z2][x2][y2] == map[z3][x3][y3 - 1]){
		map[z3][x3][y3] = 1;
		map[z2][x2][y2] = 1;
		y2 = y2 + 1;
		map[z2][x2][y2] = 18;
	}//공 습득시
	else if (map[z2][x2][y2] == 18 || map[z2][x2][y2] == 19 || map[z2][x2][y2] == 20){
		if (y2 < 12 && map[z2][x2][y2 + 1] == 1 && map[z2][x2][y2] == 18){
			y2 = y2 + 1;
			map[z2][x2][y2 - 1] = 1;
			map[z2][x2][y2] = 18;
		}//기본이동
		else if (map[z2][x2][y2 + 1] == 3){
			map[z2][x2][y2] = 1;
			z2 = !z2;
			map[z2][x2][y2] = 18;
		}//엘레베이터 
		/*언덕*/
		if (y2 < 12 && map[z2][x2][y2] == 18 && map[z2][x2][y2 + 1] == 2){
			map[z2][x2][y2] = 1;
			y2 = y2 + 1;
			map[z2][x2][y2] = 19;
		}//길에서 언덕입구로 갈때
		else if (y2 < 12 && map[z2][x2][y2] == 19 && map[z2][x2][y2 + 1] == 1){
			map[z2][x2][y2] = 2;
			y2 = y2 + 1;
			map[z2][x2][y2] = 18;
		}//언덕 입구에서 길로 갈때
		else if (y2 < 12 && map[z2][x2][y2] == 20 && map[z2][x2][y2 + 1] == 2){
			map[z2][x2][y2] = 9;
			y2 = y2 + 1;
			map[z2][x2][y2] = 19;
		}//언덕에서 언덕 입구로 갈떄
		else if (y2 < 12 && map[z2][x2][y2] == 19 && map[z2][x2][y2 + 1] == 9){
			map[z2][x2][y2] = 2;
			y2 = y2 + 1;
			map[z2][x2][y2] = 20;

		}//언덕입구에서 언덕으로 갈때
		else if (y2 < 12 && map[z2][x2][y2] == 20 && map[z2][x2][y2 + 1] == 9){
			map[z2][x2][y2] = 9;
			y2 = y2 + 1;
			map[z2][x2][y2] = 20;
		}//언덕에서 언덕으로
	}
}
