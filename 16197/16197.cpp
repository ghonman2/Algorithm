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


int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

vector<vector<char>>visited[2];
int n,m;
vector<vector<char>>board;
vector<pair<int,int>>coins;
void init()
{
	cin >> n >>m;
	visited[0] = vector<vector<char>>(n,vector<char>(m,0));
	visited[1] = vector<vector<char>>(n,vector<char>(m,0));
	board = vector<vector<char>>(n,vector<char>(m,0));
	char item;
	REP(i,0,n){ 
		REP(j,0,m) {
			cin >> item;
			board[i][j] = item;
			if(item == 'o')coins.push_back({i,j});
		}
	}
}

struct node{
	pair<int,int>spot;
	int cnt; 
};

void dfs()
{
	queue<struct node>q[2];
	q[0].push({coins[0],0});
	q[1].push({coins[1],0});
	while(!q[0].empty() && !q[0].empty()){
		struct node data0 = q[0].front();q[0].pop();
		struct node data1 = q[1].front();q[1].pop();
		if(isOut(data0) || isOut(data1)){
			cout << data0.cnt << "\n";
			return;
		}
		for(int i = 0 ; i < 4 ; i ++ ){
			int nx0 = data0.spot.first + dx[i];
			int ny0 = data0.sopt.second + dy[i];

			int nx1 = data1.spot.first + dx[i];
			int ny1 = data1.spot.first + dy[i];

			if(visit)
		}
	}

	cout << -1 << "\n";
}

int main(){
	FAST;
	init();
	dfs();
	return 0;
}

