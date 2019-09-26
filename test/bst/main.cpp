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

/** A main program which reads a file containing actor names
 *  and perform searching in user interaction
 */
int main(int argc, char* argv[]) {
    const int NUM_ARG = 2;
    unsigned int size = 0;
    int height = 0;
    string name;

    // check for Arguments
    if (argc != NUM_ARG) {
        cout << "Invalid number of arguments.\n"
             << "Usage: ./main <input filename>.\n";
        return -1;
    }

    // check for valid file
    if (!fileValid(argv[1])) return -1;

    // use a BST of string
    BST<string> tree = BST<string>();
    string line;

    // parse file for actor names and populate tree
    ifstream in;
    in.open(argv[1], ios::binary);
    while (!in.eof()) {
        getline(in, line);
        if (line.empty()) {
            break;
        }
        tree.insert(line);
    }

    // store the height and size of the tree and print
    size = tree.size();
    height = tree.height();

    cout << "Size of tree: " << size << "\n";
    cout << "Height of tree: " << height << "\n";

    char response = 'y';
    while (response == 'y') {
        cout << "Enter actor/actress name: "
             << "\n";

        // read user input for name of the actor
        getline(cin, name);

        // find the actor in the tree
        BSTIterator<string> actor = tree.find(name);

        if (actor != tree.end()) {
            cout << name << " found!" << endl;
        } else {
            cout << name << " NOT found" << endl;
        }

        cout << "Search again? (y/n)" << endl;

        // read user input for y or n and store inside the variable response
        cin >> response;
        cin.ignore();
    }

    return 0;
}
