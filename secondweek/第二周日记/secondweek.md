#week2---周记#
##生活随笔：##
过去一周的考核+训练营时间里，时间的紧迫的的确确让自己感到有压力，特别是睡眠时间这一块。不过这些问题都不大，反而让自己觉得时间很宝贵，每一个**30分钟**都可以做很多事情，将时间划分到具体的小块的这样一种生活方式，能让自己感受到每天的一点点小进步。尽管睡眠时间不足6小时，有时候更少
，但是每天下午的跑步（有时间是晚上）再加上一个热水澡却能让一天的精神疲劳彻底消除。
跑步是一项永无止境的挑战项目，在耐力和速度上都能不断挑战自我，最近一周里，耐力突破了8公里+，速度突破了2公里7：55秒，虽然不算很厉害，但是毕竟是自我一个挑战，在则一周目标突破2公里7：50秒和8.5公里耐力跑。
##bug&问题集：##
bug01：最近在学习mysql编写数据库的时候遇到了一个bug，调试很久都不知道，最后在该博客找到问题的原因
https://blog.csdn.net/chen2526264/article/details/80534239?utm_source=blogxgwz6

bug描述：
另一个类在使用静态块的时候，第一次会先加载静态块再初始化静态方法，但是如果静态块中
出现异常，则该类无法加载，抛出xception in thread "main" java.lang.NoClassDefFoundError


    public class JDBCUtil {
    /**
     * get file of properties 
     */
    	static Properties pros = new Properties();
    /**
     * loading properties when class is used	
     */
    	static{
    		try {
    			pros.load(Thread.currentThread().getContextClassLoader().getResourceAsStream("db.properties"));
    		} catch (IOException e) {
    			e.printStackTrace();
    		}
    	}
    	public static Connection getMysqlConn() {
    		try {
    			Class.forName(pros.getProperty("mysqlDriver"));
    			return (Connection) DriverManager.getConnection(pros.getProperty("mysqlURL"), 
    					pros.getProperty("mysqlUser"), pros.getProperty("mysqlPwd"));
    		} catch (Exception e) {
    			e.printStackTrace();
    			return null;
    		}
    	}


解决方案？？-------（暂时的代替方案为不用扩展项）

2.第一次使用myeclipse没有出现web.xml
解决方案：
[https://www.cnblogs.com/whgk/p/9081565.html](https://www.cnblogs.com/whgk/p/9081565.html "超链接")


3.与数据库对接的时候出现的乱码问题（项目名称）


原因：在blob中放置了文本文件，在clob中放置了图片
解决方案： 修改回来
乱码问题小结：
字符集不匹配
编码操作有误（特别是流的操作）
解码操作有误（特别是流的操作）
详细请了解该网站[https://blog.csdn.net/aerchi/article/details/80197446](https://blog.csdn.net/aerchi/article/details/80197446)

4.获取mysql的时间类date问题
报错时间类格式问题：


原因：get方法的（列参数不匹配）
在navicat中列参数需要通过设计表或者构图来观看，而不是表内容
正确视图：
1.设计表

2.图的形式

错误的使用：
此时的列参数为错误；

5.web.xml文件的配置小问题（未解决）
新建一个servlet的时候会发生错误，但是在删除掉选中的两行后就不会报错

未报错

原因：待发现
解决方案：待解决

6.提交表单未跳转页面问题（需要反省一下的bug）
问题描述：在servlet中书写的一个表单提交--打开网页却没有跳转

页面正在提交表单

然而并没有什么反应

web.xml配置正常

原因很简单，html打错代码。（手动滑稽~看了一小时）

7.网页重新载入问题bug
问题具体描述：
在显示个人信息的页面中，使用io流从数据库中获取clob数据，

网页显示

点击重载按钮

然后个人介绍神奇的消失了

但是重新登录却仍然正常（）
原因：
解决方案：

项目的疑问以及可优化的思考：
    public class StuInfo {
    	protected long id;
    	protected String name;
    	protected String major;
    	protected String group_direction;
    	protected String sex ;// f-->female m-->male
    	protected java.sql.Date dateOfBirth;
     //set get 方法
    	public void setEmpty() {
    		this.id = 0;
    		this.major = null;
    		this.name = null;
    		this.group_direction = null;
    		this.dateOfBirth = null;
    		this.sex = null;
    
    	}
    }

该子类的私有属性使用流作为存储手段。
    public class CatInfo extends StuInfo{
    	
    //get stream of self_introduce	
    	private Reader rd;
    //get the strean of personal_phpto
    	private InputStream is;
     // get set method
     //set empty（）
     ｝
## 这一周的学习的安排 ##

1. 学完视频教程中的**servlet&jsp** 
1. 之后可以开始学习**多线程和javaWeb**
2. 由于知识不系统性，可以没事的时候看看计算机导论来看看计算的方向
3. 刚就完了