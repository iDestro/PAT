/*
 * @Descripttion: 
 * @version: 
 * @Author: iDestro
 * @Date: 2019-07-23 09:17:19
 * @LastEditors: iDestro
 * @LastEditTime: 2019-07-23 10:27:32
 */

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <queue>
using namespace std;

template<class T>
struct BTNode {
    T data;
    BTNode<T> *lchild;
    BTNode<T> *rchild;
};

typedef BTNode<int> BTINT;

template<class T>
class BTree {
    BTNode<T> *m_root;
    BTNode<T> *getNewNode(T val) {
        BTNode<T> *newNode = new (std::nothrow) BTNode<T>();
        newNode -> data = val;
        if (newNode == nullptr) {
            cerr << "failed to malloc memory!" << endl;
            this -> destroyTree(m_root);
            exit(1);
        }
        return newNode;
    }
    public:
        BTree(): m_root(nullptr){}
        ~BTree() {}
        BTNode<T>* const getRootNode() {
            return m_root;
        }
        void initBinaryTree(const string& desStr) {
            if (desStr == "") {
                return;
            }
            BTNode<T>* lastNode = nullptr;
            stack<BTNode<T>* > nodeStack;
            bool isLeft = true;
            int curIt = 0;
            char ch = desStr.at(curIt);
            while (ch != '\0') {
                switch(ch) {
                    case '(':
                        nodeStack.push(lastNode);
                        isLeft = true;
                        break;
                    case ')':
                        isLeft = false;
                        break;
                    case ',':
                        isLeft = false;
                        break;
                    default:
                        lastNode = this->getNewNode(ch);
                        if (m_root == nullptr) {
                            m_root = lastNode;
                        } else {
                            BTNode<T>* parentNode = nodeStack.top();
                            if (isLeft == true) {
                                parentNode -> lchild = lastNode;
                            } else {
                                parentNode -> rchild = lastNode;
                            }
                        }
                }
                ++curIt;
                if (curIt == desStr.length()) {
                    break;
                }
                ch = desStr.at(curIt);
            }
        }

        void levelOrder(BTNode<T> *pCurNode) const {
            if (pCurNode == nullptr) return;
            BTNode<T>* curNode = pCurNode;
            queue<BTNode<T>* > Q;
            Q.push(curNode);
            while (!Q.empty()) {
                curNode = Q.front();
                Q.pop();
                cout << curNode -> data << endl;
                if (curNode -> lchild != nullptr) {
                    Q.push(curNode -> lchild);
                }
                if (curNode -> rchild != nullptr){
                    Q.push(curNode -> rchild);
                }
            }
        }

        void preOrder(BTNode<T>* pCurNode) const {
            if (pCurNode == nullptr) {
                return;
            } 
            cout << pCurNode -> data << endl;
            this -> preOrder(pCurNode -> lchild);
            this -> preOrder(pCurNode -> rchild);
        }

        void inOrder(BTNode<T>* pCurNode) const {
            if (pCurNode == nullptr) {
                return;
            }
            this -> inOrder(pCurNode -> lchild);
            cout << pCurNode -> data << endl;
            this -> inOrder(pCurNode -> rchild);
        }

        void postOrder(BTNode<T>* pCurNode) const {
            if (pCurNode == nullptr) {
                return;
            }
            this -> postOrder(pCurNode -> lchild);
            this -> postOrder(pCurNode -> rchild);
            cout << pCurNode -> data << endl;
        }

        void destroyTree(BTNode<T>* pCurNode) {
            if (pCurNode == nullptr) {
                return;
            }
            this -> destroyTree(pCurNode -> lchild);
            this -> destroyTree(pCurNode -> rchild);
            delete pCurNode;
            pCurNode = nullptr;
        }
};