/*
 * MinimaxPlayer.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: wong
 */
#include <iostream>
#include <assert.h>
#include "MinimaxPlayer.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using std::vector;

MinimaxPlayer::MinimaxPlayer(char symb) :
		Player(symb) {

}

MinimaxPlayer::~MinimaxPlayer() {

}

void MinimaxPlayer::get_move(OthelloBoard* b, int& col, int& row) {
	int minV = INT_MAX;
	int minCol = 0;
	int minRow = 0;
    for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			OthelloBoard * s = new OthelloBoard(*b);
			if (s->is_legal_move(i, j, 'O')) {
				s->play_move(i, j, 'O');
				int check = min(minV, maxValue(s));
				if (check < minV) {
					minV = check;
					minCol = i;
					minRow = j;
				}
			}
		}
	}
	col = minCol;
	row = minRow;
}

int MinimaxPlayer::maxValue(OthelloBoard* b) {
	if (!b->has_legal_moves_remaining('X')) {
		return getUtility(b);
	}
	else {
		int maxV = INT_MIN;
		vector <OthelloBoard*> successors = getSuccessors(b, 'X');
		for (int i = 0; i < successors.size(); i++) {
			maxV = max(maxV, minValue(successors[i]));
		}
		return maxV;
	}
}

int MinimaxPlayer::minValue(OthelloBoard* b) {
	if (!b->has_legal_moves_remaining('O')) {
		return getUtility(b);
	}
	else {
		int minV = INT_MAX;
		vector <OthelloBoard*> successors = getSuccessors(b, 'O');
		for (int i = 0; i < successors.size(); i++) {
			minV = min(minV, maxValue(successors[i]));
		}
		return minV;
	}
}

std::vector <OthelloBoard*> MinimaxPlayer::getSuccessors(OthelloBoard* b, char symb) {
	std::vector<OthelloBoard*> successors;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			OthelloBoard * s = new OthelloBoard(*b);
			if (s->is_legal_move(i,j, symb)) {
				s->play_move(i,j, symb);
				successors.push_back(s);
			}
		}
	}
	return successors;
}

int MinimaxPlayer::getUtility(OthelloBoard* b) {
	int netScoreForP1 = b->count_score('X') - b->count_score('O');
	if (netScoreForP1 < 0) {
		return -1;
	}
	else if (netScoreForP1 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

MinimaxPlayer* MinimaxPlayer::clone() {
	MinimaxPlayer* result = new MinimaxPlayer(symbol);
	return result;
}
