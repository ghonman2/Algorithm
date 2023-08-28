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

typedef vector<string> vs;

int n,m;
vs board;

void input()
{
	cin >> n >> m;
	board = vs(n);
	for (auto &s : board)
		cin >> s;
}

int isSqure(int number)
{
	int tmp = sqrt(number);
	return (double)tmp == sqrt(number);
}

int stpAdd(vector<pair<int, int>> &seq)
{
	int tmp = 0;
	for (auto &p : seq){
		tmp = tmp * 10 + board[p.first][p.second];
	}
	return isSqure(tmp) ? tmp : -1;
}

void sol()
{
	int answer = -1;

}

int main()
{
	input();
	sol();
	return (0);
}
