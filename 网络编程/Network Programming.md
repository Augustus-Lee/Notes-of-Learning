#### 一、网络基础

1. 协议：**一组规则**。

2. 分层模型结构：

    - OSI七层模型：1.物理层 2.数据链路层 3.网络层 4.传输层 5.会话层 6.表示层 7.应用层
    - TCP/IP 4层模型：1.数据链路层（网络接口层） 2.网络层 3.传输层 4.应用层
        - 应用层常用协议：ftp、http、ssh、telnet...
        - 传输层：TCP、UDP...
        - 网络层：IP、ICMP...
        - 链路层：ARP、以太网帧协议...

3. 网络传输流程：

    - **数据没有封装之前，是不能在网络中传递**。
    - 数据 --》应用层 --》传输层 --》网络层 --》链路层 --》网络环境

4. 以太网帧协议：

    - ARP协议：**根据IP地址获取MAC地址。**
    - 以太网帧协议：根据MAC地址，完成数据包传输。

5. IP协议：

    - 版本IPv4、IPv6。-- 大小4位（IP数据报中）
    - TTL：time to live。设置数据包在路由节点中的**跳转上限**。每经过一个路由节点，则-1，当路由为0时，有义务将该数据包丢弃。

6. 端口号和UDP协议：

    - 16位：源端口号。2^16 = 65536
    - 16位：目的端口号。
    - **IP地址**：**网络环境中可以唯一标识一台主机**。
    - **端口号**：可以在网络中的**一台主机上，唯一标识一个进程**。
    - **IP地址 + 端口号**：可以在**网络环境中，唯一标识一个进程。**

7. TCP协议：

    - 16位：源端口号。2^16 = 65536
    - 16位：目的端口号。
    - 32位序号
    - 32位确认序号
    - 6个标志位
    - 16位窗口大小。 2^16 = 65536

8. |          |        C/S（客户端/服务器）        | B/S（浏览器/服务器）             |
    | :------: | :--------------------------------: | -------------------------------- |
    | **优点** | 缓存大量数据、协议选择灵活，速度快 | 跨平台、开发工作量小、安全性较高 |
    | **缺点** |  安全性较低、不可跨平台、工作量大  | 不能缓存大量数据、严格遵守http   |

9. **TCP通信时序：**

    - **六个标志位**：
        1. **SYN(synchronous)**： **发送/同步标志，用来建立连接**，和下面的第二个标志位ACK搭配使用。连接开始时，SYN=1，ACK=0，代表连接开始但是未获得响应。当连接被响应的时候，标志位会发生变化，其中ACK会置为1，代表确认收到连接请求，此时的标志位变成了 SYN=1，ACK=1；
        2. **ACK(acknowledgement)**：确认标志，表示确认收到请求；
        3. PSH(push) ：表示推送操作，就是指数据包到达接收端以后，不对其进行队列处理，而是尽可能的将数据交给应用程序处理；
        4. **FIN(finish)**：结束标志，用于结束一个TCP会话；
        5. RST(reset)：重置复位标志，用于复位对应的TCP连接。
        6. URG(urgent)：紧急标志，用于保证TCP连接不被中断，并且督促中间层设备尽快处理。
    - **两个序号：**
        1. **Sequence number（顺序号）** ：发送数据包中的**第一个字节的序列号**，一般为小写的seq。
        2. Acknowledge number（确认号）：响应前面的seq，**值为seq+1**，可以理解为**期望下次发出的序列号为seq+1**。
    - **三次握手**：
        1. 主动发起连接请求端，发送**SYN（同步）标志位**，请求建立连接。携带顺序序号（seq number）、数据字节数（0）、滑动窗口大小。
        2. 被动接收连接请求端，**发送SYN+ACK（确认）标志位**，请求建立连接。携带**顺序序号、确认序号（ack number）**、数据字节数、滑动窗口。
        3. 主动发起请求端，发送**ACK标志位**，**应答服务器请求连接**，携带**确认序号**。
    - **四次挥手**：
        1. **主动**发送关闭连接请求端，发送**FIN（结束）标志位**。
        2. **被动**应答关闭连接请求端，**发送应答ACK标志位**。 --> 半关闭完成
        3. 被动发送关闭连接请求端，发送FIN标志位。
        4. 主动映带关闭连接请求端，应答ACK标志位。         --> 连接全部关闭
    - 滑动窗口：发送给连接对端，对本端的缓冲区大小（实时），**保证数据不会丢失**。



