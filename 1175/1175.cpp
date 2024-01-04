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

int n,m;
vector<string> board;
pi start;
int destCnt = 0;
int v[50][50][4];
vector<pi> dests;
int dir = -1;

const int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};


struct Info{
	int x;
	int y;
	int dir;
	int cnt;
};

void input()
{
	cin >> n >> m;
	board = vector<string>(n);
	for (int i= 0 ; i < n ; i ++){
		string &line = board[i];
		cin >> line;
		for (int j = 0; j < m; j++){
			if (line[j] == 'S'){ start = make_pair(i,j); line[j] = '.';}
			else if (line[j] == 'C') dests.push_back(make_pair(i,j));
		}
	}
}

int bfs(pi begin, pi dst, int &dir)
{

}


void sol()
{
}

int main()
{
	input();
	sol();
	return (0);
}
