// 

#pragma once

#define MAX_SIZE 15

struct gameState {
	char m; // ѡ���ģʽ
	int size; //ʵ��ѡ���ģʽ��С

	int answer[MAX_SIZE][MAX_SIZE] = { 0 }; //Ԥ��Ĵ𰸾���0-����1-����
	int user[MAX_SIZE][MAX_SIZE] = { ' '}; //��ҵ��������0-����1-����

	int rowHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 }; //����ʾ��ÿ�����һ����Ч���ֺ���0��-1��Ϊ�������
	int colHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 }; //����ʾ

	int rowHintLen = 0;//����ʾ����󳤶ȣ����ڶ��룩
	int colHintLen = 0; //����ʾ����󳤶ȣ����ڶ��룩

	bool cheat = 0;;//���ڿ�������ģʽ�Ŀ���
};

char menu(int *size);
void end();
int checkWin(char m,bool cheat, int size, int(&user)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1]);

void initBoard(int size, int(&answer)[MAX_SIZE][MAX_SIZE]);
void generateHints(char m,bool cheat,int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen);
void basePrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE]);
void cMenu();
int baseMode(bool cheat,char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE]);

void visualPrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE]);
void convertXY(char m,int* x, int* y, int* rowHintLen, int* colHintLen);
int drawCell(char m,bool cheat, int user1, int user2, int answer, int i, int j, int* rowHintLen, int* colHintLen, int left);
int readMouseKey(bool cheat,char m,int size, int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1],int* rowHintLen, int* colHintLen, int(&answer)[MAX_SIZE][MAX_SIZE],int(&user)[MAX_SIZE][MAX_SIZE]);
void visualMode(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE]);

void framePrint(bool cheat, char m, int size, int(&answer)[MAX_SIZE][MAX_SIZE], int(&rowHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int(&colHints)[MAX_SIZE][MAX_SIZE / 2 + 1], int* rowHintLen, int* colHintLen, int(&user)[MAX_SIZE][MAX_SIZE]);
void frameCell(int x, int y, int i, int j,int shape,const int bg=1,const int fg=0);