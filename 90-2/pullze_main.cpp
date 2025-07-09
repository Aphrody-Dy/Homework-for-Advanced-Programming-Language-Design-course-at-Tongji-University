// 
#include <iostream>
#include "pullze.h"
using namespace std;

/***************************************************************************
  函数名称：main
  功    能：主函数
  输入参数：无
  返 回 值：0
  说    明：
***************************************************************************/
int main()
{
	gameState state;
	while (1) {
		state.m = menu(&state.size);
		if (state.m == 'q' || state.m == 'Q') {
			cout << endl << endl << endl;
			cout << "游戏已退出" << endl;
			return 0;
		}
		if (state.m == 'A' || state.m == 'B' || state.m == 'C') {
			int circle = baseMode(state.cheat, state.m, state.size, state.answer, state.rowHints, state.colHints, &state.rowHintLen, &state.colHintLen, state.user);
			if (!circle) {
				continue;
			}
			if (circle == 2) {
				return 0;
			}
		}
		
		else {
			visualMode(state.cheat,state.m,state.size,state.answer,state.rowHints,state.colHints,&state.rowHintLen,&state.colHintLen,state.user);
		}
	}
}