#### 二、Socket编程

1. 网络套接字（Socket）

    - 一个文件描述符(fd)指向一个套接字（该套接字内部由内核借助两个缓冲区实现。）
    - **在通信过程中，socket一定是成对出现**。

2. 网络字节序:

    - 小端法：**高位存高地址，低位存低地址**。（PC一般采取该存储方式）

    - 大端法：**高位存低地址，低位存高地址**。（网络中一般采取该存储方式）

        - htonl(host-to-network-long 函数：用于把本地IP进行转换（**小端转成大端存储**）)  本地 -->网络（**IP**）   	192.168.1.11(string )--> atoi(int) --> htonl -->网络字节序

        - htons：本地 --> 网络（Port） 
        - ntohl：网络 --> 本地（IP）
        - ntohs：网络 --> 本地（Port）

    - IP地址转换函数：

        - ```cpp
            //用于本地字节序（string IP） ---> 网络字节序
            int inet_pton(int af, const char*src, void* dst)
            //返回值  成功 --> 1  异常 --> 0  失败 --> -1
            ```

        - af --> AF_INET, AF_INET6分别指 IPV4、IPV6

        - src：传入，IP地址（点分十进制）

        - dst：传出参数，转换后的 网络字节序的 IP地址。 

        - ```cpp
            //网络字节序 ---> 本地字节序（string IP）
            const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
            //返回值  成功 --> dst  失败 --> NULL
            ```

        - src --> 网络字节序IP地址

        - dst --> 本地字节序（string IP）

        - size --> dst的大小

3. **socketaddr数据结构**：

    - socketaddr地址结构：**IP + port  --> 在网络环境中唯一标识一个进程**

    - ```cpp
        struct sockaddr_in addr;
        
        addr.sin_family = AF_INET/AF_INET6				//man 7 ip
        addr.sin_port = htons(9527);
        int dst;
        inet_pton(AF_INET, "192.157.22.45", (void *)&dst);
        
        addr.sin_addr.s_addr = dst;
        
        addr.sin_addr.s_addr = htonl(INADDR_ANY);		//取出系统中有效的任意IP地址。二进制类型。
        
        bind(fd, (struct sockaddr *)&addr, size);
        ```

4. **socket**函数：

    - ```cpp
        //头文件
        #include<sys/socket.h>
        
        int socket(int domain,int type,int protocol)//创建一个套接字
        ```

    - ==domain== ：

        1. AF_INET（**这是大多数用来产生socket的协议，使用TCP或UDP来传输，用IPv4的地址**）,
        2. AF_INET6（类似，不过是IPv6）
        3. AF_UNIX（本地协议，使用在Unix和Linux系统上，一般都是当客户端和服务器在同一台及其上的时候使用） 

    - **type**：

        1. **SOCK_STREAM** 这个协议是按照顺序的、可靠的、数据完整的基于字节流的连接。这是一个使用最多的socket类型，这个socket是使用TCP来进行传输。
        2. **SOCK_DGRAM** 这个协议是无连接的、固定长度的传输调用。该协议是不可靠的，使用UDP来进行它的连接。

    - protocol：0表示默认协议

    - 返回值： 成功 --> **新套接字的对应文件描述符**   失败 --> -1，errno

5. **bind**函数：

    - ```cpp
        #include<arpa/inet.h>
        
        //给socket绑定一个地址结构（IP + port）
        int bind(int sockfd,const struct sockaddr_in *addr, socklen_t addrlen)
          
        ```

    - sockfd：socket函数的返回值

    - addr：**传入参数(struct sockaddr *)&addr**

    - addrlen：sizeof(addr地址结构的大小)

    - 返回值：成功：0  失败： -1，errno

