#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

vector<vi>graph;
int n, k;

void init()
{
	cin >> n >> k;
	graph = vector<vi>(n,vi(n,0));
	for(int i = 0 ; i < n; i ++){
		REP(j,0,n){
			cin >> graph[i][j];
		}
	}
}

vi dij(int start)
{
	priority_queue<pair<int,int>>q;
	q.push({0,start});
	vi distance(n,10000);
	distance[start] = 0;
	while(!q.empty())
	{
		int cur_dist, cur_dst;
		tie(cur_dist,cur_dst) = q.top(); q.pop();
		if (-cur_dist > distance[cur_dst])
			continue;
		for(int nxt_dst = 0; nxt_dst < n; nxt_dst++)
		{
			int nxt_dist = -1 * cur_dist + graph[cur_dst][nxt_dst];
			if (nxt_dist < distance[nxt_dst])
			{
				distance[nxt_dst] = nxt_dist;
				q.push({-nxt_dist,nxt_dst});
			}
		}
	}
	return distance;
}
int answer = INT_MAX;
void search(vi &visited, int depth,int result, int now, vector<vi>&path)
{
	if (answer < result)
		return;
	if (depth == n)
	{
		answer = min(answer,result);
		return;
	}
	for(int i = 0 ; i < n; i ++)
	{
		if (!visited[i] && i != now)
		{
			visited[i] = 1;
			search(visited, depth + 1,result + path[now][i],i,path);
			visited[i] = 0;
		}
	}
}

void sol()
{
	vector<vi>short_path;
	vi visited(n,0);
	for(int i = 0 ; i < n; i ++)
		short_path.push_back(dij(i));
	visited[k] = 1;
	search(visited,1,0,k,short_path);
	cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

