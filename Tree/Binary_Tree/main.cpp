#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

typedef string ElemType;

int main(){
	BinaryTree tree;
	cout<<"Please enter the tree in the previous order traversal mode.If the node is empty,use # instead:"<<endl;
	//"A B D G # # H # # # C E # I # # F # #";
	tree.levelCreate();

	cout<<"The height of the tree is "<<tree.getHeight()<<endl;
	cout<<"The number of nodes in the tree is "<<tree.getSize()<<endl;
	cout<<"The number of leaf nodes in the tree is "<<tree.getLeafs()<<endl;
	cout<<"The number of nodes with a tree degree of 1 is "<<tree.getOneLeafs()<<endl;
	cout<<"The number of full nodes in the tree is "<<tree.getFullLeafs()<<endl;
	cout<<"Please input the value : ";
	ElemType value;
	cin>>value;
	if(tree.findNode(value)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	cout<<"Whether the tree is fully binary?"<<endl;
	if(tree.isCompleteTree()){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	int level;
	cout<<"Please input the level : ";
	cin>>level;
	cout<<"The number of nodes in the "<<level<<"th layer is "<<tree.getLevelSize(level)<<endl;
	//前序遍历
	tree.preOrder();
	//非递归前序遍历
	tree.nonRec_preOrder();
	//中序遍历
	tree.inOrder();
	//非递归中序遍历
	tree.nonRec_inOrder();
	//后序遍历
	tree.postOrder();
	//非递归后序遍历
	tree.nonRec_postOrder();
	//非递归层次遍历
	tree.nonRec_levelOrder();
	//摧毁树
	tree.destroy();
	cout<<"destory the tree......"<<endl;
	cout<<"The number of nodes in the tree is "<<tree.getSize()<<endl<<endl;
	return 0;
}
