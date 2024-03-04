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
    int left = 1;
    while(left <= right) {	
        //  如果 left 左移 bit 位后，& 1 不为 0，left++
        while ((left <= right) && ((a[left] >> bit) & 1)) left++;
         //  如果 right 左移  bit 位后，& 1 不为 0，right--
        while ((left <= right) && (!((a[right] >> bit) & 1))) right--;
        // 交互 left  和 right
        if (left <= right) {
            swap(a[left++], a[right--]);
        };
    }
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
        // sort(n,i) 返回的 right 大于2，说明前2位的 & 不为 0，记录下来存放到 ans 中
        if (((j = sort(n,i))) >= 2) {	
            ans = ans | (1 << i);	
            // 下次处理时候，忽略掉已处理的数据
  	        n = j;	
        }
    }

    printf("%d\n", ans);	
	  return 0;	
}