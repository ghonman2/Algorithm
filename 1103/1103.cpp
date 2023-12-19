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
typedef vector<int> vi;

int n,m; 
vector<string> board;
int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1};
int v[50][50];
int dp[50][50];
int fin[50][50];

void input()
{
	cin >> n >> m;
	board = vector<string>(n);
	for (auto &t : board)
		cin >> t;
	bzero(v,sizeof(v));
	memset(dp,-1,sizeof(dp));
}

int dfs(int x, int y)
{
	if (v[x][y]){printf("-1\n"); exit (0);};

	if (dp[x][y] != -1) return (dp[x][y]);
	else dp[x][y] = 0;
	v[x][y] = 1;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i] * (board[x][y] - '0'), ny = y + dy[i] * (board[x][y] - '0');
		if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'H') continue;
		dp[x][y] = max(dp[x][y], dfs(nx,ny) + 1); 
	}
	v[x][y] = 0;
	return  (dp[x][y]);
}

//int isCycle(int x, int y)
//{
//	v[x][y] = 1;
//	for (int i = 0; i < 4; i ++){
//		int nx = x + dx[i] * (board[x][y] - '0'), ny = y + dy[i] * (board[x][y] - '0');
//		if (nx < 0 || ny < 0 || nx >= n || ny >= m || board[nx][ny] == 'H') continue;
//		if (v[nx][ny] || isCycle(nx,ny)) return (1);
//	}
//	v[x][y] = 0;
//	return (0);
//}

void sol()
{
	int ret = dfs(0,0);
	printf("%d\n",ret + 1);
}

int main()
{
	input();
	sol();
	return (0);
}
