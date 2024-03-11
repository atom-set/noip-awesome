#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 500 + 10;
bool flag[maxn] = {false};
struct Node{
    int r, d; //r 表示游戏的奖励，d表示游戏的截止时间
} a[maxn];
bool cmp(const Node& x, const Node& y){
    return x.r > y.r;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].d;
    }
    for(int i = 0; i < n; ++i) {
        cin >> a[i].r;
    }
    sort(a, a + n, cmp);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int t = a[i].d-1; t >= 0; --t) {
        //如果找到一个空闲的时间段，那么安排游戏
            if(!flag[t]) {
                flag[t] = true; //标记时间段为已占用
                // cout << a[i].d << " --" << a[i].r << "-->" << t << ";";
                // 4 2 4 3 1 4 6 
                // 70 60 50 40 30 20 10
                // 输出：70 60 50 40 10 
                ans += a[i].r; //累加奖励
                break; //跳出循环
            }
        }
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}