#include <iostream>

class minHeap {
public:
	int* m_arr;
	int m_size;
	int capa;

	minHeap(int capa) {
		this->m_size = 0;
		this->capa = capa;
		this->m_arr = new int[capa];
	}
	void intSwap(int a, int b) {
		int c;
		int c = a;
		a = b;
		b = c;
	}
	void upHeap() {
		int curIdx = m_size;
		while (curIdx / 2 >= 1) {
			if (m_arr[curIdx] < m_arr[curIdx / 2]) {
				intSwap(m_arr[curIdx], m_arr[curIdx / 2]);
				curIdx = curIdx / 2;
			}
			else break;
		}
	}
	void downHeap() {
		int curIdx = 1;
		while (curIdx * 2 <= m_size) {
			int min = m_arr[curIdx];
			int tarIdx = curIdx;
			if (min > m_arr[curIdx * 2]) {
				min = m_arr[curIdx * 2];
				tarIdx = curIdx * 2;
			}
			if (curIdx * 2 + 1 <= m_size && min > m_arr[curIdx * 2 + 1]) {
				min = m_arr[curIdx * 2 + 1];
				tarIdx = curIdx * 2 + 1;
			}
			if (tarIdx == curIdx) break;
			else {
				intSwap(m_arr[curIdx], m_arr[tarIdx]);
				curIdx = tarIdx;
			}
		}
	}
};