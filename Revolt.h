#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <process.h>
#include <conio.h>


unsigned __stdcall sec_set(void* arg);//�ð� �Է��ϴ� ������
unsigned __stdcall map_prin(void* arg);//����� ���� ����ϴ� ������
unsigned __stdcall pro_man(void* arg);//���̸Ӱ� �����̴� ������
unsigned __stdcall pro_com(void* arg);//��ǻ�Ͱ� �����̴� ������

void map_print();
void greed_appear();
void red_appear();
void gamer_appear();
void com_appear();
void rand_appear();
void Man_Up();
void Man_Down();
void Man_Left();
void Man_Right();
void Com_Up();
void Com_Down();
void Com_Left();
void Com_Right();
void find_man();
void find_com();
void find_ball();
void wall_appear();
void find_man1();