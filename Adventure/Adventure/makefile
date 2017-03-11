CXX = g++
CXXFLAGS = -std=c++0x -lboost_system -lboost_filesystem -ggdb

PROGS = test

all: ${PROGS}

test: main.cpp Air.o Bag.o Bridge.o Cave.o Character.o DragonLair.o Earth.o Entrance.o Exit.o Fire.o Game.o GreatCavern.o GuardianPost.o Item.o Library.o MazeRoom.o Mine.o Outside.o parser.o Room.o Treasure.o TrollBridge.o Water.o OutsideEnd.o PostMaze.o Maze.o Troll.o
	${CXX} ${CXXFLAGS} main.cpp Air.o Bag.o Bridge.o Cave.o Character.o DragonLair.o Earth.o Entrance.o Exit.o Fire.o Game.o GreatCavern.o GuardianPost.o Item.o Library.o MazeRoom.o Mine.o Outside.o parser.o Room.o Treasure.o TrollBridge.o Water.o OutsideEnd.o PostMaze.o Maze.o Troll.o -o caveAdventure
	
OutsideEnd.o: OutsideEnd.cpp OutsideEnd.h
	${CXX} ${CXXFLAGS} -c OutsideEnd.cpp

Air.o: Air.cpp Air.h
	${CXX} ${CXXFLAGS} -c Air.cpp

Bag.o: Bag.cpp Bag.h
	${CXX} ${CXXFLAGS} -c Bag.cpp
	
Bridge.o: Bridge.cpp Bridge.h
	${CXX} ${CXXFLAGS} -c Bridge.cpp

Cave.o: Cave.cpp Cave.h
	${CXX} ${CXXFLAGS} -c Cave.cpp

Character.o: Character.cpp Character.h
	${CXX} ${CXXFLAGS} -c Character.cpp

DragonLair.o: DragonLair.cpp DragonLair.h
	${CXX} ${CXXFLAGS} -c DragonLair.cpp

Earth.o: Earth.cpp Earth.h
	${CXX} ${CXXFLAGS} -c Earth.cpp

Entrance.o: Entrance.cpp Entrance.h
	${CXX} ${CXXFLAGS} -c Entrance.cpp

Exit.o: Exit.cpp Exit.h
	${CXX} ${CXXFLAGS} -c Exit.cpp

Fire.o: Fire.cpp Fire.h
	${CXX} ${CXXFLAGS} -c Fire.cpp

Game.o: Game.cpp Game.h
	${CXX} ${CXXFLAGS} -c Game.cpp

GreatCavern.o: GreatCavern.cpp GreatCavern.h
	${CXX} ${CXXFLAGS} -c GreatCavern.cpp

GuardianPost.o: GuardianPost.cpp GuardianPost.h
	${CXX} ${CXXFLAGS} -c GuardianPost.cpp

Item.o: Item.cpp Item.h
	${CXX} ${CXXFLAGS} -c Item.cpp

Library.o: Library.cpp Library.h
	${CXX} ${CXXFLAGS} -c Library.cpp

MazeRoom.o: MazeRoom.cpp MazeRoom.h
	${CXX} ${CXXFLAGS} -c MazeRoom.cpp

Mine.o: Mine.cpp Mine.h
	${CXX} ${CXXFLAGS} -c Mine.cpp

Outside.o: Outside.cpp Outside.h
	${CXX} ${CXXFLAGS} -c Outside.cpp

parser.o: parser.cpp parser.h
	${CXX} ${CXXFLAGS} -c parser.cpp

Room.o: Room.cpp Room.h
	${CXX} ${CXXFLAGS} -c Room.cpp

Treasure.o: Treasure.cpp Treasure.h
	${CXX} ${CXXFLAGS} -c Treasure.cpp

TrollBridge.o: TrollBridge.cpp TrollBridge.h
	${CXX} ${CXXFLAGS} -c TrollBridge.cpp

Water.o: Water.cpp Water.h
	${CXX} ${CXXFLAGS} -c Water.cpp

PostMaze.o: PostMaze.cpp PostMaze.h
	${CXX} ${CXXFLAGS} -c PostMaze.cpp

Maze.o: Maze.cpp Maze.h
	${CXX} ${CXXFLAGS} -c Maze.cpp
	
Troll.o: Troll.cpp Troll.h
	${CXX} ${CXXFLAGS} -c Troll.cpp

clean:
	rm -f *.o *~
