#include<cstdio>	
#include<iostream>
#include<algorithm>	
#include<cstdlib>
#include<cstring>	
using namespace std;	

// n ≤ 10^6
// 0 ≤ ai ≤2,147,483,647
// 2147483647 可以推导出 2 进制表示长度为 32 位
const int MAX_N = int(1e6) + 100;

int a[MAX_N];	

int sort(int m, int r, int k) {	
    cout << "m  r  k:" << m << r << k << endl;
    while(m <= r) {	
        cout << "m  r  k  a[m]  a[r]:" << m << "--" << r << "--" << k  << "--" << a[m] << "--" << a[r] << endl;
        while ((m <= r) && (a[m] >> k & 1)) m++;
        while ((m <= r) && (!(a[r] >> k & 1))) r--;

        cout << "m r:" << m << "--" << r << endl;
        if (m <= r) {
            swap(a[m++], a[r--]);
        };	
    }
    return r;	
}


int main() {	
    int n, j, ans = 0;	
    scanf("%d", &n);	
    // 存放输入的数到 a[n] 中
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 31; i >= 0; i--)	{
        if ((j = sort(1,n,i)) >= 2) {	
            ans = ans | (1<< i);	
  	        n = j;	
        }	
    }

    printf("%d\n", ans);	
	return 0;	
}