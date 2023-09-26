// 总结c/c++ 中的输入输出问题

1. 单个字符读入问题  整数%d 和字符数组%s都默认以空白为分隔符  而字符%c 默认没有分隔符

https://blog.csdn.net/xia7139/article/details/14522493

char c;
scanf(" %c",&c); // 会跳过空格
scanf("%c", &c); // 不会跳过空格

2. 字符串读入问题 

//cin遇空格即停止
cin >> str; 不读空格

想读入空格
//对于string类型，可使用
string str;
getline(cin,str);

//对于字符型数组，可使用

①char str[50];
scanf("%[^\n]",chs);
②cin.get(chs,max_num);
③cin.getline(str,max_num);


3. 输入控制循环问题
int x;
while(cin >> x); // 速度慢
while(~scanf("%d", &x) or while(scanf("%d", &x) != EOF) // 速度快

      
4. 优化cin问题
[cin cout 优化](https://blog.csdn.net/qq_40430360/article/details/125362584?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-125362584-blog-95493268.pc_relevant_multi_platform_whitelistv1&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-125362584-blog-95493268.pc_relevant_multi_platform_whitelistv1&utm_relevant_index=1)
①
使用
// 关闭输入输出缓存，使效率提升
ios::sync_with_stdio(false);
// 解除cin和cout的默认绑定，来降低IO的负担使效率提升
cin.tie(NULL); cout.tie(NULL);// nullptr 0 NULL 都可以
使用\n 代替endl

5. define 可以定义所有的东西  typedef 可以定义类型

6. 新版的c++ iostream包含了cstdio（scanf printf 需要）

7. string 用c风格的输入输出问题
//输出需要用到c_str()函数  读取需要先分配空间
string a;
	a.resize(100); //需要预先分配空间
	scanf("%s", &a[0]);
	puts(a.c_str());
	return 0;

	      
8. 浮点数精度问题
控制小数位数就是通过输出格式说明符来规定的

举例说明如下：

1、float f1=3.1415926;

2、float f2=1234.1415926;

3、float f3=124.1;

4、printf("%3.4f",f1);//输出结果为：_ _ 3.1416(_表示空格)

5、printf("%3.4f",f2);//输出结果为：1234.1416

6、printf("%3.4f",f3);//输出结果为：124.1000

printf("%3.4f",f);中的3是控制f的整数部分按3位的固定位宽输出；4是按四舍五入的准则保留4位小数。

注：如果整数部分不足3位，则在前面补空格，超过3位，则按实际位数输出；如果小数部分不足4，则在后面补0。



9.scanf读入二维字符数组问题

使用scanf（"%c",&a[i][j]）读入二维字符串数组时，

如果使用两个for循环，

要记得在内层循环结束后，使用getchar（）读取换行符，

即：

for i ~ n

    for j ~ n

      scanf（"%c",  &a[i][j]）

     end

        getchar()

end

因为scanf("%c")会读入换行符；

或者就直接使用scanf("%s", a[i] )

for i~n

     scanf("%s", a[i] )

end

char 类型的二维数组可以用一个循环读入
for (int i = 0; i < n; i ++) cin >> g[i]; (scanf("%s", g[i]));
可以读入连续的数据（没有空格分隔）:
123
123
123
