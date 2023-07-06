#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
};

struct Node *newNode(int item) {
  struct Node *temp = new Node;
  temp->key = item;
  temp->left = temp->right = nullptr;
  return temp;
}

void inorder(struct Node *root) {
  if (root != nullptr) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}

void preOrder(struct Node *root) {
  if (root != nullptr) {
    cout << root->key << " -> ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(struct Node *root) {
  if (root != nullptr) {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " -> ";
  }
}

struct Node *insert(struct Node *node, int key) {
  if (node == nullptr) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;
  while (current && current->left != nullptr)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root, int key) {
  if (root == nullptr) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == nullptr) {
      struct Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      struct Node *temp = root->left;
      delete root;
      return temp;
    }

    struct Node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main() {
  struct Node *root = nullptr;
  int choice;
  int inputNum, inputNum2;
  while (1) {
    cout << "\n                MENU      ";
    cout << "\n 1.Insert        ";
    cout << "\n 2.Delete   ";
    cout << "\n 3.Inorder Print   ";
    cout << "\n 4.Preorder Print   ";
    cout << "\n 5.Postorder Print   ";
    cout << "\n 6.Exit   ";
    cout << "\n Enter Choice:";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter Number to Insert: ";
        cin >> inputNum;
        root = insert(root, inputNum);
        break;
      case 2:
        cout << "Enter Number to Delete: ";
        cin >> inputNum2;
        root = deleteNode(root, inputNum2);
        break;
      case 3:
        cout << "Inorder traversal: ";
        inorder(root);
        break;
      case 4:
        cout << "Preorder traversal: ";
        preOrder(root);
        break;
      case 5:
        cout << "Postorder traversal: ";
        postOrder(root);
        break;
      case 6:
        exit(0);
        break;
      default:
        cout << "Wrong Choice\n";
        break;
    }
  }
  return 0;
}
