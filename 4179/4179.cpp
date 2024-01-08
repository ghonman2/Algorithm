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

int r,c;
pi ji;
vector<pi> fis;

vector<string> board;

const int dx[4] = {0,0,1,-1,} , dy[4] = {1,-1,0,0};
void input()
{
	cin >> r >> c;
	board = vector<string>(r,string(c,'.'));
	for (int i = 0; i< r ; i++){
		for (int j = 0; j < c; j ++){
			cin >> board[i][j];
			if (board[i][j] == 'J')
				ji = make_pair(i,j);
			else if (board[i][j] == 'F')
				fis.push_back(make_pair(i,j));
		}
	}
}

void makeFire(vector<vector<int>> &fire)
{
	queue<pi>q;
	queue<int> timeQ;

	for (auto &fi : fis){
		q.push(fi);
		timeQ.push(0);
		fire[fi.first][fi.second] = 0;
	}

	while (!q.empty()){
		int x,y; tie(x,y)= q.front();q.pop();
		int t = timeQ.front(); timeQ.pop();

		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i] ,ny = y + dy[i];			
			if (nx < 0 || ny < 0 || nx >= r || ny>=c ||
					board[nx][ny] == '#' || (fire[nx][ny] != INT_MAX && fire[nx][ny] <= t+1)) continue;
			fire[nx][ny] = t+1;
			q.push(make_pair(nx,ny));
			timeQ.push(t+1);
		}
	}
}

void sol()
{
	int answer = -1;
	vector<vector<int>> v(r, vector<int>(c,0));
	vector<vector<int>> fire(r, vector<int>(c, INT_MAX));
	makeFire(fire);
	
	queue<pi>q;
	queue<int> timeQ;

	v[ji.first][ji.second] = 1;
	q.push(ji);
	timeQ.push(0);

	while (!q.empty()){
		int x,y; tie(x,y) = q.front(); q.pop();
		int t = timeQ.front();timeQ.pop();

		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >=r || ny >= c){answer = t + 1; break;}
			if (board[nx][ny] == '#' || fire[nx][ny] <= (t+1) || v[nx][ny]) continue;
			v[nx][ny] = 1;
			q.push(make_pair(nx,ny));
			timeQ.push(t+1);
		}

		if (answer != -1)
			break ;
	}
	if (answer == -1)
		cout << "IMPOSSIBLE" << "\n";
	else
		cout << answer << '\n';
}

int main()
{
	input();
	sol();
	return (0);
}
