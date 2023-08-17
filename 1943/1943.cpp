#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int sol()
{
    int n = 0 ;
    cin >> n ;
    vi coins;
    int sum = 0;
    REP(i,0,n){
        int coin, nr_coins;
        cin >> coin >> nr_coins;
        REP(j,0,nr_coins)
            coins.push_back(coin);
        sum += coin*nr_coins;
    }
    
    sort(coins.begin(),coins.end());
    if (sum & 1)
        return 0;
    sum /= 2;
    vi dp(sum+1,0);
    dp[0] = 1;

    for(int i = 0 ; i < coins.size();i ++){
        for(int x = sum-coins[i]; x >= 0 ; --x)
            dp[x + coins[i]] |= dp[x];
	}

    if(dp[sum] != 0 )
        return 1;
    return 0;
}


int main(){
    FAST;
    vi answer(3);
    REP(i,0,3)
        answer[i] = sol();
    REP(i,0,3)
        cout << answer[i] << "\n";
    
    return 0;
}