6. **listen**函数与**accept**函数：

    - ```cpp
        //设置同时与服务器建立连接的上限数（同时进行3次握手的客户端数量）
        
        int listen(int sockfd,int backlog)
        // sockfd：函数的返回值
        //backlog上限数值。最大值128。
        //返回值  成功：0   失败：-1，errno
          
          
        //阻塞等待客户端建立连接，成功的话，返回一个与客户端成功连接的socket文件描述符。
          
        int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
        // sockfd：函数的返回值
        //addr：传出参数  成功与服务器建立连接的那个客户端的地址结构（IP+port）  
          
        //addrlen：传入传出。 &clit_addr_len
        //入：addr的大小。 出：客户端addr实际大小。
          
        //返回值  成功：能与客户端进行数据通信的 socket 对应的文件描述符
        //失败 -1，errno
        
        ```

7. **connect**函数（客户端函数）：：

    - ```cpp
        //使用现有的 socket 与服务器建立连接
        int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
          
        ```

    - sockfd：socket函数返回值

    - addr：

        1. ```cpp
            struct sockaddr_in srv_addr;		// 服务器地址结构
            srv_addr.sin_family = AF_INET;
            
            srv_addr.sin_port = 9527 //	跟服务器bind时设定的 port 完全一致。
            
            inet_pton(AF_INET, "服务器的IP地址"，&srv_adrr.sin_addr.s_addr);
            ```

        2. addr：传入参数。服务器的地址结构

    - addrlen：服务器的地址结构的大小

    - 返回值：成功：0   失败：-1，errno

    - 如果不用bind**绑定客户端地址结构**，则采用隐式绑定。

8. ==CS模型的TCP通信分析==：

    - **TCP通信流程分析**：
        - Server：
            1. socket() 创建socket
            2. bind() 绑定服务器结构地址
            3. listen() 设置监听上限
            4. accept() 阻塞监听客户端连接
            5. read(fd) 读socket获取客户端数据
            6. write(fd)
            7. close()
        - Client：
            1. socket()  创建socket
            2. connect() 与服务器建立连接
            3. write() 写数据到socket
            4. read() 读转换后的数据
            5. 显示读取结果
            6. close()

9. **多进程并发服务器（流程）：**

    - ```cpp
        	1. Socket();		创建 监听套接字 lfd
            	2. Bind()	绑定地址结构 Strcut scokaddr_in addr;
            	3. Listen();	
            	4. while (1) {
            
            				cfd = Accpet();			接收客户端连接请求。
            				pid = fork();
            				if (pid == 0){			子进程 read(cfd) --- 小-》大 --- write(cfd)
            
            				close(lfd)		关闭用于建立连接的套接字 lfd
            
            				read()
            				小--大
            				write()
            
            				} else if （pid > 0） {	
            
            					close(cfd);		关闭用于与客户端通信的套接字 cfd	
            					contiue;
            				}
            	  }
            
            	5. 子进程：
            
            		close(lfd)
            
            		read()
            
            		小--大
            
            		write()	
            
            	   父进程：
                  				 	close(cfd);
            
            						注册信号捕捉函数：	SIGCHLD
            
            						在回调函数中， 完成子进程回收
            
            							while （waitpid()）;
        ```

10. **多线程并发服务器（流程）：**

    - ```cpp
        	1. Socket();		创建 监听套接字 lfd
            
            	2. Bind()		绑定地址结构 Strcut scokaddr_in addr;
            
            	3. Listen();		
            
            	4. while (1) {		
            
            				cfd = Accept(lfd, );
            
            				pthread_create(&tid, NULL, tfn, (void *)cfd);
            
            				pthread_detach(tid);  				// pthead_join(tid, void **);  新线程---专用于回收子线程。
            	  }
            
            	5. 子线程：
            
            		void *tfn(void *arg) 
            		{
            				// close(lfd)			不能关闭。 主线程要使用lfd
            
            				read(cfd)
            
            				小--大
            
            				write(cfd)
            
            				pthread_exit（(void *)10）;	
            		}
        ```

