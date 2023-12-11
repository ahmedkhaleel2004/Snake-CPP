CC=g++
CFLAGS=-I. -g
OBJ = GameMechs.o objPos.o objPosArrayList.o Food.o MacUILib.o Player.o Project.o 
DEPS = *.h
#POSTLINKER = -lncurses   ## uncomment this if on Linux
EXEC = Project

%.o: %.cpp $(DEPENDS)
	$(CC) -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) ${POSTLINKER}

clean :
	rm -r ${OBJ} ${EXEC} ${EXEC}.exe

