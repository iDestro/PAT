#include "../header/btree.h"
int main() {
    BTree<char>* binaryTree = new BTree<char>();
	binaryTree->initBinaryTree("1(2(3,4),5(6,7))");
	cout << "前序遍历" << endl;
	binaryTree->preOrder(binaryTree->getRootNode());
	cout << "中序遍历" << endl;
	binaryTree->inOrder(binaryTree->getRootNode());
	cout << "后序遍历" << endl;
	binaryTree->postOrder(binaryTree->getRootNode());
	cout << "层次遍历" << endl;
	binaryTree->levelOrder(binaryTree->getRootNode());
	cout << endl;
	binaryTree->destroyTree(binaryTree->getRootNode());
	cout << endl;
	system("pause");
	return 0;
}