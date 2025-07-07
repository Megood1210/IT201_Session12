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
// Hàm tìm phần tử giữa danh sách
Node* findMiddleList(Node* head){
    // Kiểm tra danh sách rỗng
    if(head == NULL){
        printf("Danh sach rong\n");
        return NULL;
    }
    // Khởi 2 con trỏ mới
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next; // slow đi 1 bước
        fast = fast->next->next; // fast đi 2 bước
    } // Khi vòng lắp kết thúc(fast đi xong), slow là phần tử giữa
    // Tìm vị trí của phần tử giữa
    Node* temp = head;
    int position = 1;
    // Duyệt từ đầu đến phần tử giữa, đếm số bước của slow
    while(temp != slow){
        temp = temp->next;
        position++;
    }
    // In kết quả
    printf("Node %d: %d",position,slow->data);
}
int main(){
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);
    // Liên kết các node với nhau
    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    Node* head = node1;

    printList(head);
    // Tìm số và in kết quả
    Node* mid = findMiddleList(head);

    freeLíst(head);
    return 0;
}
