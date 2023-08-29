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

typedef pair<int, int> pi;

int n, frm, dst;
vector<int> stone;

void input()
{
	cin >> n ;
	stone = vector<int> (n + 1, 0);
	for (int i = 1; i <=n; i++)
		cin >> stone[i];
	cin >> frm >> dst;
	return ;
}

void sol()
{
	queue<pi> q;
	vector<int> v(n+1,0);
	q.push(make_pair(frm, 0));
	int answer = -1;

	while (!q.empty()){
		int node = q.front().first, cnt = q.front().second; q.pop();
		v[node] = 1;
		if (node == dst){
			answer = cnt;
			break ;
		}
		int step = stone[node];
		for (int nxt = node; nxt <= n; nxt += step){
			if (v[nxt])continue;
			q.push(make_pair(nxt, cnt + 1));
		}
		for (int nxt = node; nxt > 0; nxt -= step){
			if (v[nxt])continue;
			q.push(make_pair(nxt, cnt + 1));
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
