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

int T, n, order = 1;
vector<int>nums, v, f;
int answer = 0;
void input()
{
	cin >> n;
	nums = vector<int>(n);
	v = vector<int>(n,0);
	f = vector<int>(n,0);
	for (auto &num : nums)
	{
		cin >> num;
		num --;
	}
}

void dfs(int node)
{
	int &next_node = nums[node];
	v[node] = order ++;

	if (!v[next_node])
		dfs(next_node);
	else if (!f[next_node])
		answer += v[node] - v[next_node] + 1;
	f[node] = 1;
}

void sol()
{
	input();
	answer = 0;
	for (int i = 0; i < n; i ++){
		if (!f[i])
			dfs(i);
	}
	cout << n - answer << endl;
}

int main()
{
	cin >> T;
	int t = 0;
	while (t ++ < T)
		sol();
	return (0);
}
