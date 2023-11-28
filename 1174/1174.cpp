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
#include <iostream>


#define MAXITER (2 << 9)
#define SNUM "9876543210"

using namespace std;
int n;
int check = 0;
string ret;

void input()
{
	cin >> n;
}


void dfs(int &depth, int idx)
{
	if (depth == n)
	{
		check = 1;
		cout << ret << endl;
		return ;
	}

	for (int i = idx; i >=0; i --)
	{
		ret += SNUM[i];
		depth += 1;
		dfs(depth, i - 1);
		ret.pop_back();
	}
}


void sol()
{
	int depth = 0;
	dfs(depth,9);
	if (!check)
		printf("-1\n");
}

int main()
{
	input();
	sol();
	return (0);
}
