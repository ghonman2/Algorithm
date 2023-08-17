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
typedef pair<int,int>pi;

int n,m;
typedef vector<vector<char>> vvc;

char visited[101][101];
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1};
int board[101][101];
int out_air[101][101];
void init()
{
	cin >> n >> m;
	REP(i,0,n){
		REP(j,0,m){
			cin >> board[i][j];
		}
	}	
}

int bfs()
{
	queue<pi>q;
	q.push({0,0});
	int cnt = 0;
	while (!q.empty()){
		int x,y;
		tie(x,y) = q.front(); q.pop();
		if(visited[x][y])
			continue;
		visited[x][y] = 1;
		for(int i = 0 ; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny])
			{
				if (!board[nx][ny])
					q.push({nx,ny});
				else 
					out_air[nx][ny] ++;
			}
		}
	}	
	for(int i = 0 ; i < n; i ++){
		for(int j = 0 ; j < m; j ++){ 
			if (out_air[i][j] >= 2){
				cnt ++;
				board[i][j] = 0;
			}
		}
	}
	return cnt;
}

void sol()
{
	int answer = 0;
	memset(visited,0,sizeof(visited));
	memset(out_air,0,sizeof(out_air));
	while (bfs())
	{
		memset(out_air,0,sizeof(out_air));
		memset(visited,0,sizeof(visited));
		answer += 1;
	}
	cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

