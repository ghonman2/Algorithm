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

string name;

void input()
{
	cin >> name;
	return ;
}


int isPandlin(string &n)
{
	int length = n.length();
	for (int i = 0 ; i < length; i ++){
		if (n[i] != n[length - i - 1]) return (0);
	}
	return (1);
}

void sol()
{
	int n = name.length();
	for (int i = 0 ; i < n - 1 ; i ++){
		string sub = name.substr(0, i);
		reverse(sub.begin(), sub.end());
		string tmp = name + sub;
		if (!isPandlin(tmp))continue;
		cout << tmp.length() << endl;
		return ;
	}
	cout << name.length() * 2 - 1 << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
