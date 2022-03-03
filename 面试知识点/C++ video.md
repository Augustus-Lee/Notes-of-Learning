1. **new/ delete**:

```cpp
//创建一个数
int *p = new int;
*p = 10；
if( p != NULL)
{
  delete p;
  p = NULL;
}

//创建一个数组
int *arr_p = new int[10];//开辟长度为10的数组
if(arr_p != NULL)
{
  
  delete[] arr_p;//释放数组的内存空间
  arr_p = NULL;
}

```

2. 将一个对象当成普通函数来调用，称这种对象为**仿函数**。

3. **this指针解决函数形参和类属性相同；C++编译器对普通成员函数的内部处理（隐藏this指针）。**

4. **继承：**子类对象所占用的内存空间比父类对象要大，能够填充满父类对象所需要的空间。

   - 故子类对象可以当做父类对象使用。
   - 子类对象可以直接赋值给父类对象，子类对象可以直接初始化父类对象。
   - 父类指针可以直接指向指向子类对象。

5. 多继承：虚继承(virtual)是为了防止多继承时的变量不明确。**多继承**：class C :public B1, public B2。

6. 多态发生的三个必要条件：

   - 1.要有继承。

   - 2.要有虚函数重写。

   - 3.父类的指针或引用 指向子类对象。

7. **联编**是指一个程序模块、代码之间互相关联的一个过程。

   - C++和C都是静态编译型语言。

   - 静态联编：是程序的匹配、连接在编译阶段实现，也称为早起匹配。**重载函数使用静态联编**
   - 动态联编：是指程序联编推迟到运行时进行，又称为晚期联编。**多态是动态联编**。

8. 重载：必须是同一作用域下的两个函数。

   - 重定义：发生在两个类中，一个是基类，一个是派生类。
     - 1.普通函数重定义：如果父类的普通成员函数，被子类重写，就是重定义。
     - 2.**虚函数重写**：如果父类的虚函数，被子类重写，就是虚函数重写，**这个函数会发生多态**。

9. 多态的原理：虚函数表和vptr指针。

   - 当类中出现虚函数时，编译器会给类中生成一个虚函数表；
   - 虚函数表是一个存储***类成员函数指针***的数据结构；
   - 虚函数表是由编译器自动维护和生成的；
   - **virtual成员函数会被编译器放入虚函数表中**；
   - 存在虚函数时，每个对象都有一个**指向虚函数的表的指针（vptr指针）**。
   - 虚函数时动态联编的，而普通成员函数是静态联编的，故虚函数效率比较低。

10. VPTR指针是分布初始化的。

11. 纯虚函数与抽象类：

    - virtual 返回类型 函数名（） = **0**； 没有函数的具体实现。
    - **具有纯虚函数的类为抽象类，抽象类不能够实例化。**
    - 继承抽象类的子类需要重写纯虚函数，否则还是抽象类。

12. 函数模板：

    - 声明是函数模板：template<class T>等价于template<typename T>。**T是类型名。**
    - 普通函数与函数模板的区别：普通函数可以进行自动类型转换，函数模板必须严格匹配。
    - 函数模板也可以被重载。
    - 编译器优先考虑普通函数。若想强制调用函数模板，则加尖括号<>。**mySwap<>(a,b)。**
    - 函数模板通过具体类型产生不同的函数。 ***函数模板--->模板函数（具体函数）--->被调用。***
    - 编译器会对函数模板进行**两次编译**，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。

13. 类模板：

    - 类模板必须显示指定类型。

    - 类模板派生普通类时需要指定类型。要知道对象的类型才能分配内存。如下：

    - ```cpp
      class SubPerson : public Person<int>{};
      ```

    - 类模板派生类模板时：

    - ```cpp
      template<class T>
      class SubPerson : public Person<T>{};
      ```

    - 类模板的声明和实现建议写在同一文件下，后缀为.hpp。（即头文件和实现为一个文件）
    
14. 类型转换：

    1. static_cast：**用于转换基础类型和具有继承关系的的对象指针。**
    2. dynamic_cast  具有继承关系的的对象指针。只能由子类型转换成基类型。
    3. const_cast  指针，引用 对象指针转换。
    4. reinterpret_cast 强制类型转换

15. 异常：

    1. 异常接口声明：

    ```cpp
    void func() throw(int,char,float) //只能抛出这三种类型异常，其他会报错
    {}
    
    void func1(){}//能抛出任何异常
    ```

    2. throw的异常是有类型的，可以使数字，字符串，类对象。catch需要严格匹配异常类型。
    3. 普通类型元素，异常对象catch就析构。
    4. 引用类型，不调用拷贝构造，异常对象catch处理完就析构。
    5. 指针类型，会先析构再捕获异常，故需要重新new一个，***throw new MyException()***，再delete.

