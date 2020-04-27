SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

CXX = g++

COMPILER-FLAGS = -c

LINKER-FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

TARGET = snake

default: $(TARGET)

%.o: %.cpp %.hpp
	$(CXX) $(COMPILER-FLAGS) $(SRCS)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LINKER-FLAGS)

clean :
	rm -f $(OBJS) $(TARGET) *~
