CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = Cell.o Character.o CharacterCreator.o Dragon.o Drow.o Dwarf.o Elf.o Enemy.o Floor.o Goblin.o Gold.o Halfling.o Human.o Item.o Merchant.o main.o Orcs.o Player.o Potion.o Shade.o Stair.o Troll.o Vampire.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = CC3K-vallian

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies