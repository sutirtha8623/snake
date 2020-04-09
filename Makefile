SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CXX = g++

COMPILER-FLAGS = -c

LINKER-FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = snake

default: $(TARGET)

%.o: %.cpp
	$(CXX) $(COMPILER-FLAGS) $(SRCS)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LINKER-FLAGS)

clean :
	rm -f $(OBJS) $(TARGET) *~