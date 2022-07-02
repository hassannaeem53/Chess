#include "..\\include\\HellsBishops.h"
#include<iostream>
#include "..\\include\\ENUM.h"
#include<cstdlib>
using namespace std;


//Note :
//if max depth is not passed as the parameter then by default depth 3 will be used as maximum depth for our minimax algorithm

HellsBishops::HellsBishops(Color playerColor) :chessPlayer("Hell's Bishops", playerColor) {


}



int evaluate(gameState statecopy) {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			sum =sum+ statecopy.Board.board[i][j];
		}
	}
	return sum;
}
void copyBoard(gameState state1,gameState &state2) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			state2.Board.board[i][j]= state1.Board.board[i][j];
		}
	}

	state2.Actions = state1.Actions;
	state2.setPlayer(state1.getPlayer());
}
int minimax(gameState _state,int alpha,int beta,int depth,Color color,int& moveindex,int root) {
	if (depth == 0 || _state.Actions.getActionCount()==0) {
		return evaluate(_state);
	}
	action action;
	if (color == White) {//white
		cout << "white";
		for (int i = 0; i < _state.Actions.getActionCount(); i++) {
			gameState statecopy;
			copyBoard(_state, statecopy);
			//statecopy.applyMove(list[i]);
			_state.Actions.getAction(i, &action);
			statecopy.applyMove(action);
			int sum=minimax(statecopy, alpha, beta, depth - 1, Black,moveindex,root);

			if (sum > alpha) {
				alpha = sum;
				if (depth == root) {
					moveindex = i;
				}
				if (alpha >= beta)
					break;
			}

		}
		return alpha;
	}
	if (color == Black) {//Black
		cout << "Black";
		for (int i = 0; i < _state.Actions.getActionCount(); i++) {
			gameState statecopy;
			copyBoard(_state, statecopy);
			//statecopy.applyMove(list[i]);
			_state.Actions.getAction(i, &action);
			statecopy.applyMove(action);
			int sum=minimax(statecopy, alpha, beta, depth - 1, White,moveindex,root);
			if (sum < beta) {
				beta = sum;
				if (depth == root) {
					moveindex = i;
				}
				if (alpha >= beta)
					break;
			}
		}
		return beta;
	}

}
int getindex(gameState* state,Color color,int maxDepth) {
	int moveindex = -1;
	int alpha = INT_MIN;
	int beta = INT_MAX;
	int depth = maxDepth;
	minimax(*state,alpha,beta,depth,color,moveindex,depth);
	return moveindex;
}



void HellsBishops::decideMove(gameState* state, action* Move, int maxDepth) {
	int TotalMoves = state->Actions.getActionCount(); //= state->computePossibleActions();
	cout << endl << "Total Possible Moves " << TotalMoves;
	if (TotalMoves == 0) {
		Move->fromRow = Move->fromCol = Move->toRow = Move->toCol = 0;
		return;
	}
	if (maxDepth <= 0) {
		maxDepth = 2;
	}
	//int RandomlySelectedMove = rand() % TotalMoves;
	int SelectedMove = 0;
	SelectedMove = getindex(state, playerColor,maxDepth);

	state->Actions.getAction(SelectedMove, Move);

	return;
}
