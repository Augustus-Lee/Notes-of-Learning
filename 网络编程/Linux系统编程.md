

|                 主键盘快捷键：                 |
| :--------------------------------------------: |
|                   上  Ctrl-p                   |
|                   下  Ctrl-n                   |
|                   左  Ctrl-b                   |
|                   右  Ctrl-f                   |
|        Del   Ctrl-d delete  光标后面的         |
|           Home  Ctrl-a first  letter           |
|                End  Ctrl-e end                 |
| Backspace Backspace delete  光标前面的单个字符 |
|                清除整行  Ctrl-u                |



#### 2. Linux系统目录：

- bin:存放二进制可执行文件
- boot：存放开机启动程序
- dev：存放设备文件
- home：存放普通用户
- etc：用户信息和系统配置文件
- lib：库文件
- root：管理员宿主目录
- usr：用户资源管理目录  unix software resource
- 文件权限说明
  - **-rw-r--r-- 2 augustus staff    25 Jan 7 00:08 file**
  - **文件权限 硬链接计数 所有者 所属组 大小 时间 文件名/文件夹名**

#### 3. Linux系统文件类型： 7/8 种

- 普通文件：-
- 目录文件：d
- 字符设备文件：c
- 块设备文件：b
- 软连接：l
- 管道文件：p
- 套接字：s
- 未知文件。

#### 4. 软/硬链接

		1. 作用：为解决文件的共享使用。链接为 Linux 系统解决了文件的共享使用，还带来了隐藏文件路径、增加权限安全及节省存储等好处。
1. 软链接：相当于是window下的快捷方式。***命令：ln(link) -s file file.s***
    - 使用软链接时，**最好使用绝对路径创建，相对路径创建时，在软链接进行移动后就会失效，无法访问。**
    - 软链接的权限指的是这个软链接本身的权限，不是软链接指向文件的权限
2. 硬链接：***ln file file.s***
    - 每个文件都有一个唯一的Inode，**实际上系统是通过Inode来找到对应的文件**，文件和硬连接的**Inode**是相同的，有点类似C++中的引用，若有一个发生变化，另外的也会发生改变。
    - 当删除一个硬链接时，文件的硬链接计数-1，当这个计数减为 0 时，才会删除这个文件。当删除文件本身时，也是硬链接计数-1。



#### 5.创建、修改用户组

1. **Chmod：修改文件状态**

   - 文字设定法：chmod [who]  [+ | - | =]  [mode] filename   ----> chmod u+x  file1 

     - 操作对象 who 可以是下述字母中的任一个或者它们的组合

     - u 表示”用户(user)”，即文件或目录的所有者

     - g 表示”同组(group)用户”，即与文件所有者有相同组 ID 的所有用户

     - o 表示”其他(others)用户” 

     - a 表示”所有(all)用户”，它是系统默认值。

     - 操作符号可以是：

       \+ 添加某个权限

       \- 取消某个权限

       = 赋予给定权限并取消其他所有权限（如果有的话）

         

   - 数字设定法：

     - chmod 操作码 filename    直接用操作码修改文件权限   chmod 777 11.cpp 
     - **操作码 r(read):4; w(write) : 2; x(execute) 1**
     - 操作码为7（4 + 2 + 1）**则意味该文件在当前用户下可读可写可执行。**共有三个用户组（u,g,o）。

2. Chown：修改文件所属者

    - **sudo adduser newusername** 添加新用户
    - sudo chown username filename  (chown gus 11.cpp) 把文件11.cpp的所有者改成gus
    - **sudo chown username:groupname filename**  同时修改文件所属用户和用户组
    - su username 切换当前用户
    - sudo delusername 删除用户



#### 6.find命令：用来搜索文件

1. -type：按类型来搜索，find  目录 -type(按文件类型搜索)  d/p/s/c/b/l（linux文件类型） 
2. -name：按文件名搜索，find ./ -name '*.cpp'
3. -maxdepth：指定搜索深度，find ./  -maxdepth 2 -name '*.cpp'，2是指最大遍历的深度为2，**注意  maxdepth应作为第一参数**。
4. -size ：按文件大小搜索，**单位：k 、M、G，大小写敏感**，find ./ -size +10k -size -20k，要有两个size，查找最少10K，最大20K的文件
5. -exec： **find ./ -name ' * .cpp' -exec ls -ld {} \ ;**   --- 将find搜索的**结果集**执行某一指定命令  
    - -ok：以交互的方式，将find搜索的结果集执行某一指定命令
    - *find  ./ -name '*.cpp' | xargs ls -ld*   --- 将find搜索的**结果集**执行某一指定命令，**两者的作用是相同的**，两者差别在于当结果集合很大的时候，xargs 会对结果进行分段处理，所以性能好些；但 xargs 也有缺陷，**xargs 默认用空格来分割结果集**，当文件名有空格的时候，会因为文件名被切割 失效
        - find ./ -type f -print0 | xargs -print0 ls -l   --**print0可以解决xargs的缺陷，指定切分符号位null**，第一个 print0 指定结果集分隔为 null，第二个 print0 指定 xargs 分隔为 null。
6. -atime,ctime,mtime 按天；    atime、mmin、cmin 按分钟。
    - a表示最近访问时间
    - c表示最近改动时间，改的是文件内容
    - m表示最近更改时间，**改的是文件属性一类的**



#### grep：用来搜索文件内容

1. 











  

#### 安装、卸载、管理软件---apt/apt-get(Advanced package tools)

1. sudo apt-get/apt update   更新软件列表资源到本地  **apt是新版的管理工具，作用与apt-get类似，但功能尚未有apt-get齐全**。
2. 安装   sudo apt install softname
3. 卸载  sudo apt remove softname
4. deb包安装（linux下的软件是.deb格式）
    - sudo dpkg -i 安装包名    i --> install
    - 删除  sudo dpkg -r 安装包名    r  --> remove





#### 压缩/解压

1. 压缩命令**gzip**和**bzip2**，两者都只可以对单个文件进行压缩，**不能压缩目录也不能打包**，故配合**tar打包命令**可以对多个文件或目录进行压缩。
    - 压缩  gzip filename 
    - 解压 gunzip zipfile
2. tar zcvf 要压缩的包名  压缩材料   压缩的包名一般以.tar.gz结尾，方便识别
    - *tar **zcvf** test.tar.gz 11.cpp 22.cpp*   **使用gzip方式压缩**
    - zcvf的解释：
        - z：zip，表示压缩
        - c：create，创建
        - v：vision，显示压缩过程，可省略
        - f：file，文件
3. <u>file filename</u>  查看文件来源
4. tar **jcvf** test.gar.bz 1.cpp 2.cpp  **使用bzip2方式压缩**
5. 将 c ---> x
    - tar **zxvf** 压缩包
    - tar **jxvf** 压缩包
6. rar a -r 压缩包名（最好加.rar）压缩材料   -->  rar -a -r(递归)  test.rar 11.cpp
7. 压缩：zip  -r 压缩包名  压缩材料    解压： unzip  压缩包

#### 其他指令

1. man(manual)：系统参考手册   -----  man  n name  在系统手册第n章查看name
2. alias(别名)：给命令起别名    alias ll='ls -laF'   ---> ll 实际指令里的 **F 意味着带文件标识符，目录末尾有/，可执行文件末尾带***。





#### Vim基本操作

