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


// variable
int n,m,h,q;
int k;
unordered_map<string, int>stations;
unordered_map<int, int>dictNodeToId;
unordered_map<int, char>dictNodeType;
vector<pair<int,char>>nodes;
vector<vector<pi>> graph;
vector<vi> distances;
pair<int, int> shortPath[305];
list<int>caches[305];

void input()
{
	cin >> n >> m >> h >> q;
	for (int i = 0; i < n ; i++){
		string s;
		cin >> s;
		stations[s] = i;
	}
	nodes = vector<pair<int,char>>(m);

	for (int i = 0; i < m; i++){
		auto &node = nodes[i];
		cin >> node.first >> node.second;
	}

	sort(nodes.begin(), nodes.end());

	for (int i = 0; i < m; i++){
		dictNodeToId.insert(make_pair(nodes[i].first, i));
		dictNodeType.insert(make_pair(i,nodes[i].second));
	}

	distances = vector<vi>(m);
	cin >> k;

	graph = vector<vector<pi>>(m);
	for (int i = 0 ; i < k ; i++){
		int n1, n2, r;
		cin >> n1 >> n2 >> r; n1 = dictNodeToId[n1], n2 = dictNodeToId[n2];
		graph[n1].push_back(make_pair(n2,r));
		graph[n2].push_back(make_pair(n1,r));
	}
	bzero(shortPath,sizeof(shortPath));
}


void djsk(int start)
{
	if (!distances[start].empty()) return ;

	distances[start] = vi(m, INT_MAX);
	auto &dist = distances[start];
	dist[start] = 0;
	priority_queue<pi,vector<pi>,greater<pi>>q;
	q.push(make_pair(0,start));

	while (!q.empty()){
		int currentDist,currentDest;
		tie(currentDist,currentDest) = q.top(); q.pop();

		if (dist[currentDest] < currentDist) continue;

		for (auto &next: graph[currentDest]){
			int d = next.second + currentDist;
			if (d < dist[next.first]){
				dist[next.first] = d;
				q.push(make_pair(d, next.first));
			}
		}
	}

	char type = dictNodeType[start] == 'C' ? 'B' : 'C';
	int node = -1;
	int shortDist = INT_MAX;

	for (auto &t : nodes){
		int &i = dictNodeToId[t.first];
		if (i == start || dictNodeType[i] != type) continue;
		if (shortDist > dist[i]){
			node = i;
			shortDist = dist[i];
		}
	}
	shortPath[start].first = node, shortPath[start].second = shortDist;
}

void init()
{
	for (auto &node : nodes){
		int id = dictNodeToId[node.first];
		if (node.second == 'R' || node.second == 'C')
			djsk(id);
	}
}

int cacheHit(int nId, int sId)
{
	int hit = 0;
	auto &cache= caches[nId];
	auto iter = find(cache.begin(), cache.end(), sId);
	if (iter == cache.end() && (int)cache.size() == h) cache.pop_front();
	else if (iter != cache.end()){
		cache.erase(iter);
		hit = 1;
	}
	cache.push_back(sId);
	return  (hit);
}

void run()
{
	vi answer;
	for (int i = 0; i < q; i ++){
		int sid, id; string s;
		cin >> id >> s;
		sid = stations[s];
		id = dictNodeToId[id];
		if (cacheHit(id, sid))
			answer.push_back(2 * (shortPath[id].second));
		else 
			answer.push_back(2 * (shortPath[id].second + shortPath[shortPath[id].first].second));;	
	}
	for (auto &d :answer)
		cout << d << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	init();
	run();
	return (0);
}
