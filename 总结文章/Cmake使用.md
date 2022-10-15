### Makefile文件
一般在文件夹中包含 makefile 或者 Makefile 执行make 命令时候，优先调用makefile
所以 程序员书写代码命名为Makefile ， makefile用于用户自己编写

 project 下 main.c tool1.c tool1.h tool2.c tool2.h
 makefile 文件编写：
 格式为:
```
生成文件：依赖文件
      命令行
```
一般命令：

 ```makefile
m_exe : main.o tool1.o tool2.o
        gcc main.o tool1.o tool2.o -o m_exe
main.o: main.c
        gcc main.c -c -Wall -g -o main.o
tool1.o: tool1.c
        gcc tool1.c -c -Wall -g -o tool1.o
tool2.o: tool2.c
        gcc tool2.c -c -Wall -g -o tool2.o

clear:

        rm *.o m_exe -rf

 ```

改进版1：
```makefile
OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+= -c -Wall -g

m_exe : $(OBJS)
        $(CC)  $(OBJS) -o m_exe
main.o: main.c
        $(CC) main.c $(CFLAGS) -o main.o
tool1.o: tool1.c
        $(CC) tool1.c $(CFLAGS) -o tool1.o
tool2.o: tool2.c
        $(CC) tool2.c $(CFLAGS) -o tool2.o

clean:

        rm *.o m_exe -rf
#注释
# $(变量名), 取变量
```

改进版2:
```makefile
OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+= -c -Wall -g

m_exe : $(OBJS)
        $(CC) $^ -o $@
main.o: main.c
        $(CC) $^ $(CFLAGS) -o $@
tool1.o: tool1.c
        $(CC) $^  $(CFLAGS) -o $@
tool2.o: tool2.c
        $(CC) $^  $(CFLAGS) -o $@

clean:

        rm *.o m_exe -rf
#注释
# $^ 为上一个语句中依赖文件
# $@ 为上一个语句中目标文件
```


改进版3：
```makefile
OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+= -c -Wall -g

m_exe : $(OBJS)
        $(CC) $^ -o $@
%.o: %.c
        $(CC) $^ $(CFLAGS) -o $@

clean:
        
        rm *.o m_exe -rf
#注释
# % 为通配符
```



### CMake使用
