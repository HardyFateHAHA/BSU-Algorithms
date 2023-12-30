#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Функция для вставки ключа в дерево
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Функция для выполнения прямого левого обхода
void inorderTraversal(Node* root, ofstream& outFile) {
    if (root != nullptr) {
        outFile << root->key << endl;
        inorderTraversal(root->left, outFile);
        inorderTraversal(root->right, outFile);
    }
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    Node* root = nullptr;
    int key;
    while (inFile >> key) {
        root = insert(root, key);
    }
    inorderTraversal(root, outFile);
    inFile.close();
    outFile.close();
    return 0;
}