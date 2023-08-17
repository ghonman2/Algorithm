
#include <iostream>
#include <vector>

using namespace std;
int answer = 0 ;
vector<int> list;
int n = 0, s = 0;

void BT(int before,int index)
{
	if (s == before)
		answer += 1;
	for(int i = index + 1 ; i < n; i ++){
		BT(before + list[i],i);
	}
}


int main()
{
	cin >> n >> s ;

	for(int i = 0 ; i < n; i ++)
	{
		int tmp = 0 ;
		cin >> tmp;
		list.push_back(tmp);
	}
	for (int i = 0 ; i < n; i++)
		BT(list[i],i);
	cout << answer;

	return 0;
}
