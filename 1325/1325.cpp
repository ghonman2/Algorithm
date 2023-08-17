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
vector<vi>graph;
vector<int>visited;

void input()
{
	cin >> n >> m;
	graph = vector<vi>(n+1);
	visited = vector<int>(n+1, 0);
	for (int i = 0 ; i < m; i ++){
		int src, dst;
		cin >> src >> dst;
		graph[dst].push_back(src);
	}
}

void dfs(vector<int> &visited, int &cnt, int now)
{
	visited[now] = 1;
	cnt ++;
	for (auto &node : graph[now])
	{
		if (visited[node]) continue;
		dfs(visited, cnt, node);
	}
}

void sol()
{
	vector<int>answer(n + 1);

	for (int i = 1; i <= n; i++){
		vector<int>visited(n+1, 0);
		int cnt = 0;
		dfs(visited, cnt, i);
		answer[i] = cnt;
	}
	int maxNum = *max_element(answer.begin(), answer.end());
	for (int i = 1 ; i <= n; i ++)
		if (answer[i] == maxNum) printf("%d ",i);
	printf("\n");
}

int main()
{
	input();
	sol();
	return (0);
}
