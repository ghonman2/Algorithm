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
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,pi> ppi;

typedef struct 
{
	int x;
	int y;
	int dir;
} Robot;


int v[100][100][4];
const int dx[4] = {0,0,1,-1},  dy[4] = {1,-1,0,0};


int n,m;
vector<vi> board;
Robot frm,dst;

void input()
{
	cin >> n >> m;
	board = vector<vi>(n,vi(m));

	for (auto &line : board)
		for (auto &num : line)
			cin >> num;
	cin >> frm.x >> frm.y >> frm.dir;
	cin >> dst.x >> dst.y >> dst.dir;

	frm.x -= 1, frm.y -=1 , frm.dir -= 1;
	dst.x -= 1, dst.y -= 1, dst.dir -= 1;
}


int bfs()
{
	queue<Robot> q;
	queue<int> cntQ;


	q.push(frm);
	cntQ.push(0);

	v[frm.x][frm.y][frm.dir] = 1;

	while (!q.empty()){
		Robot now = q.front(); q.pop();
		int cnt = cntQ.front(); cntQ.pop();
		if (now.x == dst.x && now.y == dst.y && now.dir == dst.dir) return (cnt);

		for (int i = 0; i < 2; i ++){
			int ndir = now.dir > 1 ? (0 + i) : (2 + i);
			if (v[now.x][now.y][ndir]) continue;
			v[now.x][now.y][ndir] = 1;
			q.push((Robot){now.x,now.y,ndir});
			cntQ.push(cnt + 1);
		}

		for (int i = 1; i <= 3; i ++){
			int nx = now.x + dx[now.dir] * i, ny = now.y + dy[now.dir] * i;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 1) break;
			if (v[nx][ny][now.dir]) continue;
			v[nx][ny][now.dir] = 1;
			q.push((Robot){nx,ny,now.dir});
			cntQ.push(cnt + 1);
		}
	}

	return (INT_MAX);
}

void sol()
{
	int tmp = bfs();
	printf("%d\n",tmp);
}


int main(){
	FAST;
	input();
	sol();
	return 0;
}
