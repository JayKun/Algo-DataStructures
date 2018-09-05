// Binary Heap
// A Binary Heap is a Binary Tree with following properties.
// 1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible).
// 2) This property of Binary Heap makes them suitable to be stored in an array.
// 3) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap.
// The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

// Using STL we can create a heap

// (i-1)/2 --> return the parent node.
// (2*i)+1 --> return the left child node.
// (2*i)+2 --> return the right child node. 

#include <bits/stdc++.h>

using namespace std;

// How to make a min heap of user defined class?
class Point
{
    int x;
    int y;

public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	int GetX() const
	{
		return x;
	}

	int GetY() const
	{
		return y;
	}
};

class myComparatorMinHeap
{
public:
	bool operator() (const Point& p1, const Point& p2)
	{
		return p1.GetX() > p2.GetX();
	}
}

class myComparitorMaxHeap
{
public:
	bool operator() (const Point& p1, const Point& p2)
	{
		return p1.GetX() <= p2.GetX();
	}
}

int main()
{
	priority_queue<Point, vector<Point>, myComparitorMaxHeap> maxHeap;
	priority_queue<Point, vector<Point>, myComparitorMinHeap> minHeap;
}
