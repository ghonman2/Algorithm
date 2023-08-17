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

inline double getSlope(int x, int y)
{
	return ((1.0) * (numbers[x] - numbers[y]) / ((x-y) * 1.0));
}

void sol()
{
	int answer = 0;
	for (int i = 0 ; i < (int)numbers.size() - 1; i ++)
	{
		int  j = i +1;
		for (; j < (int)numbers.size(); j ++)
		{
			double stdSlope = getSlope(i, j);
			int tmp = 1;
			for (int idx = i + 1; idx < j ; idx ++)
			{
				double slope = getSlope(i, idx);
				if (slope < stdSlope)
					tmp += 1;
				else
					break;
			}
			answer = max(tmp, answer);
		}
	}
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
