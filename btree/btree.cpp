#include <iostream>
#include <queue>

struct BTNode
{
    char data;
    struct BTNode *lchild, *rchild;
};

void createBTree(BTNode* &T)
{
    char ch;
    if((ch = getchar()) == '#') {
        T = NULL;
        return;
    } else {
        T = new BTNode;
        T->data = ch;
        createBTree(T->lchild);
        createBTree(T->rchild);
    }
}

void preOrder(BTNode* &T)
{
    if(T) {
        std::cout << T->data << " ";
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void posOrder(BTNode* &T)
{
    if(T) {
        posOrder(T->lchild);
        posOrder(T->rchild);
        std::cout << T->data << " ";
    }
}

void inOrder(BTNode* &T)
{
    if(T) {
        inOrder(T->lchild);
        std::cout << T->data << " ";
        inOrder(T->rchild);
    }
}

void levelOrder(BTNode* &T)
{
    std::queue<BTNode *> q_bt;
    if (T) {
        q_bt.push(T);
    }
    while (!q_bt.empty()) {
        BTNode *current = q_bt.front();
        q_bt.pop();
        std::cout << current->data << " ";
        if(current->lchild)
            q_bt.push(current->lchild);
        if(current->rchild)
            q_bt.push(current->rchild);
    }
}

void deleteBTree(BTNode* &T)
{
    if(T) {
        deleteBTree(T->lchild);
        deleteBTree(T->rchild);
        delete T;
    }
}

int main()
{
    BTNode *T;
    createBTree(T);
    preOrder(T);
    std::cout << std::endl;
    inOrder(T);
    std::cout << std::endl;
    posOrder(T);
    std::cout << std::endl;
    levelOrder(T);
    std::cout << std::endl;
    deleteBTree(T);
    return 0;
}
