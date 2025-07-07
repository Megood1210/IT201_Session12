#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
// Định nghĩa cấu trúc danh sách liên kết đôi
typedef struct Node{
    int data;
    struct Node *next; // Con trỏ đến phần tử tiếp theo
    struct Node *prev; // Con trỏ đến phần tử trước đó
}Node;
// Hàm tạo một Node
Node* createNode(int value){
    // Cấp phát bộ nhớ
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; // Gán giá trị cho node
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
// Hàm in danh sách
void printList(Node* head){
    Node* temp = head; // Biến trung gian
    while(temp != NULL){
        printf(" %d <->",temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
    printf("\n");
}
// Hàm giải phóng bộ nhớ
void freeLíst(Node* head){
    Node* temp;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
// Hàm sắp xếp danh sách liên kết theo thứ tự tăng dần
Node* sortList(Node* head){
    // Kiểm tra danh sách rỗng
    if(head == NULL){
        return NULL;
    }

    int swap;
    Node* ptr1;
    Node* last = NULL;

    do{
        swap = 0;
        ptr1 = head;

        // Duyệt đến phần tử cuối
        while(ptr1->next != last){
            if(ptr1->data > ptr1->next->data){
                // Hoán đổi giá trị
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swap = 1;
            }
            ptr1 = ptr1->next;
        }
        // Cập nhật node cuối
        last = ptr1;
    }
    while (swap); // Lặp lại nếu còn đổi
    return head; // Trả về đầu danh sách
}
int main(){
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);
    Node* node6 = createNode(6);
    // Liên kết các node với nhau
    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    node5->next = node6;
    node6->prev = node5;

    Node* head = node1;

    printList(head);
    // In kết quả
    head = sortList(head);
    printList(head);
    freeLíst(head);
    return 0;
}
