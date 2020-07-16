#pragma once
#include <vector>
using namespace std;
template<class K, int M = 3>
struct BTreeNode
{
	// Ϊ�˷�������Ժ��ٷ��ѣ�ʵ���������Ƕ����һ���ռ�,�ڵ��л���ֻ�ܴ�M-1���ؼ���
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];
	BTreeNode<K, M>* _parent;
	size_t       _keysize;           // ��¼�ؼ��ֵ�����

	BTreeNode()
	{
		for (size_t i = 0; i < M + 1; ++i)
			_subs[i] = nullptr;

		_parent = nullptr;
		_keysize = 0;
	}
};

template<class K, int M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	pair<Node*, int> Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			int i = 0;
			while (i < cur->_keysize)
			{
				if (key < cur->_keys[i]) // ��ǰ�ؼ���С���͵���������ȥ�� 
				{
					break;
				}
				else if (key > cur->_keys[i]) // ��ǰ�ؼ��ִ󣬼�������һ���ؼ��Ƚ�
				{
					++i;
				}
				else
				{
					return make_pair(cur, i);
				}
			}

			parent = cur;
			cur = cur->_subs[i];
		}

		return make_pair(parent, -1);
	}

	void InsertKey(Node* node, const K& key, Node* child)
	{
		int end = node->_keysize - 1;
		while (end >= 0 && node->_keys[end] > key)
		{
			node->_keys[end + 1] = node->_keys[end];
			node->_subs[end + 2] = node->_subs[end + 1];
			--end;
		}

		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child;
		if (child)
			child->_parent = node;

		node->_keysize++;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_keysize = 1;
			return true;
		}

		pair<Node*, int> ret = Find(key);
		if (ret.second != -1)
		{
			return false;
		}

		Node* node = ret.first;
		K k = key;
		Node* child = nullptr;
		// ����ѭ�������߼�����node�в���k��child
		while (1)
		{
			InsertKey(node, k, child);
			if (node->_keysize < M)
			{
				return true;
			}
			else
			{
				// ���node->_keysize == M,��˵���ڵ����ˣ���Ҫ���Ѵ���
				int mid = M / 2;
				// ���Ұ�������ѿ����½ڵ��У�ע����˿����ؼ��ֻ�Ҫ������ֽ
				Node* newnode = new Node;
				int j = 0;
				int i = mid + 1;
				for (; i < M;)
				{
					newnode->_keys[j] = node->_keys[i];
					newnode->_subs[j] = node->_subs[i];
					if (node->_subs[i])
						node->_subs[i]->_parent = newnode;

					node->_keys[i] = K();
					node->_subs[i] = nullptr;

					newnode->_keysize++;
					++j;
					++i;
				}

				newnode->_subs[j] = node->_subs[i];
				if (node->_subs[i])
					node->_subs[i]->_parent = newnode;
				node->_subs[i] = nullptr;

				node->_keysize -= (newnode->_keysize + 1);

				// node�ڵ��parent����ǿգ�������µĸ�
				if (node->_parent == nullptr)
				{
					_root = new Node;
					_root->_keys[0] = node->_keys[mid];
					_root->_subs[0] = node;
					_root->_subs[1] = newnode;
					node->_parent = newnode->_parent = _root;
					_root->_keysize = 1;

					node->_keys[mid] = K();


					return true;
				}
				else
				{
					// ����ת��������node�ڵ�parent��ȥ����һ��node->key[mid] �� newnode
					k = node->_keys[mid];
					child = newnode;

					node->_keys[mid] = K();

					node = node->_parent;

				}

			}
		}

		return true;
	}

	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
		{
			return;
		}

		int i = 0;
		while (i < cur->_keysize)
		{
			_InOrder(cur->_subs[i]);
			cout << cur->_keys[i] << " ";
			++i;
		}

		_InOrder(cur->_subs[i]);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root = nullptr;
};

void TestBTree()
{
	/*int a[] = { 53, 139, 75, 49, 145, 36, 101 };
	BTree<int, 3> t;
	for (auto e : a)
	{
	t.Insert(e);
	}
	t.InOrder();*/


	const size_t n = 10000;
	vector<int> v;
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	BTree<int, 1024> t;
	for (auto e : v)
	{
		t.Insert(e);
	}

	t.InOrder();
}