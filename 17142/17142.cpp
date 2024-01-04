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
typedef vector<vi> vvi;

int n,m;
int nrZero = 0;
vvi board;
vector<pi> virus;


const int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};

void input()
{
	cin >> n >> m;
	board = vvi(n,vi(n));

	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			cin >> board[i][j];
			if (board[i][j] == 2) 
				virus.push_back(make_pair(i,j));
			else if (board[i][j] == 0)
				nrZero += 1;
		}
	}
}

int bfs(vector<int> &tmp)
{
	vvi v(n,vi(n,0));
	queue<pi> q;
	queue<int> timeQ;
	int cntZero = 0;

	for (size_t i = 0; i < virus.size(); i ++){
		if (!tmp[i]) continue;
		q.push(virus[i]);
		v[virus[i].first][virus[i].second] = 1;
		timeQ.push(0);
	}

	while (!q.empty()){
		int x,y,time = timeQ.front(); timeQ.pop();
		tie(x,y) = q.front();q.pop();

		if (board[x][y] == 0) cntZero ++;
		if (cntZero == nrZero) return (time);

		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1 || v[nx][ny]) continue;
			v[nx][ny] = 1;
			q.push(make_pair(nx,ny));
			timeQ.push(time + 1);
		}
	}
	return (INT_MAX);
}

void sol()
{
	int answer = INT_MAX;
	vector<int> tmp(virus.size(), 0);
	for (int i = 0; i < m; i ++)
		tmp[i] = 1;
	do {
		answer = min(bfs(tmp),answer);
	}while (prev_permutation(tmp.begin(),tmp.end()));
	if (answer == INT_MAX)
		cout << -1 << endl;
	else 
		cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
