#include <iostream>
#include <vector>
#include <stack>

// A Tree node
struct Node{
    char ch;
    int freq;
    Node *left, *right;
};

struct Path{
    int weight, node;

    Path(int b, int w): node(b), weight(w){}
};
struct Node{
    std::vector<Path> paths;
    bool visited = false;
};

class Graph{
    std::vector<Node> nodes;
    std::stack<int> temp;
    std::vector<int> dist;
    int size, start, end;

public:
    Graph(int t, int S, int E): size(t), start(S-1), end(E-1){
        nodes.resize(t);
        dist.resize(t, 9999999);
    }

    void add_bridge(int a, int b, int w){
        nodes[a].paths.emplace_back(b, w);
    }

    void Top_sort(){
        for (int i = 0; i < size; ++i) {
            if (!nodes[i].visited){
                DFS(i);
            }
        }
        this->Clean();
    }

    void DAG(){
        while(temp.top() != start){
            temp.pop();
        }
        int cur = temp.top();
        dist[start] = 0;
        while(!temp.empty()){
            if (dist[cur] != 9999999) {
                for (auto path: nodes[cur].paths) {
                    dist[path.node] = std::min(dist[path.node], dist[cur] + path.weight);
                }
            }
            cur = temp.top();
            temp.pop();
        }
        if (dist[end] == 9999999){
            cout << -1;
            return;
        }
        cout << dist[end];
    }
private:
    void Clean(){
        for (int i = 0; i < size; ++i) {
            nodes[i].visited = false;
        }
    }
    void DFS(int i){
        nodes[i].visited = true;
        for (auto path:nodes[i].paths) {
            if (!nodes[path.node].visited){
                DFS(path.node);
            }
        }
        temp.push(i);
    }

};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
            unordered_map<char, string> &huffmanCode){
    if (root == nullptr)
        return;

    Graph graph(N, S, T);
    int a, b, w;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> w;
        a--; b--;
        graph.add_bridge(a, b, w);
    }

    graph.Top_sort();

    graph.DAG();
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
    // count frequency of appearance of each character
    // and store it in a map
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of
    // Huffman tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it
    // to the priority queue.
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    // do till there is more than one node in the queue
    while (pq.size() != 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();	pq.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq.top();

    // traverse the Huffman Tree and store Huffman Codes
    // in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n" << '\n';
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nOriginal string was :\n" << text << '\n';

    // print encoded string
    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << str << '\n';

    // traverse the Huffman Tree again and this time
    // decode the encoded string
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
}

// Huffman coding algorithm
int main(){
    string text = "Huffman coding is a data compression algorithm.";

    buildHuffmanTree("Apple");

    return 0;
}