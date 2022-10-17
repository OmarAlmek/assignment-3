//Linked list reference: https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
#include "LinkedList.h"
using namespace std;

void insertafter(vector<int>& av) { // requires input from user
    int firstvalue = 0;
    int secondvalue = 0;
    cout << "Enter first value: \n";
    cin >> firstvalue;
    cout << "Enter the value to be inserted after all instances first value: \n";
    cin >> secondvalue;
    for (int i = 0; i < av.size(); i++) {
        if (av.at(i) == firstvalue)
            av.insert(av.begin() + (i + 1), secondvalue);
    }
};


void insertafter(vector<int>& av, int firstvalue, int secondvalue) { //overloaded, doesnt require input from user
    for (int i = 0; i < av.size(); i++) {
        if (av.at(i) == firstvalue)
            av.insert(av.begin() + (i + 1), secondvalue);
    }
};



vector<int> vect(){ //function to create a vector
        int n;
        cout << "Enter number of integers that u want to insert: \n";
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cout << "Enter element number  " << i + 1 << " of the list: "; // to help user understand index of vector
            cin >> v[i];
            cout << endl;
        }
        return v;
}

int main()
{
    vector<int> v= vect();
    Linkedlist example;
    insertafter(v);
    example = example.createlist(v);
}

