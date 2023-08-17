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

vector<int> wrongButtons;
vector<int> buttons(10, 1);
int target;
int n;

#define MAX_ITER 1000001

void input()
{
	cin >> target;
	cin >> n;
	for (int i = 0; i < n ; i ++){
		int tmp;
		cin >> tmp;
		buttons[tmp] = 0;
	}
}

int isTrans(int num)
{
	string n = to_string(num);
	for (int i = 0 ; i < (int)n.length(); i++){
		if (!buttons[n[i] - '0'])
			return (0);
	}
	return (1);
}

void sol()
{
	int minNum = abs(target - 100);
	for (int i = 0 ; i < MAX_ITER; i ++){
		if (isTrans(i)){
			minNum = min((int)(abs(target - i) + to_string(i).length()), minNum);
		}
	}
	cout << minNum << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	sol();
	return (0);
}
