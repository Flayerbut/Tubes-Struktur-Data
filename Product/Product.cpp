#include "Product.h"
#include <iostream>
using namespace std;

adrNode createNode(string name, int jumlah) {
    adrNode p = new Product;
    p->name = name;
    p->jumlah = jumlah;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertProduct(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
    } else {
        if (p->jumlah < root->jumlah) {
            insertProduct(root->left, p);
        } else {
            insertProduct(root->right, p);
        }
    }
}

adrNode searchProduct(adrNode root, int jumlah) {
    if (root == nullptr || root->jumlah == jumlah) {
        return root;
    } else {
        if (jumlah < root->jumlah) {
            return searchProduct(root->left, jumlah);
        } else {
            return searchProduct(root->right, jumlah);
        }
    }
}

void inOrder(adrNode root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->name << " (" << root->jumlah << ")\n";
        inOrder(root->right);
    }
}

void preOrder(adrNode root) {
    if (root != nullptr) {
        cout << root->name << " (" << root->jumlah << ")\n";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(adrNode root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->name << " (" << root->jumlah << ")\n";
    }
}

adrNode deleteNode(adrNode root, int jumlah) {
    if (root == nullptr) {
        return nullptr;
    } else {
        if (jumlah < root->jumlah) {
            root->left = deleteNode(root->left, jumlah);
        } else if (jumlah > root->jumlah) {
            root->right = deleteNode(root->right, jumlah);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            } else if (root->left == nullptr) {
                adrNode temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                adrNode temp = root->left;
                delete root;
                return temp;
            }
        }
        return root;
    }
}
