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

int r = 0, c = 0 , k = 0;

vector<vi>board;


void printB()
{
	for (auto b : board)
	{
		for (auto i : b)
			cout << i << " ";
		cout << "\n";
	}
}

void init()
{
	cin >> r >> c >> k;
	board = vector<vi>(3, vi(3));
	
	for (int i = 0 ; i < 3 ; i ++)
	{
		for (int  j = 0 ; j < 3 ; j ++)
			cin >> board[i][j];
	}
}

vector<int>get_number(int number)
{
	vector<int> ret;
	int end_number = max_element(nr_number.begin(), nr_number.end(),[](const pair<int, int> &x, const pair<int,int> &y)
			{return x.second < y.second;})->second;
	while(!nr_number.empty())
	{
		auto iter = min_element(nr_number.begin(), nr_number.end(), [](const pair<int,int> &x, const pair<int,int> &y)
				{return x.second < y.second;});
		cout << iter->first << " " << iter->second << "\n";
		for (int i = 0 ; i < iter->second; i ++)
			ret.push_back(iter->first);
		nr_number.erase(iter);
	}
	ret.push_back(end_number);
	return (ret);
}

void calR(vector<vi> &board)
{
	for (size_t i = 0 ; i < board.size(); i ++)
	{
		map<int,int> nr_number;
		nr_number.clear();
		for (size_t j = 0 ; j < board[i].size(); j ++)
		{
			if (board[i][j] == 0) 
				continue ;
			if (nr_number.find(board[i][j]) == nr_number.end())
				nr_number.insert({board[i][j], 1});
			else
				nr_number[board[i][j]] += 1;
		}
		board[i] = get_number(nr_number);
	}
}

int main(){
	FAST;
	init();
	calR(board);
	printB();
	return 0;
}

