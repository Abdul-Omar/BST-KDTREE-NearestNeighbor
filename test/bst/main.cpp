/**
 * This program takes in two files: one file with string data to insert in BST,
 * one file with query string data to find in BST. For each query data, it
 * prints if it was found in the BST.
 * An optional flag "-p" can be added. In this case, inorder and iterator
 * traversal with be performed to print the data in BST.
 *
 * Usage: ./main -p <input filename> <query filename>
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "BST.hpp"

using namespace std;

/** Check if a given data file is valid */
bool fileValid(const char* fileName) {
    ifstream in;
    in.open(fileName, ios::binary);

    // Check if input file was actually opened
    if (!in.is_open()) {
        cout << "Invalid input file. No file was opened. Please try again.\n";
        return false;
    }

    // Check for empty file
    in.seekg(0, ios_base::end);
    unsigned int len = in.tellg();
    if (len == 0) {
        cout << "The file is empty. \n";
        return false;
    }
    in.close();
    return true;
}

/** Check if command line arguments are valid */
bool argValid(int argc, char* argv[]) {
    const int NUM_ARG_NO_FLAG = 3;
    const int NUM_ARG_FLAG = 4;
    if (argc != NUM_ARG_FLAG && argc != NUM_ARG_NO_FLAG) {
        cout << "Invalid number of arguments.\n"
             << "Usage: ./main -p <input filename> <query filename>.\n";
        return false;
    }
    if (argc == NUM_ARG_FLAG) {
        if (string(argv[1]) != "-p") {
            cout << "Invalid flag.\n"
                 << "Usage: ./main -p <input filename> <query filename>.\n";
            return false;
        }
        if (!fileValid(argv[2]) || !fileValid(argv[3])) return false;
    } else {
        if (!fileValid(argv[1]) || !fileValid(argv[2])) return false;
    }
    return true;
}

/** Parse files to build BST and query vector */
void parseFiles(BST<string>& bst, vector<string>& queryNames, char* argv[],
                bool printFlag) {
    ifstream in;
    string line;
    // parse file for building BST
    if (!printFlag) {
        in.open(argv[1], ios::binary);
    } else {
        in.open(argv[2], ios::binary);
    }
    while (!in.eof()) {
        getline(in, line);
        if (line.empty()) break;
        bst.insert(line);
    }
    in.close();

    // parse file for query names
    if (!printFlag) {
        in.open(argv[2], ios::binary);
    } else {
        in.open(argv[3], ios::binary);
    }
    while (!in.eof()) {
        getline(in, line);
        if (line.empty()) break;
        queryNames.push_back(line);
    }
    in.close();
}

int main(int argc, char* argv[]) {
    const int TRUC_LEN = 2;
    const int NUM_ARG_FLAG = 4;
    bool printFlag = false;
    vector<string> inorderVec;
    string result;

    // check for Arguments
    if (!argValid(argc, argv)) return -1;
    if (argc == NUM_ARG_FLAG) printFlag = true;

    // parse files to build BST and query vector
    BST<string> tree = BST<string>();
    vector<string> queryNames;
    parseFiles(tree, queryNames, argv, printFlag);

    // print size, height, is empty
    cout << "Size of BST: " << tree.size() << endl;
    cout << "Height of BST: " << tree.height() << endl;
    cout << "BST is empty: ";
    if (tree.empty()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // print find query results
    result = "";
    for (string& query : queryNames) {
        if (tree.find(query) == tree.end()) {
            result += "not found, ";
        } else {
            result += "found, ";
        }
    }
    result = result.substr(0, result.length() - TRUC_LEN);
    cout << "Find results for query names: " << result << endl;

    if (printFlag) {
        // print inorder traversal
        inorderVec = tree.inorder();
        result = "";
        for (string& data : inorderVec) {
            result += (data + ", ");
        }
        result = result.substr(0, result.length() - TRUC_LEN);
        cout << "Inorder traversal: " << result << endl;

        // print iterator traversal
        result = "";
        for (auto it = tree.begin(); it != tree.end(); it++) {
            result += (*it + ", ");
        }
        result = result.substr(0, result.length() - TRUC_LEN);
        cout << "Iterator traversal: " << result << endl;
    }

    return 0;
}
