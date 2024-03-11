#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt;
int main()
{
	cin>>n;
	for (ll i=2;i*i<=n;i++)//记得开long long，从2开始
	{
		cnt=0;//记录质因数个数
		if (n%i==0)//如果i是质因数
		{
			while(n%i==0)//一直分解直到无法分解为止
			{
				n/=i;
				cnt++;
			}
			if (cnt==1) cout<<i;//如果只有一个，不用输出指数
			else cout<<i<<'^'<<cnt;//否则输出指数
			if (n>1) cout<<" * ";//如果不是最后一个质因数就输出乘号
		}
	}
	if (n>1) cout<<n;//如果没分解干净就输出剩下的质因数
	return 0;
}