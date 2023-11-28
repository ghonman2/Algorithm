#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int n,k;
vector<int> coins;

void input()
{
    cin >> n >> k;
    coins = vector<int>(n);
    for (auto &t : coins)
        cin >> t;
}

void sol()
{
    vector<int> dp (k+1,0);
    dp[0] = 1;

    for (auto &coin : coins){
        for (int i = 1; i <= k; i++){
            if (i >= coin) dp[i] += dp[i - coin];
        }
    }
    printf("%d\n",dp[k]);
}

int main()
{
    input();
    sol();
    return (0);
}