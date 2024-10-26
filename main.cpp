#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct node {
    long long value;
    long long l_bord = LONG_LONG_MIN;
    long long r_bord = LONG_LONG_MAX;
    node (long long value) : value(value) {};
    node(long long value, long long l_bord, long long r_bord) : value(value), l_bord(l_bord), r_bord(r_bord) {};
};


int main() {
    int num_of_nodes;
    ifstream in("bst.in");
    in >> num_of_nodes;
    vector <node*> data (num_of_nodes);
    long long input;
    in >> input;
    data[0] = new node(input);
    for (int i = 1; i < num_of_nodes; i++) {
        long long value;
        int row;
        char d;
        in >> value >> row >> d;
        if (d == 'R') {
            if (value >= data[row-1]->value && value < data[row-1]->r_bord) {
                data[i] = new node(value, data[row-1]->value, data[row-1]->r_bord);
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
            if (value >= data[row-1]->l_bord && value < data[row-1]->value) {
                data[i] = new node(value, data[row-1]->l_bord, data[row-1]->value);
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