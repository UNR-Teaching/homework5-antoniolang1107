template <class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode() {
    leftChildPtr = nullptr;
    rightChildPtr = nullptr;
}

template <class ItemType>
LinkedBTreeNode<ItemType>::LinkedBTreeNode(const ItemType& newData, Node<ItemType>* left, Node<ItemType>* right) {
    item = newData;
    leftChildPtr = left;
    rightChildPtr = right;
}

template <class ItemType>
void LinkedBTreeNode<ItemType>::setItem(const ItemType& newData) {
    item = newData;
}

bool LinkedBTreeNode<ItemType>::isLeaf() const {
    return leftChildPtr == nullptr && rightChildPtr == nullptr;
}

template <class ItemType>
Node<ItemType>* LinkedBTreeNode<ItemType>::getLeftChildPtr() const {
    return leftChildPtr;
}

template <class ItemType>
Node<ItemType>* LinkedBTreeNode<ItemType>::getRightChildPtr() const {
    return rightChildPtr;
}

template <class ItemType>
void LinkedBTreeNode<ItemType>::setLeftChildPtr(Node<ItemType>* newLeftChildPtr) {
    leftChildPtr = newLeftChildPtr;
}

template <class ItemType>
void LinkedBTreeNode<ItemType>::setRightChildPtr(Node<ItemType>* newRightChildPtr) {
    rightChildPtr = newRightChildPtr;
}