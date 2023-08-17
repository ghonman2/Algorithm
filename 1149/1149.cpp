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

struct rgb{
	int r;
	int g;
	int b;
};

vector<struct rgb> colors;
int n;

void input()
{
	cin >> n;
	colors = vector<struct rgb>(n);

	for (auto &c : colors)
		cin >> c.r >> c.g >> c.b;
}

void sol()
{
	vector<struct rgb>dp(n, {INT_MAX,INT_MAX,INT_MAX});

	dp[0] = colors[0];
	for (int i = 1; i < n; i++)
	{
		dp[i].r = min(dp[i - 1].g, dp[i - 1].b) + colors[i].r;
		dp[i].g = min(dp[i - 1].r, dp[i - 1].b) + colors[i].g;
		dp[i].b = min(dp[i - 1].r, dp[i - 1].g) + colors[i].b;
	}
	int answer = min(dp[n-1].r, dp[n-1].g);
	answer = min(dp[n-1].b, answer);
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
