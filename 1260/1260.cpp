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

vector<vi>graph;
int n,m,v;

void input()
{
	int frm,to;
	cin >> n >> m >> v;
	graph = vector<vi>(n + 1);

	for (int i = 0; i < m; i++){
		cin >> frm >> to;
		graph[frm].push_back(to);
		graph[to].push_back(frm);
	}
	for (auto &node : graph){
		sort(node.begin(), node.end());
	}
}


void dfs(int node, vector<int> &v)
{
	printf("%d ",node);
	v[node] = 1;
	for (auto &point : graph[node]){
		if (!v[point])
			dfs(point, v);
	}
}

void bfs(int frm, vector<int> &v)
{
	queue<int> q;
	q.push(frm);
	while (!q.empty()){
		int node = q.front(); q.pop();
		if (v[node]) continue;
		v[node] = 1;
		printf("%d ",node);
		for (auto &point : graph[node]){
			if (!v[point])
				q.push(point);
		}
	}
}

void sol()
{
	vector<int> visited(n+1,0);
	dfs(v, visited);
	printf("\n");
	visited = vector<int>(n+1,0);
	bfs(v, visited);
	printf("\n");
}

int main()
{
	input();
	sol();
	return (0);
}