16. 输入输出流：

    1. cout/cin：全局流对象。 cerr：标准错误，输出数据到显示屏，无缓冲区。clog：标准日志，输出数据到显示屏，有缓冲区。

    2. cin.ignore():忽略当前字符。从缓冲区中把当前字符拿走了。

    3. cin.get(ch)获取一个字符，cin.getline()读取一行字符。

       - cin.peek()查看缓冲区中第一个字符
       - cin.putback()放回缓冲区，与cin.get()联用。

    4. cout.flush():刷新缓冲区。

       - ```cpp
         cout.put('a'); //向缓冲区中写入一个字符。cout.write("hello",strlen("hello"));//写入一个字符串
         ```

       - cout.width(10)   设置输出宽度为10。通过成员方法调用。

    5. 文件读写：

       1. ```cpp
           char *inFilePath = "/Users/swqt/Desktop/source.txt";
           char *outFilePath = "/Users/swqt/Desktop/target.txt";
           ifstream iFile(inFilePath,ios::in);
             	//ios::app可以保证target文件内容不会被删除
           ofstream oFile(outFilePath,ios::out | ios::app);
          //    ifstream iFile;等价于上一个
          //    iFile.open(inFilePath,ios::in);
          ```

17. **STL（standard template library）理论基础**

    1. 序列式容器：容器的元素位置是由进入的时机和地点来决定的。
    2. 关联式容器：容器已经有规则，进入容器的元素的位置不会由时机和地点来决定。
    3. 迭代器：可以理解为指针，对指针的基本操作都可以都迭代器使用。**实际上，迭代器是一个类，这个类封装一个指针。**
    4. 算法：**通过有限步骤，来解决问题。**

18. vector容器：

    1. vector实现动态增长：当插入新元素的时候，如果空间不足，那么vector会重新申请更大的一块内存空间，将原空间数据拷贝到新空间，释放旧空间的数据，再把新元素插入到新空间。

    2. vector<int> v1, 读取元素时，**v1.at(i)当i如果越界时，则会抛出out_of_range的异常，而v1[i]不会。**

    3. vector是动态数组，连续存储空间，支持随机访问。

    4. 头插法：v1.insert(v1.begin(),30)；尾插法：v1.insert(v1.end(),20)。

    5. **reserve预留空间，没有创建元素对象；resize是改变容器大小并且创建对象。**

    6. vector是单口容器，在尾部删除和插入效率高，指定删除或插入效率低，因为要把其他元素移动。

       ```cpp
       		//构造函数		
       		vector<int> v1;
           int arr[] = {10,20,30,40};
           //begin   and  end(尾元素的下一个位置)
           vector<int> v2(arr,arr + sizeof(arr) / sizeof(int));
           vector<int> v3(v2.begin(),v2.end());
           vector<int> v4(v3);
       ```

       

19. deque容器（双端队列）：

    1. 双端都可以插入和删除，故效率比较高。
    2. 类似vector。

20. 栈（stack）

    1. 不提供迭代器，不支持随机访问。
    2. 先进后出。
    3. s.top()返回栈顶元素，s.pop()出栈。

21. Queue（队列）：

    1. **队头删除，队尾插入，先入先出的原则。**

    2. 不提供迭代器，故不能遍历，不支持随机访问。

       ```cpp
       //声明一个int型指向TestObj的成员变量的指针
           int TestObj::*pId = &TestObj::mID;
       
           TestObj *tp = new TestObj(10);
           TestObj *tp1 = new TestObj(100);
           TestObj *tp2 = new TestObj(101);
           TestObj *tp3 = new TestObj(102);
       
           //-------queue存储对象指针-----
           queue<TestObj*> q1;
       
           q1.push(tp);
           q1.push(tp1);
           q1.push(tp2);
           q1.push(tp3);
       
           while(!q1.empty())
           {
               cout << q1.front()->*pId << " ";
               q1.pop();
           }
       ```

22. list容器（双向链表）：

    1. 内存空间不连续，不支持随机访问，只能支持迭代器访问。
    2. remove(i);//删除所有的匹配值i
    3. list<int> L1, L1.sort(),  sort是list的成员函数。**因为sort算法仅支持可以随机访问的容器，而list不支持随机访问，故自己提供成员函数的sort方法。**

    

24. pair容器（对组）：

    ```cpp
    	//构造方法
    		pair<string,int> pair1("aa",20);
    
        cout << pair1.first << " " << pair1.second << endl;
    
        pair<string,int> pair2 = make_pair("bb",20);
    
        cout << pair2.first << " " << pair2.second << endl;
    
        pair<string,int> pair3 = pair2;
        cout << pair3.first << " " << pair3.second << endl;
    ```

25. 仿函数（函数对象）：

    1. 仿函数不是函数，它是一个类。
    2. 仿函数通过重载()运算符，使得可以像函数一样调用。
    3. 某个类中有重载的operator()函数，且只获取**一个参数**，则称之为**一元仿函数**。有两个参数，则为二元仿函数，以此类推。
    4. 函数对象也可以有参数和返回值。

26. map/multimap:

    1. map<key,value>，key是唯一的，不能重复。

    2. ```cpp
       //构造方法
       map<int,int> mymap; 
       mymap.insert(pair<int,int>(10,10));
       mymap.insert(make_pair(20,30));
       mymap[30] = 30;
       ```

27. 谓词：是指**普通函数或重载的operator()**返回值是***bool类型***的函数对象（仿函数）。如果operator接受一个参数就是一元谓词，以此类推。

28. 适配器：

    1. 绑定适配器：将一个二元函数对象转变成一元函数对象。

    2. ```cpp
       1.容器中存储的是对象，调用成员函数遍历， 则用mem_fun_ref(&类名::函数名)
       2.容器中存储的是对象指针，调用成员函数遍历， 则用mem_fun(&类名::函数名)
         
       ```



























