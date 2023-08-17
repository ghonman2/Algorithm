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


int n,r,c;
int answer = 0;

void input()
{
	cin >> n >> r >> c;
}


void dfs(int x, int y, int size)
{
	if (r == x && y == c)
	{
		cout << answer << endl;
		return ;
	}
	
	if (r < x + size && r >= x && c < y +size && c >= y)
	{
		dfs(x, y, size / 2);
		dfs(x, y + size / 2, size / 2);
		dfs(x + size / 2, y , size / 2);
		dfs(x + size / 2, y + size / 2, size / 2);
	}
	else
		answer += size * size;
}

void sol()
{
	dfs(0,0,(1 << n));
}

int main()
{
	input();
	sol();
	return (0);
}
