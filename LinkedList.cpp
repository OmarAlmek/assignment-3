#include "LinkedList.h"
void Linkedlist::deleteNode(int position)
{
    Node* q = head, * p = NULL;
    int ListLen = 0;

    if (head == NULL) {
        cout << "linked list is empty." << endl;
        return;
    }
    while (q != NULL) { // counter to increment list size
        q = q->next;
        ListLen++;
    }
    if (ListLen < position) { //check if index is out of the list, eg. -1 
        cout << "Index out of list"
            << endl;
        return;
    }
    q = head;

    if (position == 1) { //check if the element deleted is the first and only element of the list
        head = head->next;
        delete q;
        return;
    }
    while (position > 1) {// normal traverse in case there are more than one element in the list

        p = q;
        q = q->next;
        position--;
    }
    p->next = q->next;
    delete q;
}

void Linkedlist::insert(int data)
{
    Node* newNode = new Node({ data });

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) { // normal traverse to add element
        temp = temp->next;
    }
    temp->next = newNode;
}
void Linkedlist::print()
{
    Node* temp = head;
    if (head == NULL) {
        cout << "linked list is empty" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void Linkedlist::sum(Node *h, int *sum){ //function to create a sum
    if (h == NULL)
        return;
    Linkedlist::sum(h->next, sum);
    *sum += h->data * h->occur;
};
int Linkedlist::get_sum(Node* h) {// function to return the sum using the previous sum function
    int sum = 0;
    Linkedlist::sum(h, &sum);
    return sum;
}
Node* Linkedlist::get_head() {// extra function to help get the sum in driver function
    return head;
}
Linkedlist Linkedlist::createlist(vector<int> c) { // function to create a list based on a vector and returning that list // it also prints the new list info
    Linkedlist list;
    Node* temp = list.head;
    list.insert(c.at(0));
    for (int i = 1; i < c.size(); i++) {
        temp = list.head;
        while (temp != NULL) {
            if (temp->data == c.at(i)) {
                temp->occur++;
                break;
            }
            else if (temp->next == NULL) {
                list.insert(c.at(i));
                break;
            }
            temp = temp->next;
        }
    }
    cout << "Sum of all elements of the new list created = " << list.get_sum(list.get_head()) << endl;
    cout << "Elements of the list: ";
    list.print();
    cout << endl;
    for (int i = 0; i < c.size(); i++) {
        if (list.head != NULL && list.head->occur > 1)
            cout << list.head->data << " occured " << list.head->occur << " times. \n";
        if (list.head->next != NULL) {
            list.head = list.head->next;
        }
       
    }
    return list;
}