11. **TCP状态时序图（结合三次握手、四次挥手理解记忆）：**

    1. **主动**发起连接请求端：CLOSE（初始状态） --> 发送SYN -->  **SYN_SEND** --> 接收对端的ACK、SYN --> **SYN_SEND** --> 发送ACK --> **ESTABLISHED**（数据通信状态） 【结合三次握手】
    2. **主动**关闭连接请求端：**ESTABLISHED** --> 发送FIN --> **FIN_WAIT_1** --> 接收对端的ACK --> **FIN_WAIT_2（半关闭状态）** --> **对端**发送FIN  -->  **FIN_WAIT_2** --> 回发ACK --> **TIME_WAIT**（只**有主动关闭连接请求端，会经历该状态**） --> 等待2MSL -->**CLOSE**          【结合四次挥手】
    3. **被动**接收连接请求端：CLOSE --> **LISTEN** --> 接收SYN --> **LISTEN** --> 发送SYN、ACK --> **SYN_RCVD** --> 接收ACK --> **ESTABLISHED**
    4. **被动**关闭连接请求端：**ESTABLISHED** --> 接收FIN --> **ESTABLISHED** --> 发送ACK --> **CLOSE_WAIT (说明对端【主动关闭连接端】处于半关闭状态)**  --> 发送FIN  --> **LAST_ACK**  --> 接收ACK  --> **CLOSE**
    5. **2MSL时长**：一定出现在**主动关闭请求连接端**！对应TIME_WAIT状态。 **作用**：保证对端能成功收到最后一个ACK。（等待期间，若对端没有收到我端的发的ACK，对端会再次发送FIN）

12. **端口复用**：

    - ```cpp
        int opt = 1; // 设置端口复用。
        //固定模板  记住
        setsockopt(lfd,SOL_SOCKET,SO_REUSEADDR,(void *)&opt,sizeof(opt));
        ```

13. 半关闭：通信双方中，**只有一端关闭通信**。

    - close(fd)

    - ```cpp
        shutdown(int fd, int how) 
        /*
        how: 	SHUT_RD   关闭读端
        			SHUT_WR	  关闭写端
        			SHUT_RDWR 关闭读写端
        	
        */
        ```

    - shutdown在关闭多个文件描述符应用的文件时，采用全关闭方式。close，只关闭一个。

14. **select**函数

    - ```cpp
        int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
        /*
        	nfds --> 监听的所有的文件描述符中，最大文件描述符+1
        	readfds --> 读 文件描述符监听集合       传入传出参数 
        	writefds --> 写 文件描述符监听集合      传入传出参数      NULL
        	exceptfds --> 异常 文件描述符监听集合   传入传出参数			 NULL	
        	timeout     > 0 :设置监听超时时长。   NULL：阻塞监听   0：非阻塞监听，轮询
        	
        	返回值：  >0：所有监听集合中，满足对应事件的总数
        						0：没有满足监听条件的文件描述符
        						-1：errno
        */
        ```

    - **select多路IO转接**：

        - 原理：**借助内核，select监听，而客户端进行连接、数据通信事件**。

        - ```cpp
            fd_set rset;//创建一个文件描述符集合
            //将一个文件描述符从监听集合中移除
            void FD_CLR(int fd, fd_set *set);
            e.g: FD_CLR(4,&rset);
            
            //判断一个文件描述符是否在监听集合中
            int  FD_ISSET(int fd, fd_set *set);
            
            //将待监听的文件描述符添加到监听集合中
            void FD_SET(int fd, fd_set *set);
            
            //清空一个文件描述符集合
            void FD_ZERO(fd_set *set);
            ```

15. **select实现多路IO转接设计思路**：

    - ```cpp
        int maxFd;//最大listenfd + 1
        lfd = socket();//创建socket
        bind();//绑定地址结构
        listen();//设置监听上限
        
        fd_set rset, allset;//设置读 事件监听集合 与备份监听集合
        FD_ZERO(&allset);//清空rset集合
        FD_SET(lfd,&allset);//将lfd添加至allset集合
        
        while(1)
        {
          rset = allset；
          ret = select(lfd+1,&rset,NULL,NULL,NULL);//阻塞监听
          if(ret > 0)
          {
            if(FD_ISSET(lfd,&rset))
            {
              cfd = accept();
              
              maxFd = cfd;
              
              FD_SET(cfd,&allset);
            }
            
            for(i = lfd + 1; i <= maxFd; i++)
            {
              if(FD_ISSET(i,&rset))
              {
                read/write
                ....
              }
            }
            
            
          }
          
          close(lfd)
        }
        
        ```
        
        
        
    
