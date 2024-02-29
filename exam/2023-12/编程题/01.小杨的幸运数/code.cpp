
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;


/**
* 题干分析
* 1.数学上，平方数，或称完全平方数，是指可以写成某个整数的平方的数，即其平方根为整数的数。 例如，9 = 3 × 3，它是一个平方数。 eg: 1、4、9、16、25
* 2.超级幸运数: x的平方根为整数
* 3.幸运数: 超级幸运数的倍数
* 4.幸运化: 非幸运数可以通过连续加 1，变成幸运数
*/

// 要求: 1 ≤ x ≤ 1,000,001， 1000001 的平方根为 1000.000499999875
const int N = 1001*1001;

// 1e-8指的是1乘以10的-8次方 0.00000001，表示一个非常小的数
const double eps =1e-8;

// 是否为幸运数
bool is_lucky[N+5];

// 存放通过连续加 1 最终得到幸运数 
int next_lucky[N+5];

void init() {
}

int main( ){
    int a,T;
    scanf("%d%d", &a, &T);

    // 获取所有的幸运数
    for (int i = 1; i <= N; i++) {
        // 求平方数根
        int t = int(sqrt(i) + eps);

        // 是完全平方数
        if (i >= a && t*t == i){
            // 存放幸运数
            is_lucky[i] = 1;
        }

        if(!is_lucky[i]) {
            continue ;
        }
     
        // 为幸运数，处理幸运数的倍数
        for (int j = i + i; j <= N; j += i)  {
            // cout << i << "---" <<j << "==>" << endl;
            is_lucky[j] = 1;
        }
    }

    // for(int i = 1; i < N; i++) {
    //     cout << i << "==>";
    //     cout << is_lucky[i]  << endl;
    // }


    // 处理幸运化，从后完全遍历
    // eg: 如果 next_lucky[56]不是幸运数，+1 后是next_lucky[57]，如果next_lucky[57]是幸运数，就放57，如果不是，next_lucky[57] 下一个就到58了
    for(int i = N; i; i--) {
        next_lucky[i] = is_lucky[i] ? i : next_lucky[i+1];
    }

    // for(int i = 1; i <= N; i++) {
    //     cout << i << "==>";
    //     cout << next_lucky[i]  << endl;
    // }

    while(T--) {
        int x;
        scanf("%d", &x);
        if (is_lucky[x]) {
            cout << "lucky" << endl;
        } else {
            cout << next_lucky[x] << endl;
        }

    }
    return 0;
}