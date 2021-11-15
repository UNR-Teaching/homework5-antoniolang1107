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
    else {
        if (newNodePtr->getItem() <= subTreePtr->getItem())
            placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        else
            placeNode(subTreePtr-getRightChildPtr(), newNodePtr);
    }
    return subTreePtr;
    
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeValue(LinkedBTreeNode<ItemType>* subTreePtr, const ItemType target, bool& isSuccessful) override {
    
}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeNode(LinkedBTreeNode<ItemType* nodePtr) {

}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeLeftmostNode(LinkedBTreeNode<ItemType>* inorderSuccessor) {

}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::removeRightmostNode(LinkedBTreeNode<ItemType>* postorderSuccessor) {

}

template <class ItemType>
LinkedBTreeNode<ItemType>* LinkedBSearchTree<ItemType>::findNode (LinkedBTreeNode<ItemType>* treePtr, const ItemType& target, bool& isSuccessful) const {

}