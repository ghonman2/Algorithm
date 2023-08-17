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

typedef pair<int, int>pi;

int n,m;

vector<string>beg;
vector<string>target;

void input()
{
	cin >> n >> m;
	
	target = vector<string>(n);
	beg = vector<string>(n);
	for(auto &b :beg)
		cin >> b;
	for (auto &t : target)
		cin >> t;
}

void change(int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
			beg[i][j] = beg[i][j] == '0' ? '1' : '0';  
	}
}

void back()
{
	int answer = 0;
	if (n-3 < 0 || m - 3 < 0 ){
		cout << -1 << endl; 
		return ;
	}
	for (int i = 0 ; i <= n - 3 ; i++)
	{
		for (int  j = 0 ; j <= m - 3; j ++)
		{
			if (beg[i][j] != target[i][j])
			{
				change(i,j);
				answer ++;
			}
		}
	}

	if (beg == target)
		cout << answer << endl;
	else
		cout << -1  <<endl;
}

int main()
{
	input();
	back();
	return (0);
}
