template <class ItemType>
bool LinkedBSearchTree<ItemType>::add(const ItemType& newData) {
    LinkedBTreeNode<ItemType>* newNodePtr(newData);
    rootPtr = placeNode(rootPtr, newNodePtr);
    return true;
}


template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::placeNode(LinkedBTreeNode<ItemType>* subTreePtr, LinkedBTreeNode<ItemType>* newNodePtr) {
    if (subTreePtr == nullptr)
        return newNodePtr;
    else if (subTreePtr->getItem() > newNodePtr->getItem()) {
        LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else {
        LinkedBTreeNode<ItemType>* tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    // else {
    //     if (newNodePtr->getItem() <= subTreePtr->getItem())
    //         placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
    //     else
    //         placeNode(subTreePtr-getRightChildPtr(), newNodePtr);
    // }
    return subTreePtr;
    
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) {
    if (subTreePtr == nullptr) {
        isSuccessful = false;
    }
    else if (subTreePtr->getItem() == target) {
        isSuccessful = true;
        return removeNode(subTreePtr);
    }
    else if (subTreePtr->getItem() > target) {
        LinkedBTreeNode<ItemType>* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else {
        LinkedBTreeNode<ItemType>* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedBTreeNode<ItemType>* nodePtr) {
    if (this->isLeaf())
        rootPtr = nullptr;
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBTreeNode<ItemType>* inorderSuccessor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else {
        tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
        nodePtr->getLeftChildPtr(tempPtr);
        return nodePtr;
    }
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeRightmostNode(LinkedBTreeNode<ItemType>* postorderSuccessor) {

}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& target, bool& isSuccessful) const {

}