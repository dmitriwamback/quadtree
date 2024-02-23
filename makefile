INCLUDES := -I./qd

build:
	g++ --std=c++17 main.cpp $(INCLUDES) && ./a.out