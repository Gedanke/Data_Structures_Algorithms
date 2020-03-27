#include <bits/stdc++.h>

using namespace std;

typedef string ElemType;
//定义树的节点
typedef struct BinaryNode{
	//节点
	ElemType val;
	//左子树
	BinaryNode* left;
	//右子树
	BinaryNode* right;
	BinaryNode(ElemType x) : val(x),left(NULL),right(NULL){}
}BinaryNode,*BiTree;

//二叉树
//层序遍历创建二叉树
/*
先将根节点入队，当队列不为空时，循环执行以下操作：
输入左子树的值，不为空，将其入队
输入右子树的值，不为空，将其入队
*/
BiTree levelCreate(){
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

//实现层次遍历
void levelOrder(BiTree root){
	queue<BiTree> q;
	q.push(root);
	while(!q.empty()){
		//每层的节点
		int num_level = q.size();
		while(num_level--){
			BiTree node = q.front();
			q.pop();
			cout<<node->val<<" ";
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
		}
	}
}

// 摧毁树
void destroy(BiTree root){
	if(root != NULL){
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
}

// 94 二叉树的中序遍历,递归版
void inorderTraversal_helper(BiTree root,vector<int>& res){
    if(root == NULL){
        return ;
    }
    inorderTraversal_helper(root->left,res);
    res.push_back(stoi(root->val));
    inorderTraversal_helper(root->right,res);
}
vector<int> inorderTraversal(BiTree root){
    vector<int> res;
    inorderTraversal_helper(root,res);
    return res;
}
// 94 二叉树的中序遍历,非递归版
vector<int> inorderTraversal_(BiTree root){
    stack<BiTree> m;
    vector<int> res;
    BiTree rt = root;
    while(rt != NULL|| m.size() != 0){
        while(rt != NULL){
            m.push(rt);
            rt = rt->left;
        }
        rt = m.top();
        m.pop();
        res.push_back(stoi(rt->val));
        rt = rt->right;
    }
    return res;
}

// 96 不同的二叉搜索树
int numTrees(int n) {
    vector<int> data(n+1,0);
    data[0]=1;
    data[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            data[i]+=data[j-1]*data[i-j];
        }
    }
    return data[n];
}

// 98 验证二叉搜索树,递归
bool isValidBST_helper(BiTree root,long l,long r){
    if(root == NULL){
        return true;
    }
    if(l >= stoi(root->val) || r <= stoi(root->val)){
        return false;
    }
    if(isValidBST_helper(root->left,l,stoi(root->val)) && isValidBST_helper(root->right,stoi(root->val),r)){
        return true;
    }
    return false;
}
bool isValidBST(BiTree root){
    return isValidBST_helper(root,LONG_MIN,LONG_MAX);
}
// 98 验证二叉搜索树,非递归
bool isValidBST_(BiTree root){
    stack<BiTree> sk;
    long temp = LONG_MIN;
    while(root || sk.size()){
        while(root){
            sk.push(root);
            root = root->left;
        }
        root = sk.top();
        sk.pop();
        if(temp >= stoi(root->val)){
            return false;
        }
        temp = stoi(root->val);
        root = root->right;
    }
    return true;
}

// 99 恢复二叉搜索树
void recoverTree_helper(BiTree &root,BiTree &first,BiTree &second,BiTree &cur){
    if(root == nullptr){
        return ;
    }
    recoverTree_helper(root->left,first,second,cur);
    if(first == nullptr && stoi(cur->val) > stoi(root->val)){
        first = cur;
    }
    if(first != nullptr && stoi(cur->val) > stoi(root->val)){
        second = root;
    }
    cur = root;
    recoverTree_helper(root->right,first,second,cur);
}
void recoverTree(BiTree &root){
    BiTree first = nullptr;
    BiTree second = nullptr;
    int value_ = INT_MIN;
    BiTree cur = new BinaryNode(to_string(value_));
    recoverTree_helper(root,first,second,cur);
    swap(first->val,second->val);
}

// 100 相同的树
bool isSameTree(BiTree tree1,BiTree tree2){
    if(tree1 == NULL && tree2 == NULL){
        return true;
    }
    if(tree1 != NULL && tree2 != NULL && tree1->val == tree2->val){
        return isSameTree(tree1->left,tree2->left) && isSameTree(tree1->right,tree2->right);
    }else{
        return false;
    }
}

// 101 对称二叉树
bool isSymmetric_helper(BiTree tree_left,BiTree tree_right){
    if(tree_left == NULL && tree_right == NULL){
        return true;
    }
    if((tree_left == NULL || tree_right == NULL)||(tree_left->val != tree_right->val)){
        return false;
    }
    return isSymmetric_helper(tree_left->right,tree_right->left) && isSymmetric_helper(tree_left->left,tree_right->right);
}
bool isSymmetric(BiTree root){
    if(root == NULL){
        return true;
    }
    return isSymmetric_helper(root->left,root->right);
}

// 102 二叉树的层次遍历,由于本题的代码模板函数和原有的函数重复了,在原函数的基础上增加了下划线以区分
vector<vector<int>> levelOrder_(BiTree root){
    vector<vector<int>> res;
    queue<BiTree> q;
    if(root == NULL){
        return res;
    }
    q.push(root);
    while(!q.empty()){
        //， ，每一层的节点数
        int n = q.size();
        //用以存储该层节点的数据域
        vector<int> level;
        while(n--){
            //以此将本层的节点出队列
            BiTree node = q.front();
            q.pop();
            //存入level中
            level.push_back(stoi(node->val));
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        //保存该层所有节点
        res.push_back(level);
    }
    return res;
}

// 103 二叉树的锯齿形层次遍历
vector<vector<int>> zigzagLevelOrder(BiTree root){
    vector<vector<int>> res;
    if(root == NULL){
        return res;
    }
    //设置两个栈，一个从左到右记录，一个从右到左记录
    //即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行
    stack<BiTree> left_stack,right_stack;
    //奇数层，从左到右记录,记录完后将该层所有节点的左，右子节点压入右栈
    //偶数层，从右到左记录,记录完后将该层所有节点的右，左子节点压入左栈
    left_stack.push(root);
    while(left_stack.size() != 0 || right_stack.size() != 0){
        if(left_stack.size() != 0){
            res.push_back(vector<int> ());
            while(left_stack.size() != 0){
                //得到当前节点
                BiTree node = left_stack.top();
                left_stack.pop();
                res.back().push_back(stoi(node->val));
                //左节点压入右栈
                if(node->left){
                    right_stack.push(node->left);
                }
                //右节点压入右栈
                if(node->right){
                    right_stack.push(node->right);
                }
            }
        }
        if(right_stack.size() != 0){
            res.push_back(vector<int> ());
            while(right_stack.size() != 0){
                //得到当前节点
                BiTree node = right_stack.top();
                right_stack.pop();
                res.back().push_back(stoi(node->val));
                //右节点压入左栈
                if(node->right){
                    left_stack.push(node->right);
                }
                //左节点压入左栈
                if(node->right){
                    left_stack.push(node->left);
                }
            }
        }
    }
    return res;
}

// 104 二叉树的最大深度
int maxDepth(BiTree root){
    if(root == NULL){
        return 0;
    }
    int left_ = maxDepth(root->left);
    int right_ = maxDepth(root->right);
    return max(left_,right_) + 1;
}

// 105 从前序与中序遍历序列构造二叉树
BiTree PI_buildTree_helper(vector<int>& preorder,int &cur, vector<int>& inorder,int left,int right){
    if(cur >= preorder.size()){
        return 0;
    }
    int index = left;
    for(index = left;index <= right;index++){
        if(preorder[cur] == inorder[index]){
            break;
        }
    }
    //根节点
    BiTree node = new BinaryNode(to_string(preorder[cur]));
    //左子树
    if(left <= index - 1){
        cur++;
        node->left = PI_buildTree_helper(preorder,cur,inorder,left,index - 1);
    }
    //右子树
    if(index + 1 <= right){
        cur++;
        node->right = PI_buildTree_helper(preorder,cur,inorder,index + 1,right);
    }
    return node;
}
BiTree PI_buildTree(vector<int>& preorder, vector<int>& inorder){
    int cur = 0;
    return PI_buildTree_helper(preorder,cur,inorder,0,inorder.size()-1);
}

// 106 从中序与后序遍历序列构造二叉树
BiTree IP_buildTree_helper(vector<int>& postorder,int &cur, vector<int>& inorder,int left,int right){
    if(cur < 0 || left > right){
        return 0;
    }
    int index = left;
    for(index = left;index <= right;index++){
        if(postorder[cur] == inorder[index]){
            break;
        }
    }
    //根节点
    BiTree node = new BinaryNode(to_string(postorder[cur]));
    //右子树
    if(index + 1 <= right){
        cur--;
        node->right = IP_buildTree_helper(postorder,cur,inorder,index + 1,right);
    }
    //左子树
    if(left <= index - 1){
        cur--;
        node->left = IP_buildTree_helper(postorder,cur,inorder,left,index - 1);
    }
    return node;
}
BiTree IP_buildTree(vector<int>& inorder, vector<int>& postorder){
    int cur = inorder.size() - 1;
    return IP_buildTree_helper(postorder,cur,inorder,0,inorder.size() - 1);
}

// 107 二叉树的层次遍历 II
void levelOrderBottom_helper(vector<vector<ElemType>>& res,BiTree root,int level){
    if(root == NULL){
        return ;
    }
    if(level == res.size()){
        res.push_back({});
    }
    res[level].push_back(root->val);
    if(root->left){
        levelOrderBottom_helper(res,root->left,level+1);
    }
    if(root->right){
        levelOrderBottom_helper(res,root->right,level+1);
    }
}
vector<vector<ElemType>> levelOrderBottom(BiTree root){
    vector<vector<ElemType>> res;
    levelOrderBottom_helper(res,root,0);
    reverse(res.begin(),res.end());
    return res;
}

// 108 将有序数组转换为二叉搜索树
BiTree sortedArrayToBST_helper(vector<ElemType>& nums,int start_,int end_){
    if(start_ > end_){
        return nullptr;
    }
    int mid = start_ + (end_ - start_)/2;
    BiTree point = new BinaryNode(nums[mid]);
    point->left = sortedArrayToBST_helper(nums,start_,mid-1);
    point->right = sortedArrayToBST_helper(nums,mid+1,end_);
    return point;
}
BiTree sortedArrayToBST(vector<ElemType>& nums){
    if(nums.size() == 0){
        return nullptr;
    }
    return sortedArrayToBST_helper(nums,0,nums.size()-1);
}

// 110 平衡二叉树
int isBalanced_helper(BiTree root){
    if(root == NULL){
        return 1;
    }else{
        return max(isBalanced_helper(root->left),isBalanced_helper(root->right)) + 1;
    }
}
bool isBalanced(BiTree root){
    if(root == NULL){
        return true;
    }else{
        int ans = abs(isBalanced_helper(root->left) - isBalanced_helper(root->right));
        return (ans <= 1) && isBalanced(root->left) && isBalanced(root->right);
    }
}

// 111 二叉树的最小深度
int minDepth(BiTree root){
    if(root == NULL){
        return 0;
    }
    int level = 1;
    if(root->left == NULL && root->right == NULL){
        return level;
    }
    if(root->left == NULL){
        return level + minDepth(root->right);
    }
    if(root->right == NULL){
        return level + minDepth(root->left);
    }
    return level + min(minDepth(root->left),minDepth(root->right));
}

// 112 路径总和
bool hasPathSum(BiTree root,int sum){
    if(root == NULL){
        return false;
    }
    if(root->left == NULL && root->right == NULL && sum == stoi(root->val)){
        return true;
    }
    if(root->left != NULL && hasPathSum(root->left,sum - stoi(root->val))){
        return true;
    }
    if(root->right != NULL && hasPathSum(root->right,sum - stoi(root->val))){
        return true;
    }
    return false;
}

// 113 路径总和 II
void pathSum_helper(BiTree root,vector<vector<int>> &res,vector<int> &path,int sum){
    if(root == NULL){
        return ;
    }
    path.push_back(stoi(root->val));
    sum -= stoi(root->val);
    if((root->left == NULL) && (root->right == NULL) && sum == 0){
        //满足条件，左右子树为空，和为sum，path入res
        res.push_back(path);
    }
    //递归左子树
    pathSum_helper(root->left,res,path,sum);
    //递归左子树
    pathSum_helper(root->right,res,path,sum);
    //将path最后一个元素去除
    path.pop_back();
    sum += stoi(root->val);
}
vector<vector<int>> pathSum(BiTree root,int sum){
    /*
    将 path,res 设置成全局变量或者类成员变量更优
    这里为了避免变量命名冲突,设置成局部变量
    */
    vector<int> path;
    vector<vector<int>> res;
    pathSum_helper(root,res,path,sum);
    return res;
}

// 124 二叉树中的最大路径和
int maxPathSum_helper(BiTree root,int &val_){
    if(root == nullptr){
        return 0;
    }
    int left_ = maxPathSum_helper(root->left,val_);
    int right_ = maxPathSum_helper(root->right,val_);
    int path1 = stoi(root->val) + max(0,left_) + max(0,right_);
    int path2 = stoi(root->val) + max(0,max(left_,right_));
    val_ = max(val_,max(path1,path2));
    return path2;
}
int maxPathSum(BiTree root){
    int val = INT_MIN;
    maxPathSum_helper(root,val);
    return val;
}

// 129 求根到叶子节点数字之和
void sumNumbers_helper(BiTree root,int path,int &sum){
    if(root == NULL){
        return ;
    }
    path = path*10 + stoi(root->val);
    if(root->left == NULL && root->right == NULL){
        sum += path;
    }else{
        sumNumbers_helper(root->left,path,sum);
        sumNumbers_helper(root->right,path,sum);
    }
    path = path/10;
}
int sumNumbers(BiTree root){
    int sum = 0;
    sumNumbers_helper(root,0,sum);
    return sum;
}

// 144 二叉树的前序遍历
void preorderTraversal_helper(BiTree root,vector<int>& res){
    if(root != NULL){
        res.push_back(stoi(root->val));
        preorderTraversal_helper(root->left,res);
        preorderTraversal_helper(root->right,res);
    }
}
vector<int> preorderTraversal(BiTree root){
    vector<int> res;
    preorderTraversal_helper(root,res);
    return res;
}
vector<int> preorderTraversal_(BiTree root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    stack<BiTree> s;
    BiTree p = root;
    s.push(p);
    while(!s.empty()){
        BiTree node = s.top();
        s.pop();
        res.push_back(stoi(node->val));
        if(node->right){
            s.push(node->right);
        }
        if(node->left){
            s.push(node->left);
        }
    }
    return res;
}

// 145 二叉树的后序遍历
void postorderTraversal_helper(BiTree root,vector<int> &res){
    if(root != NULL){
        postorderTraversal_helper(root->left,res);
        postorderTraversal_helper(root->right,res);
        res.push_back(stoi(root->val));
    }
}
vector<int> postorderTraversal(BiTree root){
    vector<int> res;
    postorderTraversal_helper(root,res);
    return res;
}
vector<int> postorderTraversal_(BiTree root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    stack<BiTree> s1;
    stack<BiTree> s2;
    s1.push(root);
    while(!s1.empty()){
        BiTree node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left){
            s1.push(node->left);
        }
        if(node->right){
            s1.push(node->right);
        }
    }
    while(!s2.empty()){
        res.push_back(stoi(s2.top()->val));
        s2.pop();
    }
    return res;
}

// 173 二叉搜索树迭代器
class BSTIterator{
public:
    stack<BiTree> storeNode;
    BSTIterator(BiTree root){
        while(root){
            storeNode.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next(){
        BiTree node = storeNode.top();
        int ans = stoi(node->val);
        storeNode.pop();
        node = node->right;
        while(node){
            storeNode.push(node);
            node = node->left;
        }
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext(){
        return !storeNode.empty();
    }

};

// 222 完全二叉树的节点个数
int countNodes_(BiTree root){
    return (root == NULL) ? 0 : (1 + countNodes_(root->left) + countNodes_(root->right));
}
// 222 完全二叉树的节点个数
int countNodes_helper(BiTree root){
    int depth = 0;
    while(root){
        depth++;
        root = root->left;
    }
    return depth;
}
int countNodes(BiTree root){
    int depth = countNodes_helper(root);
    int ans = (1<<depth) - 1;
    for(int i=1;i<depth;i++){
        if(countNodes_helper(root->right) + i == depth){
            root = root->right;
        }else{
            root = root->left;
            ans -= 1<<(depth - i - 1);
        }
    }
    return ans;
}

//226 翻转二叉树
BiTree invertTree(BiTree root){
    if(root == NULL){
        return NULL;
    }
    BiTree r = invertTree(root->right);
    BiTree l = invertTree(root->left);

    root->left = r;
    root->right = l;
    return root;
}

// 230 二叉搜索树中第 k 小的元素
void kthSmallest_helper(BiTree root,int k,int &index,int &ans){
    if(!root){
        return ;
    }
    kthSmallest_helper(root->left,k,index,ans);
    index++;
    if(index == k){
        ans = stoi(root->val);
    }
    kthSmallest_helper(root->right,k,index,ans);
}
int kthSmallest(BiTree root,int k){
    //递归
    int index = 0;
    int ans = 0;
    kthSmallest_helper(root,k,index,ans);
    return ans;
}

// 235 二叉搜索树的最近公共祖先
// 引入辅助函数寻找节点，假设节点存在于树中
BiTree lowestCommonAncestor_helper(BiTree root,int value){
    BiTree node = NULL;
    if(root == NULL){
        return root;
    }
    if(root->val == to_string(value)){
        return root;
    }else{
        node = lowestCommonAncestor_helper(root->left,value);
        if(node != NULL){
            if(node->val == to_string(value)){
                return node;
            }
        }
        node = lowestCommonAncestor_helper(root->right,value);
    }
    return node;
}
BiTree lowestCommonAncestor(BiTree root,BiTree p,BiTree q){
    if(root == NULL){
        return NULL;
    }
    //递归右子树
    if(stoi(q->val) > stoi(root->val) && stoi(p->val) > stoi(root->val)){
        return lowestCommonAncestor(root->right,p,q);
    }
    //递归左子树
    if(stoi(q->val) < stoi(root->val) && stoi(p->val) < stoi(root->val)){
        return lowestCommonAncestor(root->left,p,q);
    }
    return root;
}

// 257 二叉树的所有路径
void binaryTreePaths_helper(BiTree root,string path,vector<string> &data){
    if(root != NULL){
        path += root->val;
        // 叶子节点
        if((root->left == NULL) && (root->right == NULL)){
            data.push_back(path);
            path = "";
        }else{
            path += "->";
            binaryTreePaths_helper(root->left,path,data);
            binaryTreePaths_helper(root->right,path,data);
        }
    }
}
vector<string> binaryTreePaths(BiTree root){
    vector<string> data;
    binaryTreePaths_helper(root,"",data);
    return data;
}

// 404 左叶子之和
void sumOfLeftLeaves_helper(BiTree root,int& sum){
    if(root == NULL){
        sum = sum;
    }else{
        if(root->left != NULL){
            // 左叶子的条件
            if(root->left->left == NULL && root->left->right == NULL){
                sum += stoi(root->left->val);
            }else{
                sumOfLeftLeaves_helper(root->left,sum);
            }
            if(root->right != NULL){
                sumOfLeftLeaves_helper(root->right,sum);
            }
        }
    }
}
int sumOfLeftLeaves(BiTree root){
    int sum = 0;
    sumOfLeftLeaves_helper(root,sum);
    return sum;
}

// 501 二叉搜索树中的众数
void findMode_helper(BiTree root,vector<int> &res){
    if(root != NULL){
        findMode_helper(root->left,res);
        res.push_back(stoi(root->val));
        findMode_helper(root->right,res);
    }
}
vector<int> findMode(BiTree root){
    vector<int> res;
    findMode_helper(root,res);
    vector<int> result;
    if(res.size() == 1){
        result.push_back(res[0]);
    }
    int cur = 0;
    int max = 0;
    for(int i = 1;i < res.size();i++){
        if(res[i] == res[i-1]){
            cur++;
        }else{
            cur = 0;
        }
        if(cur == max){
            if(i == 1&&cur == 0){
                result.push_back(res[0]);
            }
            result.push_back(res[i]);
        }else if(cur > max){
            result.clear();
            max = cur;
            result.push_back(res[i]);
        }
    }
    return result;
}

// 513 找树左下角的值
int findBottomLeftValue_helper(BiTree root){
    if(root == NULL){
        return 0;
    }
    int l = findBottomLeftValue_helper(root->left);
    int r = findBottomLeftValue_helper(root->right);
    return max(l,r) + 1;
}
int findBottomLeftValue(BiTree root){
    int depth = findBottomLeftValue_helper(root);
    int level = 1;
    queue<BiTree> q;
    q.push(root);
    while(!q.empty()&&level!=depth){
        int n = q.size();
        level++;
        while(n--){
            BiTree node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    BiTree node = q.front();
    return stoi(node->val);
}

// 515 在每个树行中找最大值
vector<int> largestValues(BiTree root){
    vector<int> res;
    queue<BiTree> q;
    if(root == NULL){
        return res;
    }
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int max_ = INT_MIN;
        while(n--){
            BiTree node = q.front();
            q.pop();
            if(stoi(node->val) > max_){
                max_ = stoi(node->val);
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        res.push_back(max_);
    }
    return res;
}

// 530 二叉搜索树的最小绝对差
void getMinimumDifference_helper(BiTree root,int &pre,int &curr){
    if(root == NULL){
        return ;
    }
    getMinimumDifference_helper(root->left,pre,curr);
    if(pre >= 0){
        curr = min(curr,stoi(root->val) - pre);
    }
    pre = stoi(root->val);
    getMinimumDifference_helper(root->right,pre,curr);
}
int getMinimumDifference(BiTree root){
    int pre = INT_MIN;
    int curr = INT_MAX;
    getMinimumDifference_helper(root,pre,curr);
    return curr;
}

// 538 把二叉搜索树转换为累加树
void convertBST_helper(BiTree root,int &sum){
    if(root != NULL){
        convertBST_helper(root->right,sum);
        sum += stoi(root->val);
        root->val = to_string(sum);
        convertBST_helper(root->left,sum);
    }
}
BiTree convertBST(BiTree root){
    int sum = 0;
    convertBST_helper(root,sum);
    return root;
}

// 563 二叉树的坡度
int findTilt_helper(BiTree root,int &sum){
    if(root == NULL){
        return 0;
    }
    int l = findTilt_helper(root->left,sum);
    int r = findTilt_helper(root->right,sum);
    sum += abs(l - r);
    return l + r + stoi(root->val);
}
int findTilt(BiTree root){
    int sum = 0;
    findTilt_helper(root,sum);
    return sum;
}



int main(){
    //test
    cout<<"test:......"<<endl;
    return 0;
}
