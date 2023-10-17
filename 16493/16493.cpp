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
int n,m;
vector<pi> chapters;
vector<vector<int>>dp;

void input()
{
	cin >> n >> m;
	chapters = vector<pi>(m);
	for (auto & c : chapters)
		cin >> c.first >> c.second;

	dp = vector<vector<int>>(m+1, vector<int>(n+1,0));
}

void sol()
{
	for (int i = 1; i <= m; i ++){
		for (int j = 0; j <= n; j ++){
			if (j >= chapters[i].first)
				dp[i][j] = max(dp[i-1][j-chapters[i].first] + chapters[i].second, dp[i-1][j]);
			dp[i][j] = max(dp[i-1][j], dp[i][j]);
		}
	}
	cout << dp[m][n] << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
