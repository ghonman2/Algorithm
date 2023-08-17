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

int n,m;
vi indegree;
vector<vi> graph;
void input()
{
	cin >> n >> m;
	indegree = vi(n+1,0);
	graph = vector<vi>(n + 1);
	for (int i = 0 ; i < m; i ++)
	{
		int frm, dst;
		cin >> frm >> dst;
		indegree[dst]++;
		graph[frm].push_back(dst);
	}
}

void findNoInput(priority_queue<int,vector<int>, greater<int>> &q)
{
	for (int i = 1; i <= n ; i ++)
	{
		if (indegree[i] == 0){
			q.push(i);
		}
	}	
}

void sol()
{
	priority_queue<int,vector<int>, greater<int>>q;
	vector<int> ret;
	findNoInput(q);
	
	while (!q.empty())
	{
		int node = q.top(); q.pop();
		ret.push_back(node);
		for (auto n : graph[node]){
			indegree[n] --;
			if (indegree[n] == 0)
				q.push(n);
		}
	}
	if ((int)ret.size() != n )
			printf("FUCK\n");
	for (int i = 0 ; i < (int)ret.size(); i ++)
		cout << ret[i] << " ";
	cout << endl;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	sol();
	return (0);
}
