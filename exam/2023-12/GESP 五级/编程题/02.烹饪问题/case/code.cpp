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

int sort(int right, int bit) {
    cout << "right  bit: " << right << "-->" << bit << endl;	
    int left = 1;
    while(left <= right) {	
        // cout << "right  bit  a[left]  a[right]: " << right << "-->" << bit  << "-->" << a[left] << "-->" << a[right] << endl;
        // cout << "b1: " << (a[left] >> bit) << "--" << ((a[left] >> bit) & 1) << endl;
        // cout << "b2: " << (a[right] >> bit) << "--" << ((a[right] >> bit) & 1) << endl;
       
        while ((left <= right) && ((a[left] >> bit) & 1)) left++;
        while ((left <= right) && (!((a[right] >> bit) & 1))) right--;

        // cout << "left right: " << left << "--" << right << endl;
        if (left <= right) {
            swap(a[left++], a[right--]);
        };

        // for (int i = 1; i <= 5; i++) {
        //     printf("%d", a[i]);
        // }
        // cout <<  endl;
    }
    // cout << "right:" << right <<  endl;
    return right;	
}


int main() {	
    int n, j, ans = 0;	
    scanf("%d", &n);	
    // 存放输入的数到 a[n] 中
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 31; i >= 0; i--)	{
        cout << "n  i: " << n << "-->" << i << endl;
        if (((j = sort(n,i))) >= 2) {	
            // cout << "j:" << j <<  endl;
            // cout << "1 << i :" << 1 << i <<  endl;
            // cout << "ans1 :" << ans <<  endl;
            ans = ans | (1 << i);	
            // cout << "ans2 :" << ans <<  endl;
  	        n = j;	
        }
        // cout << "n :" << n <<  endl;
        // cout << "#########" << endl;
    }

    printf("%d\n", ans);	
	  return 0;	
}