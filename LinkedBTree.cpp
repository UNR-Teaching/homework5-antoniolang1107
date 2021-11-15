template <class ItemType>
LinkedBTree<ItemType>::LinkedBTree() {
    rootPtr = nullptr;
    rootPtr->setLeftChildPtr(nullptr);
    rootPtr->setRightChildPtr(nullptr);
}

template <class ItemType>
bool LinkedBTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template <class ItemType>
int LinkedBTree<ItemType>::getHeight() const {
    return getHeightHelper(rootPtr);
}

template <class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodes() const {
    // add 1 for every node visited in traversal
}

template <class ItemType>
ItemType LinkedBTree<ItemType>::getRootData() const {
    rootPtr->getItem();
}

template<class ItemType>
bool LinkedBTree<ItemType>::add(const ItemType& newData) {
    LinkedBTreeNode<ItemType>* newNodePtr(newData);
    rootPtr = balancedAdd(rootPtr, newNodePtr);
    return true;
}

template<class ItemType>
bool LinkedBTree<ItemType>::remove(const ItemType& data) {
    // iterate through tree until data value
    // remove node
    // shuffle remaining nodes
    return true;
}

template<class ItemType>
void LinkedBTree<ItemType>::clear() {

}

template <class ItemType>
ItemType LinkedBTree<ItemType>::getEntry(const ItemType& anEntry) const {
    
}

template <class ItemType>
bool LinkedBTree<ItemType>::contains(const ItemType& anEntry) const {

    return true;
}

template <class ItemType>
void LinkedBTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    if (rootPtr != nullptr) {
        ItemType tempItem = rootPtr->getItem();
        visit(tempItem);
        preorder(visit, rootPtr->getLeftChildPtr());
        preorder(visit, rootPtr->getRightChildPtr());
    }
}

template <class ItemType>
void LinkedBTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    if (rootPtr != nullptr) {
        inorder(visit, rootPtr->getLeftChildPtr());
        ItemType tempItem = rootPtr->getItem();
        visit(tempItem);
        inorder(visit, rootPtr->getRightChildPtr());
    }
}

template <class ItemType>
void LinkedBTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    if (rootPtr != nullptr) {
        postorder(visit, rootPtr->getLeftChildPtr());
        postorder(visit, rootPtr->getRightChildPtr());
        ItemType tempItem = rootPtr->getItem();
        visit(tempItem);
    }
}

template <class ItemType>
LinkedBTree<ItemType>::~LinkedBTree() {
    clear();
}

template<class ItemType>
int LinkedBTree<ItemType>::getHeightHelper(LinkedBTreeNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    }
    else {
        return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}

template<class ItemType>
int LinkedBTree<ItemType>::getNumberOfNodesHelper(LinkedBTreeNode<ItemType>* subTreePtr) const {
    if (subTreePtr == nullptr) {
        return 0;
    }
    else {
        return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
    }
}

template<class ItemType>
LinkedBTreeNode<ItemType>* LinkedBTree<ItemType>::balancedAdd(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr) {
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

            subTreePtr->setLeftChildPtr(leftPtr);
        }
        return subTreePtr;
    }
}

template <class ItemType>
void LinkedBTree<ItemType>::visit(ItemType& value) {
    std::cout << value << std::endl;
}

/*
LinkedBTreeNode<ItemType>* removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful);
LinkedBTreeNode<ItemType>* moveValuesUpTree(LinkedBTreeNode<ItemType>* subTreePtr);
LinkedBTreeNode<ItemType>* findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& targert, bool& isSuccessful) const;
LinkedBTreeNode<ItemType>* copyTree (const LinkedBTreeNode<ItemType>* oldTreeRootPtr) const;
void destroyTree(LinkedBTreeNode<ItemType>* subTreePtr);
*/