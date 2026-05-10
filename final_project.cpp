// ECE 205 Final Project - Martin Wu
#include <iostream> 
#include <vector> 
#include <stack> 
#include <sstream> 
#include <string> 

using namespace std;

// each node in the tree holds a value (number or operator) and pointers to left and right children
struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(NULL), right(NULL) {} // constructor with null
};

// checks if a given string is one of the four basic operators
bool isOperator(string s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

// returns the precedence level of an operator
int precedence(string op) {
    if (op == "+" || op == "-") {
        return 1; // lower precedence
    }
    if (op == "*" || op == "/") {
        return 2; // higher precedence
    }
    return 0; // for a string that isn't an operator
}

// takes the raw input string and splits it into individual tokens
vector<string> tokenize(string expr) {
    vector<string> tokens; // stores the resulting tokens
    stringstream ss(expr); // wraps the string so we can read word by word
    string tok;
    while (ss >> tok) {// extract each space-separated token
        tokens.push_back(tok); // add it to the list
    }
    return tokens;
}

// converts infix notation to postfix using the shunting-yard algorithm
vector<string> infixToPostfix(vector<string> tokens) {
    stack<string> ops; // operator stack
    vector<string> output; // the resulting postfix expression

    for (int i = 0; i < tokens.size(); i++) { // go through each token
        string tok = tokens[i];

        if (tok == "(") {
            ops.push(tok); // push open parens onto the stack to handle grouping
        }
        else if (tok == ")") { // pop operators onto output until we find the matching '('
            while (!ops.empty() && ops.top() != "(") {
                output.push_back(ops.top());
                ops.pop();
            }
            if (!ops.empty()) {
                ops.pop(); // discard the '(' itself
            }
        }
        else if (isOperator(tok)) {
            // pop operators with higher or equal precedence onto output first
            while (!ops.empty() && precedence(ops.top()) >= precedence(tok)) {
                output.push_back(ops.top());
                ops.pop();
            }
            ops.push(tok); // then push current operator onto stack
        }
        else {
            output.push_back(tok); // numbers go straight to output
        }
    }

    // pop any remaining operators onto the output
    while (!ops.empty()) {
        output.push_back(ops.top());
        ops.pop();
    }
    return output;
}

// builds a binary expression tree from postfix tokens
Node* buildTree(vector<string> postfix) {
    stack<Node*> st; // stack to hold tree nodes as we build

    for (int i = 0; i < postfix.size(); i++) {
        if (!isOperator(postfix[i])) {
            // if it's a number, make a leaf node and push it
            st.push(new Node(postfix[i]));
        }
        else {
            // if it's an operator, pop two nodes to be its children
            Node* r = st.top(); 
            st.pop(); 
            Node* l = st.top(); 
            st.pop();
            Node* node = new Node(postfix[i]); // create operator node
            node->left = l;  
            node->right = r; 
            st.push(node);    // push the subtree back onto the stack
        }
    }
    return st.top(); // last node on the stack is the root
}

// recursively computes the height of the tree equalling to the longest path from root to a leaf
int getHeight(Node* root) {
    if (root == NULL) { // empty tree has height 0
        return 0; 
    }
    int l = getHeight(root->left); // height of left subtree
    int r = getHeight(root->right); // height of right subtree
    return 1 + max(l, r); // take the taller one and add 1 for current node
}

// places node values and branch characters (/ \) into a 2d grid
void fill(Node* root, vector<vector<string> >& grid, int row, int col, int gap) {
    if (root == NULL) {
        return; // nothing to place
    }
    grid[row][col] = root->value; // put the node's value in the grid

    if (root->left) { // place a '/' one row down and to the left
        if (row + 1 < (int)grid.size() && col - 1 >= 0) {
            grid[row + 1][col - 1] = "/";
        }
        fill(root->left, grid, row + 2, col - gap, (gap + 1) / 2); // recursively fill the left subtree shifted left 
    }
    if (root->right) { // place a '\' one row down and to the right
        if (row + 1 < (int)grid.size() && col + 1 < (int)grid[0].size()) {
            grid[row + 1][col + 1] = "\\";
        }
        fill(root->right, grid, row + 2, col + gap, (gap + 1) / 2); // recursively fill the right subtree shifted right
    }
}

// prints the tree top-down by building a 2d text grid and outputting it
void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    int h = getHeight(root); // get tree height to size the grid
    int w = (1 << h) * 4; // grid width (wide enough for deepest level)
    int rows = h * 2; // each tree level takes 2 rows (node + connector)

    // create a 2d grid filled with spaces
    vector<vector<string> > grid(rows, vector<string>(w, " "));
    // fill the grid starting at top center, with initial gap based on height
    fill(root, grid, 0, w / 2, 1 << (h - 1));

    // print each row of the grid
    for (int r = 0; r < rows; r++) {
        // find the rightmost non-space character so we don't print trailing spaces
        int last = -1;
        for (int c = w - 1; c >= 0; c--) {
            if (grid[r][c] != " ") { 
                last = c; 
                break; 
            }
        }
        if (last == -1) {
            // this row is empty, check if all remaining rows are too
            bool done = true;
            for (int rr = r; rr < rows && done; rr++) {
                for (int c = 0; c < w; c++) {
                    if (grid[rr][c] != " ") { 
                        done = false; 
                        break; 
                    }
                }
            }
            if (done) {
                break; 
            }
            cout << endl;
            continue;
        }
        // print characters up to the last non-space column
        for (int c = 0; c <= last; c++) {
            cout << grid[r][c];
        }
        cout << endl;
    }
}

// evaluates the expression tree and returns the result
int evaluate(Node* root) {
    // if it's a number, convert string to int and return
    if (!isOperator(root->value)) {
        return stoi(root->value);
    }
    int l = evaluate(root->left); // evaluate left subtree
    int r = evaluate(root->right); // evaluate right subtree

    // use the operator at node
    if (root->value == "+") {
        return l + r;
    }
    if (root->value == "-") {
        return l - r;
    }
    if (root->value == "*") {
        return l * r;
    }
    if (root->value == "/") {
        if (r == 0) { // division by zero case
            cout << "Error: division by zero" << endl;
            return 0;
        }
        return l / r;
    }
    return 0; 
}


int main() {
    string expr;
    cout << "Enter an infix expression (spaces between tokens): " << endl;
    getline(cin, expr);
    vector<string> tokens = tokenize(expr);
    vector<string> postfix = infixToPostfix(tokens);
    cout << "\nPostfix: ";
    for (int i = 0; i < postfix.size(); i++) {
        cout << postfix[i] << " ";
    }
    cout << endl;
    Node* root = buildTree(postfix); 
    cout << "\nExpression Tree:" << endl;
    printTree(root);
    cout << "\n\nResult: " << evaluate(root) << endl;
    return 0;
}