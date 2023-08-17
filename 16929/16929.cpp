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
typedef vector<char>vc;

vector<vc>board;
vector<vc>visited;
int n,m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
struct data{
	int x;
	int y ;
	int dir;
};
void init()
{
	cin >> n >> m;
	board = vector<vc>(n,vc(m,0));
	visited = vector<vc>(n,vc(m,0));
	REP(i,0,n){REP(j,0,m){ cin >> board[i][j];}}
}

int dfs(int a, int b)
{
	queue<struct data>q;
	q.push({a,b,-1});
	visited[a][b] = 1;
	char type = board[a][b];
	while(!q.empty()){
		int x,y,dir;
		struct data pot = q.front();q.pop();
		x = pot.x , y = pot.y ,dir = pot.dir;
		for(int i = 0 ; i < 4; i ++ ){
			if(dir != -1 && dir == (i+2)%4) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >=0 && ny >=0 && nx < n && ny < m){ 
				if(!visited[nx][ny] && board[nx][ny] == type){
					q.push({nx,ny,i});
					visited[nx][ny] = 1; 
				}else if(visited[nx][ny] && board[nx][ny] == type){
					return 1;
				}
			}
		}
	}
	return 0;
}

void sol()
{
	int ret = 0 ;
	REP(i,0,n){
		REP(j,0,m){
			if(!visited[i][j]){
				ret = dfs(i,j);
			}
			if(ret) {cout << "YES"<< "\n"; return;}
		}
	}
	cout << "NO" << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

