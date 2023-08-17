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
typedef vector<ll> vl;
vector<vl>board;
int m,n;
vector<vl>dp;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void init()
{
	cin >> m >> n ;
	board = vector<vl>(m,vl(n,0));
	dp = vector<vl>(m,vl(n,-1));
	REP(i,0,m){
		REP(j,0,n){
			cin >> board[i][j];
		}
	}

}

int dfs(int x, int y)
{
	if(dp[x][y] !=-1 )return dp[x][y];
	
	dp[x][y] = 0;

	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >=0 && ny >=0 && nx < m && ny < n 
				&& board[x][y] > board[nx][ny]){
			dp[x][y] = dp[x][y] + dfs(nx,ny);
		}
	}
	return dp[x][y];
}

void sol()
{
	dp[m-1][n-1] = 1;
	dfs(0,0);
	cout << dp[0][0] << "\n";
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

