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

vector<int> orders;
int n;

void input()
{
	cin >> n;
	orders = vector<int>(n);
	for (auto &n : orders)
		cin >> n;
}

// 4 2 1 3
//       0
void getOrder(vector<int> &ret, vector<int> &nums)
{
	for (int i = 0 ; i < n ; i ++){
		int cnt = 0;
		for (int j = 0; j < i; j ++){
			if (nums[j] > nums[i])
				cnt ++;
		}
		ret[nums[i] - 1] = cnt;
	}
}

void sol()
{
	vector<int> nums(n);

	for (int i = 0; i < n ; i ++)
		nums[i] = i + 1;
	vector<int> permOrder(n);
	do {
		getOrder(permOrder, nums);
		if (permOrder == orders)
			break ;
	}while(next_permutation(nums.begin(), nums.end()));
	for (auto & n :nums)
		cout << n << ' ';
	cout << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
