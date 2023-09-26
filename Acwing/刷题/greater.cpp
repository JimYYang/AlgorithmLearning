https://blog.csdn.net/Ginsn/article/details/81590473

小括号在这里的意思是对结构体的初始化，调用结构体默认的构造函数创建一个实例，这里sort函数调用需要传入一个greater的实例变量，所以要加小括号，
但是小根堆是在构造函数中使用greater，小根堆的构造函数需要的是greater类，所以不能加小括号