1. ![vim](/Users/swqt/Desktop/Gus/Programming/vim.png)
2. **vim删除、查找等操作**
    - **i-->进入编辑模式，光标前插入字符，a-->光标后插入字符，o-->光标所在行的下一行插入**。（无特殊说明，都是命令模式下）。
    - **I-->光标所在行的的行首插入，A-->光标所在行的行末插入，O-->光标所在行的上一行插入字符**
    - s-->删除光标所在字符进入编辑模式，S-->删除光标所在行并进入编辑模式
    - x-->删除光标所在字符，工作模式不变；dw-->删除一个单词，前提是光标在单词首字母.
    - *命令模式下的光标移动：h-->左移，l-->右移，j-->下移，k-->上移。*
    - **命令模式下：gg-->跳至首行，G-->跳至尾行，gg=G-->排版。**
    - *%-->找到对应括号所在位置。*
    - <u>dd-->删除光标所在行，n+dd-->删除指定行数。</u>工作模式不变。
    - 0-->光标移至行首，工作模式不变；$-->光标移至行尾，工作模式不变。
    - d+0-->删除光标所在位置到行首，d+$-->删除光标所在位置到行尾，工作模式不变都不变；D-->删除光标所在位置到行末，工作模式不变。
    - r-->替换单个字符（按了r之后再按要替换的字符）
    - v-->进入“可视模式”，选中区域之后可按d删除选中区域。
    - yy-->复制一行；p-->**向后**粘贴，P-->**向前**粘贴（vim不存在真正意义上的删除，**所谓删除都是剪切**）
    - **查找：/ + findname（末行模式下）n-->是next，查找下一个；光标在目标单词上任意字母，按*或者#即可查找下一个**
    - u-->撤销，ctrl+r-->反撤销
    - 分屏：sp-->横屏分，ctrl + w + w切换屏幕；vsp-->竖屏分，ctrl + w + w切换屏幕。
    - **跳转至man手册，光标放置单词处，K-->跳转，nK-->跳转至指定卷**
    - 执行SHELL命令：（末行模式）<u>！+ command</u>     **:! g++ hello.cpp -o hello**
    - <u>:%s  /待替换词/替换词</u> -->全文替换，默认只替换每行首个； **<u>:%s  /待替换词/替换词/ g</u> -->真正意义上的全局替换**
3. vim配置：
    - /etc/vim/vimrc
    - ~/.vimrc   属于用户配置  **用户目录下~/.vimrc优先级较高，两个都设置时，优先使用用户目录下。**
4. g++编译：*g++ test.cpp -o test*    生成名为test的可执行文件
    - ![编译四步骤](/Users/swqt/Desktop/Gus/Programming/编译四步骤.png)
    - -I -->指定头文件所在目录。**-I与目录之间没有空格**  *g++ test.cpp -o test* -I/home/cpp/test
    - **-c -->只做预处理、编译、汇编。得到二进制文件！即.o文件(目标文件)。**
    - -g -->编译时添加调试语句。主要支持gdb语句。
    - -Wall -->显示所有警告信息。
    - -D -->向程序中“动态”注册宏定义。



#### 静态/动态库

