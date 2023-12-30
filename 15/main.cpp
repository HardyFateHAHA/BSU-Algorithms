#include <bits/stdc++.h>

using namespace std;

struct Node{
    long long value;
    Node *left;
    Node *right;
    long long height;
    long long count;
    bool is = false;

    Node() : value(0), left(nullptr), right(nullptr) {}

    explicit Node(long long value_) : value(value_), left(nullptr), right(nullptr), is(false) {}
};
void Add(long long value, Node *current) {
    Node *temp = current;
    if (value != temp->value) {
        if (value > temp->value) {
            if (temp->right == nullptr) {
                temp->right = new Node(value);
            }
            else {
                Add(value, temp->right);
            }
        }
        else {
            if (temp->left == nullptr) {
                temp->left = new Node(value);
            }
            else {
                Add(value, temp->left);
            }
        }
    }
}
void PreOrderTraversal(Node *root, vector<long long> &result) {
    Node *temp = root;
    if (temp == nullptr) {
        return;
    }
    if (temp != nullptr) {
        result.push_back(temp->value);
    }

    if (temp->left != nullptr) {
        PreOrderTraversal(temp->left, result);
    }
    if (temp->right != nullptr) {
        PreOrderTraversal(temp->right, result);
    }

}
Node *GetMinimum(Node *root) {
    if (root->left == nullptr) {
        return root;
    }
    return GetMinimum(root->left);
}
Node *DeleteNode(Node *root, long long key) {
    if (root == nullptr) {
        return root;
    }
    else if (key < root->value) {
        root->left = DeleteNode(root->left, key);
    }
    else if (key > root->value) {
        root->right = DeleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr || root->right == nullptr) {
            if (root->left != nullptr) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        else {
            Node *min_in_right = GetMinimum(root->right);
            if (min_in_right != nullptr) {
                root->value = min_in_right->value;
                root->right = DeleteNode(root->right, min_in_right->value);
            }
        }
    }

    return root;
}
bool Solve(Node *root1, Node *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
return Solve(root1->left, root2->right) &&
           Solve(root1->right, root2->left);
}

int main() {
    freopen("tst.in", "r", stdin);
    freopen("tst.out", "w", stdout);

    vector<long long> result;
    vector<long long> output;
    vector<long long> roots(2);
    Node *root1 = nullptr;
    string h;
    if(cin >> h){
        if(h != "*"){
           roots[0] = stoi(h);
           root1 = new Node(stoi(h));
        }
    }
    while(cin >> h){
        if(h == "*")break;
        if(h != "*")Add(stoi(h), root1);
    }
    Node *root2 = nullptr;
    if(cin >> h){
        if(h != "*"){
            roots[1] = stoi(h);
            root2 = new Node(stoi(h));
        }
    }
    while(cin >> h)if(h != "*")Add(stoi(h), root2);
    root1 = DeleteNode(root1, roots[0]);
    root2 = DeleteNode(root2, roots[1]);
    if(Solve(root1, root2)){
        cout << "YES\n";
        PreOrderTraversal(root1, output);
        for(long long i = 0 ; i < output.size() ; i++){
                cout << output[i];
                if(i != output.size() - 1)cout << ' ';
        }
        if(output.size() != 0)cout << '\n';
        output.clear();
        PreOrderTraversal(root2, output);
        for(long long i = 0 ; i < output.size() ; i++){
                cout << output[i];
                if(i != output.size() - 1)cout << ' ';
        }
        if(output.size() != 0)cout << '\n';
    }else cout << "NO\n";

    return 0;
}