#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi,pi> ppi;

int dx[] = {1,-1};
int dirs[] = {0,1,2,3}; // 동서남북
int board[100][100];
int m = 0,n = 0 ;
int dstx,dsty,dstdir;
int frmx,frmy,frmdir;
int answer = INT_MAX ;
void init()
{
	cin >> n >> m;
	memset(board,0,sizeof(board));
	REP(i,1,n+1){
		REP(j,1,m+1){
			cin >> board[i][j];
		}
	}
	cin >> frmy >> frmx >> frmdir; 
	cin >> dsty >> dstx >> dstdir;
	frmdir --;
	dstdir --;

}

void dfs()
{
	queue<ppi>q;
	q.push({{frmx,frmy},{frmdir,0}});
	char visited[n+1][m+1][4];
	memset(visited,0,sizeof(visited));

	while(!q.empty()){
		pi a,b;
		tie(a,b) = q.front(); q.pop();
		int x = a.first, y = a.second, dir = b.first, cnt = b.second;
		if(x == dstx && y == dsty && dir == dstdir){
			answer = min(answer,cnt);
		}

		cout << x <<" "<< y<< " "<< dir << " "<< cnt << "\n";
		visited[y][x][dir] = 1;

		REP(i,1,4){
			int nx = 0;
			int ny = 0 ;
			if(dir == 0){
				nx = i + x;
				if(nx <= m && !visited[y][nx][dir] && board[y][nx] != 1 )
					q.push({{nx,y},{dir,cnt+1}});
				else 
					break;
			}
			else if(dir == 1){
				nx = x - i;
				if(nx >= 1 && !visited[y][nx][dir] && board[y][nx] != 1 )
					q.push({{nx,y},{dir,cnt+1}});
				else 
					break;
			}
			else if(dir == 2){
				ny = y + i;
				if(ny <= n && !visited[ny][x][dir] && board[ny][x] != 1)
					q.push({{x,ny},{dir,cnt+1}});
				else 
					break;
			}
			else if(dir == 3){
				ny = y - i;
				if(ny >= 1 && !visited[ny][x][dir] && board[ny][x] != 1)
					q.push({{x,ny},{dir,cnt+1}});
				else 
					break;
					
			}
		}
		if(dir == 0 || dir == 1){
			if(!visited[x][y][2])
				q.push({{x,y},{2,cnt+1}});
			if(!visited[x][y][3])
				q.push({{x,y},{3,cnt+1}});
		}else {
			if(!visited[x][y][0])
				q.push({{x,y},{0,cnt+1}});
			if(!visited[x][y][1])
				q.push({{x,y},{1,cnt+1}});
		}
	}
}
int main(){

	FAST;
	init();
	dfs();
	print(answer);
	return 0;
}
