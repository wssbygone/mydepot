// https://blog.csdn.net/K346K346/article/details/106277346
#include  <iostream>
#include <stack>
#include <queue>  
using namespace std;

// 二叉树节点结构体
struct BinaryTreeNode {
	int m_key;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 先根递归遍历。
void preOrderRecursion(BinaryTreeNode* root) {
	if(root==NULL) return;
	cout<< " " << root->m_key;
	preOrderRecursion(root->m_pLeft);
	preOrderRecursion(root->m_pRight);
}


// 先序非递归遍历，需要使用栈
void preOrderStack(BinaryTreeNode* root) {
	if(root==NULL) return;
	
	stack<BinaryTreeNode*> stack;
	stack.push(root);
	BinaryTreeNode* cur=NULL;
	while(!stack.empty()) {
		cur=stack.top();
		cout<<" "<<cur->m_key; //visit
		stack.pop();
		if(cur->m_pRight!=NULL) {
			stack.push(cur->m_pRight);
		}
		if(cur->m_pLeft!=NULL) {
			stack.push(cur->m_pLeft);
		}
	}
}



// 中序递归遍历。
void midOrderRecursion(BinaryTreeNode* root){
	if(root==NULL) return;
	midOrderRecursion(root->m_pLeft);
	cout<<" "<<root->m_key;   //visit
	midOrderRecursion(root->m_pRight);
}



// 中根非递归遍历，需要使用栈
void midOrderStack(BinaryTreeNode* root) {
	if(root==NULL) return; 
	
	stack<BinaryTreeNode*> stack;
	BinaryTreeNode* cur=root;
	while(!stack.empty() || cur!=NULL) {
        while(cur) {  
            stack.push(cur);  
            cur=cur->m_pLeft;  
        }  
        cur=stack.top();  
		cout<<" "<<cur->m_key;   //visit
        stack.pop();  
        cur=cur->m_pRight;  
    }
}


// 后根递归遍历
void postOrderRecursion(BinaryTreeNode* root) {
	if(root==NULL) return;
	postOrderRecursion(root->m_pLeft);
	postOrderRecursion(root->m_pRight);
	cout << " " << root->m_key;
}


// 非递归后序遍历，版本1
void postOrderStack1(BinaryTreeNode* root) {
	if(root==NULL) return; 
	
	stack<pair<BinaryTreeNode*, bool>> s;
    pair<BinaryTreeNode*,bool> cur=make_pair(root,true);
    while(cur.first!=NULL||!s.empty()) {
     	//沿左子树一直往下搜索，直至出现没有左子树的结点
        while(cur.first!=NULL) {
            s.push(cur);
			cur=make_pair(cur.first->m_pLeft,true);
        }
        if(!s.empty()) {
        	//表示是第一次出现在栈顶
            if(s.top().second==true) { 
                s.top().second=false;
                cur=make_pair(s.top().first->m_pRight,true); //将当前节点的右节点入栈
            } else {
            	// 第二次出现在栈顶 
                cout << s.top().first->m_key << " ";
                s.pop();
            }
        }
    }
}



// 非递归后序遍历，版本 2。
void postOrderStack2(BinaryTreeNode* root) {	
	if(root==NULL) return;
	
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* cur;		//当前结点 
    BinaryTreeNode* pre=NULL;	//前一次访问的结点
    s.push(root);
    while(!s.empty()) {
        cur=s.top();
        //在判断当前结点时，左孩子和右孩子都在根结点前已经被访问
        if((cur->m_pLeft==NULL&&cur->m_pRight==NULL) || (pre!=NULL&&(pre==cur->m_pLeft || pre==cur->m_pRight))) {
            cout<<cur->m_key<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
            s.pop();
            pre=cur; 
        } else {
            if(cur->m_pRight!=NULL) s.push(cur->m_pRight);
            if(cur->m_pLeft!=NULL) s.push(cur->m_pLeft);
        }
    }    
}


// 广度优先遍历二叉树，使用队列实现
void breadthFirstOrder(BinaryTreeNode* root) {
	if(root==NULL) return;
	queue<BinaryTreeNode*> queue;
	queue.push(root);
	while(!queue.empty()) {
		BinaryTreeNode* cur=queue.front();
		cout<<" "<<cur->m_key;//visit
		queue.pop();
		if(cur->m_pLeft!=NULL) queue.push(cur->m_pLeft);
		if(cur->m_pRight!=NULL) queue.push(cur->m_pRight);
	}
}    


/****************************************
func:根据前序序列和中序序列构建二叉树
para:preOrder:前序序列;midOrder:中序序列;len:节点数
****************************************/
BinaryTreeNode* construct(int* preOrder,int* midOrder,int len) {
	if(preOrder==NULL||midOrder==NULL||len<=0) return NULL;

	//先序遍历的第一个值是根结点的键值
	int rootKey=preOrder[0];
	BinaryTreeNode* root=new BinaryTreeNode;
	root->m_key=rootKey;
	root->m_pLeft=root->m_pRight=NULL;
	
	//只有一个节点
	if(len==1 && *preOrder == *midOrder) return root;
	
	//在中序遍历中找到根节点的值
	int* rootMidOrder=midOrder;
	int leftLen=0; //左子树节点数
	while(*rootMidOrder!=rootKey&&rootMidOrder<=(midOrder+len-1)) {
		++rootMidOrder;
		++leftLen;
	}
	//在中序序列未找到根结点，输入错误
	if(*rootMidOrder!=rootKey) return NULL;
	
	//构建左子树
	if(leftLen>0) {
		root->m_pLeft=construct(preOrder+1,midOrder,leftLen);
	}
	//构建右子树
	if(len-leftLen-1>0) {
		root->m_pRight=construct(preOrder+leftLen+1,rootMidOrder+1,len-leftLen-1);
	}
	return root;
}

int main() {
	// 先序序列
	int preOrder[8]={1,2,4,7,3,5,6,8};
	// 中序序列
	int midOrder[8]={4,7,2,1,5,3,8,6};
    // 建树
	BinaryTreeNode* root=construct(preOrder, midOrder, 8);
	
	cout<<"---preOrder---"<<endl;
	cout<<"recursion version: ";
	preOrderRecursion(root);
	cout<<endl<<"stack version: ";
	preOrderStack(root);
	
	cout<<endl<<endl<<"---midOrder---"<<endl;
	cout<<"recursion version: ";
	midOrderRecursion(root);
	cout<<endl<<"stack version1: ";
	postOrderStack1(root);
	cout<<endl<<"stack version2: ";
	postOrderStack2(root);
	
	cout<<endl<<endl<<"---postOrder---"<<endl;
	cout<<"recursion version: ";
	postOrderRecursion(root);
	cout<<endl<<"stack version: ";
	postOrderStack1(root);
	
	cout<<endl<<endl<<"---Breadth First Order---"<<endl;
	breadthFirstOrder(root);
}
