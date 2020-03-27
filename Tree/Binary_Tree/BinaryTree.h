#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <bits/stdc++.h>
#include "BinaryNode.h"

using namespace std;

typedef string ElemType;
//二叉树
class BinaryTree{
private:
	//根节点
	BiTree mRoot;
	//节点总数
	int size;
	//按前序遍历方式递归创建二叉树
	BiTree precreate();
	//层序遍历创建二叉树
	BiTree levelcreate();
	//递归构造平衡二叉树
	BiTree balBiTree_();
	//非递归构造平衡二叉树
	BiTree nonRec_balBiTree_();
	//递归实现前序遍历
	void preOrder(BiTree root);
	//非递归实现前序遍历
	void nonRec_preOrder(BiTree root);
	//递归实现中序遍历
	void inOrder(BiTree root);
	//非递归实现中序遍历
	void nonRec_inOrder(BiTree root);
	//递归实现后序遍历
	void postOrder(BiTree root);
	//非递归实现后序遍历
	void nonRec_postOrder(BiTree root);
	//非递归实现层次遍历
	void nonRec_levelOrder(BiTree root);
	//递归实现摧毁树(前序遍历)
	void destroy(BiTree root);
	//递归得到树的节点数
	int getSize(BiTree root);
	//递归得到树的高度
	int getHeight(BiTree root);
	//得到叶子节点的个数
	int getLeafs(BiTree root);
	//得到度为1的节点个数
	int getOneLeafs(BiTree root);
	//得到满节点个数
	int getFullLeafs(BiTree root);
	//获取第 k 层的节点数
	int getLevelSize(BiTree root,int level);
	//查找指定值的节点
	BiTree findNode(BiTree root,ElemType value);

public:
	//按前序遍历方式递归创建二叉树
	void preCreate();
	//层序遍历创建二叉树
	void levelCreate();
	//递归构造平衡二叉树
	void balBiTree();
	//非递归构造平衡二叉树
	void nonRec_balBiTree();
	//递归实现前序遍历
	void preOrder();
	//非递归实现前序遍历
	void nonRec_preOrder();
	//递归实现中序遍历
	void inOrder();
	//非递归实现中序遍历
	void nonRec_inOrder();
	//递归实现后序遍历
	void postOrder();
	//非递归实现后序遍历
	void nonRec_postOrder();
	//递归实现层次遍历
	void nonRec_levelOrder();
	//递归实现摧毁树(前序遍历)
	void destroy();
	//递归得到树的节点数
	int getSize();
	//递归得到树的高度
	int getHeight();
	//得到叶子节点的个数
	int getLeafs();
	//得到度为1的节点个数
	int getOneLeafs();
	//得到满节点个数
	int getFullLeafs();
	//获取第 k 层的节点数
	int getLevelSize(int level);
	//判断是否为完全二叉树
	bool isCompleteTree();
	//查找指定值的节点
	BiTree findNode(ElemType value);

};

//所有成员函数的实现
//按前序遍历方式递归创建二叉树
BiTree BinaryTree::precreate(){
	BiTree newNode = NULL;
	ElemType value;
	//此处 ElemType 应该是基本类型数据,若为自定义类型,请重载输入流
	cin>>value;
	//# 表示当前子树为空
	if(value == "#"){
		return NULL;
	}else{
		//递归创建左右子树,使用 size 记录下树的节点树
		size++;
		newNode = new BinaryNode(value);
		newNode->left = precreate();
		newNode->right = precreate();
		return newNode;
	}
}
void BinaryTree::preCreate(){
	mRoot = precreate();
}

