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
typedef vector<int> vi;

int n, m;

vector<vi> board;

void input()
{
	cin >> n >> m ;
	string line;
	board = vector<vi>(n, vi(m));

	for (int i = 0 ; i < n ; i ++){
		cin >> line;
		for (int j = 0; j < m; j ++)
			board[i][j] = line[j] - '0';
	}
}

void sol()
{
	int maxIter = min(n, m);
	int iter = maxIter;
	int check = 0;
	for (;iter > 0; iter --){
		for (int i = 0 ; i + iter < n ; i ++){
			for (int  j = 0; j + iter < m; j++){
				if (board[i][j] == board[i][j + iter] && board[i][j] == board[i+ iter][j] && board[i][j] == board[i + iter][j + iter]){
					check = 1;
				}
			}
		}
		if (check)
			break ;
	}
	cout << (iter + 1 ) *( iter + 1 )<< endl;
}

int main()
{
	input();
	sol();
	return (0);
}
