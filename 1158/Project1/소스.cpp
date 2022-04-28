#include <iostream>
using namespace std;
//singly likned lists


class Node {
public:
	int elem;
	Node* next;
	
};
class SinglyLinkedList {
	
public:
	Node* head;
	Node* tail;
	SinglyLinkedList(int);
	void remove();
	void remove_Josep(int,int);
	bool empty() {
		return(head == NULL);
	};
	
};

SinglyLinkedList::SinglyLinkedList(int N) {
	for (int i = 1; i < N + 1; i++) {
		Node* v = new Node;
		v->elem = i;
		v->next = NULL;
		if (empty()) {
			head = tail = v;
		}
		else {
			tail->next = v;
			tail = v;
		}

	}
	tail->next = head;

}

void SinglyLinkedList::remove_Josep(int N, int K) {
	Node* s = head;
	int* arr = new int[N];

	for(int i=0; i<N-1; i++) {
		for (int j = 0; j < K - 1; j++) {
			s->next = s;
		}
		if(empty()){
		return;}
		Node* old = s;
		arr[i] = s->elem;
		s->next = s;
		delete old;

	}

	cout << "<" << arr[N] << ">" << endl;

}
int main() {
	int N, K;
	cin >> N >> K;
	SinglyLinkedList sl(N);
	sl.remove_Josep(N, K);
	
}
	



