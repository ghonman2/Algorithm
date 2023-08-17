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

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
deque<int> numbers;

int n,m;

vi orders;

void input()
{
	cin >> n >> m;
	numbers = deque<int>(n);
	orders = vi(m);
	for (int i = 0 ; i < n ; i ++)
		numbers[i] = i;
	for (int i = 0; i < m; i ++)
	{
		int x;
		cin >> x ;
		orders[i] = x - 1;
	}
}

void printNumber(int ans)
{
	printf("ans is %d : ",ans);
	for (auto n : numbers)
		printf("%-3d ", n);
	printf("\n");
}

void sol()
{
	int answer = 0;
	for (auto order : orders)
	{
		int idx = find(numbers.begin(), numbers.end(), order) - numbers.begin();
		if (idx == 0)
			numbers.pop_front();
		else if (idx <= (int)(numbers.size() / 2))
		{
			rotate(numbers.begin(), numbers.begin() + idx, numbers.end());
			answer += idx;
			numbers.pop_front();
		}else
		{
			rotate(numbers.begin(), numbers.end() - (numbers.size() - idx), numbers.end());
			answer += (numbers.size() - idx);
			numbers.pop_front();
		}
	}
	cout << answer << "\n";
	return ;
}

int main()
{
	input();
	sol();
	return (0);
}
