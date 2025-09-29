CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

OBJS = main.o user/user.o logger/logger.o functions/functions.o

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

main.o: main.cpp user/user.h functions/functions.h
user/user.o: user/user.cpp user/user.h
logger/logger.o: logger/logger.cpp logger/logger.h
functions/functions.o: functions/functions.cpp functions/functions.h logger/logger.h

clean:
	rm -f *.o user/*.o logger/*.o functions/*.o main log_*.txt
