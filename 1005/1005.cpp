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

typedef vector<int> vi;
typedef pair<int, int> pi;

int t,n,k, w;
int T = 0;

vi timeToBuild;
vector<vi>graph;
vi inDegree;

void input()
{
	cin >> n >> k;
	timeToBuild = vi(n+1);
	graph = vector<vi>(n+1);
	inDegree = vi(n+1, 0);

	for (int i = 1; i <= n; i++)
		cin >> timeToBuild[i];
	for (int i = 0, frm = 0, to = 0; i < k; i++){
		cin >> frm >> to;
		graph[frm].push_back(to);
		inDegree[to] ++;
	}
	
	cin >> w;
}

void sol()
{
	vector<int> time(n+1, 0);
	queue<int>q;
	vector<vi> result(n+1);

	for (int i = 1; i <= n; i++){
		if (!inDegree[i]) q.push(i);
		time[i] = timeToBuild[i];
	}

	while (!q.empty()){
		int build = q.front(); q.pop();
		//result[build.second].push_back(build.first);
	
		for (auto &g : graph[build]){
			time[g] = max(time[g], time[build] + timeToBuild[g]);
			if(--inDegree[g] == 0){
				q.push(g);
			}
		}
	}
	cout << time[w] << endl;
}

int main()
{
	cin >> t;
	while (++T <= t){
		input();
		sol();
	}
	return (0);
}
