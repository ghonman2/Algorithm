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

#define INIT_COST (100001)

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
	int dp[INIT_COST];
	memset(dp,0,sizeof(dp));

	for (int i = 0; i < INIT_COST; i ++){
		for (auto &cost: infos){
			if (i >= cost.first) dp[i] = max(dp[i], dp[i-cost.first] + cost.second);
		}
		if (dp[i] >= c){
			printf("%d\n",i);
			break;
		}
	}
}

int main()
{
	input();
	sol();
	return (0);
}
