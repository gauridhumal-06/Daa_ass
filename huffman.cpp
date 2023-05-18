Huffman encoding using greedy method, in cpp

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;
};

// Function to create a new Huffman tree node
Node* createNode(char data, int frequency, Node* left, Node* right) {
    Node* node = new Node();
    node->data = data;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

// Comparison function for priority queue
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->frequency > r->frequency);
    }
};

// Function to generate Huffman encoding
void generateHuffmanEncoding(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }
    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }
    generateHuffmanEncoding(root->left, code + "0", huffmanCodes);
    generateHuffmanEncoding(root->right, code + "1", huffmanCodes);
}

// Function to perform Huffman encoding
string huffmanEncoding(string text) {
    // Count the frequency of each character
    unordered_map<char, int> frequencyMap;
    for (char c : text) {
        frequencyMap[c]++;
    }

    // Create a priority queue to store the nodes
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto& pair : frequencyMap) {
        pq.push(createNode(pair.first, pair.second, nullptr, nullptr));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        int sumFrequency = left->frequency + right->frequency;
        pq.push(createNode('$', sumFrequency, left, right));
    }

    // Get the root of the Huffman tree
    Node* root = pq.top();

    // Generate Huffman codes for each character
    unordered_map<char, string> huffmanCodes;
    generateHuffmanEncoding(root, "", huffmanCodes);

    // Encode the input text using the Huffman codes
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }

    // Clean up memory
    delete root;

    return encodedText;
}

int main() {
    string text = "ABRACADABRA";

    string encodedText = huffmanEncoding(text);

    cout << "Original text: " << text << endl;
    cout << "Encoded text: " << encodedText << endl;

    return 0;
}
