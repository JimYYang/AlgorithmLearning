#include<iostream>

using namespace std;

int main(){
    double x;
    scanf("%lf", &x);
    // cin >> x;
    double l = -10000, r = 10000;
    const double eps = 1e-8;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if(mid * mid * mid >= x)r = mid;
        else l = mid;
    }
    printf("%lf\n",l);
    return 0;
}
