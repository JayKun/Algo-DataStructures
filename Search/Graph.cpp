#include <iostream>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

class Graph
{
public:
	Graph(int V);
	void AddEdge(int start, int end);
	void DFS(int start);
	void BFS(int start);
private:
	int m_v;
	list<int>* m_adj;
};

Graph::Graph(int V)
	:m_v(V)
{
	m_adj = new list<int>[V];
}

void Graph::AddEdge(int start, int end)
{
	m_adj[start].push_back(end);
}

void Graph::DFS(int start)
{
	std::bitset<10> visited;
	stack<int> myStack;
	myStack.push(start);
	while (!myStack.empty())
	{
		int cur = myStack.top();
		myStack.pop();
		visited.set(cur);
		cout << cur << endl;
		for (auto it = m_adj[cur].begin(); it != m_adj[cur].end(); ++it)
		{
			if (!visited.test(*it))
			{
				myStack.push(*it);
			}
		}
	}
}

void Graph::BFS(int start)
{
	bitset<100> visited;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
    	int cur = q.front();
    	q.pop();
    	visited.set(cur);
    	cout << cur << endl;
    	for(auto it = m_adj[cur].begin(); it != m_adj[cur].end(); ++it)
    	{
    		if(!visited.test(*it))
    		{
    			q.push(*it);
    		}
    	}
    }
}

int main()
{
	Graph graph(10);
	for (int i = 0; i < 5; ++i)
	{
		graph.AddEdge(i, i + 1);
		graph.AddEdge(i + 1, i * 2);
	}
	graph.DFS(0);
}