# MFC连接本地的SQL server

感觉这学生信息管理系统要写的代码实在太多了，所以我们可以精诚合作一波。
我的MFC窗口已经可以显示SQL Server数据库里的数据了，但感觉使用MFC 连接sql server 并不是很容易，所以我写了
这个大家来参考一下。

大概的步骤就是：

1. 先安好sql server，然后安装sql management studio，创建好student的数据，这个数据库基本和数据库课程里学的差不多。注意数据库里最好有点数据，不然不好测试。

2. 数据库大家用的都是不用输入密码，本机直接登陆的方式，这里要改成使用sa登陆，具体方法看[这个博客](https://jingyan.baidu.com/article/e5c39bf5c3d0cf39d76033a6.html),注意弄完了以后sql server 要重启，具体方法右键数据库用户名点击重启。

3. 然后按照[这个博客](https://blog.csdn.net/zcyzsy/article/details/53027416)设置ODBC

4. 打开你的vs工程文件

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/3.jpg)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/4.png)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/5.png)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/6.png)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/7.png)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/8.png)

![image](https://github.com/zyzisyz/Programming-Practice/blob/master/img/9.png)