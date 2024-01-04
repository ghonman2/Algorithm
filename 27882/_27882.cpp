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
typedef vector<pi> vp;

unordered_map<int, vp> graph;
unordered_map<string,int> stations;
int n,m,h,q,k;
vector<pair<int,string>>requests;

class Node {
	public :
		unordered_map<int,int> ws;
		int id;
		int type;
		bool operator < (const Node &other) const {
			return this->id < other.id;
		};
		Node(int id_, int type_) : id(id_), type(type_) {}
};

class RNode : public Node{
	public :
		int nearCacheNode;
		int nearCacheNodeDist;
		RNode(int id_, int type_) : Node(id_,type_), nearCacheNode(-1), nearCacheNodeDist(-1){}
 };

class CNode : public Node {
	public :
		list<int> cache;
		int nearBucketNode;
		int nearBucketNodeDist;
		static int nrCache;
		CNode(int id_, int type_) : Node(id_, type_), nearBucketNode(-1), nearBucketNodeDist(-1){}

		int lru(int &s){
			int hit = 0;
			auto iter = find(cache.begin(), cache.end(), s);
			if (iter == cache.end()){
				if((int)cache.size() >= h) cache.pop_front();
			}
			else {cache.erase(iter);hit++;}
			cache.push_back(s);
			return (hit);
		};
};

class BNode : public Node {
	public :
		BNode(int id_, int type_) : Node(id_, type_) {}
};

unordered_map<int,RNode*>rNodes;
unordered_map<int,CNode*>cNodes;
unordered_map<int,BNode*>bNodes;

void input()
{
	cin >> n>> m >> h >> q;
	for (int i = 0; i < n; i ++){
		string tmp;
		cin >> tmp;
		stations[tmp] = i;
	}
	for (int i = 0; i < m; i ++){
		int id;
		char type;
		cin >> id >> type;	
		if (type == 'R')
			rNodes[id] = (new RNode(id, (int)type));
		else if (type == 'C')
			cNodes[id] = (new CNode(id,(int)type));
		else if (type == 'B')
			bNodes[id] = (new BNode(id,(int)type));		
	}

	cin >> k;

	for (int i = 0; i < k; i ++){
		int n1, n2, r;
		cin >> n1 >> n2 >> r;
		graph[n1].push_back(make_pair(n2,r));
		graph[n2].push_back(make_pair(n1,r));
	}
	requests = vector<pair<int, string>>(q);
	for (auto &r : requests)
		cin >> r.first >> r.second;
}

void djsk(int id, unordered_map<int,int> &distances)
{
	for (auto &node : cNodes)
		distances[node.first] = INT_MAX;
	for (auto &node : bNodes)
		distances[node.first] = INT_MAX;
	for (auto &node : rNodes)
		distances[node.first] = INT_MAX;

	priority_queue<pi, vector<pi>, less<pi>> q;
	distances[id] = 0;
	q.push(make_pair(0,id));

	while (!q.empty()){
		int currentDist,currentDest;
		tie(currentDist,currentDest) = q.top(); q.pop();
		if (distances[currentDest] < currentDist) continue;
		for (auto &next: graph[currentDest]){
			int dist = currentDist + next.second;
			if (dist < distances[next.first]) {
				distances[next.first] = dist;
				q.push(make_pair(dist, next.first));
			}
		}
	}
}

void init()
{
	for (auto &bNode : bNodes)
		djsk(bNode.first, bNode.second->ws);
	for (auto &cNode : cNodes)
		djsk(cNode.first, cNode.second->ws);

	for (auto &c : cNodes){
		auto &cNode = c.second;
		int minLength = INT_MAX;
		int minId = -1;
		for (auto &b : bNodes){
			auto &bNode = b.second;
			if (minLength > bNode->ws[c.first]){
				minLength = bNode->ws[c.first];
				minId = bNode->id;
			}else if (minLength == bNode->ws[c.first] && minId > bNode->id)
				minId = bNode->id;
		}
		cNode->nearBucketNode = minId;
		cNode->nearBucketNodeDist = minLength;
	}

	for (auto &r : rNodes){
		auto &rNode = r.second;
		int minLength = INT_MAX;
		int minId = -1;
		for (auto &c: cNodes){
			auto &cNode = c.second;
			if (minLength > cNode->ws[rNode->id]){
				minLength = cNode->ws[rNode->id];
				minId = cNode->id;
			}else if (minLength == cNode->ws[r.first] && minId > cNode->id)
				minId = cNode->id;
		}
		rNode->nearCacheNode = minId;
		rNode->nearCacheNodeDist = minLength;
	}
}

void run()
{
	for (auto &r : requests){
		RNode *node = rNodes[r.first];
		CNode *cNode = cNodes[node->nearCacheNode];
		if (cNode->lru(stations[r.second]))
			cout << node->nearCacheNodeDist * 2 << "\n";
		else
			cout << 2*(node->nearCacheNodeDist + cNode->nearBucketNodeDist) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	init();
	run();
	return (0);
}
