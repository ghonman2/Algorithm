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

int answer = 0;
vi numbers;
int n;
map<int,int> is_in;

void init()
{
	cin >> n;
	numbers = vi(n);
	REP(i,0,n)
		cin >> numbers[i];
	sort(numbers.begin(), numbers.end());
}

int find_number(int nbr)
{
	unsigned long idx = find(numbers.begin(), numbers.end(), nbr) - numbers.begin();
	if (idx == numbers.size())
		return -1;
	return (int)idx;
}


void __search(int nbr, int idx, int depth)
{
	int find_idx;
	if (nbr > numbers.back() || (unsigned long)idx > numbers.size())
		return;
	if (depth != 1 && (find_idx = find_number(nbr)) != -1 && !is_in.count(nbr))
	{
		is_in[nbr] = 1;
		answer += 1;
	}
	for (unsigned long i = idx ; i < numbers.size(); i++)
	{
		__search(nbr + numbers[i], idx + 1,depth + 1);
	}
}


void sol()
{
	for(int i = 0 ; i < n; i ++)
	{
		int val = numbers[i];
		int l = 0, r = n - 1,sum;
		while (l < r)
		{
			sum = numbers[l] + numbers[r];
			if (val == sum)
			{
				if(l!=i && r!=i){
					answer ++;
					break;
				}
				else if(l==i) l++;
				else if(r==i) r--;
			}
			else if(sum < val)
				l += 1;
			else
				r -= 1;
		}
	}
}

int main(){
	FAST;
	init();
	sol();
	cout << answer << "\n";
	return 0;
}

