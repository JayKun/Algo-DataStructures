class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);

    void AddEdge(int v, int w); 
    void BFS(const int& s);
    void BFS_R(const int& s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w);
}

void BFS(const int& s)
{
	std::bitset<128> visited;
	std::queue<int> queue;
    
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.top();
        cout << s << " ";
        visited.set(s);
        queue.pop();

        for(auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
        	if(!visited.test(*i))
        	{
        		queue.push(*i);
        	}
        }
    }
}

void DFS(const int& s)
{
    Process(s);
    Visited(s);
    for(auto it = adj[s].begin(); it != adj[s].end(); ++it)
    {
        if(!visited[*it])
        {
            DFS(*it);
        }
    }
}


void InOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
    	return;
    }

    InOrderTraversal(root->left);
    ProcessNode(root);
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
    	return;
    }

    ProcessNode(root);
    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
    if(root == nullptr)
    {
    	return;
    }

    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
    ProcessNode(root);
}

bool BinarySearch(vector<int> arr, int x)
{
    int low = 0, int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;

    	if(arr[mid] == x)
    	{
            return true;
    	}

        else if(arr[mid] > x)
        {
        	high = mid-1;
        }
        else
        {
        	low = mid+1
        }
    }
    return false;
}

bool BinarySearchRecursive(const vector<int>& arr, const int& x, int& low, int& high)
{
	if(low > high)
		return false;

    int mid = (low + high) / 2;
    
    if(arr[mid] == x)
    {
    	return true;
    }
    else if(arr[mid] > x)
    {
    	return BinarySearchRecursive(arr, x, low, mid-1);
    }
    else
    {
    	return BinarySearchRecursive(arr, x, mid+1, high);
    }
}

bool BinarySearch(std::vector<int> arr, int x)
{
    BinarySearchRecursive(arr, x, 0, arr.size() - 1);
}

AdjacencyList representation of graphs

