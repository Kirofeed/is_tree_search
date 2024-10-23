#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct node {
    int value;
    int l_bord = INT_MIN;
    int r_bord = INT_MAX;
    node (int value) : value(value) {};
    node(int value, int l_bord, int r_bord) : value(value), l_bord(l_bord), r_bord(r_bord) {};
};


int main() {
    int num_of_nodes;
    ifstream in("bst.in");
    in >> num_of_nodes;
    vector <node*> data (num_of_nodes);
    int input;
    in >> input;
    data[0] = new node(input);
    for (int i = 1; i < num_of_nodes; i++) {
        int value;
        int row;
        char d;
        in >> value >> row >> d;
        if (d == 'R') {
            if (value >= data[row]->value && value < data[row]->r_bord) {
                data[i] = new node(value, data[row]->value, data[row]->r_bord);
            }
            else {
                in.close();
                ofstream out("bst.out");
                out << "NO";
                out.close();
                return 0;
            }
        }
        else {
            if (value >= data[row]->l_bord && value < data[row]->value) {
                data[i] = new node(value, data[row]->value, data[row]->r_bord);
            }
            else {
                in.close();
                ofstream out("bst.out");
                out << "NO";
                out.close();
                return 0;
            }
        }
    }
    in.close();
    ofstream out("bst.out");
    out << "YES";
    out.close();
    return 0;
    
}
