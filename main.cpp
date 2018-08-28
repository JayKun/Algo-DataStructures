#include "Node.h"
#include <iostream>
using namespace std;

int main()
{
	Node<int> head(1);
	for (int i = 0; i < 10; ++i)
	{
		head.AppendToEnd(i);
	}

	Node<int>* ptr = &head;
    while(ptr != nullptr)
	{
		cout << ptr->GetData() << endl;
		ptr = ptr->GetNextNode();
	}
	system("pause");
	return 0;
}