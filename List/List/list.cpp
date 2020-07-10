#define  _CRT_SECURE_NO_WARNINGS 1
template <class T>
struct ListNode
{
	T _date;
	ListNode<T>* _prev;
	ListNode<T>* _next;
	ListNode(const T& value = T())
		:_date(value)
		, _prev(nullptr)
		, _next(nullptr)
	{

	}
};
template <class T>
class List
{
public :
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator iterator;
	List()
	{
		CreatHead();
	}
	void CreatHead()
	{
		head = new Node;
		head->_prev = head;
		head->_next = head;
	}
	void PushBack(T value)
	{
		pNode newNode = new Node(value);
		pNode tail = head->_prev;
		newNode->_next = head;
		head->_prev = newNode;
		tail->_next = newNode;
		newNode->_prev = tail;
	}
	iterator begin()
	{
		return head->_next;
	}
	iterator end()
	{
		return head;
	}
private:
	pNode head;
};
template <class T>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef Node* pNode;
	pNode _node;
	ListIterator(pNode node)
		:_node(node)
	{

	}
	T& operator*()
	{
		return _node->_date;
	}
	ListIterator<T>& operator++()
	{
		_node = _node->next;
		return *this;
	}
	bool operator!=(const ListIterator<T>& it)
	{
		return _node != it._node;
	}
	ListIterator<T>& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	T* operator->()
	{
		return &operator*();
	}
};