//层序遍历创建二叉树
/*
先将根节点入队，当队列不为空时，循环执行以下操作：
输入左子树的值，不为空，将其入队
输入右子树的值，不为空，将其入队
*/
BiTree BinaryTree::levelcreate(){
	ElemType value;
	BiTree root;
	queue<BiTree> q;
	cin>>value;
	if(value == "#"){
		return NULL;
	}else{
		root = new BinaryNode(value);
		q.push(root);
	}
	while(!q.empty()){
		BiTree p = q.front();
		q.pop();
		cin>>value;
		if(value == "#"){
			p->left = NULL;
		}else{
			p->left = new BinaryNode(value);
			q.push(p->left);
		}
		cin>>value;
		if(value == "#"){
			p->right = NULL;
		}else{
			p->right = new BinaryNode(value);
			q.push(p->right);
		}
	}
	return root;
}
void BinaryTree::levelCreate(){
	mRoot = levelcreate();
}

//递归实现前序遍历
void BinaryTree::preOrder(BiTree root){
	if(root != NULL){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void BinaryTree::preOrder(){
	cout<<"The result of the preorder traversal is "<<endl;
	preOrder(mRoot);
	cout<<endl;
}

//非递归实现前序遍历
void BinaryTree::nonRec_preOrder(BiTree root){
	if(root == NULL){
		return ;
	}
	stack<BiTree> s;
	BiTree p = root;
	s.push(p);
	while(!s.empty()){
		BiTree node = s.top();
		cout<<node->data<<" ";
		s.pop();
		if(node->right){
			s.push(node->right);
		}
		if(node->left){
			s.push(node->left);
		}
	}
}
void BinaryTree::nonRec_preOrder(){
	cout<<"The result of the non-recursive preorder traversal is "<<endl;
	nonRec_preOrder(mRoot);
	cout<<endl;
}

//递归实现中序遍历
void BinaryTree::inOrder(BiTree root){
	if(root != NULL){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
void BinaryTree::inOrder(){
	cout<<"The result of the in-order traversal is "<<endl;
	inOrder(mRoot);
	cout<<endl;
}

//非递归实现中序遍历
void BinaryTree::nonRec_inOrder(BiTree root){
	if(root == NULL){
		return ;
	}
	stack<BiTree> myStack;
	BiTree rt = root;
	while(rt != NULL || !myStack.empty()){
		while(rt != NULL){
			myStack.push(rt);
			rt = rt->left;
		}
		rt = myStack.top();
		myStack.pop();
		cout<<rt->data<<" ";
		rt = rt->right;
	}
}
void BinaryTree::nonRec_inOrder(){
	cout<<"The result of the non-recursive in-order traversal is "<<endl;
	nonRec_inOrder(mRoot);
	cout<<endl;
}

//递归实现后序遍历
void BinaryTree::postOrder(BiTree root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}
void BinaryTree::postOrder(){
	cout<<"The result of the postorder traversal is "<<endl;
	postOrder(mRoot);
	cout<<endl;
}

//非递归实现后序遍历,双栈法
/*
	栈 s1 入栈顺序：根节点-> 左节点-> 右节点
	栈 s2 入栈顺序：右节点-> 左节点-> 根节点
	出栈顺序：根节点-> 左节点-> 右节点
*/
void BinaryTree::nonRec_postOrder(BiTree root){
	if(root == NULL){
		return ;
	}
	stack<BiTree> s1;
	stack<BiTree> s2;
	s1.push(root);
	while(!s1.empty()){
		BiTree p = s1.top();
		s1.pop();
		s2.push(p);
		if(p->left){
			s1.push(p->left);
		}
		if(p->right){
			s1.push(p->right);
		}
	}
	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}
void BinaryTree::nonRec_postOrder(){
	cout<<"The result of the non-recursive postorder traversal is "<<endl;
	nonRec_postOrder(mRoot);
	cout<<endl;
}

//非递归实现层次遍历
void BinaryTree::nonRec_levelOrder(BiTree root){
	queue<BiTree> q;
	q.push(root);
	while(!q.empty()){
		//每层的节点
		int num_level = q.size();
		while(num_level--){
			BiTree node = q.front();
			q.pop();
			cout<<node->data<<" ";
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}
	}
}
void BinaryTree::nonRec_levelOrder(){
	cout<<"The result of the non-recursive sequence traversal is "<<endl;
	nonRec_levelOrder(mRoot);
	cout<<endl;
}

//递归实现摧毁树(前序遍历)
void BinaryTree::destroy(BiTree root){
	if(root != NULL){
		destroy(root->left);
		destroy(root->right);
		free(root);
		size = 0;
	}
}
void BinaryTree::destroy(){
	size = 0;
	destroy(mRoot);
}

//递归得到树的节点数
int BinaryTree::getSize(BiTree root){
	int num = 0;
	if(root == NULL){
		return 0;
	}else{
		num = 1 + getSize(root->left) + getSize(root->right);
	}
	return num;
}
int BinaryTree::getSize(){
	return getSize(mRoot);
	//return size;
}

//递归得到树的高度
int BinaryTree::getHeight(BiTree root){
	if(root == NULL){
		return 0;
	}
	int l = getHeight(root->left);
	int r = getHeight(root->right);
	return max(l,r)+1;
}
int BinaryTree::getHeight(){
	return getHeight(mRoot);
}

//得到叶子节点的个数
int BinaryTree::getLeafs(BiTree root){
	int num = 0;
	if(root == NULL){
		return 0;
	}else if(root->left == NULL && root->right == NULL){
		return 1;
	}else{
		num = getLeafs(root->left) + getLeafs(root->right);
	}
	return num;
}
int BinaryTree::getLeafs(){
	return getLeafs(mRoot);
}

//得到度为1的节点个数
int BinaryTree::getOneLeafs(BiTree root){
	int num = 0;
	if(root == NULL){
		return 0;
	}else if(root->left == NULL && root->right == NULL){
		return 0;
	}else if((root->left != NULL)&&(root->right == NULL)){
		num = 1 + getOneLeafs(root->left);
	}else if((root->left == NULL)&&(root->right != NULL)){
		num = 1 + getOneLeafs(root->right);
	}else{
		num = getOneLeafs(root->left) + getOneLeafs(root->right);
	}
	return num;
}
int BinaryTree::getOneLeafs(){
	return getOneLeafs(mRoot);
}

//得到满节点个数,和统计一度节点个数类似,也可以通过节点数计算出来
int BinaryTree::getFullLeafs(BiTree root){
	int num = 0;
	if(root == NULL){
		return 0;
	}else if(root->left == NULL && root->right == NULL){
		return 0;
	}else if(root->left != NULL && root->right == NULL){
		num = getFullLeafs(root->left);
	}else if(root->left == NULL && root->right != NULL){
		num = getFullLeafs(root->right);
	}else{
		num = 1 + getFullLeafs(root->left) + getFullLeafs(root->right);
	}
	return num;
}
int BinaryTree::getFullLeafs(){
	return getFullLeafs(mRoot);
}

//获取第 k 层的节点数
int BinaryTree::getLevelSize(BiTree root,int level){
	if(root == NULL){
		return 0;
	}
	if(level == 1){
		return 1;
	}
	return getLevelSize(root->left,level-1) + getLevelSize(root->right,level-1);
}
int BinaryTree::getLevelSize(int level){
	return getLevelSize(mRoot,level);
}

//判断是否为完全二叉树
bool BinaryTree::isCompleteTree(){
    queue<BiTree> q;
    if(mRoot){
		q.push(mRoot);
    }
    bool res = true;

    while(!q.empty()){
		BiTree front = q.front();
		q.pop();
		if(front->left){
			if(!res){
				return res;
			}
			q.push(front->left);
		}else{
			res = false;
		}
		if(front->right){
			if(!res){
				return res;
			}
			q.push(front->right);
		}else{
			res = false;
		}
    }
    return true;
}

//查找指定值的节点
BiTree BinaryTree::findNode(BiTree root,ElemType value){
	BiTree node = NULL;
	if(root == NULL){
		return root;
	}
	if(root->data == value){
		return root;
	}else{
		node = findNode(root->left,value);
		if(node != NULL){
			if(node->data == value){
				return node;
			}
		}
		node = findNode(root->right,value);
	}
	return node;
}
BiTree BinaryTree::findNode(ElemType value){
	return findNode(mRoot,value);
}

#endif // BINARYTREE_H_INCLUDED
