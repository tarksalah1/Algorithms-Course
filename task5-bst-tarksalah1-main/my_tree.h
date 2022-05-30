#ifndef MY_TREE_H
#define MY_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class MyTree {

    struct node {
        T data;
        node* left;
        node* right;
    };

    node* root;

private:

    bool search(node* t, T key) {
        if (t == NULL)
            return NULL;
        else if (key < t->data)
            return search(t->left, key);
        else if (key > t->data)
            return search(t->right, key);
        else
            return t;
    }

    node* insert(node* t, T key) {

        if (t == NULL)
        {
            t = new node;
            t->data = key;
            t->left = t->right = NULL;
        }
        else if (key < t->data)
            t->left = insert(t->left, key);
        else if (key > t->data) {
            t->right = insert(t->right, key);

        }
        return t;
    }

    void inorder_rec(node* root) {
        if (root != NULL) {

            inorder_rec(root->left);
            cout << root->data << " ";
            inorder_rec(root->right);
        }
    }

    void preorder_rec(node* root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder_rec(root->left);
            preorder_rec(root->right);
        }
    }

    void postorder_rec(node* root) {
        if (root != NULL) {
            postorder_rec(root->left);
            postorder_rec(root->right);
            cout << root->data << " ";
        }
    }

    int size(node* node)
    {
        if (node == NULL)
            return 0;
        else
            return(size(node->left) + 1 + size(node->right));
    }

    node* minValueNode(node* Node)
    {
        node* current = Node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    node* deleteNode(node* root, T key)
    {
        // base case
        if (root == NULL)
            return root;

        // If the key to be deleted is
        // smaller than the root's
        // key, then it lies in left subtree
        if (key < root->data)
            root->left = deleteNode(root->left, key);

        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
        else {
            // node has no child
            if (root->left == NULL and root->right == NULL)
                return NULL;

            // node with only one child or no child
            else if (root->left == NULL) {
                node* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                node* temp = root->left;
                free(root);
                return temp;
            }

            // node with two children: Get the inorder successor
            // (smallest in the right subtree)
            node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

public:

    MyTree() {
        root = nullptr;
    }

    MyTree(vector<T> elements) {
        int mid = (0 + elements.size() - 1) / 2;
        root = new node;
        root->data = elements[mid];
        root->left = root->right = NULL;

        for (int i = 0;i < elements.size();i++) {
            if (i == mid) {
                continue;
            }
            insert(root, elements[i]);
        }

    }

    //node* buildTree(node* r,vector<int>& arr, int start, int end)
    //{
    //    
    //    if (start > end)
    //        return NULL;

    //    /* Get the middle element and make it root */
    //    int mid = (start + end) / 2;
    //    if (r == NULL) {
    //        r = new node;
    //        r->data = arr[mid];
    //        r->left = r->right = NULL;
    //    }
    //    else if (key < t->data)
    //        t->left = buildTree(r->left, start, mid - 1);
    //    else if (key > t->data) {
    //        t->right = buildTree(r->right, start, mid - 1);

    //    /* Recursively construct the left subtree */
    //    r->left = buildTree(r->left,arr, start, mid - 1);

    //    /* Recursively construct the right subtree */
    //    r->right = buildTree(r->right,arr, mid + 1, end);

    //    return r;
    //}

    

    void inorder_it()
    {
        // create an empty stack
        stack<node*> stack;

        // start from the root node (set current node to the root node)
        node* curr = root;

        // if the current node is null and the stack is also empty, we are done
        while (!stack.empty() || curr != nullptr)
        {
            // if the current node exists, push it into the stack (defer it)
            // and move to its left child
            if (curr != nullptr)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else {
                // otherwise, if the current node is null, pop an element from the stack,
                // print it, and finally set the current node to its right child
                curr = stack.top();
                stack.pop();
                cout << curr->data << " ";

                curr = curr->right;
            }
        }
    }

    void preorder_it() {
        // return if the tree is empty
        if (root == nullptr) {
            return;
        }

        // create an empty stack and push the root node
        stack<node*> s;
        s.push(root);

        // create another stack to store postorder traversal
        stack<T> out;

        // loop till stack is empty
        while (!s.empty())
        {
            // pop a node from the stack and push the data into the output stack
            node* curr = s.top();
            s.pop();

            out.push(curr->data);

            // push the left and right child of the popped node into the stack
            if (curr->left) {
                s.push(curr->left);
            }

            if (curr->right) {
                s.push(curr->right);
            }
        }

        // print postorder traversal
        while (!out.empty())
        {
            cout << out.top() << " ";
            out.pop();
        }
    }

    void postorder_it() {// Check for empty tree
        if (root == NULL)
            return;

        // Create two stacks
        stack<node*> s1, s2;

        // push root to first stack
        s1.push(root);
        node* node;

        // Run while first stack is not empty
        while (!s1.empty()) {
            // Pop an item from s1 and push it to s2
            node = s1.top();
            s1.pop();
            s2.push(node);

            // Push left and right children
            // of removed item to s1
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }

        // Print all elements of second stack
        while (!s2.empty()) {
            node = s2.top();
            s2.pop();
            cout << node->data << " ";
        }
    }

    void breadth_traversal() {
        queue<node*> q;

        if (root) {
            q.push(root);
            cout << root->data << " ";
        }
        while (!q.empty()) {
            const node* const temp_node = q.front();
            q.pop();

            if (temp_node->left) {
                q.push(temp_node->left);
                cout << temp_node->left->data << " ";
            }

            if (temp_node->right) {
                q.push(temp_node->right);
                cout << temp_node->right->data << " ";
            }

        }
    }



    bool search(T key) {
        return search(root, key);
    }

    void insert(T key) {
        insert(root, key);
    }

    void inorder_rec() {
        inorder_rec(root);
    }

    void preorder_rec() {
        preorder_rec(root);
    }

    void postorder_rec() {
        postorder_rec(root);
    }
    int size() {
        return size(root);
    }

    node* deleteNode(T key) {
        return deleteNode(root, key);
    }
};

#endif

