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

#include<bits/stdc++.h>

using namespace std;

vector<int> nums;
set<int> v;
int n;

void input()
{
	cin >> n;
	nums = vector<int>(n);
	for (auto &t : nums)
		cin >> t;
}

int getSum(vector<int> &ns)
{
	int ret = ns[0];

	if (ns.size() <= 2) return (ns.size() < 2 ? ret : ns[0] + ns[1]);

	ret += ns[1];
	for (int i = 2; i < n; i ++){
		ret = ret * 2 + ns[i];
	}
	return (ret);
}

void sol()
{
	priority_queue<int,vector<int>, greater<int>>q;
	int answer = 0;

	for (auto &n : nums)
		q.push(n);

	while (q.size() != 1)
	{
		int t1 = q.top(); q.pop();
		int t2 = q.top(); q.pop();
		answer += (t1 + t2);
		q.push(t1 + t2);
	}
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
