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

int n,sum = 0;
vector<int> marble;
long long dp[11][11][11][11][11][6][6];

void input()
{
	cin >> n;
	marble = vector<int>(n, 0);
	for (auto &m : marble){
		cin >> m;
		sum += m;
	}
}

long long dfs(int cnt, int prv, int pprv)
{
	if (cnt == sum)
		return (1);
	
	long long &tmp = dp[marble[0]][marble[1]][marble[2]][marble[3]][marble[4]][prv][pprv];
	if (tmp != -1)
		return tmp;
	tmp = 0;
	
	for (int i = 0; i < n ; i++){
		if(i == prv || i == pprv || !marble[i])continue;
		marble[i] -= 1;
		tmp += dfs(cnt + 1, i, prv);
		marble[i] += 1;
	}
	return tmp;
}

void sol()
{
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, -1, -1) << endl;
}

int main()
{
	input();
	sol();

	return (0);
}
