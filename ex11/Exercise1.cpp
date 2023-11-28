#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void generateFibonacciTree(int n, vector<int>& callTree, int& treeSize, int& treeDepth, int& leafCount, int depth) {
    if (n <= 1) {
        callTree.push_back(1);
        treeSize++;
        leafCount++;
        treeDepth = max(treeDepth, depth);
    } else {
        callTree.push_back(fibonacci(n));
        treeSize++;

        generateFibonacciTree(n - 1, callTree, treeSize, treeDepth, leafCount, depth + 1);
        generateFibonacciTree(n - 2, callTree, treeSize, treeDepth, leafCount, depth + 1);
    }
}

void preOrderTraversal(int n) {
    vector<int> callTree;
    int treeSize = 0, treeDepth = 0, leafCount = 0;

    generateFibonacciTree(n, callTree, treeSize, treeDepth, leafCount, 1);

    cout << "Call tree in pre-order: ";
    for (int num : callTree) {
        cout << num << " ";
    }

    cout << "\nCall tree size: " << treeSize
         << "\nCall tree depth: " << treeDepth
         << "\nCall tree leafs: " << leafCount << endl;
}

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        preOrderTraversal(n);
    }

    return 0;
}
