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

int n, s;
vector<int>numbers;

void input()
{
	cin >> n;
	numbers = vector<int>(n);
	for (int i = 0 ; i < n; i ++)
		cin >> numbers[i];
	cin >> s;
}

int cmp(int &a, int &b)
{
	return (a > b);
}

void sol()
{
	int t = 0;
	int idx = 0;
	vector<int> sorted = numbers;
	sort(sorted.begin(), sorted.end(), cmp);
	while (t < s)
	{
		if (numbers == sorted)
			break ;
		if (numbers[idx] < numbers[idx + 1])
		{
			swap(numbers[idx], numbers[idx + 1]);
			t ++;
		}
		idx ++;
		if (idx == n - 1)
			idx = 0;
	}
	for (int i = 0 ; i < n ;i ++)
		cout << numbers[i] << " ";
	cout <<endl;
}

int main()
{
	input();
	sol();
	return (0);
}
