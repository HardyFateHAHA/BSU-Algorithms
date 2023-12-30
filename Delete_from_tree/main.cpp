#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int key;
    Tree* left;
    Tree* right;
    Tree(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Функция для вставки ключа в дерево
Tree* insert(Tree* root, int key) {
    if(root == nullptr)return new Tree(key);
    if(key < root->key)root->left = insert(root->left, key);
    else if(key > root->key)root->right = insert(root->right, key);
    return root;
}

// Функция для выполнения прямого левого обхода
void Leftcout(Tree* root, ofstream& outFile) {
    if(root != nullptr){
        outFile << root->key << endl;
        Leftcout(root->left, outFile);
        Leftcout(root->right, outFile);
    }
}

// Функция для удаления ключа из дерева
Tree* deleteKey(Tree* root, int key){
    if(root == nullptr)return root;
    if(key < root->key)root->left = deleteKey(root->left, key);
    else if(key > root->key)root->right = deleteKey(root->right, key);
    else{
        if(root->left == nullptr){
            Tree* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr) {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        Tree* minRight = root->right;
        while(minRight->left != nullptr)minRight = minRight->left;
        root->key = minRight->key;
        root->right = deleteKey(root->right, minRight->key);
    }
    return root;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int key_to_delete;
    inFile >> key_to_delete;

    Tree* root = nullptr;
    int key;
    while (inFile >> key) {
        root = insert(root, key);
    }

    root = deleteKey(root, key_to_delete);

    Leftcout(root, outFile);

    inFile.close();
    outFile.close();

    return 0;
}