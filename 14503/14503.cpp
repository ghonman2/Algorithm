#include <iostream>
#include <algorithm>
#include <vector>
#include <stdbool.h>

using namespace std;

#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define REP(i,a,b) for(int  i = a ; i < b ; i ++)
typedef vector<int> vi;
typedef pair<int, int> pi;
int d;
int n,m;
pi robot;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<vi>board;
vector<vector<char>>visited;

void init()
{
	cin >> n >> m;
	int x,y;
	cin >> x >> y >>d;
	robot = make_pair(x,y);
	board = vector<vi>(n,vi(m,0));
	visited = vector<vector<char>>(n,vector<char>(m,0));
	REP(i,0,n)
		REP(j,0,m) cin >>board[i][j];

}

// 북 동 남 서 
void sol()
{
	visited[robot.first][robot.second] = 0;
	int cnt = 0;
	int nx, ny;

	while(1)
	{
		char is_round = 0;

		if (!visited[robot.first][robot.second])
		{
			cnt += 1;
			visited[robot.first][robot.second] = 1;
		}
		for (int i = 0 ; i < 4; i++)
		{
			d = (d + 3) % 4;
			nx = dx[d] + robot.first;
			ny = dy[d] + robot.second;
			if (!visited[nx][ny] && !board[nx][ny])
			{
				robot = make_pair(nx,ny);
				is_round = 1;
				break;
			}
		}
		if (!is_round)
		{
			int back = (d + 2) % 4;
			if (board[robot.first + dx[back]][robot.second + dy[back]])
				break;
			robot = make_pair(robot.first + dx[back], robot.second + dy[back]);
		}
	}
	cout << cnt << "\n";
}
int main()
{
	FAST;
	init();
	sol();
	return (0);
}

