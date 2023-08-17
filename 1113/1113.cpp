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

vector<vi> pool;
int n,m;


void init()
{
	cin >> n >> m;
	string str;
	pool = vector<vi>(n,vi(m,0));
	for(int i = 0 ; i < n ; i++){
		cin >> str;
		for (int  j = 0 ; j < m ; j ++)
			pool[i][j] = str[j] - '0';
	}
}

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int answer = 0;
void bfs(vector<vi> &visited, int a, int b)
{
	visited[a][b] = 1;
	int std_num = min(pool[a-1][b],pool[a][b-1]);
	if (std_num <=  pool[a][b])
		return;
	queue<pair<int,int>>q;
	q.push({a,b});
	vector<pair<int,int>>locs;
	locs.push_back({a,b});
	while (!q.empty())
	{
		int x,y;
		tie(x,y) = q.front(); q.pop();
		visited[x][y] = 1;
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <=ny && ny < m && !visited[nx][ny] && std_num > pool[nx][ny])
			{
				if (nx == n-1 || ny == m- 1 || nx == 0 | ny == 0) return;
				q.push({nx,ny});
				visited[nx][ny] = 1;
				locs.push_back({nx,ny});
			}
		}
	}

	cout << std_num << "\n";
	for(auto loc : locs)
	{
		cout << loc.first << " " << loc.second << "\n";
		answer += (std_num - pool[loc.first][loc.second]);
	}
	cout << "\n";
}

void sol()
{
	if (n < 3 || m < 3)
	{
		cout << 0 << "\n";
	}
	vector<vi> visited(n,vi(m,0));
	for(int i = 1 ; i < n -1; i ++)
	{
		for(int j = 1 ; j < m - 1; j ++)
		{
			if(!visited[i][j])
				bfs(visited,i,j);
		}
	}
	cout << answer << '\n';
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