16. **epoll相关函数**：

      1. ```cpp
          //1.创造一个监听红黑树
          int epoll_create(int size)
          /*
          	size:创建红黑树的监听节点数量。（仅供内核参考）
          	返回值：指向新创建的红黑树的根节点的 fd
          				失败： -1 errno
          */
            
          ```

      2. ```cpp
          //2.操作（control）监听红黑树
            int epoll_ctl(int epfd,int op,int fd,strcut epoll_event *event)
            /*
            	epfd：epoll_create函数的返回值
            	op：对该监听红黑树的操作
            			EPOLL_CTL_ADD 添加fd到 监听红黑树
          				EPOLL_CTL_MOD 修改fd在 监听红黑树上的监听事件。
          				EPOLL_CTL_DEL 将一个fd 从监听红黑树上摘下（取消监听）
          		fd：待监听的fd
          		event：本质 strut epoll_event  结构体  地址
          				成员 events：
          					EPOLLIN / EPOLLOUT / EPOLLERR
          
          				成员 data： 联合体（共用体）：
          						int fd;	  对应监听事件的 fd
          						void *ptr； 
          						uint32_t u32;
          						uint64_t u64;	
          						
          		返回值： 成功： 0；  失败：-1，errno	
            */
          ```

      3. ```cpp
          //3.阻塞监听
          int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout)
            
          /*
          	epfd：epoll_create函数的返回值
          	events：传出参数，【数组】， 满足监听条件的 那些 fd 结构体。
          	maxevents：数组 元素的总个数。 1024
          			struct epoll_event evnets[1024]
          	timeout：
          			-1: 阻塞
          			0： 不阻塞
          			>0: 超时时间 （毫秒）
          	返回值：
          			>0 ：满足监听的总个数，可以用作循环上限
          			0：没有fd满足监听事件
          			-1：失败，errno
          */
          ```

      4. **epoll实现多路IO转接思路：**

          - ```cpp
              //大致流程
              lfd = socket(); //监听连接事件lfd
              bind();
              listen();
              
              int epfd = epoll_create(1024); //epfd：监听红黑树的树根
              struct epoll_event tep, ep[1024]; //tep,用来设置单个fd的属性，ep是epoll_wait函数的传出的满足监听事件的数组
              
              tep.events = EPOLLIN;	//初始化  lfd的监听属性。读
              tep.data.fd = lfd
                
              epoll_ctl(epfd,EPOLL_CTL_ADD,lfd,&tep);//将 lfd 添加到监听红黑树上
              
              while(1)
              {
                ret = epoll_wait(epfd,ep,1024,-1);//实施监听
                for(i = 0; i < ret; i++)	// lfd 满足读事件，有新的客户端发起连接请求
                {
                  if(ep[i].data.fd == lfd)
                  {
                    cfd = Accept();
                    tep.events = EPOLLIN; //初始化cfd监听属性
                    tep.data.fd = cfd;
                    epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&tep)
                  }
                  else
                  {
                    nbytes = read(ep[i].data.fd,buf,sizeof(buf));
                    if(nbytes == 0) //对端已关闭连接
                    {
                      close(ep[i].data.fd);
              
              				epoll_ctl(epfd， EPOLL_CTL_DEL, ep[i].data.fd , NULL);	// 将关闭的cfd，从监听树上摘下。
                    }
                    else if(nbytes > 0)
                    {
                      
                      Write(ep[i].data.fd,buf,nbytes)
                    }
                    
                  }
                  
                }
                
                
              }
              
              ```

      5. 阻塞和非阻塞关注的是**程序在等待调用结果（消息，返回值）时的状态.**

          - 阻塞：阻塞调用是指调用结果返回之前，该当前线程会被**”挂起“**。调用线程只有在获得结果之后才返回。
          - 非阻塞：非阻塞调用指在不能立刻得到结果之前，该调用不会阻塞当前线程。

      6. epoll事件模型：

          - ET(Edge Triggered)模式：

              - **边沿触发**：缓冲区未读尽的数据**不会**导致epoll_wait()返回。新的事件满足，才会触发。（等数据到来时才会触发）

              - ```cpp
                  struct epoll_event ep;
                  ep.events = EPOLLIN | EPOLLET;
                  ```

              - ET模式适用于高效模式，只支持**非阻塞模式**。-- 忙轮询

                  - ```cpp
                      struct epoll_event ep;
                      ep.events = EPOLLIN | EPOLLET;
                      
                      epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&ep);
                      int flg = fcntl(cfd,F_GETFL);
                      fls |= O_NONBLOCK;
                      fcntl(cfd,F_SETFL,fls);
                      ```

          - LT(Level Triggered )模式：

              - **水平触发**（默认模式）：缓冲区未读尽的数据**会**导致epoll_wait()返回。（只要有数据就会触发）

          - 结论：

              1. 优点：高效，突破1024文件描述符。
              2. 缺点：不能跨平台，只适用于Linux。

          - **epoll反应堆模型**：<u>ET模式 + 非阻塞 、轮询+ void *ptr</u>

              1. >  之前：socket、bind、listen、--> epoll_create 创建监听红黑树 --> 返回epfd --> epoll_ctl 操作监听红黑树，向树上添加一个监听fd --> while(1 )  --> epoll_wait监听 -->对应监听的fd有事件产生 --> 返回 满足监听的事件数组  --> 判定返回的数组元素 --> if (lfd满足) -->Accept --> else(cfd满足) --> read() --> write回去

                  > 反应堆模型：
                  >
                  > 现在：socket、bind、listen、--> epoll_create 创建监听红黑树 --> 返回epfd --> epoll_ctl 操作监听红黑树，向树上添加一个监听fd --> while(1 )  --> epoll_wait监听 -->对应监听的fd有事件产生 --> 返回 满足监听的事件数组  --> 判定返回的数组元素 --> if (lfd满足) -->Accept --> else(cfd满足) --> read() --> cfd从监听红黑树上拿下 --> EPOLLOUT（写） --> epoll_ctl  EPOLL_CTL_ADD 重新放到红黑上监听写事件 --> 等待epoll_ctl返回 说明 cfd 可写 --> write回去 -->cfd从监听红黑树上摘下 --> EPOLLIN --> epoll_ctl() --> EPOLL_CTL_ADD 重新放到红黑上监听读事件 --> epoll_wait 监听

              2. **反应堆理解**：反应堆模式就是在处理数据之后，监听写事件，满足可以写回客户端的条件了，才会做写回操作；写回之后，又监听读事件，如此循环。


     

