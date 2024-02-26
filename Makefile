CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack_test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
OBJS = llrec-test.o llrec.o
OBJSS = stack_test.o stack.o

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp
  $(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

stack_test: $(OBJSS)
  $(CXX) $(CXXFLAGS) -o $@ $(OBJSS)

stack_test.o: $(OBJSS)
  $(CXX) $(CXXFLAGS) -o $@ -c stack_test.cpp

stack.o: stack.cpp
  $(CXX) $(CXXFLAGS) -o $@ -c stack.cpp






clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 