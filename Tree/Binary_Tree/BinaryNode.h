#ifndef BINARYNODE_H_INCLUDED
#define BINARYNODE_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

typedef string ElemType;
//定义树的节点
typedef struct BinaryNode{
	//节点
	ElemType data;
	//左子树
	BinaryNode* left;
	//右子树
	BinaryNode* right;
	BinaryNode(ElemType value){
		data = value;
		left = NULL;
		right = NULL;
	}
}BinaryNode,*BiTree;


#endif // BINARYNODE_H_INCLUDED