#### 三、线程池

##### 3.1 线程池相关结构体

- ```cpp
    struct threadpool_t {
    
        pthread_mutex_t lock;               /* 用于锁住本结构体 */    
        pthread_mutex_t thread_counter;     /* 记录忙状态线程个数的锁 -- busy_thr_num */
    
        pthread_cond_t queue_not_full;      /* 当任务队列满时，添加任务的线程阻塞，等待此条件变量 */
        pthread_cond_t queue_not_empty;     /* 任务队列里不为空时，通知等待任务的线程 */
    
        pthread_t *threads;                 /* 存放线程池中每个线程的tid。数组 */
        pthread_t adjust_tid;               /* 存管理线程tid */
        threadpool_task_t *task_queue;      /* 任务队列(数组首地址) */
    
        int min_thr_num;                    /* 线程池最小线程数 */
        int max_thr_num;                    /* 线程池最大线程数 */
        int live_thr_num;                   /* 当前存活线程个数 */
        int busy_thr_num;                   /* 忙状态线程个数 */
        int wait_exit_thr_num;              /* 要销毁的线程个数 */
    
        int queue_front;                    /* task_queue队头下标 */
        int queue_rear;                     /* task_queue队尾下标 */
        int queue_size;                     /* task_queue队中实际任务数 */
        int queue_max_size;                 /* task_queue队列可容纳任务数上限 */
    
        int shutdown;                       /* 标志位，线程池使用状态，true或false */
    };
    
    
    typedef struct
    {
      void *(*function)(void*);							/* 函数指针，回调函数 */
      void *arg;														/* 上面函数的参数 */
    }	
    ```

##### 3.2 线程池模型分析

1. main():

    ```cpp
    1.创建线程池
    
    2.向线程池中添加任务
    
    3.销毁线程池
    ```

