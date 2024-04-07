#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main()
{
    int n, m, k;
    
    scanf("%d%d%d", &n, &m, &k);
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    int left = 0, right = m - 1;
    
    while (left < n && right >= 0)
    {
        int sum = a[left] + b[right];
        if (sum < k)
        {
            left++;
        }
        else if (sum > k)
        {
            right--;
        }
        else
        {
            printf("%d %d\n", left, right);
            left++;
        }
    }
    
    return 0;
}
