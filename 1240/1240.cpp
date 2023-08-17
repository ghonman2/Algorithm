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
typedef pair<int, int>pi;
typedef vector<pi> vpi;
vector<vpi> graph;

void input()
{
	cin >> n >> m;
	graph = vector<vi>(n+1);
	for (int i = 0 ; i < n - 1; i++){
		int f,d,w;
		cin >> f >> d >> w;
		graph[f].push_back(make_pair(d,w));
		graph[d].push_back(make_pair(f,w));
	}
}

void sol()
{

}

int main()
{
	input();
	sol();
	return (0);
}
