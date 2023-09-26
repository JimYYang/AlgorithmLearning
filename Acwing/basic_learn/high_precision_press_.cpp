https://www.acwing.com/solution/content/7152/

https://www.acwing.com/blog/content/2116/

https://www.acwing.com/solution/content/123811/

// 题目 火车进栈

// 写在前面,
// 为什么要压位呢?
// 当我们的一个数很大, 大到数组空间开不到那么多位了, 我们考虑压位来解决问题, 压多少位, 数组空间将变为多少分之一, 降低了空间复杂度, 时间复杂度与普通的高精度是一样的

// 加减法一般压9位, 乘除法压4位

// 压位算法相较于普通的高精度算法主要区别在于进制数(压几位就模十的几次方), 和储存(见代码)
// 板子 (以高精度加法为例)



1.模数不同
vector<int> add (vector<int> &A, vector<int> &B)
{
    vector<int> c;

    int t = 0;
    for(int i = 0 ; i < A.size() || i < B.size() ; i ++ )
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        c.push_back(t % mod); // ***
        t /= mod; // ***
    }

    if(t) c.push_back(1);

    return c;
}

2.存储方式不同
for(int i = a.size() - 1, sum = 0, j = 0, t = 1 ; ~i ; i -- )
{
    sum += (a[i] - '0') * t;
    j ++ , t *= 10;
    if(j == 9 || i == 0) // 九位一个元素
    {
        A.push_back(sum);
        sum = j = 0;
        t = 1;
    }
}
for(int i = b.size() - 1, sum = 0, j = 0, t = 1 ; ~i ; i -- ) 
{
    sum += (b[i] - '0') * t;
    j ++ , t *= 10;
    if(j == 9 || i == 0)
    {
        B.push_back(sum);
        sum = j = 0;
        t = 1;
    }
}

3.输出方式不同
printf("%d", c.back()); // 第一个元素不需要补前导零
for(int i = c.size() - 2 ; ~i ; i -- ) printf("%09d", c[i]);

  
  
