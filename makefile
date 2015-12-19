#------------------------------------------------------------------------------
# Requirement #20: Demonstrate a makefile.
#------------------------------------------------------------------------------
CXX = g++
CXXFLAGS = -std=c++0x
SRCS = mazemaker.cpp Maze.cpp Menus.cpp UtilFuncs.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = mazemaker

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm $(OBJS) $(EXEC)
