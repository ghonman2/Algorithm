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

#define INIT_COST (1000 * 20 + 1)

typedef pair<int, int>pi;

int c, n;
vector<pi> infos;
unordered_map<int, int >dp;

void input()
{
	cin >> c >> n;
	infos = vector<pi>(n);
	for (auto &info : infos){
		cin >> info.first >> info.second;
	}
}

void sol()
{
	for (auto &info : infos)
		dp[info.first] = info.second;
	int cost = 0;

	while (1)
	{
		for (int i = 0 ; i <= cost; i ++)
			dp[cost] = max(dp[cost - i] + dp[i], dp[cost]);
		if (dp[cost] >= c)
			break;
		//printf("%d ", dp[cost]);
		cost ++;
	}
	//printf("\n");
	cout << cost << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
