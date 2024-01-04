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
typedef vector<int> vi;

vector<vector<int>>v;
int n,m;

int dx[8] = {0,0,-1,1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int bfs(vector<string> &board, pi start, int& cnt)
{
	queue<pi> q;
	q.push(start);
	v[start.first][start.second] = 1;
	int t = 0;

	while (!q.empty()){
		int x,y;
		tie(x,y) = q.front(); q.pop();
		cnt += 1;
		t = 0;

		for (int i = 0; i < 8; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] 
					|| board[nx][ny] == '.')continue;
			v[nx][ny] = 1;
			q.push(make_pair(nx,ny));
		}
	}

	return (1);
}

vector<int> soluntion(vector<string> board)
{
	vector<int> answer(2,0);
	n = board.size(), m = board[0].length();
	v = vector<vector<int>>(n, vi(m,0));
	answer[1] = 0;

	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j++){
			if (board[i][j] == '.')
				floodFill(board,i,j,answer[1]);
		}
	}
	printf("%d %d\n",answer[0], answer[1]);
	return (answer);
}


int main()
{
	int n = 0;
	cin >> n;
	vector<string>board(n);

	for (auto &s: board)
		cin >> s;
	soluntion(board);
	return (0);
}
