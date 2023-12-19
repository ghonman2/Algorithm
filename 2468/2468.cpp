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

typedef vector<int>vi;
typedef pair<int, int>pi;


int n, maxDepth;
vector<vi> board;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};


void input()
{
	cin >> n;
	maxDepth = 0;
	board = vector<vi>(n,vi(n));
	for (auto &line :board){
		for (auto &num: line){
			cin >> num;
			maxDepth = max(num,maxDepth);
		}
	}
}


int bfs(pi pos, vector<vi> &v, int cut)
{
	queue<pi>q;
	q.push(pos);
	v[pos.first][pos.second] = 1;

	while (!q.empty()){
		pi now = q.front();q.pop();

		for (int i = 0; i < 4; i++){
			int nx = now.first + dx[i], ny = now.second + dy[i];

			if (nx < 0 || ny < 0 || nx >=n || ny >= n || 
					v[nx][ny] || board[nx][ny] <= cut) continue;
			v[nx][ny] = 1;
			q.push(make_pair(nx,ny));
		}
	}
	return (1);
}

int getArea(int cut)
{
	int ret = 0;
	vector<vi>v(n,vi(n,0));

	for (int i = 0; i< n ;i ++){
		for (int j = 0; j < n; j++){
			if (v[i][j] || board[i][j] <= cut) continue;
			ret += bfs(make_pair(i,j),v,cut);
		}
	}

	return (ret);
}

void sol()
{
	int ret = 1;
	for (int i = 1; i <= maxDepth; i++)
		ret = max(ret, getArea(i));
	printf("%d\n",ret);
}

int main()
{
	input();
	sol();
	return (0);
}
