#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

/*
template<class K,class V>
class BSTNode{
public:
	K _key;
	V _val;
	BSTNode<K,V>* _left;
	BSTNode<K, V>* _right;

	BSTNode(const K& key = K() , const V& val = V())
		:_key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K,class V>
class BSTree{
public:
	typedef BSTNode<K,V> Node;

	Node* find(const K& key){
		Node* cur = _root;
		while (cur){
			if (cur->_key == key){
				return cur;
			}
			else if (cur->_key < key){
				cur = cur->_right;
			}
			else if (cur->_key > key){
				cur = cur->_left;
			}
		}
		// 查找结束如果不存在就返回 nullptr
		return nullptr;
	}

	// 插入

	bool insert(const K& key,const V& val){
		if (_root == nullptr){
			_root = new Node(val);
			return  true;
		}
		// 查找插入的节点位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur){
			parent = cur;
			if (cur->_key == key){
				return false;
			}
			else if (cur->_key < key){
				cur = cur->_right;
			}
			else  if (cur->_key > key){
				cur = cur->_left;
			}
		}
		cur = new Node(key , val);
		// 判断放在parent的哪一边
		if (parent->_key < key){
			parent->_right = cur;
		}
		else{
			parent->_left = cur;
		}
		return true;
	}

	void destroy(Node* root){
		if (root){
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
	}
	~BSTree()
	{
		// 析构函数需要一个点一个点的析构，将每一个点都释放
		destroy(_root);// 析构函数无法递归，所以外面嵌入一个destroy
	}

	// 遍历的过程中创建节点
	void copyTree(Node* root){
		if (root){
			insert(root->_key , root->_val);
			copyTree(root->_left);
			copyTree(root->_right);
		}
	}

	//深拷贝，用于拷贝构造，不会存在二次释放的问题
	Node* copyTree2(Node* root){
		if (root){
			Node* cur = new Node( root->_key , root->_val);
			cur->_left = copyTree2(root->_left);
			cur->_right = copyTree2(root->_right);
			return cur;
		}
		return nullptr;
	}
	BSTree() :_root(nullptr){}
	// 实现拷贝函数,拷贝节点与其结构，可以逐个插入
	// 深拷贝，拷贝构造
	BSTree(const BSTree<T>& bst)
		:_root(nullptr)
	{
		_root = copyTree2(bst._root);
	}

	// 现代写法,代码复用
	// 在参数中做一个拷贝构造，然后再进行交换
	// 先调用拷贝构造创建局部对象，然后再将局部对象与当前对象相互交换，完成拷贝
	BSTree<T>& operator=(BSTree<T> bst){
		swap(_root, bst._root);
		return *this;
	}

	// 经典写法
	BSTree<T> operator=(const BSTree<T>& bst){
		if (this != &bst){
			destroy(_root);
			_root = copyTree2(bst._root);
		}
		return *this;
	}

	//中序遍历
	void _inorder(Node*  root){
		if (nullptr == root){
			return nullptr;
		}
		_inorder(root->_left);
		cout <<root->_key <<":"<< root->_val << " ";
		_inorder(root->_right);
	}
	void inorder(){
		_inorder(_root);
		cout << endl;
	}
private:
	BSTNode<K,V>* _root = nullptr;
};
*/
void test1(){

}

bool is1To9(char c){
	return (c >= '0' && c <= '9');
}
// 先判断是一个可以转换的字符串
bool isToInt(string str){
	if (str[0] != '+' && str[0] != '-' && str[0] != '0' && !is1To9(str[0])){
		return false; 
	}
	for (int i = 1; i <str.size(); ++i){
		if (!is1To9(str[i])){
			return false;
		}
	}
	return true;
}
int toInt(string str){
	int sum = 0;
	int flg = 1;
	int mul = 1;
	for (int i = str.size() - 1; i>0; i--){
		sum += (str[i] - '0')*mul;
		mul *= 10;
	}
	if (str[0] == '-'){
		flg = -flg;
	}
	else if (is1To9(str[0])) {
		sum += (str[0] - '0')*mul;
	}
	sum = sum*flg;
	return sum;
}
int StrToInt(string str) {
	int ret = isToInt(str);
	if (ret){
		return toInt(str);
	}
	else{
		return 0;
	}
}
void test2(){
	string str = "+1234";
	cout << StrToInt(str) << endl;
}

int main(){

	test();
	//test1();
	while (1);
	return 0;
}