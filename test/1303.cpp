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

typedef pair<int, int> pi;

int n, m;
vector<string> board;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};
vector<vector<int>>v;


void input()
{
	cin >> m >> n;
	board = vector<string>(n);
	for (auto & row : board)
		cin >> row;
	v = vector<vector<int>>(n,vector<int>(m,0));
}

int bfs(int _x, int _y, char ch)
{
	int nrCnt = 1;
	queue<pi> q;
	q.push(make_pair(_x, _y));
	v[_x][_y] = 1;

	while (!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != ch || v[nx][ny]) continue;
			nrCnt += 1;
			v[nx][ny] = 1;
			q.push(make_pair(nx, ny));
		}
	}
	return nrCnt;
}

void sol()
{
	int answer[2] ={0,0};

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j ++){
			if (v[i][j]) continue;
			int cnt = bfs(i, j, board[i][j]);
			answer[board[i][j] == 'W' ? 0 : 1] += cnt * cnt; 
		}
	}
	printf("%d %d\n", answer[0], answer[1]);
}

int main()
{
	input();
	sol();
	return (0);
}