2. threadpool_create():

    ```cpp
    1.创建线程池结构体 指针
    2.初始化线程池结构体 【N个成员变量】
    3.创建N个任务线程
    4.创建一个管理者线程
    5.失败时，销毁开辟的所有空间（释放）
    ```

3. threadpool_thread():

    ```cpp
    //子线程回调函数
    1.进入子线程回调函数
    2.接收参数 void *arg --> pool结构体
    3.加锁 --> lock（指整个结构体的锁）
    4.判断条件变量 --> wait
    ```

4. adjust_thread():

    ```cpp
    //管理线程
    1.循环10s执行一次
    2.进入管理者线程回调函数
    3.接收采纳数 void *arg --> pool结构体
    4.加锁 --> lock （指整个结构体的锁）
    5.获取管理线程池要要用的变量。task_num, live_num, busy_num
    6.根据既定算法，使用上述3个变量，判断是是否应该创建、销毁线程池中指定步长的线程
    ```

5. threadpool_add():

    ```cpp
    //向线程池中添加一个任务
    总功能：
      模拟生产任务
      设置回调函数，处理任务
    内部实现：
      1.加锁
      2.初始化任务队列结构体成员。回调函数function，arg
      3.利用环形队列机制，实现添加任务。
      4.唤醒阻塞在 条件变量上的线程
      5.解锁
    ```

    

6. threadpool_destory():

    ```cpp
    //创建、销毁线程
    1.管理者线程根据task_num, live_num, busy_num
    2.根据既定算法，使用上述3个变量，判断是是否应该创建、销毁线程池中指定步长的线程
      如果满足创建条件：
      	pthread_create();   回调 任务线程函数。		live_num++
      如果满足销毁条件：
      	wait_exit_thr_num = 10;  
    		signal 给阻塞在条件变量上的线程发送假条件满足信号    
    ```

    

#### 四、TCP/UDP通信

##### 4.1 TCP/UDP通信各自的优缺点：

1. TCP：面向连接的、可靠数据包传输。对于不稳定的网络层，采取完全弥补的通信方式。丢包重传。
    - 优点：稳定。数据流量稳定、速度稳定、顺序
    - 缺点：传输速度慢，效率低，资源开销大
    - 使用场景：数据的完整型要求较高、不追求效率。如大数据传输、文件传输
2. UDP：无连接的不可靠的数据包传递。对于不稳定的网络层，采取**完全不弥补**的通信方式。默认还原网络状况
    - 优点：传输速度快，效率高，资源开销小
    - 缺点：不稳定。
    - 使用场景：时效性要求高，稳定性其次。如视频电话、游戏

##### 4.2 UDP通信：

1. **流程：**

```cpp
//recv()/send()函数只能用于TCP通信（专门的函数）。read/write（文件读写）也可用于socket
//故需要函数替代 sendto/recvfrom
accept(); connect(); //被丢弃

server：
  sockfd = socket(AF_INET,SOCK_DGRAM,0);//SOCK_DGRAM 报式协议
	bind();
	listen();//可有可无
	while(1)
  {
    
    read()  -- 被替换成 recvfrom() --> 涵盖accept传出地址结构
    write() -- 被替换成 sendto()
  }
	close();

client:
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		sendto（‘服务器的地址结构’， 地址结构大小）
		recvfrom（）
		写到屏幕
		close();
	
```

2. 函数：

    ```cpp
    ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
    /*
    			sockfd： 套接字
    			buf：缓冲区地址
    			len：缓冲区大小
    			flags： 0
    			src_addr：（struct sockaddr *）&addr 传出。 对端地址结构
    			addrlen：传入传出。
    			
    			返回值： 成功接收数据字节数。 失败：-1 errn。 0： 对端关闭。
    */
    
    ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
    /*
    			ssockfd： 套接字
    			buf：存储数据的缓冲区
    			len：数据长度
    			flags： 0
    			src_addr：（struct sockaddr *）&addr 传入。 目标地址结构
    			addrlen：地址结构长度。
    
    			返回值：成功写出数据字节数。 失败 -1， errno	
    */
    
    ```

##### 4.3 本地套接字

