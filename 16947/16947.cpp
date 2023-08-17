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
typedef vector<char> vc;
vector<char>cycle;
vector<vi>graph;
int n;
struct data{
	int spot;
	int prev;
	int cnt;
};

void init()
{
	cin >> n ;
	graph = vector<vi>(n+1);
	REP(i,0,n){
		int in,out;
		cin >> in >> out;
		graph[in].push_back(out);
		graph[out].push_back(in);
	}
	cycle = vector<char>(n+1,0);
}

int makeCycle(int start)
{
	vc tmp = vc(n+1,0);
	stack<struct data>s;
	s.push({start,-1,0});
	tmp[start] = 1;
	int ret = 0;
	cout << start << " ";
	while(!s.empty()){
		struct data mdata = s.top();s.pop();
		int spot,prev,cnt;
		spot = mdata.spot, prev = mdata.prev, cnt = mdata.cnt;
		for(auto node : graph[spot]){
			if(prev == node) continue;
			if(!tmp[node]){
				tmp[node] = 1;
				cout << node << " ";
				s.push({node,spot,cnt+1});
			}else {
				cout << node <<"\n";
				ret = 1;
			}
		}
		if(ret)break;
	}
	
	return ret;
}


void sol()
{
	REP(i,1,n+1){
		if(makeCycle(i))
			break;
	}
	REP(i,1,n+1) printf("%d ", cycle[i]);
	cout << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

