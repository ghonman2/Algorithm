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
typedef vector<int> vi;
typedef deque<int> di;

int n;
vi P, S;
set<vi> visited;

void input()
{
	cin >> n;
	P = vi(n);
	S = vi(n);
	for (int i = 0 ; i < n; i++)
		cin >> P[i];
	for (int i = 0 ; i < n; i++)
		cin >> S[i];
}

void suffle(vi &dst, vi &frm)
{
	for (int i = 0; i < n ; i ++)
		dst[i] = frm[S[i]];
}

int check(vi &a)
{
	for (int i = 0 ; i < n; i ++)
		if (a[i] != P[i])
			return (0);
	return (1);
}

void sol()
{
	int cnt = 0;
	vi now(n);
	for (int i = 0; i <n ; i++)
		now[i] = i % 3;
	vi prv = now;
	set<vi>visited;
	while (1)
	{
		prv = now;
		if (check(now))
			break;
		suffle(now,prv);
		if(visited.find(now) != visited.end()){
			cnt = -1;
			break;
		}
		cnt ++;
		visited.insert(now);
	}
	cout << cnt <<endl;
}

int main()
{
	input();
	sol();
	return (0);
}
