#pragma once
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    public:
    int data;
    int occur =1;
    Node* next;
};
class Linkedlist {
private:
    Node* head;
public:
   
    Linkedlist() { head = NULL;}
    int count(Node* head, int key);
    void insert(int);
    void print();
    void deleteNode(int);
    void sum(Node* h,int* sum);
    int get_sum(Node* h);
    Node* get_head();
    Linkedlist createlist(vector<int> c);
};
