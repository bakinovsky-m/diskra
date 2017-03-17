#include <string>
#include <iostream>

class Node{
public:
	Node() = default;
	Node(int d) : data(d) {}
	int data = 0;
	Node * next = nullptr;
};

class List{
public:
	List() = default;
	Node * tail = nullptr;
	Node * head = nullptr;
	int length = 0;

	void add(Node * n);

	void del(int n);

	std::string toString() const;
};

void List::add(Node * n){
	if (head == nullptr && tail == nullptr){
		head = n;
		tail = n;
	}
	n->next = tail;
	tail = n;
	length += 1;
}

void List::del(int n){
	Node * cur = tail;

	if(n == 1){
		tail = tail->next;
	}

	for(int i = 0; i < n - 2; i++){
		cur = cur->next;
	}
	// std::cout << "deleting" << std::endl;
	cur->next = cur->next->next;

	length -= 1;
}


std::string List::toString() const {
	std::string str = "";
	Node * cur = tail;

	for (int i = 0; i < length; i++) {
		str += std::to_string(cur->data);
		cur = cur->next;
	}
	return str;
}

int main(){
	std::cout << "creating nodes" << std::endl;
	Node a = Node(1);
	Node b = Node(2);
	Node c = Node(3);
	Node d = Node(4);
	std::cout << "creating list" << std::endl;
	List l;

	std::cout << "adding nodes" << std::endl;
	l.add(&a);
	l.add(&b);
	l.add(&c);
	l.add(&d);

	std::cout << "list to string, from tail to head" << std::endl;
	std::cout << l.toString() << " <-head" << std::endl;

	l.del(1);
	std::cout << l.toString() << " <-head" << std::endl;


	l.del(2);
	std::cout << l.toString() << " <-head" << std::endl;
	return 0;
}