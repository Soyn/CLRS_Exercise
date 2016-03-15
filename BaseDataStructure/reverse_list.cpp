#include <iostream>
#include <vector>

/*******************
* @Author: Soyn
* @Brief: Reverse the list, the first telephone review at Alibaba.What a pity.
* @CreatedTime: 15/3/16.
********************/

struct Node{
    int val_;
    Node *next;
    Node(int val) : val_(val) {}
};


void Print(Node *head)
{
    for(auto *p = head; p; p = p->next){
        std :: cout << p->val_ << " ";
    }
    std :: cout << std :: endl;
}
Node *CreatedList()
{
    std :: vector<int> int_vector{1, 2, 3, 4, 5};
    Node *head, *tail;
    head = tail = nullptr;
    Node *curr;
    for(auto e : int_vector){
        curr = new Node(e);
        curr->next = nullptr;

        if(head){
            tail->next = curr;
        }else{
            head = tail = curr;
        }
        tail = curr;
    }


    std :: cout << "Original sequence: " << std :: endl;
    Print(head);
    return head;
}

Node* ReverseListIteration(Node *head)
{
    Node *new_head = nullptr;
    for(auto curr = head->next; head; head = curr, curr = curr->next){
        head->next = nullptr;
        if(new_head || !curr){
            head->next = new_head;
            new_head = head;
            if(!curr) break;
        }else{
            new_head = head;
        }
    }
    return new_head;
}


Node *new_head = nullptr;
Node* ReverseListRecursion(Node *head)
{

    if(head->next){
        auto curr =  ReverseListRecursion(head->next);
        curr->next = head;
        head->next = nullptr;
        return head;
    }else{
        return new_head = head;
    }
}

void Test()
{
    Node *t = CreatedList();
    std :: cout << "I'm iteration version(time cost O(n), space cost O(1)): "
    << std :: endl;
    Node* h = ReverseList(t);  // output ===> 5, 4, 3, 2, 1
    Print(h);

    std :: cout << "I'm recursion version(Time cost:O(n) Space cost O(1)): "
    << std :: endl;
    ReverseListRecursion(h);
    Print(new_head);  // output ==> 1, 2, 3, 4, 5
}
int main(int argc, char **argv)
{
    Test();
    return 0;
}
