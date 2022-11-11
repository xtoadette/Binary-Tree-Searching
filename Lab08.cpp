// Lab08.cpp
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node(T data, Node* left, Node* right) {
        this->data  = data;
        this->left  = left;
        this->right = right;
    }
    Node(T data) : Node(data, nullptr, nullptr){}
};

// In-order binary tree traversal
template <typename T>
void in_order_traversal (Node<T>* root) {
    stack<Node<T>*> S; //Stack to store data
    Node<T>* node = root; //copy of root
    while (!S.empty() || node != nullptr) //checks nodes and stack
    {
        if (node != nullptr) //pushes to stack
        {
            S.push(node);
            node = node->left; //moves left
        }
        else
        {
            node = S.top(); //prints node and pops stack
            S.pop();
            cout << node->data << " ";
            node = node->right; //moves to right
        }
    }
}

// Level-order binary tree traversal
template <typename T>
void level_order_traversal (Node<T>* root)
{
    queue<Node<T>*> queue; //queue to store data
    Node<T>* node; //need a copy
    queue.push(root); //add root to queue
    while(!queue.empty())
    {
        node = queue.front(); //add a node
        cout << node->data << " "; //output
        if (node->left != nullptr) //adds left node
        {
            queue.push(node->left);
        }
        if (node->right != nullptr) //adds right node
        {
            queue.push(node->right);
        }
        queue.pop(); //empties queue
    }
    
}

void test1() {

    //        9
    //      /   \
    //    5      16
    //   / \    /  \
    //  3   7  12   18

    Node<int> n3  ( 3);
    Node<int> n7  ( 7);
    Node<int> n12 (12);
    Node<int> n18 (18);
    Node<int> n5  ( 5, &n3, &n7);
    Node<int> n16 (16,&n12,&n18);
    Node<int> root( 9, &n5,&n16);

    cout << "in-order: "; 
    in_order_traversal(&root);
    cout << endl;
}

void test2() {
    //        9
    //      /   \
    //    4       17
    //   / \      / \
    //  1   7    11  19
    //     / \        \
    //    6   8       25
    //               /  \
    //              20  36

    Node<int> n6  (6);
    Node<int> n8  (8);
    Node<int> n11 (11);
    Node<int> n20 (20);
    Node<int> n36 (36);
    Node<int> n25 (25, &n20, &n36);
    Node<int> n1  ( 1);
    Node<int> n7  ( 7, &n6,  &n8 );
    Node<int> n4  ( 4, &n1,  &n7);
    Node<int> n19 (19, nullptr, &n25);
    Node<int> n17 (17, &n11,&n19);
    Node<int> root( 9, &n4, &n17);

    cout << "level-order: " << endl;; 
    level_order_traversal(&root);
}

int main() {
    test1();
    test2();

    return 0;
}