1. 静态库制作步骤及使用步骤：

    - 静态库名字以lib开头，以.a结尾，如 libmylib.a

    - 静态库生成指令 --> <u>ar rcs libmylib.a  file1.o</u>

    - 步骤一：写好源代码；

    - 步骤二：编译源代码生成.o文件 --> <u>g++ -c test.cpp -o test.o</u>

    - 步骤三：制作静态库  ar  rcs  libmylib.a  file1.o  file2.o

    - **静态库使用：** g++ test.cpp libmylib.a -o test

    - 上述会出现一些警告，故使用头文件的方式来加载静态库

    - ```cpp
        #ifndef _MYMATH_H
        #define _MYMATH_H //防止多次包含此头文件
        
        int add(int, int);
        
        int sub(int, int);
        
        int div1(int, int);
        
        #endif
        ```

    - **将静态库与头文件放在不同目录：g++ libtest.cpp ./mylib/libmymath.a -o tt -I ./temp/**。*-I --> 加载头文件所在位置*。

2. 动态库（共享库）制作及使用

    1. 将文件生成与位置无关的.o文件  --> *g++ -c add.c -o add.o -fPIC*   使用这个参数过后，生成的函数就与位置无关挂上@plt标识，等待动态绑定。
    2. 使用g++ -shared 制作动态库  -->  *g++ -shared -o libmymath.so add.o sub.o div1.o*
    3. 编译可执行程序时指定所使用的动态库。-l --> 指定库名(取中间，不要lib，如mymath)   -L --> 库的路径(.so文件的路径)。   *g++ libtest.cpp -o  a.out -l mymath  -L ./mylib -I ./inc*
    4. **运行可执行程序 ./a.out  ！！！ --> 会报错**
        - 原因:
            1. 链接器：工作于链接阶段，工作时需要-l 和-L。
            2. **动态链接器：两者毫无关联。工作于程序运行阶段，工作时需要提供动态库所在目录。**
        - 解决方法：
            1. **通过环境变量**：在终端中执行 export LD_LIBRARY_PATH=./mylib (动态库路径)  -->  **但这是临时性的，重启终端会失效。**
            2. **永久生效**：写入终端配置文件，vim ~/.bashrc  --> 建议使用绝对路径。
                - 在.bashrc配置文件中写入 *export LD_LIBRARY_PATH=/home/augustus/Desktop/Linux/dynamicLib/mylib (动态库路径)* 
                - . .bashrc --> 执行bashrc文件 / sourec .bashrc 使之生效，或者重启终端也行
            3. 配置文件法：
                - sudo vim /etc/ ld.so.conf
                - **写入 动态库绝对路径**  保存
                - sudo ldconfig -v 是配置文件生效
                - ./b.out 成功执行！！！ ----使用 ldd b.out可以查看动态库路径是否正确

3. 函数库**：一组具有相近、相似功能函数结合。作用是为了提高代码复用，提高开发效率。静态库和动态库属于函数库。**

4. **动态库（共享库）：**

    - 多个可执行程序共享同一个库文件（共享代码，不共享数据）
    - 节省内存，易于更新
    - 速度较慢，适用于对时间要求较低，对空间要求较高的场合
    - **动态、静态库共存时，编译器优先使用动态库**

5. **静态库：**

    - **每个使用静态库的程序都要将整个静态库编译到可执行程序中**，故很消耗内存空间。
    - 库函数本地，调用较快；系统消耗资源大
    - 适用于对空间要求较低，而对时间要求较高的核心程序中。







#### GDB调试工具

1. -g：使用该参数编译可执行文件，得到调试表。 *g++ gdbtest.cpp -o a.out -g*
2. 基础指令：
    - gdb a.out 进入gdb调试
    - l(list): 列出源码  l 1列出指定行号源码
    - b(break)：断点设置  b 20 --> 在20行设置断点
    - r(run)：运行程序
    - **n(next)：下一条指令（跳过函数）**
    - **s(step)：下一条指定（进入函数）**
    - p(print)：p  i 查看变量i的值
    - continue：继续执行断点后续指令
    - finish：结束当前函数调用
    - quit：退出gdb当前调试
3. 其他指令：
    - 使用run可以查找段错误出现位置
    - set args：设置**main函数**命令行参数 --> set args sb cd 
    - run 字串1 字串2...：设置**main函数**命令行参数  --> run ab cd 
    - info b：查看断点信息表
    - b 10 if i = 5：设置条件断点。当i=5时设置第十行的断点。
    - ptype：查看变量类型。
    - 栈帧：**随着函数的调用而在stack上开辟的一片内存空间。用于存放函数调用时产生的局部变量和临时值。**
    - bt(backtrace)：列出当前程序正在存活着的栈帧。
    - frame：根据栈帧编号，切换栈帧
    - display：设置跟踪变量
    - undisplay：取消设置跟踪变量。使用跟踪变量的编号。

#### Open函数

1. ```cpp
    //返回一个文件描述符，理解为整数，若错误则返回-1
    int open(const char *pathname, int flags);
    int open(const char *pathname, int flags, mode_t mode);
    ```

2. pathname --> 文件路径， flags -->  权限控制   只读、只写、读和写  O_RDONLY  O_WRONLY   O_RDWR    

    - O_TRUNC --> **若文件存在，则长度截为0，意味着清楚文件原有的内容,在创建空文件**
    - O_RDONLY|O_WRONLY|O_RDWR O_CREAT|O_APPEND|O_TRUNC|O_EXCL|O_NONBLOCK ....

3. mode --> 用来指定文件的权限，数字设定法    文件权限 = mode & ~umask

    - umask：**umask命令指定在建立文件时预设的权限掩码。umask可用来设定[权限掩码]。[权限掩码]是由<u>3个八进制的数字所组成</u>，<u>将现有的存取权限减掉权限掩码后</u>，即可产生建立文件时预设的权限。**

4. open常见错误：

    - 打开文件不存在
    - 以只写方式打开只读文件（权限问题）
    - 以只写方式打开目录文件
    - **当open出错时门程序会自动设定*errorno*，可以通过*strerror*(errorno)查看报错数字的含义**



#### Read函数

1. ```cpp
    ssize_t read(int fd, void *buf, size_t count);
    ```

2. fd --> 文件描述符  buf -->**存数据的缓冲区**  count --> **缓冲区大小**

3. 返回值：

    - 0：读到文件末尾
    - 成功：>0 读到的字节数
    - 失败：-1，设置errorno   **返回-1且当error = EAGIN或EWOULDBLOCK，说明不是read失败，而是read在以非阻塞方式读一个设备文件（网络文件），并且文件无数据。**

4. 错误处理函数：

    - ```cpp
        //错误处理函数： 与 errno 相关。
        cout << errno << endl;
        
        char *strerror(int errnum);
        cout << strerror(errno) << endl;
        
        void perror(const char *s);
        perror("open error");
        
        if(fd == -1)
        {
          perror("opem xxx error!");
          exit(1);//结束
        }
        ```



#### Write函数

```cpp
ssize_t write(int fd, const void *buf, size_t count);
```

1. fd --> 文件描述符  buf -->**待写出数据的缓冲区**  count --> **数据大小**

2. 返回值：

    - 成功 --> 写入的字节数
    - 失败 --> -1，设置errno

3. ```cpp
    		//用read和write实现copy
        
        1 #include <iostream>                                                       
        2 #include <unistd.h>
        3 #include <fcntl.h>
        4 #include <cstring>
        5 #include <cstring>
        6 
        7 using namespace std;
    ✹   8 int main(int argc, char *argv[])
        9 {
       10     char buf[1024];//一次性读取1024个字节
       11     int n = 0;
       12     int fd1 = open(argv[1],O_RDONLY); //read
       13 
       14     int fd2 = open(argv[2],O_RDWR | O_TRUNC |O_CREAT,0664);//rw--r--r
       15     while((n = read(fd1,buf,1024)) != 0)
       16     {
       17         write(fd2,buf,n);
       18     }
       19 
       20     close(fd1);
       21     close(fd2);
       22 
       23     return 0;
       24 }
       25 
    
    ```



#### 系统函数与库函数的比较（Copy的实现）

1. **read/write系统函数，每进行一次写入，会进行内核态与用户态的切换，如果频繁进行切换（小字节的写入），会非常耗时。fgetc/fputc库函数有个缓冲区，大小为4096字节，故并不是一个字节一个字节的写入，则内核态与用户态切换就比较少**。
2. 预读入，缓输出机制。所以系统函数不是一定比库函数好，能使用库函数的地方尽量都使用库函数。
3. **标准IO函数自带用户缓冲区，系统函数无用户级缓冲**。系统缓冲区是都有的。
4. 应用程序 --> 标库函数 --> 系统调用 --> 驱动 --> 硬件



#### 文件描述符：

1. 定义：**指向一个文件结构体的指针。**
2. PCB(进程控制块)：本质是一个结构体（类）。
    - 成员：文件描述符表。
    - 文件描述符：0、1、2、3....1023    每次使用的是表中可用的最小的。
    - 0 --> STDIN_FILENO   1 --> STDOUT_FILENO   2 --> STDERR_FILENO



#### 阻塞、非阻塞：是设备文件、网络文件的属性。

1. 产生阻塞的场景：读设备文件，度网络文件。（读常规文件无阻塞概念）
2. /dev/tty  -- 终端文件
3. open("/dev/tty",O_RDWR | O_NONBLOCK)    ---设置/dev/tty非阻塞状态。（默认为阻塞状态）



#### fcntl改变文件属性

1. fcntl：用来改变一个**已经打开的文件**的访问控制属性。**例如把一个阻塞读改成非阻塞读。**重点掌握两个参数：***F_GETFL --> 获取文件状态, F_SETFL --> 设置文件状态***
2. int flgs = fcntl(fd, *F_GETFL*)   fd --> 文件描述符  
3. flgs |= O_NONBLOCK  -->或等于  l
4. fcntl(fd,*FSETFL*,flgs);





#### lseek函数：

1. ```cpp
     *off_t lseek(int fd, off_t offset, int whence);*  
    ```

2. fd --> 文件描述符    offset  -->  **偏移量**  whence  --> **起始偏移位置**：SEEK_SET / SEEK_CUR /SEEK_END

3. 返回：较起始位置偏移量   失败  -->  -1 errno

4. 应用场景：

    1. 文件的**读、写**应使用同一偏移位置。
    2. 使用lseek函数获取文件大小。即0~SEEK_END的偏移量。**用 lseek 读取文件大小实际用的是读写指针初末位置的偏移差**。
    3. 使用lseek拓展文件大小：要想使文件大小真正拓展，必须引起IO操作。**lseek 读取到偏移差的时候，还没有写入最后的‘$’符号，于是就至少要写入一个字符，故总的大小要加上write函数写入的大小。**

#### 传入传出参数：

1. 传入参数：
    - 指针作为函数参数
    - **通常有const关键字修饰**
    - 指针指向有效区域，在函数内部做读操作
2. 传出参数:
    - 指针作为函数参数
    - 在函数调用之前，指针指向的空间可以无意义，但必须有效。
    - 在函数内部，做写操作。
    - 函数调用结束后，充当函数返回值。
3. 传入传出参数;
    - 指针作为函数参数
    -  **在函数调用之前，指针指向的空间有实际意义。**
    -  **在函数内部，先做读操作，后做写操作。**
    -  函数调用结束后，充当函数返回值。



#### 目录项和inode

1. 一个文件主要有两部分组成，**dentry（目录项）和inode**
2. inode的本质是结构体，存储文件的属性信息，如：权限、类型、大小、时间...也叫做文件属性管理结构，大多数的inode都存储在磁盘上。少量常用、近期使用的inode会被缓存到内存中。
3. 所谓的删除文件，就是删除inode，但是数据其实还在硬盘上，以后会覆盖掉。



#### stat函数

1. 作用：获取文件属性（从inode结构体中获取）

2. stat/lstat函数：

    - ```cpp
        int stat(const char *path, struct stat *buf)
          
        //知识补充
        int main(int argc, char *argv[])
        // int argc 是指命令行中参数的总个数
        //argv是一个字符数组，其大小是int argc，数组中每个元素都是一个参数，通常argv[0]是可执行文件的文件名，故从argv[1]开始
        ```

    - path：文件路径     **buf：传出参数，存放文件属性，inode结构体指针**

3. 返回值：0 --> 成功    -1--> 失败  errno

4. 获取文件属性：

    - 获取文件大小 --> buf.st_size
    - 获取文件类型 --> buf.st_mode
    - 获取文件权限 --> buf.st_mode

5. 符号穿透：**stat 会拿到符号链接指向那个文件或目录的属性，不想符号穿透就使用lstat。**





#### Link和Unlink隐式回收

1. 硬链接数就是dentry（**目录项：记录着文件名，上级目录等信息**）数目，link就是用来创建硬链接数的，link可以用来实现mv命令。

2. ```cpp
    int link(const char *oldpath, const char *newpath)
    ```

3. 实现mv，用oldpath来创建newpath，然后删除oldpath。

4. ```cpp
    //删除一个链接
    int unlink(const char *pathname)
    ```

5. unlink 函数的特征：清除文件时，如果文件的硬链接数到 0 了，没有 dentry 对应，但该文件仍不会

    马上被释放，**要等到所有打开文件的进程关闭该文件，系统才会挑时间将该文件释放掉**。

6. 隐式回收：**当进程结束运行时，所有进程打开的文件会被关闭，申请的内存空间会被释放**。称之为隐式回收系统资源



#### 目录操作函数

1. ```cpp
    #include<dirent.h>
    
    //都只有一个参数
    DIR* opendir(char *name);
    
    int closedir(DIR *dp);
    
    struct dirent *readdir(DIR *dp);
    
    struct dirent
    {
      ino_t inode;
      char dname[256];
    }
    
    
    //实现ls操作
    
     int main(int argc, char *argv[])
         {
            DIR *dp;
            struct dirent *sdp;
            dp = opendir(argv[1]);
           	if(dp == nullptr)
            {
               perror("opendir error");
                exit(1);
           	}
        
           	while((sdp = readdir(dp)) != nullptr)//每次都要更新 sdp
           	{
               cout << "name: " << sdp->d_name << "\t";
            }                                                                         
            cout << endl;
            closedir(dp);
            return 0;
        }
    
    ```

2. 没有写目录操作，因为目录写操作就是创建文件。可以用touch。







#### 实现递归遍历目录

1. 任务需求：使用opendir closedir  readdir  stat函数实现递归遍历目录的程序
2. 先实现一个简单版的，判定文件以及读取文件大小
3. sprintf(path, "%s/%s", dir, sdp->d_name);路径





#### dup和dup2

1. 作用：用来做重定向，**本质就是复制文件描述符**。

2. ```cpp
    //文件描述符复制
    int dup(int oldfd);
    //oldfd --> 已有文件描述符
    //返回 --> 新文件描述符和oldfd指向相同内容
    ```

3. ```cpp
    int dup2(int oldfd,int newfd);//文件描述符复制，oldfd 拷贝给 newfd。返回 newfd
    
    ```

4. **将oldfd拷贝给newfd，故newfd与oldfd都指向同一个文件，即oldfd指的文件，可通过newfd进行写操作来修改oldfd指向的文件（类似变量的引用）**，默认打开的文件，读写指针是从头开始，如果文件中有内容，则会**覆盖原有内容。**



### fcntl实现dup描述符

1. ```cpp
    int fcntl(int fd,int cmd,...)// cmd --> F_DUPFD
      
    ```

2. 参数3 --> **被占用的，返回最小可用的。  未被占用，返回=该值的文件描述符**

3.  ```cpp
    			int main(int argc, char *argv[])
        8 {
        9     int fd = open(argv[1],O_RDWR);
       10     cout << "fd: " << fd << endl;
       11 
       12     int newfd = fcntl(fd,F_DUPFD,5);//返回最小的可用的文件描述符
       13     cout << "newfd: " << newfd << endl;
       14 
       15     int ret = write(newfd,"hello world!",12);//返回成功写入的字节数
       16     cout << ret << endl;
       17                                                                           
       18     return 0;
       19 }
    
    ```



#### 进程和程序以及CPU相关

1. 程序：编译好的二进制文件。“死的”，只占用磁盘空间，不占用系统资源。 -->剧本
2. 进程：“活的”，运行起来的程序，占用内存、CPU等系统资源。 --> 戏
3. 并发和并行：
    - **并发：一个时间段多个程序并行执行。**
    - 多道程序设计：**并行是宏观上并发，微观上串行。**
4. MMU(Memory Management Unit)：**可以完成虚拟地址到物理地址的转换（虚拟内存管理）。**
5. 进程控制块PCB：
    - 进程ID（PID）
    - 文件描述符表
    - 进程状态（五种）：初始态、就绪态、运行态、挂起态（等待除CPU以外的其他资源主动放弃cpu）、终止态。**其中初始态为进程准备状态，常与就绪态结合来看。**
    - 进程工作目录位置
    - umask掩码
    - 信号相关信息资源
    - 用户id和组id
    - 命令ps aux返回的第二列为PID
6. 环境变量：**一般是指在<u>操作系统</u>中用来指定操作系统运行环境的一些参数**。
    - echo $PATH 查看环境变量  PATH --> 环境变量里记录了一系列的值，**当运行一个可执行文件时，系统会去环境变量记录的位置查找这个文件并执行。**
    - env --> 查看所有环境变量



#### fork函数原理（重要）

1. ```cpp
    pid_t fork(void)  //用于创建子进程   返回值为pid（整数）
    ```

2. **父子进程各自返回，父进程返回子进程pid，子进程返回0**。

3. 两个函数：**getpid() --> 获取当前进程id   getppid() --> 获取当前进程的父进程id**

4. *子进程id = 父进程 id + 1*

5. **对操作系统而言，子进程（一个或多个）与父进程争抢cpu，谁抢到cpu，谁就执行，但可以使用sleep休眠函数使之休眠指定时间。**

6. **父、子进程共享内容：**

    - **父、子进程相同**：刚fork后，data段、text段、堆、栈、环境变量、全局变量
    - 父、子进程**不同**：进程id、返回值、各自的父进程、进程的创建时间
    - 父、子进程**共享**：
        1. **读时共享，写时复制**  --> 应用于全局变量区
        2. 文件描述符
        3. mmap映射区



#### exec函数族

1. 作用：使进程执行某一程序。成功无返回值，失败返回-1。**当进程调用exec函数，该进程原来的空间代码和数据完全被新程序替换，从新程序的启动例程开始执行。exec函数并不创建新进程，原来的进程ID并没有发生变化。即换核不换壳。**

2. ```cpp
    //p --> 指PATH环境变量，故一般用于执行系统命令
    int execlp(cosnt char *file,const char *arg,....);
    ```

3. 参数1 --> 程序名   参数2 --> **argv0**(即也是程序名)   参数3 --> argv1  ....  最后一个必须为哨兵NULL（声明这是到最后了）

4. ```cpp
    //自己指定待执行程序路径
    int execl(const char*path, const char*arg,...);
    ```

5. ```cpp
    					pid_t pid = fork();
       10     if(pid == -1)
       11     {                                                               
       12         perror("fork error");
       13         exit(1);
       14     }
       15     else if (pid == 0)
       16     {
       17         //execlp("ls","ls","-a","-l",NULL);//成功无返回值
       18         execl("./22","22",NULL);
       19         perror("exec error");
       20         exit(1);
       21 
       22     }
       23     else
       24     {
       25         sleep(1);
       26         cout << "I'm parent " << getpid() << endl;
       27     }
        
    ```

6. **exec函数一旦调用成功，即执行新程序，不会再返回。只有失败的时候才会返回-1。**

7. l(list)  p(path)  v(vector)  e(environment) 

8. *事实上，只有execve函数是真正的系统调用，其他函数都是库函数，通过调用execve。*

#### 孤儿进程和僵尸进程

1. 孤儿进程：父进程先于子进程终止，**子进程沦为“孤儿进程”**，会被init进程领养。

2. 僵尸进程：**子进程终止，父进程尚未对子进程进行回收，在此期间，子进程沦为“僵尸进程”**。kill对其无效。*Notes：每个进程结束后都必然经历僵尸态，时间长短而已。*

3. 子进程终止时，子进程残留资源 PCB 存放于内核中，PCB 记录了进程结束原因，进程回收就是回

    收 PCB。回收僵尸进程，得 kill 它的父进程，让孤儿院去回收它。



#### wait函数回收子进程

1. ```cpp
    //回收子进程退出的资源，阻塞回收任意一个
    pid_t wait(int *status);
    //参数：（传出）回收进程的状态
    //返回值   成功 --> 回收进程的pid     失败 --> -1，error
    ```

2. 作用：

    - 阻塞等待子进程退出
    - 清理子进程残留在内核的pcb资源
    - 通过传出参数，得到子进程的结束状态

3. **获取子进程退出值和异常终止信号**：

    - 获取子进程退出值：WIFEXITED(status)  --> 为真   --> 调用WEXITSTATUS(status)  --> 得到子进程退出值。
    - 获取导致子进程异常终止信号：WIFSIGNALED(status) --> 为真   --> 调用WTERMSIG(status) --> 得到导致子进程异常终止的信号编号。

4. waitpid函数：指定某一个进程进行回收。可以设置非阻塞。

5. ```cpp
    pid_t waitpid(pid_t pid, int *status, int options)
     //返回值   >0：待回收的子进程pid   -1：任意子进程    0：同组的子进程
    ```

6. 参数：

    - pid --> 指定回收某一个子进程pid   
    - status：（传出）回收进程的状态
    - options：WNOHANG 指定回收状态，非阻塞。

7. **一次wait/waitpid函数调用，只能回收一个子进程。**wait函数会随机回收一个子进程。

8. ```cpp
    			int main(int argc, char *argv[])
        9 {
       10     pid_t pid, wpid, tmpid;
       11     int i;
       12 
       13     for(i = 0; i != 5; i++)
       14     {
       15 
       16         pid = fork();
         					//循环期间  子进程不fork
       17         if(pid == 0)
       18         {
       19             break;
       20         }
       21         //指定 第三个进程回收
       22         if(i == 2)
       23         {
       24             tmpid = pid;
       25             cout << "pid : " << tmpid << endl;
       26         }
       27 
       28 
       29     }
       30     //父进程
       31     if(i == 5)
       32     {
       33         sleep(5);
       34 
       35         wpid = waitpid(tmpid,NULL,0);//阻塞回收
       36         if(wpid == -1)
       37         {
       38             perror("waitpid error");
       39             exit(1);
       40         }
       41 
       42         cout << "I'm parent, pid: " << wpid << endl;
       43     }
       44     else
       45     {
       46         //按顺序执行
       47         sleep(i);
       48         cout << "I'm " << i + 1 << "th child, pid: " << getpid() << endl;
       49     }
       50     return 0;
       51 }
    
   ```

9. **waitpid回收多个子进程**

    - ```cpp
        //借助于 while loop
        //以 阻塞方式 回收多个子进程
        while(wpid = waitpid(-1,NULL,0))
          
        //以 非阻塞方式 
        while(wpid = waitpid(-1,NULL,WNOHANG))
        ```



#### IPC（InterProcess Communication）进程间通信

1. 进程间通信的常用方式，特征：

    - 管道（pipe）：简单，适用于有血缘关系（父子进程，兄弟进程...）的进程之间
    - 信号：开销小
    - mmap映射：非血缘关系进程间
    - socket（套接字）：稳定，难度也最大

2. **管道：**

    - 实现原理：**内核借助于环形队列机制，使用内核缓冲区实现**。
    - 特质：
        1. 伪文件
        2. 管道中的数据**只能进行一次读取**。（队列的特征）
        3. 数据在管道中，只能单向流动。
    - 局限性
        1. 自己写，不能自己读。
        2. **双向半双工**（一次只能读或者写，不能同时进行）
        3. 只能在有公共祖先的进程间进行通信（即有血缘关系）

3. 管道的基本用法:

    - pipe函数：创建并打开管道

    - ```cpp
        int pipe(int fd[2]);
        //参数： fd[0] -->读端   fd[1] -->写端
        //返回值  成功 --> 0  失败 --> -1   error
        ```

    - ```cpp
        					pid_t pid;
           17     int fd[2];
           18 
           19     int ret;
           20     const char *str = "hello world!"; 
           21     char buf[1024];
           22 
           23     ret = pipe(fd);
           24 
           25     if(ret == -1) sys_err("pipe error");                                                                                                                                          
           26 
           27     pid = fork();
           28     //父进程写
           29     if(pid > 0)
           30     {
           31         close(fd[0]); //关闭读段
           32         //sleep(2);
           33         write(fd[1],str,strlen(str));
           34 
           35         close(fd[1]);
           36         
           37 
           38     }
           39     else if(pid == 0)
           40     {
           41         //子进程读
           42         close(fd[1]);//关闭写段
           43 
           44         ret = read(fd[0],buf,sizeof(buf));
           45         
           46         cout << "child process read bytes: " << ret << endl;
           47         write(STDOUT_FILENO,buf,ret);//把读到buf的内容输出到屏幕上
           48 
           49         close(fd[0]);
           50 
           51     }
           52     else
           53     {
           54         sys_err("fork error");
           55     }
            
        ```

4. 管道的读写行为：

    - 读管道：
        1. 管道有数据，read返回实际读到的字节数
        2. 管道无数据，
            - 无写端，read返回0（类似读到末尾）
            - 有写端，read阻塞等待
    - 写管道：
        1. 无读端，异常终止。（SIGPIPE导致的）
        2. 有读端：
            - 管道已满，则阻塞等待
            - 管道未满，返回写出的字节个数

5. **普通文件，目录，软链接这三个占用磁盘空间；管道，套接字，字符设备，块设备不占磁盘空间，是伪文件。**

6. **实现 ls | wc -l命令**：

    - ```cpp
        				int ret = 0;
           17     pid_t pid;
           18     int fd[2];
           19 
           20 
           21     ret = pipe(fd);
           22 
           23     if(ret == -1)
           24     {
           25         sys_err("pipe error");
           26     }
           27 
           28     pid = fork();
           29 
           30     if(pid == 0)
           31     {
           32         close(fd[0]);//关闭读端，子进程写
           33         dup2(fd[1],STDOUT_FILENO);
           34         execlp("ls","ls",NULL);
           35         sys_err("execlp error");
           36     }
           37     else if (pid > 0)
           38     {
           39         close(fd[1]);
           40         dup2(fd[0],STDIN_FILENO);
           41         execlp("wc","wc","-l",NULL);
           42         sys_err("execlp error");                                                                                                                                                  
           43     }
           44     else
           45     {
           46         sys_err("fork error");
           47     }
        
        ```

    - **允许一个pipe有一个写端多个读端，也可以是一个读端多个写端。**

7. 命名管道fifo的创建

    - 具有管道的特点，**以及适用于无血缘关系的进程间通信**。

    - ```cpp
        //读端
        open(fifo,O_RDONLY)
          
        //写端
         open(fifo,O_WRONLY)
        ```

    - fifo操作起来像文件。

    - **使用fifo在无血缘关系的进程间通信，需要两个文件，一个用于写fifo，一个用于读fifo。**

8. 文件可用于进程间通信：

    - 打开的文件是内核中的一块缓冲区。**多个无/有血缘关系的进程，可以同时访问该文件。**





#### mmap函数原型

1. 存储映射 I/O（Memory-mapped I/O）**使一个磁盘文件与存储空间中的一个缓冲区相映射**。于是**从缓冲区中取数据，就相当于读文件中的相应字节。与此类似，将数据存入缓冲区，则相应的字节就自己写入文件**。这样，就可以不适用read和write函数，是地址指针完成I/O操作。可以使用*mmap*函数完成这种映射。

2. ```cpp
    void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
    //创建共享内存映射
    //返回值  成功：映射区的首地址   失败：MAP_FAILED (void*(-1)),errno
    ```

3. 参数：

    - addr：指定映射区的**首地址**，通常使用NULL，表由有系统自动分配
    - length：共享内存映射区的**大小**。（<=文件的实际大小）
    - prot：共享内存映射区的**读写属性**。PROT_READ、PROT_WRITE、PROT_READ|PROT_WRITE
    - flags：标注共享内存的共享属性。MAP_SHARED,MAP_PRIVATE
        - *shared 意思是修改会反映到磁盘上，private 表示修改不反映到磁盘上*
    - fd：**用于创建共享内存映射区的那个文件的文件描述符**。
    - offset：默认0，表示映射文件全部。偏移位置。需是4K的整数倍

4. ```cpp
    int mumap(void *addr, size_t length);   //释放映射区
    // addr --> mmap的返回值    length --> 大小
    ```

5. mmap建立映射区：

    - ```cpp
         //mmap
           18     int fd;
           19     char *p;
           20 
           21     fd = open("testmmap",O_RDWR|O_TRUNC|O_CREAT,0664);
           22 
           23 
           24     if(fd == -1)
           25     {
           26         sys_err("open error");
           27     }
           28 
           29     //拓展文件大小
           30 
           31    // lseek(fd,20,SEEK_END);
           32    // write(fd,"\0",1);
           33 
           34     ftruncate(fd,20);//拓展文件大小  等于lseek  + write 
           35     int len = lseek(fd,0,SEEK_END);//计算文件大小
           36 
           37     p = reinterpret_cast<char*>				(mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0));
            
           38 
           39     if(p == MAP_FAILED)
           40     {
           41         sys_err("mmap error");
           42     }
           43 
           44     strcpy(p,"what's up guys");
           45 
           46     cout << p << endl;
           47 
           48     int ret = munmap(p,len);
           49 
           50     if(ret == -1)
           51     {
           52         sys_err("munmap error");
           53     }
           54     close(fd);
            
        ```

    - **mmap使用注意事项**：

        1. *用于创建映射区的文件大小为0*，实际指定**非0大小的文件**创建映射区，出“**总线错误**”。
2. *用于创建映射区的文件大小为0*，实际指定0大小的文件创建映射区，出“**无效参数**”。
        3. 用于创建映射区的文件读写属性为，只读。映射区属性为 读、写。 出 “无效参数”。
4. 创建映射区，需要 read 权限。当访问权限指定为 **“共享”MAP_SHARED 时**， mmap 的读写权限，应该 <=文件的 open 权限。 只写不行。
        5. 文件描述符 fd，**在 mmap 创建映射区完成即可关闭**。后续访问文件，用地址访问。
6. offset必须是4096的整数倍。（MMU映射的最小单位为4K）
        7. 对映射区分配的内存，不能越界访问。
8. munmap用于释放的地址，必须是mmap申请返回的地址。
        9. 映射区的访问权限是“私有”MAP_PRIVATE时，对内存做的所有修改，只在内存有效，不会反映到物理磁盘上。
10. 映射区的访问权限是“私有”MAP_PRIVATE时，只需要open文件时，有读权限，用于创建映射区即可。  
        
- mmap函数的保险调用方式：
  
    - ```cpp
            fd = open("文件名",O_RDWR);
        
            mmap(NULL,有效文件大小，PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
        ```
    
6. 父子进程间mmap通信

    	1. **父进程先创建映射区，open("filename"，O_RDWR)，mmap(...)。**
     	2. 指定MAP_SHARED权限。
     	3. fork创建子进程。一个进程读，一个进程写。

7. **mmap：数据可以重复读写。fifo：数据只能一次读取。**

8. 匿名映射：只能用于 血缘关系进程间通信。*p = (int *)mmap(NULL, 40, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);*





#### 信号

1. 信号的共性：简单、不能携带大量信息、满足条件才发送。

2. 信号的特质：信号是**软件层面**上的中断。一旦信号产生，无论程序执行到什么位置，必须立即停止运行，马上处理信号，处理结束之后再继续执行后续指令。

3. 所有信号的产生及处理全部都是由**内核**完成的。

4. 产生信号：

    1. 按键产生
    2. 系统调用产生
    3. 软件条件产生
    4. 硬件异常产生
    5. 命令产生

5. 概念

    - **未决**：产生与递达之间的状态。主要由于阻塞（屏蔽）导致该状态。
    - **递达**：产生并且送达到进程。直接被内核处理掉。

6. 信号处理方式：

    1. 执行默认动作
    2. 忽略（丢弃）
    3. 捕捉（调**用户处理函数**）

7. 阻塞信号集（信号屏蔽字）：本质：位图。**用来记录信号的屏蔽状态**。一旦被屏蔽的信号，在解除屏蔽前，一直处于未决态。

8. 未决信号集：本质 --> 位图，**用来记录信号的处理状态**。该信号集里的信号表示已产生但尚未被处理。

9. **信号四要素**：

    - 信号编号（SIGHUP...）、信号名称（value）、信号对应事件（Action）、信号默认处理动作。
    - 默认动作：
        1. Terminal：终止进程
        2. Ignore：忽略信号（默认即对该种信号忽略操作）
        3. Core：终止进程，生成Core文件。（查明进程死亡原因，用于gdb调试）
        4. Stop：停止（暂停）进程
        5. Cont（continue）：继续进行进程。

10. *SIGKILL*和*SIGSTOP*信号，**不允许忽略和捕捉，只能执行默认动作。甚至不能将其设置为阻塞。**   

    - 11）SIGSEGV（段错误）--> 非法访问内存。
    - 7）SIGBUS --> 总线错误
    - 8）SIGFPE --> 除0操作

11. **kill函数/命令产生信号**

    1. kill命令：kill -SIGKILL pid

    2. ```cpp
        int kill(pid_t pid,int sig) //sig  待发送的信号
        //返回值  成功：0   失败：-1
        ```

    3. pid > 0：发送信号给指定的进程。

        - pid = 0：发送信号给跟**调用kill函数的那个进程属于同一进程组的进程**
        - pid < -1：取绝对值，发送信号给**该绝对值所对应的进程组的所有组员**。
        - pid =-1：发送信号给有权限发送的**所有进程**。

12. alarm函数：使用自然计时法

    - 定时发送SIGALRM给当前进程

    - ```cpp
        unsigned int alarm(unsigned int seconds)
        //seconds：定时秒数
        //返回值：上次定时剩余时间  无错误现象 
        alarm(0)：取消闹钟
        ```

    - time命令：查看程序执行时间。 实际时间 = 用户时间 + 系统时间 + 等待时间   ——》优化瓶颈IO

13. setitimer函数：

    - ```cpp
        int setitimer(int which, const struct itimerval* new_value,struct itimerval 
        *old_value)
          //返回值  成功：0  失败：-1 errno
        ```

    - 参数：

        1. which : 

            -  ITIME_REAL   ——》**采用自然计时**   SIGALRM
            - ITIMER_VIRTUAL: 采用用户空间计时 ---> SIGVTALRM
            - ITIMER_PROF: 采用内核+用户空间计时 ---> SIGPROF

        2. new_value：定时秒数

            - ```cpp
                类型：struct itimerval {
                	struct timeval {
                		time_t tv_sec; /* seconds */
                		suseconds_t tv_usec; /* microseconds */
                	}it_interval;  //---> 周期定时秒数
                	struct timeval {
                		time_t tv_sec; 
                		suseconds_t tv_usec; 
                	}it_value; //---> 第一次定时秒数
                };
                ```

        3. old_value：传出参数，上次定时剩余时间

            - ```cpp
                e.g.
                struct itimerval new_t;
                struct itimerval old_t;
                
                new_t.it_interval.tv_sec = 2;//以后是每2s循环
                new_t.it_interval.tv_usec = 0;
                new_t.it_value.tv_sec = 1; //第一次开始时间是1s后
                new_t.it_value.tv_usec = 0;
                
                int ret = setitimer(ITIME_REAL,&new_t, &old_t); 定时 1 秒
                ```

14. **信号集操作函数**：

    - ```cpp
        sigset_t set; //自定义信号集
        
        sigemptyset(sigset_t *set); //清空信号集
        
        sigfillset(sigset_t *set); //全部置 1
        
        sigaddset(sigset_t *set, int signum); //将一个信号添加到集合中
        
        sigdelset(sigset_t *set, int signum); //将一个信号从集合中移除
        
        sigismember（const sigset_t *set，int signum); //判断一个信号是否在集合中。 在:1，不在:0
        ```

    - 设置信号屏蔽字和解除屏蔽

        - ```cpp
            int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
            //how --> SIG_BLOCK: 设置阻塞  SIG_UNBLOCK: 取消阻塞   
            //SIG_SETMASK: 用自定义 set 替换 mask。
            //set 自定义set
            //oldset 旧的mask
            ```

    - 查看未决信号集

        - ```cpp
            int sigpending(sigset_t *set)
            //传出的未决信号集    set:传出参数
            ```

        - ```cpp
            					//1. create 
               31     sigset_t set, oldset, pedset;
               32 
               33     //2. clear	
               34     sigemptyset(&set);
               35     
               36     //3. add signal to set 
               37     sigaddset(&set,SIGINT);
               38 
               39     //4. set block 
               40     int ret = sigprocmask(SIG_BLOCK,&set,&oldset);
               41     if(ret == -1)
               42     {
               43         sys_err("sigproc error");
               44     }
               45     while(1)
               46     {
               47         //look up undetermined signal set 
               48         sigpending(&pedset);
               49         printSet(&pedset);
               50         sleep(1);
               51     }
                
            ```

15. **信号捕捉函数：**

    - ```cpp
        
        // 1.
        typedef void (*sighandler_t)(int); //函数指针  注册一个信号捕捉函数
        
        sighandler_t signal(int signum, sighandler_t handler);
        
        ```

    - signum --> 待捕捉信号  handler --> **捕捉信号后的操纵函数**

    - ```cpp
        //第二个信号捕捉函数    -----重要
        int sigaction(int signum, const struct sigaction *act,
                             struct sigaction *oldact);
        //返回值 成功：0  失败：-1
        
        struct sigaction {
                       void     (*sa_handler)(int);
                       void     (*sa_sigaction)(int, siginfo_t *, void *);
                       sigset_t   sa_mask;
                       int        sa_flags;
                       void     (*sa_restorer)(void);
                   };
        
        					struct sigaction act, oldact;	
           26 
           27     act.sa_handler = sigCatch;//设置回调函数
           28     sigemptyset(&(act.sa_mask)); //清空屏蔽字，只在sig_catch工作时有效
           29 
           30     act.sa_flags = 0;//默认为0
           31 
           32     int ret = sigaction(SIGINT, &act, &oldact);
           33     if(ret == -1)
           34     {
           35         sys_err("sigaction error");
           36     }
        
        
        ```

    - 信号捕捉的特性：

        1. 捕捉函数执行期间，信号屏蔽字由mask --> sa_mask，捕捉函数执行结束，恢复回mask。
        2. 捕捉函数执行期间，**本信号自动被屏蔽(sa_flaf = 0)**
        3. 捕捉函数执行期间，被屏蔽信号多次发送，解除屏蔽后只**处理一次。**

16. **中断系统调用**

     - 慢速系统调用中断：**可能会使进程永久阻塞的一类**。如果在阻塞期间收到一个信号，该系统调用就被中断，不再继续执行，也可以设定系统调用是否重启。如read、write、pause...

17. 会话：**多个进程组的集合。**

     - 创建会话的六点注意事项：
         1. 调用进程不能是进程组组长，该进程变成新会话首进程。
         2. 该进程成为一个新进程组的组长进程。
         3. 需要root权限（ubuntu不需要）
         4. 新会话丢弃原有的控制终端，该会话没有控制终端。
         5. 该调用进程是组长进程，则出错返回
         6. 建立新会话时，先调用fork，父进程终止。
     - getsid函数：pid getsid(pid_t pid)    -->获取当前进程的会话id
     - setsid函数：pid setsid(void)   创建一个会话，并以自己的ID设置进程组ID，同时也是新会话的ID。



#### 进程/线程

1. **守护进程：**

    - daemon进程。通常运行于操作系统后台，脱离终端控制。一般不与用户直接交互。**周期性的等待某个事件的发生或周期性的执行某一动作。**
    - 不受用户登录注销影响，一般用d结尾。

2. 守护进程创建步骤：

    1. fork子进程，让父进程终止。
    2. 子进程调用setsid()创建新会话
    3. 通常根据需要，**改变工作目录位置chdir()**，防止目录被卸载。
    4. 根据需要,**重设umask文件权限掩码**，影响新文件的创建权限。022 --> 755（**umask表示反码，通常用777 -umask所设定的反码**）。
    5. 根据需要，关闭/重定向文件描述符
    6. 守护进程业务逻辑。while()

3. **线程：**

    - 什么是线程：
        1. LWP：*light weight process*  -->  **轻量级的进程**，本质仍是进程（Linux环境下）。
        2. **进程：拥有独立的进程地址空间，有PCB；线程：无独立的进程地址空间（共享），*有PCB*。**区别：在于是否共享地址空间。
        3. Linux下：线程：最小的执行单位；进程：最小的资源分配和管理的单位。
        4. **ps -LF 进程id**     -->   查看线程号。LWP   -->  cpu执行的最小单位。

4. 线程控制原语：

    1. ```cpp
        pthread_t pthread_self(void);  //获取线程id   线程 id 是在进程地址空间内部，用来标识线程身份的 id 号。
        //返回本线程id
        
        
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);
        
        /*
        参数1：传出参数，表新创建的子线程id
        参数2：线程属性，传NULL表使用默认属性
        参数3：子线程回调函数。创建成功，pthread_create函数返回时，该函数会被自动调用
        参数4：参数3的参数。没有的话，传NULL
        
        返回值：成功  0；失败：errno
        */
        
        g++ thread.cpp -o thread -lpthread //要加上链接库-lpthread，以调用静态链接库。因为pthread并非Linux系统的默认库。 
        ```

    2. **线程间全局变量共享。**

    3. pthread_exit();

        ```cpp
        void pthread_exit(void *retval); //退出当前线程
        /*retval：退出值，无退出值时，NULL
        
        exit(0)：退出当前进程
        return：返回到调用者那里去
        */
        
        ```

        

    4. pthread_join函数：

        ```cpp
        int pthread_join(pthread_t thread, void **retval );//阻塞  回收进程
        	
         	//thread:待回收的线程id
        	//retval：传出参数。回收的那个线程的退出值   线程异常助力，值为-1
        	//返回值：成功  0  失败：errno
        
        ```

    5. pthread_cancle函数：

        ```cpp
        int pthread_cancle(pthread_t thread)  //杀死一个进程，需要到达取消点
        //thread：待杀死的线程id
        //返回值：成功 0 失败：errno
        
        ```

        - 如果，子线程没有到达取消点，那么pthread_cancel无效。我们可以手动添加一个取消点，pthread_testcancel()。
        - 成功被 pthread_cancel() 杀死的线程，返回 -1.使用 pthead_join 回收。
        - **pthread_cancel 工作的必要条件是进入内核**。

    6. int pthread_detach(pthread_t thread)函数

        ```cpp
        //线程中  检查出错返回使用 strerror
        int pthread_detach(pthread_t thread); //设置线程分离
        /*
        thread：待回收的线程id
        分离后的线程  会自动回收
        
        返回值：  成功 0   失败 errno
        
        */
        ```

        |   线程控制原语   | 进程控制原语 |
        | :--------------: | :----------: |
        | pthread_create() |    fork()    |
        |  pthread_self()  |   getpid()   |
        |   pthread_exit   |    exit()    |
        |   pthread_join   |    wait()    |
        |  pthread_cancel  |    kill()    |
        |  pthread_detach  |              |

5. **线程的属性：**

    - ```cpp
        //设置分离属性
        pthread_attr_t attr  //创建一个线程属性结构体变量
        pthread_attr_init(&attr) //初始化线程属性
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED)//设置线程属性为分离状态
          
        pthread_create(&tid,&attr,tfn,NULL) //借助修改后的 设置线程属性 创建为分离态的新线程
        pthread_attr_destory(&attr)  //销毁线程属性
        ```

6. **线程使用注意事项：**

    1. 主线程退出其他线程不退出时，**主线程应调用pthread_exit()函数。**
    2. 避免僵尸线程：
        - pthread_join()
        - pthread_detach()
        - pthread_create函数指定分离属性
    3. **避免在多线程中使用fork()函数，**子进程中只有fork的线程存在，其他的线程都pthread_exit()。
    4. **避免在多线程中引用信号机制。**

7. **线程同步**：

    - 协同步调，对公共区域数据**按序访问**。**防止数据混乱，产生与时间相关的错误。**
    - 数据混乱的原因：
        1. 资源共享（独享资源则不会）。
        2. 调度随机（则数据访问会出现竞争）
        3. 线程间缺乏必要的同步机制。



#### 互斥锁/互斥量(mutex)

1. 主要函数：

    - pthread_mutex_init; 
    - pthread_mutex_destroy
    - pthread_mutex_lock 
    - pthread_mutex_trylock
    - pthread_mutex_unlock 

2. 一般步骤：

    1. **pthread_mutex_t mlock; 创建锁**
    2. **pthread_mutex_init; 初始化**
    3. **pthread_mutex_lock 加锁**    1--  --》0
    4. **访问共享数据**
    5. **pthread_mutex_unlock 解锁**  0++ --》 1

3. ```cpp
    int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr)
    //restrict是关键字  表示指针指向的内容只能通过这个指针进行修改
    /*
    	restrict关键字：用来限定指针变量。 被该关键字限定的指针变量所指向的内存操作，必须由本指针完成。
    
    */
    ```

4. ```cpp
    
    pthread_mutex_t mutex;
    
    pthread_mutex_init(&mutex,NULL);  //动态初始化
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //静态初始化
    ```

5. 锁的使用：**建议锁！**对公共数据进行保护，所有线程**应该在访问公共数据前先拿锁再访问**，但锁本身并不具备强制性。

6. 注意事项：

    - 尽量保证锁的粒度，越小越好。（*访问公共数据前，加锁。访问结束立即解锁*）
    - 互斥锁，**本质是结构体，我们可以看成整数**。初值为-1。（pthread_mutex_init()函数调用成功）
    - 加锁：--操作，阻塞线程。解锁：++操作，唤醒线程。
    - try锁：**尝试加锁**，成功则--；失败则返回，同时设置错误号EBUSY。

7. 死锁：**是使用锁不恰当导致的现象**。

    - 两种死锁：
        1. 对一个锁反复加锁(lock)。
        2. 两个线程，各自持有一把锁，请求另一把。

8. 读写锁特性：

    1. 读写锁是“**写模式加锁**”时，解锁前，所有对该锁加锁的线程都会被堵塞。

    2. 读写锁是以“**读模式加锁**”时，解锁前，如果线程以读模式加锁会成功，如果线程以写模式加锁会阻塞。

    3. 读锁，写锁并行阻塞，**写锁优先级高**。

    4. 读写锁又称共享-独占锁。当读写锁以读模式锁住时，是以共享模式锁住的；当它以写模式锁住时，它是以独占模式锁住的。**写独占，读共享。**

    5. 读写锁非常适合对于数据结构**读的次数远大于写的情况**。

    6. **锁只有一把**，但有两种状态。以读方式给数据加锁--读锁，以写方式给数据加锁--写锁。

    7. ```cpp
        pthread_rwlock_t rwlock;  //定义一个读写锁变量
        pthread_rwlock_init(&rwlock,NULL);
        pthread_rwlock_rdlock(&rwlock);
        pthread_rwlock_wrlock(&rwlock);
        pthread_rwlock_unlock(&rwlock);
        pthread_rwlock_destroy(&rwlock);
        
        ```

9. **条件变量：**本身不是锁，但通常结合锁来使用。mutex

    - ```cpp
        pthread_cond_t cond;	//定义条件变量
        
        pthread_cond_init
        pthread_cond_destory
        pthread_cond_wait
        pthread_cond_timewait;//设置等待时长  当前时间：time_t cur = time(NULL)  绝对时间：timespec
        pthread_cond_signal
        pthread_cond_broadcast
        //以上函数的返回值 成功：0  失败：返回相应的错误号
          
        //初始化条件变量
        pthread_cond_init(&cond,NULL);  //动态初始化变量
        pthread_cond_t cond = PTHREAD_COND_INITALIZER;  //静态初始化变量
        ```

    - ```cpp
        //阻塞等待条件
        pthread_cond_wait(&cond,&mutex);
        /*
        作用：
        		1.阻塞  等待至条件变量满足
        		2.解锁已经加锁成功的信号量  --》 pthread_mutex_lock
        		3.当条件满足，函数返回时，解除阻塞并重新申请获取互斥锁，重新加锁信号量  --》 pthread_mutex_unlock
        */
        
        ```

    - ```cpp
        pthread_cond_signal(); // 唤醒阻塞在条件变量上的（至少）一个线程
        pthread_cond_broadcast(); //唤醒阻塞在条件变量上的  所有线程
        ```

    - ![producer and consumer](/Users/swqt/Desktop/Gus/Programming/producer and consumer.png)

10. 信号量(semaphore)

    1. 作用：**应用于线程间、进程间同步。**

    2. **相当于初始化为N的互斥量**。N --》**表示可以同时访问共享区域的最大的线程数**。

    3. 函数：

        - ```cpp
            sem_t sem;//定义类型
            int sem_init(sem_t *sem, init pshared, unsigned int value);
            /*
            	参数：
            			sem：信号量
            			pshared：0 --》用于线程间同步
            							 1（非0）--》 用于进程间同步
            			value：N值（指定同时访问的线程数）
            */
            
            sem_destory();
            
            sem_wait(); //一次调用，做一次 -- 操作，当信号量的值为0时，再进行--操作会阻塞（对比pthread_mutex_lock()）
            sem_post(); //一次调用，做一次 ++ 操作，当信号量为N时再进行++操作会阻塞（对比pthread_mutex_unlock()）
            
            ```

        - 



















































