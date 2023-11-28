#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int n;
vector<int> p;

void input()
{
    cin >> n;
    p = vector<int> (n);
    for (auto &t : p)
        cin >> t;
}

void sol()
{
    vector<int> dp (n+1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i] = max(dp[i], dp[i-j] + p[j-1]);
        }
    }
    cout << dp[n] << '\n';
}

int main()
{
    input();
    sol();
    return (0);
}