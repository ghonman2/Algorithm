/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>pi;

int n = 5;
vector<string> board(5);

const int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
void input()
{
	for (auto &line : board)
		cin >> line;
}

int isSequence(vector<int> &tail)
{
	queue<int> q;
	set<int> s;
	for (int i = 0; i < 25; i ++){
		if (tail[i]) s.insert(i);
		if (tail[i] && q.empty())q.push(i);
	}

	while (!q.empty()){
		int x = q.front() / 5, y = q.front() % 5, num = q.front(); q.pop();

		if (s.find(num) == s.end()) continue;
		else s.erase(num);

		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;
			q.push(nx * 5 + ny);
		}
	}
	return (s.size() == 0);
}

int isFine(vector<int> &tail)
{
	int cnt = 0;

	for (int i = 0; i < 25; i ++){
		if (!tail[i]) continue;
		if (board[i/5][i%5] == 'S')
			cnt ++;
	}
	return (cnt > 3);
}

void sol()
{
	vector<int> tail(25,0);
	int answer = 0;

	for (int i = 0; i < 7; i++)
		tail[i] = 1;
	do {
		if (!isSequence(tail)) continue;
		if (isFine(tail)) answer ++;
	}while (prev_permutation(tail.begin(),tail.end()));

	cout << answer << endl;
}


int main()
{
	input();
	sol();
	return (0);
}
