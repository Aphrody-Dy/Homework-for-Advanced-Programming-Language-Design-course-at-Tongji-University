// 
#include <iostream>
#include "pullze.h"
using namespace std;

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�������
  �����������
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int main()
{
	gameState state;
	while (1) {
		state.m = menu(&state.size);
		if (state.m == 'q' || state.m == 'Q') {
			cout << endl << endl << endl;
			cout << "��Ϸ���˳�" << endl;
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