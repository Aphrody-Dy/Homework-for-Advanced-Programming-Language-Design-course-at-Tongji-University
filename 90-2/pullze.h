// 

#pragma once

#define MAX_SIZE 15

struct gameState {
	char m; // 选择的模式
	int size; //实际选择的模式大小

	int answer[MAX_SIZE][MAX_SIZE] = { 0 }; //预设的答案矩阵（0-无球，1-有球）
	int user[MAX_SIZE][MAX_SIZE] = { ' '}; //玩家的作答矩阵（0-无球，1-有球）

	int rowHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 }; //行提示，每行最后一个有效数字后用0或-1作为结束标记
	int colHints[MAX_SIZE][MAX_SIZE / 2 + 1] = { 0 }; //列提示

	int rowHintLen = 0;//行提示的最大长度（用于对齐）
	int colHintLen = 0; //列提示的最大长度（用于对齐）

	bool cheat = 0;;//用于控制作弊模式的开关
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