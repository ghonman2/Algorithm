#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <queue>
#include <limits>
using namespace std;

int n, m, h, q;
int k;
unordered_map<string, int> s_id; //(역 이름, 새로 부여하는 역의 id)
unordered_map<int, int> n_id; //(node_id, 새로 부여하는 노드의 id(노드 id))
unordered_map<int, char> n_type; //(노드 id, 노드 타입)
vector<pair<int, int>> adj[305]; //[노드 id] = (거리, 연결되는 노드 id)

pair<int, int> short_cache[305]; //[노드 id] = (가장 가까운 캐시의 노드 id, 거리)
int short_bucket[305]; //[노드 id] = bucket까지 거리

list<int> cache[305]; //[캐시의 노드 id] = 캐시 리스트 (가장 오래전에 사용된 역의 id가 리스트의 앞에 존재)
unordered_map<int, list<int>::iterator> cache_point[305]; //[캐시의 노드 id][역 id] = 캐시 리스트에서 존재하는 위치
list<int>::iterator it;
vector<int> output;

void find_short_dist(int start, char find_type) {

	vector<int> short_dist(305, numeric_limits<int>::max());
	priority_queue<pair<int, int>> pq; //(-cost, -노드 id) 거리가 가까운순, 노드 id가 작은 순

	short_dist[start] = 0;
	pq.push(make_pair(-0, -start));

	while (!pq.empty()) {
		int here = -pq.top().second;
		int here_cost = -pq.top().first;
		pq.pop();

		if (here_cost > short_dist[here]) {
			continue;
		}

		char here_type = n_type[here];

		if (here_type == find_type) {
			if (find_type == 'C') { //캐시를 찾는 경우일때
				short_cache[start] = make_pair(here, here_cost);
			}

			if (find_type == 'B') { //버킷을 찾는 경우일때
				short_bucket[start] = here_cost;
			}
			break;
		}

		for (size_t i = 0; i < adj[here].size(); i++) {
			int there_cost = here_cost + adj[here][i].first;
			int there = adj[here][i].second;

			if (short_dist[there] > there_cost) {
				short_dist[there] = there_cost;
				pq.push(make_pair(-there_cost, -there));
			}
		}
	}
	printf("id[%d]:{%d %d}\n",start,short_cache[start].first, short_cache[start].second);
}

int solve(int start_n_id, int find_s_id) {
	int short_cache_id = short_cache[start_n_id].first;
	int short_cache_dist = short_cache[start_n_id].second;
	int short_bucket_dist = short_bucket[short_cache_id];
	int result = 0;

	//해당 캐시에 find_s_id가 있는지 확인

	//해당 캐시에 find_s_id가 있을때
	if (cache_point[short_cache_id].count(find_s_id) != 0) {

		//find_s_id를 리스트의 가장 뒤로 옮긴다 (기존거 지우고, 뒤에 새로 삽입)

		it = cache_point[short_cache_id][find_s_id];

		//지우기
		cache[short_cache_id].erase(it);
		cache_point[short_cache_id].erase(find_s_id);

		//새로 삽입
		cache[short_cache_id].push_back(find_s_id);
		it = cache[short_cache_id].end();
		it--;
		cache_point[short_cache_id].insert(make_pair(find_s_id, it));

		result = short_cache_dist * 2;
	}

	//해당 캐시에 find_s_id가 없을때 
	else {

		//해당 캐시가 꽉 차있을때
		if ((int)cache[short_cache_id].size() == h) {
			//해당 캐시의 제일 앞에 것 지우기
			it = cache[short_cache_id].begin();
			cache_point[short_cache_id].erase(*it);
			cache[short_cache_id].pop_front();
		}

		//해당 캐시의 제일 뒤에 새로 삽입
		cache[short_cache_id].push_back(find_s_id);
		it = cache[short_cache_id].end();
		it--;
		cache_point[short_cache_id].insert(make_pair(find_s_id, it));

		result = (short_cache_dist + short_bucket_dist) * 2;
	}

	return result;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> h >> q;

	for (int i = 0; i < n; i++) {
		string station;
		cin >> station;
		s_id.insert(make_pair(station, i));
	}

	vector<pair<int, char>> input_node_info;
	for (int i = 0; i < m; i++) {
		int node_id;
		char node_type;
		cin >> node_id >> node_type;
		input_node_info.push_back(make_pair(node_id, node_type));
	}
	// node_id가 작은것부터 새로운 id가 작은게 부여되도록 한다 (추후 캐시값이 같은거 일때, id가 작은거 선택하는 경우 고려)
	sort(input_node_info.begin(), input_node_info.end());
	for (int i = 0; i < m; i++) {
		n_id.insert(make_pair(input_node_info[i].first, i));
		n_type.insert(make_pair(i, input_node_info[i].second));
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		int node1, node2, rt;
		cin >> node1 >> node2 >> rt;
		int n_id1 = n_id[node1];
		int n_id2 = n_id[node2];
		adj[n_id1].push_back(make_pair(rt, n_id2));
		adj[n_id2].push_back(make_pair(rt, n_id1));
	}

	for (int i = 0; i < m; i++) {
		if (n_type[i] == 'R') {
			find_short_dist(i, 'C'); //i 노드에서 가장 가까운 캐시와 캐시까지 최단 거리 구하기
		}
		if (n_type[i] == 'C') {
			find_short_dist(i, 'B'); //i 노드에서 버킷까지 최단 거리 구하기
		}
	}

	for (int i = 0; i < q; i++) {
		int node;
		string station_name;
		cin >> node >> station_name;
		int start_n_id = n_id[node];
		int find_s_id = s_id[station_name];
		int result = solve(start_n_id, find_s_id);
		output.push_back(result);
	}

	for (size_t i = 0; i < output.size(); i++) {
		cout << output[i] << "\n";
	}

	return 0;
}
