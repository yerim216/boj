#include <iostream>
using namespace std;
bool visit[101]{ false };

template<typename T>
struct Node { //doubly Linked List�� Node
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node() {
		prev = next = NULL;
	}
	Node(T data) {
		this->data = data;
		prev = next = NULL;
	}
};
template<typename T>
class LinkedList { //Doubly Linked List
public:
	Node<T>* header;
	Node<T>* trailer;

	LinkedList() {
		header = new Node<T>();
		trailer = new Node<T>();
		header->next = trailer;
		trailer->prev = header;
	}
	void insert_back(Node<T>* new_node) {
		new_node->prev = trailer->prev;
		new_node->next = trailer;
		trailer->prev->next = new_node;
		trailer->prev = new_node;
		return;
	}
	void remove(Node<T>* del_node) {
		del_node->prev->next = del_node->next;
		del_node->next->prev = del_node->prev;
		delete del_node;
		return;
	}
};
struct edge;
struct vertex {
	int vertex_id; //���� ������ȣ
	int degree; //������ ������ ������ ����
	LinkedList<edge*>* incident_edges; //������ ������ ���� ����Ʈ
	Node<vertex*>* vertex_node;

	vertex() {
		vertex_id = 0;
		degree = 0;
		incident_edges = new LinkedList<edge*>();
		vertex_node = new Node<vertex*>(this);
	}
	vertex(int vertex_id) {
		this->vertex_id = vertex_id;
		degree = 0;
		incident_edges = new LinkedList<edge*>();
		vertex_node = new Node<vertex*>(this);
	}
};
struct edge { //���� ����ü
	vertex* src_vertex; //������ ���� ����
	vertex* dst_vertex; //������ �� ����
	Node<edge*>* src_incident_edge_node; //���� ������ ���� ��������Ʈ�� ��� ������
	Node<edge*>* dst_incident_edge_node; //�� ������ ���� ��������Ʈ�� ��� ������
	Node<edge*>* total_edge_node; //�׷����� ��������Ʈ�� ��� ������
	edge() {
		src_vertex = NULL;
		dst_vertex = NULL;
		src_incident_edge_node = new Node<edge*>(this);
		dst_incident_edge_node = new Node<edge*>(this);
		total_edge_node = new Node<edge*>(this);
	}
	edge(vertex* src_vertex, vertex* dst_vertex) {
		this->src_vertex = src_vertex;
		this->dst_vertex = dst_vertex;
		src_incident_edge_node = new Node<edge*>(this);
		dst_incident_edge_node = new Node<edge*>(this);
		total_edge_node = new Node<edge*>(this);
	}
};
class graph {
public:
	LinkedList<vertex*>* vertex_list;
	LinkedList<edge*>* edge_list;
	int vertex_size;

	vertex* find_vertex(int vertex_id) {
		for (Node<vertex*>* cur = vertex_list->header->next; cur != vertex_list->trailer; cur = cur->next) {
			if (cur->data->vertex_id == vertex_id) return cur->data;
		}
		return NULL;
	}

	edge* find_edge(vertex* src_vertex, vertex* dst_vertex) {
		if (src_vertex->degree <= dst_vertex->degree) {
			for (Node<edge*>* cur = src_vertex->incident_edges->header->next; cur != src_vertex->incident_edges->trailer; cur = cur->next)
				if (cur->data->dst_vertex == dst_vertex) return cur->data;

		}
		else {
			for (Node<edge*>* cur = src_vertex->incident_edges->header->next; cur != src_vertex->incident_edges->trailer; cur = cur->next)
				if (cur->data->src_vertex == src_vertex) return cur->data;

		}
		return NULL;
	
	}

	graph() {
		vertex_list = new LinkedList<vertex*>();
		edge_list = new LinkedList<edge*>();
		vertex_size = 0;
	}
	void insert_vertex(int vertex_id) {
		if (find_vertex(vertex_id) != NULL) return;
		vertex* new_vertex = new vertex(vertex_id);
		vertex_list->insert_back(new_vertex->vertex_node);
		vertex_size++;
		return;
	}
	void insert_Edge(int src_id, int dst_id) {
		vertex* src_vertex = find_vertex(src_id);
		vertex* dst_vertex = find_vertex(dst_id);
		if (src_vertex == NULL || dst_vertex == NULL) return;
		if (find_edge(src_vertex, dst_vertex) != NULL) return;

		edge* new_edge = new edge(src_vertex, dst_vertex);
		src_vertex->incident_edges->insert_back(new_edge->src_incident_edge_node);
		dst_vertex->incident_edges->insert_back(new_edge->dst_incident_edge_node);
		edge_list->insert_back(new_edge->total_edge_node);
		src_vertex->degree++;
		dst_vertex->degree++;
		return;
	}


};

int main() {
	graph gr;
	void dfs(int vertex_id) {
		visit[vertex_id] = true;
		vertex* a = gr

	}
	
	int n;
	int s;
	cin >> n >> s;
	for (int j = 0; j < n; j++) {

		gr.insert_vertex(j);
	}
	for (int i = 0; i < s; i++) {
		int src_id;
		int dst_id;
		cin >> src_id >> dst_id;
		gr.insert_Edge(src_id, dst_id);
	}
}