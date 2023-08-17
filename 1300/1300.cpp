#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    ll n,k;
    cin >> n >> k;
    ll l = 0 , r = n*n,mid = n*n;
	ll answer = 0;
    while (l <= r){
        mid = (l+r)/2;
        ll cnt = 0 ;
        for(int i = 1; i <= n ; i ++){
            cnt += min(mid/i,n);
        }
        if (cnt < k) l = mid + 1;
        else {
            answer = mid;
            r = mid -1;
        }
    }
    cout << answer << "\n";
    return 0;
}
