makefileCXXFLAGS = -g -Wall -std=c++11 -Werror=return-type -Werror=uninitialized
CXX = g++

OBJECTS = main.o hashtable.o node.o createEncrypted.o createRaw.o test.o

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o main $(OBJECTS)

main.o: main.cpp createRaw.hpp createEncrypted.hpp
hashtable.o: hashtable.cpp hashtable.hpp node.hpp
node.o: node.cpp node.hpp
createRaw.o: createRaw.cpp createRaw.hpp
createEncrypted.o: createEncrypted.cpp createEncrypted.hpp
test.o: test.cpp test.hpp createEncrypted.o hashtable.o

.PHONY : clean
clean: 
	rm main $(OBJECTS) 
