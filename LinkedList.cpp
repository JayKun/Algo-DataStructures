template <typename Data>
class Node
{
public:
	Node(Data data);
    void AppendToEnd(Data data);
    void AppendToEnd(Node* data);
    void SetNextNode(Node* node);
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
    while(ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    SetNextNode(new Node(data));
}

template<typename Data>
void Node<Data>::AppendToEnd(Node* node)
{
    Node* ptr = this;
    while(ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    SetNextNode(node);
}