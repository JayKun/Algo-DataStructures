#pragma once

#include <algorithm>

template <typename Data>
class Node
{
public:
	Node(Data data);
	void AppendToEnd(Data data);
	void AppendToEnd(Node* data);
	void SetNextNode(Node* node);
	const Data& GetData() { return m_data; }
	Node* GetNextNode() { return m_next;  }
private:
	Data m_data;
	Node* m_next;
};

template<typename Data>
Node<Data>::Node(Data data)
{
	m_data = std::move(data);
	m_next = nullptr;
}

template<typename Data>
void Node<Data>::SetNextNode(Node* node)
{
	m_next = node;
}

template<typename Data>
void Node<Data>::AppendToEnd(Data data)
{
	Node* ptr = this;
	while (ptr->GetNextNode() != nullptr)
	{
		ptr = ptr->GetNextNode();
	}
	ptr->SetNextNode(new Node(data));
}

template<typename Data>
void Node<Data>::AppendToEnd(Node* node)
{
	Node* ptr = this;
	while (ptr->GetNextNode() != nullptr)
	{
		ptr = ptr->GetNextNode();
	}
	ptr->SetNextNode(node);
}