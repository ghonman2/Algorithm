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

int n;
vector<string> lines;
void input()
{
	cin >> n;
	lines = vector<string>(n);
	for (auto &line : lines)
		cin >> line;
}

int isPadline(string &line,int left, int right, bool isTest)
{
	while (left < right)
	{
		if (line[left] != line[right]){
			if (isTest) return (2);
			if (!isPadline(line, left, right - 1, true) || !isPadline(line, left + 1, right, true))
				return (1);
			return (2);
		}
		left ++, right --;
	}
	return (0);
}

void sol()
{
	for (auto &line : lines)
		cout << isPadline(line, 0, line.length() - 1, false) << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
