#week3---周记#
##生活随笔：##
生活上和以往两周保持一致的节奏，没有太大偏差，但是最近这个泛型队列让自己
在c上又花了很多功夫，对一些库函数不是很熟练导致打码时间延长许多（主要是之前学java）
##bug&问题集：##
**问题1**
在队列大组作业中，出现了一个未定义的类型size_t
原以为是一个未声明的类型，于是使用了typedef来声明未int类型，但是系统出现*invalid preprocessor command* 
（无效的预处理命令）查询之后才发现size_t是一种数据类型，在stdio.h或stblib.h中，只要在头文件里#--stdio.h 和stblib.h即可使用。

**size_t 类型表示C 中任何对象所能达到的最大长度。它是无符号整数，因为负数在这里没有意义。它的目的是提供一种可移植的方法来声明与系统中可寻址的内存区域一致的长度。size_t 用做sizeof 操作符的返回值类型，同时也是很多函数的参数类型，包括malloc 和strlen。**
[https://blog.csdn.net/qq_30866297/article/details/51465473](https://blog.csdn.net/qq_30866297/article/details/51465473 "size_t数据类型")

**问题2**
如何知道void函数指向的类型-

    /**
     *  @name: void LPrint(void *q)
     *	@description : 操作函数
     *	@param q 指针q
     *  @notice  : None
     */
    void LPrint(void *q)；

经过网上多个资源搜索-
基本方案都是
1.增加一个参数（效率高）
2.使用让void*指向枚举类来获取类型
3.其他
个人猜想：是否可以通过sizeof来获取void *的指向内存大小，如int，double，虽然void指向无类型可以包含任意类型，是否确定了void*的变量就确定了其状态量。
测试如下：

    int main()
    {
    	void *p = (void *)malloc(sizeof(int));
    	int a = 9;
    	p = memcpy(p,&a,sizeof(int));
    	printf("%d",sizeof(void *));
    	return 0;
    }
结果是4；-->但是无法通过*p来获取其内存的大小-->
于是我增加了一个参数
 
问题5：
	最近把myeclipse的项目拿到eclipse上面，发现其余都能正常加载，但是就是js和css在tomcat上运行不了，网上的办法试过一些还未解决。（试着把jsp直接改成html结果js和css又显示出来了）
	困扰许久，还在解决
## 这一周的学习的安排 ##
清明三天--大概学了一下html+js+ajax（仅仅初步了解）（css具体只会一点点）
本来打算开始使用js和ajax的结果eclipse的js和css效果的bug还没调好。。。
数据库表----rbac权限设计思想大概了解了一下

接下来的剩下的时间就开始学一些缺漏的点----比如css---js和ajax应用时的问题--
java--io流以后的知识也要进行学习。