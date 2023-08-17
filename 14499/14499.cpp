#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>

#define FAST cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false);
#define REP(i,a,b)  for (int i = a; i < b ; i++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair <int, int> pii;
typedef vector<pii> vpi;

int dx[9] = {0,0,0,-1,1,1,-1,0,0};
int dy[9] = {0,1,-1,0,0,0,0,1,1};

int n,m;
int x,y;
int k;
vector<vi> board;
vi dirs;
vector<int>dice(7,0);

void init()
{
	cin >> n >> m >> x >> y >>k;
	board = vector<vi>(n,vi(m,0));
	REP(i,0,n)
		REP(j,0,m)
			cin >> board[i][j];
	dirs = vi(k);
	REP(i,0,k)
		cin >> dirs[i];
}


void down_to_up(int *a, int *b)
{
	if(*b == 1)
		*a = (*a + 2) % 4;
	else
	{
		if(*b == 0 && * a == 1)
			*b = 3;
		else if(*b == 2 && *a == 1)
			*a = 3;
		else 
			cout <<"SIBAL " << *a << " " << *b <<"\n";
	}
}
void rollEast()
{
    dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
}

void rollWest()
{
    dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void rollNorth()
{
    dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
}

void rollSouth()
{
    dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
}

void roll(int order)
{
    switch (order)
    {
    case 1:
        rollEast();
        break;
    case 2:
        rollWest();
        break;
    case 3:
        rollNorth();
        break;
    case 4:
        rollSouth();
        break;
    default:
        break;
    }
}

void sol()
{
	for(int i = 0 ; i < k ; i ++)
	{
		int nx = x + dx[dirs[i]];
		int ny = y + dy[dirs[i]];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			x = nx, y = ny;
			//cout << "x is " << x << " y is "<<  y << "\n";
			roll(dirs[i]);
			if(board[x][y] == 0)
			{
				board[x][y] = dice[6];
			}else {
				dice[6] = board[x][y];
				board[x][y] = 0;
			}
			cout << dice[1] << "\n";
		}
	}
}

int main()
{
	FAST;
	init();
	sol();
	return 0;
}

