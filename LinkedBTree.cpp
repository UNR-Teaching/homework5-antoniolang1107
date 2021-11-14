template <class ItemType>
LinkedBTree<ItemType>::LinkedBTree() {

}

template <class ItemType>
bool LinkedBTree<ItemType>::isEmpty() const {

}

template <class ItemType>
int LinkedBTree<ItemType>::getHeigh() const {
    return getHeightHelper(rootPtr);
}

template <class ItemType>
int LinkedBTree<ItemType>::getNumberOfNode() const {

}

template <class ItemType>
ItemType LinkedBTree<ItemType>::getRootData() const {

}
template<class ItemType>
bool LinkedBTree<ItemType>::add(const ItemType& newData) {
    LinkedBTreeNode<ItemType>* newNodePtr(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}
bool LinkedBTree<ItemType>::remove(const ItemType& data) {

}
void LinkedBTree<ItemType>::clear() {

}

template <class ItemType>
ItemType LinkedBTree<ItemType>::getEntry(const ItemType& anEntry) const {

}

template <class ItemType>
bool LinkedBTree<ItemType>::contains(const ItemType& anEntry) const {

}

template <class ItemType>
void LinkedBTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {

}

template <class ItemType>
void LinkedBTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {

}

template <class ItemType>
void LinkedBTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {

}

~LinkedBTree::LinkedBTree() {

}

template<class ItemType>
int LinkedBTree<ItemType>::getHeightHelper(LinkedBTreeNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    }
    else {
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

int getNumberOfNodesHelper(LinkedBTreeNode<ItemType>* subTreePtr) const;
LinkedBTreeNode<ItemType>* balancedAdd(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr) {
    if (subTreePtr == nullptr)
        return newNodePtr;
    else {
        LinkedBTreeNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
        LinkedBTreeNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
            rightPtr = balancedAdd(rightPtr, newNodePtr);
        }
        else {
            leftPtr = balancedAdd(leftPtr, newNodePtr);

            subTreePtr->setLeftChild(leftPtr);
        }
        return subTreePtr;
    }
}
LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
LinkedBTreeNode<ItemType>* moveValuesUpTree(LinkedBTreeNode<ItemType>* subTreePtr);
LinkedBTreeNode<ItemType>* findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& targert, bool& isSuccessful) const;
LinkedBTreeNode<ItemType>* copyTree (const LinkedBTreeNode<ItemType>* oldTreeRootPtr) const;
void destryTree(LinkedBTreeNode<ItemType>* subTreePtr);
void preorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const;

void inorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const {
    if (treePtr != nullptr) {
        inorder(visit, treePtr->getLeftChild());
        ItemType theItem = treePtr->getItem();
        visit(theItem);
        inorder(visit, treePtr->getRightChild());
    }
}
void postorder(void visit(ItemType&), LinkedBTreeNode<ItemType>* treePtr) const;