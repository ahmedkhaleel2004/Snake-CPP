CC=g++
CFLAGS=-I. -lm -g
DEPS = *.h
OBJ = objPos.o objPosArrayList.o Test.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ALTester: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#testCompile: Test.cpp Matrix.cpp
#	g++ -o Test.cpp Matrix.cpp
test:	testALTester
testLab4:
# next line must start with a real TAB (ASCII 9)
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o ALTester
