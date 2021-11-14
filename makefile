BTreeExec: main.o
	g++ main.o -o BTreeExec

main.o: main.cpp LinkedBTreeNode.h LinkedBTree.h LinkedBSearchTree.h
	g++ -c -std=c++11 main.cpp -o main.o

clean:
	rm *.o BTreeExec