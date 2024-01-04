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
typedef pair<int,int> pi;

int n,m,h,q,k;
unordered_map<string, int>stationsDict;
unordered_map<int, int> nodeIdDict;
unordered_map<int, char> typeDict;
vector<vector<pi>> graph;
vector<pair<int, int>> requests;
vector<vi> distances;
vector<pi> shortPath;
vector<list<int>> caches;


void input()
{
	cin  >> n >> m >> h >> q;

	for (int i = 0; i < n ; i++){
		string s;
		cin >> s;
		stationsDict.insert(make_pair(s,i));
	}

	vector<pair<int,char>>nodes(m);
	for (auto &node : nodes)
		cin >> node.first >> node.second;
	sort(nodes.begin(),nodes.end());
	for (int i = 0; i < m; i++){
		nodeIdDict.insert(make_pair(nodes[i].first, i));
		typeDict.insert(make_pair(i,nodes[i].second));
	}

	cin >> k;
	graph = vector<vector<pi>>(m);
	for (int i = 0; i < k; i++){
		int n1, n2, r;
		cin >> n1 >> n2 >> r;
		n1 = nodeIdDict[n1], n2 = nodeIdDict[n2];
		graph[n1].push_back(make_pair(r,n2));
		graph[n2].push_back(make_pair(r,n1));
	}

	requests = vector<pi>(q);
	for (auto &r : requests){
		string s;
		cin >> r.first >> s;
		r.first = nodeIdDict[r.first];
		r.second = stationsDict[s];
	}
	distances = vector<vi>(m);
	shortPath = vector<pi>(m,make_pair(-1,-1));
	caches = vector<list<int>>(m);
}

void dijk(int start)
{
	if (!distances[start].empty()) return;

	distances[start] = vi(m,numeric_limits<int>::max());
	auto &dist = distances[start];
	priority_queue<pair<int, int>> q;
	char type = typeDict[start] == 'C' ? 'B' : 'C';
	
	dist[start] = 0;
	q.push(make_pair(-0,-start));

	while (!q.empty()){
		int currentDist, currentDest;
		tie(currentDist, currentDest) = q.top(); q.pop(); currentDist *= -1, currentDest *= -1;

		if (dist[currentDest] < currentDist) continue;

		if (type == typeDict[currentDest]){
			shortPath[start].first = currentDest;
			shortPath[start].second = currentDist;
			break ;
		}

		for (auto &node: graph[currentDest]){
			int d = currentDist + node.first;
			if (d < dist[node.second]){
				dist[node.second] = d;
				q.push(make_pair(-d,-node.second));
			}
		}
	}
}

void init()
{
	for (auto &node : nodeIdDict){

		char &type = typeDict[node.second];
		if (type == 'C' || type == 'R')
			dijk(node.second);
	}
}

int cacheHit(list<int> &cache, int s)
{
	int hit = 0;
	auto it = find(cache.begin(), cache.end(), s);
	if (it != cache.end()){
		cache.erase(it);
		hit = 1;
	}else {
		if (cache.size() == (size_t)h)
			cache.pop_front();
	}

	cache.push_back(s);
	return (hit);
}

void run()
{
	for (auto &r: requests){
		auto &cache = caches[r.first];
		if (cacheHit(cache,r.second))
			cout << 2 * (shortPath[r.first].second) << '\n';
		else
			cout << 2 * (shortPath[r.first].second + shortPath[shortPath[r.first].first].second) << '\n';
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	init();
	run();
	return (0);
}
