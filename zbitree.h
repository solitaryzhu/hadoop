#ifndef ZBITREE_H
#define ZBITREE_H
#include <iostream>
#include <queue>

#define LH 1
#define EH 0
#define RH -1

template <class T>
class ZBiTreeNode
{
private:
    ZBiTreeNode<T>* pLeftChild;
    ZBiTreeNode<T>* pRightChild;
    T data;
    int ef;
public:
    ZBiTreeNode():pLeftChild(0),pRightChild(0){}
    ZBiTreeNode(T item):data(item),pLeftChild(0),pRightChild(0){}
    ZBiTreeNode(T item, ZBiTreeNode* pLeft, ZBiTreeNode* pRight):
        data(item),pLeftChild(pLeft),pRightChild(pRight){}
    ~ZBiTreeNode(){}

    ZBiTreeNode<T>* Left(){ return pLeftChild; }
    ZBiTreeNode<T>* Right(){ return pRightChild; }
    void setLeft(ZBiTreeNode<T>* pNode){ pLeftChild = pNode; }
    void setRight(ZBiTreeNode<T>* pNode){ pRightChild = pNode; }
    T Data(){ return data; }
    int getEF(){ return ef; }
    void setEF(int item){ ef = item; }
};

template <class T>
ZBiTreeNode<T>* CreateTreeNode(T item, ZBiTreeNode<T>* pLeft, ZBiTreeNode<T>* pRight)
{
    ZBiTreeNode<T>* ptr = 0;
    ptr = new ZBiTreeNode<T>(item, pLeft, pRight);
    return ptr;
}

template <class T>
void visit(T item)
{
    std::cout<<item<<' ';
}

template <class T, void(*ptr)(T)>
void LevelScan(ZBiTreeNode<T>* pNode)
{
    std::queue<ZBiTreeNode<T>*> q;
    ZBiTreeNode<T>* p;
    q.push(pNode);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        ptr(p->Data());
        if(p->Left())
        {
            q.push(p->Left());
        }
        if(p->Right())
        {
            q.push(p->Right());
        }

    }
}

template <class T>
ZBiTreeNode<T>* findFromSearchTree(ZBiTreeNode<T>* pNode, const T& item)
{
    if(item == pNode->Data())
        return pNode;
    else if(item < pNode->Data())
        return findFromSearchTree(pNode->Left(), item);
    else if(item > pNode->Data())
        return findFromSearchTree(pNode->Right(), item);
}

template <class T>
void insertBiSearchTree(ZBiTreeNode<T>* pParent, ZBiTreeNode<T>* pNode, const T& item)
{
    if(pNode == 0)
    {
        pNode = new ZBiTreeNode<T>(item);
        if(pParent->Data() > pNode->Data())
            pParent->setLeft(pNode);
        else
            pParent->setRight(pNode);
    }
    else if(item > pNode->Data())
    {
        insertBiSearchTree(pNode, pNode->Right(), item);
    }
    else if(item < pNode->Data())
    {
        insertBiSearchTree(pNode, pNode->Left(), item);
    }
}

template <class T>
ZBiTreeNode<T>* LL_Rotate(ZBiTreeNode<T>* pRoot)
{
    ZBiTreeNode<T>* pLeft = pRoot->Left();
    if(0 == pLeft)
        exit(1);
    pRoot->setLeft(pLeft->Right());
    pLeft->setRight(pRoot);
    pRoot->setEF(0);
    pLeft->setEF(0);
    return pLeft;
}

template <class T>
ZBiTreeNode<T>* RR_Rotate(ZBiTreeNode<T>* pRoot)
{
    ZBiTreeNode<T>* pRight = pRoot->Right();
    if(0 == pRihgt)
        exit(1);
    pRoot->setRight(pRight->Left());
    pRight->setLeft(pRoot);
    pRoot->setEF(0);
    pRight->setEF(0);
    return pRight;
}

template <class T>
ZBiTreeNode<T>* LR_Rotate(ZBiTreeNode<T>* pRoot)
{
    ZBiTreeNode<T>* ptr = LL_Rotate(pRoot);
    return RR_Rotate(ptr);
}

template <class T>
ZBiTreeNode<T>* RL_Rotate(ZBiTreeNode<T>* pRoot)
{
    ZBiTreeNode<T>* ptr = RR_Rotate(pRoot);
    return LL_Rotate(ptr);
}

#endif // ZBITREE_H
