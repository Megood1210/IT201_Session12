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
// Hàm thêm phần tử vào cuối danh sách
Node* insertNode(Node* head, int x){
    Node* newNode = createNode(x); //newNode mới chứa dữ liệu thêm
    // Kiểm tra danh sách rỗng
    if (head == NULL){
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        // Di chuyển đến cuối danh sách
        temp = temp->next;
    }
    // Liên kết node mới với node cuối
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}
int main(){
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
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
    // Nhập phần tử muốn thêm
    int x;
    printf("Nhap so bat ky:");
    scanf("%d", &x);
    // Thêm phần tử
    head = insertNode(head, x);
    // In kết quả
    printList(head);
    freeLíst(head);
    return 0;
}