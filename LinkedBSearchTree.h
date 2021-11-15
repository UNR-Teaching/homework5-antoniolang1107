#ifndef LINKED_BSTREE
#define LINKED_BSTREE
#include "LinkedBTree.h"

template <class ItemType>
class LinkedBSearchTree : public LinkedBTree<ItemType> {
private:
    LinkedBTreeNode<ItemType>* = rootPtr;

public:
    bool add(const ItemType& newData);
    ~LinkedBSearchTree() { }

protected:
    LinkedBTreeNode<ItemType>* placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr);
    LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) override;
    LinkedBTreeNode<ItemType>* removeNode(LinkedBTreeNode<ItemType* nodePtr);
    LinkedBTreeNode<ItemType>* removeLeftmostNode(LinkedBTreeNode<ItemType>* inorderSuccessor);
    LinkedBTreeNode<ItemType>* removeRightmostNode(LinkedBTreeNode<ItemType>* postorderSuccessor);
    LinkedBTreeNode<ItemType>* findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& targert, bool& isSuccessful) const;
};

#include "LinkedBSearchTree.h"
#endif