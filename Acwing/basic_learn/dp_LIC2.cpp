// // labuladong https://mp.weixin.qq.com/s/mvv1tsHmjUJUOLpwhCnGSQ  这种方法是纸牌的思想
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int top[N];
int piles, n;


int main(){
    scanf("%d", &n);
    int x;
    
    while(n--){
      scanf("%d", &x);
       
      int l = 0, r = piles - 1;
      while(l <= r){
          int mid = l + (r - l) / 2;
          if(top[mid] >= x) r = mid - 1;
          else l = mid + 1;
      }
    //   cout << l << " " << top[l] << " " << piles<< endl;
      if(l == piles){
          piles ++;
      }
      top[l] = x;
      cout << l << " " << top[l] << " " << piles<< endl;
    }
    printf("%d\n", piles);
    
    return 0;
}

// 数组长度变化的时候不用yxc的方法  不好判断


// labuladong https://mp.weixin.qq.com/s/mvv1tsHmjUJUOLpwhCnGSQ  这种方法是纸牌的思想
// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 100010;

// int top[N];
// int piles, n;


// int main(){
//     scanf("%d", &n);
//     int x;
 
 
 
 
//     //  int l = 0, r = n - 1;
//     //     while(l < r){
//     //         int mid = (l + r) >> 1;
//     //         if(q[mid] >= tar)r = mid;
//     //         else l = mid + 1;
//     //     }
 
 
// //  cout << piles <<endl;
//     // cout << (0 >> 1) << endl;
//     while(n --){
//       scanf("%d", &x);
//     //   cout << x << ' ' ;
//       int l = 0, r = piles - 1;
//       while(l < r){
//           int mid = (l + r) / 2;
//           if(top[mid] >= x) r = mid;
//           else l = mid + 1;
//       }
//     //   cout << l << " " << top[l] << " " << piles<< endl;
//       if(top[l] < x){
//           piles ++;
//       }
//       top[l] = x;
//     //   cout << l << " " << top[l] << " " << piles<< endl;
       
//     }
//     printf("%d\n", piles);
    
//     return 0;
// }



// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 100010;

// int q[N];
// int n, res;


// 二分查找的边界有时候也会影响结果

// int main(){
//     scanf("%d", &n);
    
//     int x, l, r;
//     while(n --) {
//         scanf("%d", &x);
        
//         l = 1, r = res;
        
//         while(l <= r){
//             int mid = l + r  >> 1;
            
//             if(q[mid] >= x) r = mid - 1;
//             else l = mid + 1; 
//         }
//         // cout << r << endl;
//         // if(r == -1){
//         //     q[1] = x;
//         //     res = max(res, 1);
//         // }
//         // else {res = max(res, r + 1);
//         // q[r + 1] = x;
//         // }
//         res = max(res, r + 1);
//         q[r + 1] = x;
//     }
    
//     cout << res ;
    
//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int q[N];
int n, res;


int main(){
    scanf("%d", &n);
    
    int x, l, r;
    while(n --) {
        scanf("%d", &x);
        
        l = 0, r = res; // 长度为0的最小数设为-INF，
        
        while(l < r){
            int mid = l + r + 1 >> 1;
            
            if(q[mid] < x) l = mid;
            else r = mid - 1; 
        }
        // cout << r << endl;
        // if(r == -1){
        //     q[1] = x;
        //     res = max(res, 1);
        // }
        // else {res = max(res, r + 1);
        // q[r + 1] = x;
        // }
        res = max(res, r + 1);
        q[r + 1] = x;
    }
    
    cout << res ;
    
    return 0;
}
