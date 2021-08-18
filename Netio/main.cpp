//
//  main.cpp
//  Netio
//
//  Created by Sadullah Nader on 9/5/11.
//  Copyright 2011. All rights reserved.
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class TreeNode
{
public:
    TreeNode(int32_t Data);
    void setLeft(TreeNode* Left);
    void setRight(TreeNode* Right);
    
    TreeNode* getLeft() { return m_Left; }
    TreeNode* getRight() { return m_Right; }
    
private:
    int32_t m_Data;
    TreeNode* m_Left;
    TreeNode* m_Right;
};

void swapChildren(TreeNode* Node)
{
    if (Node)
    {
        TreeNode* Temp = Node->getLeft();
        Node->setLeft(Node->getRight());
        Node->setRight(Temp);
    }
    
}

void invertBinaryTree(TreeNode* Root)
{
    queue<TreeNode*> nodeQueue;
    
    nodeQueue.push(Root)
    
    while (!nodeQueue.empty())
    {
        TreeNode* Node = nodeQueue.front();
        nodeQueue.pop();
        swapChildren(Node);
        if (TreeNode* Left = Node->getLeft())
        {
            nodeQueue.push(Left);
        }
        
        if (TreeNode* Right = Node->getRight())
        {
            nodeQueue.push(Right);
        }
    }
}

class MinHeap
{
    int* m_harr; // pointer to array of elements in heap
    int m_capacity; // maximum possible size of min heap
    int m_heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity)
        : m_capacity(capacity)
        , m_heap_size(0)
        m_harr(nullptr)
    {
        m_harr = new int[m_capacity];
    }
  
    // to heapify a subtree with the root at given index
    void MaxHeapify(int i)
    {
        
    }
  
    int parent(int i)
    {
        return (i-1)/2;
    }
  
    // to get index of left child of node at index i
    int left(int i)
    {
        return (2*i + 1);
    }
  
    // to get index of right child of node at index i
    int right(int i)
    {
        return (2*i + 2);
    }
  
    // to extract the root which is the minimum element
    int extractMin()
    {
        
    }
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val)
    {
        
    }
  
    // Returns the minimum key (key at root) from min heap
    int getMin()
    {
        return harr[m_heap_size - 1];
    }
  
    // Deletes a key stored at index i
    void deleteKey(int i)
    {
        
    }
  
    // Inserts a new key 'k'
    void insertKey(int k)
    {
        if (m_heap_size == m_capacity)
        {
            int index = m_heap_size - 1;
            deleteKey(index);
        }
        
        ++m_heap_size;
        int index = m_heap_size - 1;
        m_harr[index] = k;
        
        while (index != 0 && )
    }
};


int main (int argc, const char * argv[])
{
    
    return 0;
}
