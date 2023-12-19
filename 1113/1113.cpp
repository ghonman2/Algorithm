#include <bits/stdc++.h>
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef vector<int> vi;
typedef pair<int, int>pi;

vector<vi> pool;
int n,m;
vector<vi>v;

void input()
{
	cin >> n >> m;
	pool = vector<vi>(n,vi(m));

	for (auto &p:pool){
		string tmp;
		cin >> tmp;
		for (int i = 0; i < m; i++)
			p[i] = (int)(tmp[i] - '0');
	}
}

inline void printS()
{
	for (auto &p : pool){
		for (auto &t :p)
			printf("%d ",t);
		printf("\n");
	}
}

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int bfs(pi pos)
{

	int check = 0;
	vector<pi> line;
	queue<pi> q;

	q.push(pos);
	v[pos.first][pos.second] = 1;
	line.push_back(pos);


	while (!q.empty()){
		int x,y;
		tie(x,y) = q.front(); q.pop();

		for (int i = 0; i < 4; i ++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m){check = 1; continue;}
			if (v[nx][ny]) continue;
			if (pool[nx][ny] != pool[x][y]) continue;
			q.push(make_pair(nx, ny));
			v[nx][ny] = 1;
			line.push_back(make_pair(nx,ny));
		}
	}
	for (auto &t: line)
		pool[t.first][t.second] += 1;
	return (check ? 0 : line.size());
}

void sol()
{
	int answer = 0;

	for (int h = 1; h < 10; h ++){

		v = vector<vi>(n,vi(m,0));

		for (int i = 0; i < n; i ++){
			for (int j = 0; j < m; j ++){
				if (v[i][j] || pool[i][j] != h) continue;
				answer += bfs(make_pair(i,j));
			}
		}
	}
	printf("%d\n",answer);
}

int main(){
	FAST;
	input();
	sol();
	return 0;
}

