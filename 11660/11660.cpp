#include <bits/stdc++.h>
#include <iostream>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n,m;

vector<vector<int>> board;
vvi cmds;


int input()
{
    cin >> n >> m;
    cmds = vvi(m, vi(4));
    board = vvi(n, vi(n));
    for (auto &line: board){
        for (auto &t : line)
            cin >> t;
    }
    for (auto &line : cmds)
        cin >> line[0] >> line[1] >> line[2] >> line[3];

    return (0);
}

int sol()
{
    vvi dp = vvi(n, vi(n,0));
    for (int i = 0; i < n; i ++){
        dp[i][0] = board[i][0];
        for (int j = 1; j < n; j++)
            dp[i][j] += dp[i][j-1] + board[i][j];
    }

    for (auto &cmd : cmds){
        int sx = cmd[0] - 1, sy= cmd[1] - 1 , dx = cmd[2] - 1, dy = cmd[3] - 1;
        int answer = 0;
        for (int t = sx; t <= dx; t++)
            answer += dp[t][dy] - (sy == 0 ? 0 : dp[t][sy - 1]);
        printf("%d\n",answer); 
    }


    return (0);
}

int main()
{
    return (input() || sol());
}