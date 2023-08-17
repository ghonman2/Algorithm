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

typedef long long ll;

string l,r;

void input()
{
	cin >> l >> r;
}

int getDec(ll num)
{
	int cnt = 0;
	while (num)
	{
		cnt ++;
		num /= 10;
	}
	return cnt;
}

void sol()
{
	int answer = 0;
	int decL = l.length(), decR = r.length();

	if (decL != decR)
		cout << answer << endl;
	else
	{
		int idx = 0;
		for (; idx < decL; idx ++)
		{
			if (l[idx] != r[idx])
				break;
			else if (l[idx] == r[idx] && l[idx] == '8')
				answer ++;
		}
		cout << answer << endl;
	}
}

int main()
{
	input();
	sol();
	return (0);
}
