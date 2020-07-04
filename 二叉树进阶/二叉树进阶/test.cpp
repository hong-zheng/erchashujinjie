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
		// ���ҽ�����������ھͷ��� nullptr
		return nullptr;
	}

	// ����

	bool insert(const K& key,const V& val){
		if (_root == nullptr){
			_root = new Node(val);
			return  true;
		}
		// ���Ҳ���Ľڵ�λ��
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
		// �жϷ���parent����һ��
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
		// ����������Ҫһ����һ�������������ÿһ���㶼�ͷ�
		destroy(_root);// ���������޷��ݹ飬��������Ƕ��һ��destroy
	}

	// �����Ĺ����д����ڵ�
	void copyTree(Node* root){
		if (root){
			insert(root->_key , root->_val);
			copyTree(root->_left);
			copyTree(root->_right);
		}
	}

	//��������ڿ������죬������ڶ����ͷŵ�����
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
	// ʵ�ֿ�������,�����ڵ�����ṹ�������������
	// �������������
	BSTree(const BSTree<T>& bst)
		:_root(nullptr)
	{
		_root = copyTree2(bst._root);
	}

	// �ִ�д��,���븴��
	// �ڲ�������һ���������죬Ȼ���ٽ��н���
	// �ȵ��ÿ������촴���ֲ�����Ȼ���ٽ��ֲ������뵱ǰ�����໥��������ɿ���
	BSTree<T>& operator=(BSTree<T> bst){
		swap(_root, bst._root);
		return *this;
	}

	// ����д��
	BSTree<T> operator=(const BSTree<T>& bst){
		if (this != &bst){
			destroy(_root);
			_root = copyTree2(bst._root);
		}
		return *this;
	}

	//�������
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
// ���ж���һ������ת�����ַ���
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