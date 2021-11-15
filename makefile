BTreeExec: main.o
	g++ main.o -o BTreeExec

main.o: main.cpp LinkedBTreeNode.h LinkedBTree.h LinkedBSearchTree.h
	g++ -c -std=c++11 main.cpp

clean:
	rm *.o BTreeExec