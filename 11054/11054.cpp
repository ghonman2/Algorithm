#include <bits/stdc++.h>
#include <iostream>


using namespace std;

vector<int>numbers;
int n;

int input()
{
    cin >> n;
    numbers = vector<int>(n);
    for (auto &n : numbers)
        cin >> n;
    return (0);
}

int sol()
{
    vector<int> dp(n,0);
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j ++)
            if (numbers[j] < numbers[i]) dp[i] = max(dp[j] + 1, dp[i]);
    }

    vector<int>rdp(n,0);
    for (int i = n - 1; i >= 0 ; i--){
        rdp[i] = 1;
        for (int j = i;  j < n; j ++)
            if (numbers[j] < numbers[i]) rdp[i] = max(rdp[j] + 1, rdp[i]);
    }

    for (int i = 0; i < (int)dp.size();  i++)
        dp[i] += rdp[i];
    printf("%d\n",*max_element(dp.begin(), dp.end()) - 1);
    return (0);
}

int main()
{
    return (input() || sol());
}