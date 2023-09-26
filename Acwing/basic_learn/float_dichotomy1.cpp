#include<iostream>

using namespace std;

int main(){
    double x;
    cin >> x;
    double l = 0, r = max(1,x);//这样的二分是自己先通过判断 得到左右边界 而不同于数组二分
    while(r - l > 1e-8){
        double mid = (l + r) / 2;
        if(mid * mid > x)r = mid;
        else l = mid;
    }
    printf("%lf\n",l);
    // cout << l << endl;
    return 0;
}