1. 对比网络编程：

    ```cpp
    //1.
    int socket(int domain, int type, int protocol)
      /*
      	domain: AF_INET --> AF_UNIX/AF_LOCAL
      	type: SOCK_STREAM/SOCK_DGRAM  都可以。
      	
      */
    //2.
      size_t offsetof(type, member);
    
      sockaddr_in --> sockaddr_un
      struct sockaddr_in serAddr;        --> struct sockaddr_un serAddr;
    	serAddr.sin_family = AF_INET;      -->  serAddr.sun_family = AF_UNIX;
    	serAddr.sin_port = htons(8888);    --> strcpy(serAddr.sun_path,"ser.socket");
    	serAddr.sin_addr.s_addr = htonl(INADDR_ANY); --> len = offsetof(struct sockaddr_un, sun_path) + strlen("ser.socket");//计算偏移量
    
    	bind(fd,(struct sockaddr *)&serAddr,sizeof(serAddr));  --> bind(fd,(struct sockaddr *)&serAddr,len);
    
    //3.
    	bind函数调用成功，会创建一个socket文件。因此为保证bind成功，可以使用unlink("ser.socket")删除之前已有的socket文件。
    
    //4.
        客户端不能依赖“隐式绑定”。并且在通信建立过程中，创建且初始化两个地址结构：
        	1.client_addr --> bind()
        	2.server_addr --> connect();
      
      
    
    
    ```



#### 五、 Libevent库

##### 5.1 简介

- Libevent 是一个轻量级的**开源高性能网络库，源代码精简，专注于网络通信**，跨平台（Linux，Windows，MacOs）

##### 5.2 Libevent封装的框架思想

1. 创建event_base  **【底座**】

    ```cpp
    struct event_base *event_base_new(void);
    struct event_base *base = event_base_new();
    
    ```

2. 创建事件event

    - 常规事件 event --> event_new();
    - bufferevent -->  bufferevent_socket_new();

3. 将事件添加到base上

    ```cpp
    int event_add(struct event *ev, const struct timeval *tv);
    ```

4. 循环监听事件满足

    ```cpp
    int event_base_dispatch(struct event_base *base);
    event_base_dispatch(base);
    ```

5. 释放event_base

    ```cpp
    event_base_free(base);
    ```

##### 5.3 特性

- 基于**事件**异步通信模型。  -- 回调

##### 5.4 创建事件对象

```cpp
//创建事件event
struct event *ev;
struct event * event_new(struct event_base *base,evutil_socket_t fd，short what，event_callback_fn cb, void *arg)
  
  /*
  	base：event_base_new()的返回值
  	fd：绑定到event上的文件描述符
  	what：对应的事件(r,w,e)
  		EV_READ		一次 读事件
			EV_WRTIE	一次 写事件
			EV_PERSIST	持续触发。 结合 event_base_dispatch 函数使用，生效。(持续读或持续写)
		cb：一旦事件满足监听条件，回调的函数
			typedef void (*event_callback_fn)(evutil_socket_t fd,  short what,  void *arg)	
		arg：回调的函数的参数
  	返回值：成功创建的 event
  */
 
```

##### 5.5 事件event的操作

```cpp
//添加事件到event_base
int event_add(struct event *ev, const struct timeval *tv);
		//ev: event_new() 的返回值。
		//tv：NULL --> 不会超时
      
//销毁事件
 int event_free(struct event *ev)
    // event_new()的返回值
```

##### 5.6 未决和非未决

- 未决：有资格被处理，还未被处理
- 非未决：没有资格被处理。
- event_new() --> event （非未决） --> event_add （ 未决）--> dispatch()  && 监听事件被触发 --> 激活态 --> 执行回调函数 --> 处理态 --> 非未决 --> event_add && EV_PERSIST （未决） -->  event_del （非未决）

##### 5.7 单文件通信流程分析

1. getline()获取http协议的第一行。
2. 从首行中拆**分GET、文件名、协议版本。获取用户请求的文件名**。
3. 判断文件是否存在。stat()函数  --》 获取文件信息
4. 判断文件是目录还是文件
5. 是文件：open --》 read --》 写回给浏览器
6. 先写http应答协议头： 
    - **http/1.1 200 ok**
    - **Content-Type：text/plain; charset=iso-8859-1**



































































