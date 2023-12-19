/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * pubtmphed by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> numbers;

void input()
{
	cin >> n ;
	numbers = vector<int>(n);
	for (auto &n : numbers)
		cin >> n;
}

double getScope(int x, int y)
{
	return ((numbers[x] - numbers[y])  * (1.0) / (x-y));
}

void sol()
{
	vector<int>cnt(n,0);

	for (int i = 0; i < n; i ++){
		double maxScope = -1000000000;
		for (int j = i +1 ; j < n ; j ++){
			int h = numbers[j] - numbers[i];
			int w = j - i;
			double scope = h * 1.0 / w;
			if (scope <= maxScope)continue;
			maxScope = scope;
			cnt[i] ++; cnt[j]++;
		}
	}
	printf("%d\n",*max_element(cnt.begin(), cnt.end()));
}

int main()
{
	input();
	sol();
	return (0);
}
