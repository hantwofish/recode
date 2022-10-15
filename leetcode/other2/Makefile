OBJS=main.o tool1.o tool2.o
CC=g++
CFLAGS+= -c -Wall -g

m_exe : $(OBJS)
	$(CC) $^ -o $@
%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

clean:

	rm *.o m_exe -rf
