#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n"
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

#define MAX 500


int n = 0 ;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int visited[MAX];
int dp[MAX][MAX];
int board[MAX][MAX];


int move(int x, int y)
{
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	
	for(int i = 0 ; i < 4; i ++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx >=0 && ny >= 0 && nx < n && ny < n){
			if(board[x][y] < board[nx][ny]){
				dp[x][y] = max(dp[x][y],move(nx,ny)+1);
			}
		}
	}
	return dp[x][y];
}



void init()
{
	cin >> n;
	memset(dp,0,sizeof(dp));
	memset(dp,0,sizeof(board));
	REP(i,0,n){
		REP(j,0,n)
			cin >> board[i][j];
	}
}

int main(){
	FAST;
	init();
	int answer = 0 ;
	REP(i,0,n){
		REP(j,0,n)
			answer  = max(answer,move(i,j));
	}
	cout << answer << "\n";
	return 0;
}
