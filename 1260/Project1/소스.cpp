#include <iostream>
using namespace std;

struct vertex {
	int vertex_id; 
	int matrix_id; 
	vertex* prev;
	vertex* next;

	vertex() {
		vertex_id = matrix_id = -1;
		prev = next = NULL;
	}
	vertex(int vertex_id) {
		this->vertex_id = vertex_id;
		matrix_id = -1;
		prev = next = NULL;
	}
};
struct edge {
	vertex* src;
	vertex* dst;
	edge* prev;
	edge* next;

	edge() {
		src = dst = NULL;
		prev = next = NULL;
	}
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		prev = next = NULL;
	}
};
class VertexList {
	vertex* header;
	vertex* trailer;
public:
	VertexList() {
		header = new vertex();
		trailer = new vertex();
		header->next = trailer;
		trailer->prev = header;
	}
	
};



