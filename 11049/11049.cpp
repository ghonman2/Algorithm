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
#define FAST ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int>pi;

int n;
vector<pi> rces;

void input()
{
	cin >> n;
	rces = vector<pi>(n);
	for (auto &s : rces)
		cin >> s.first >> s.second;
}

void sol()
{
	vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
	for (int i = 0; i < n ; i++)
		dp[i][i] = 0;

	for (int x = 0; x < n; x ++){
		for (int y = x + 1; y < n; y ++){
			for (int mid = x + 1; mid < y; mid++){
				dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y] + rces[x].first * rces[mid].second *rces[y].second);
			}
		}
	}
	for (auto &num : dp[n-1])
		printf("%d ", num);
	printf("\n");

	printf("%d\n",dp[n-1][n-1]);
}

int main(){
	FAST;
	input();
	sol();
	return 0;
}

