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

int n = 0;

void input()
{
	cin >> n;
}

void dfs(int depth, vector<int> &line, vector<long long> &nums)
{
	if (depth > 9)
		return;

	for (int i = depth; i < 10 ; i ++)
	{
		line.push_back(i);
		long long num = 0;
		for (int d = line.size() - 1;d >= 0; d--)
			num = num * 10 + line[d];
		nums.push_back(num);
		dfs(i + 1 , line, nums);
		line.pop_back();
	}
}

int main()
{
	input();
	vector<long long>nums;
	vector<int> line;
	dfs(0,line, nums);
	sort(nums.begin(), nums.end());
	if ((int)nums.size() <= n)
		cout << - 1 << endl;
	else
		cout << nums[n] << endl;
	return (0);
}
