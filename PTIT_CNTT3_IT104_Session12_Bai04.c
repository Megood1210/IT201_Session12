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
// Hàm in danh sách từ cuối về đầu
void printListReverse(Node* head){
    Node* temp = head; // Biến trung gian
    // Di chuyển từ đầu đến node cuối
    while (temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    // Duyệt từ đầu về cuối danh sách
    while (temp != NULL){
        printf(" %d <->", temp->data);
        // Quay về node trước
        temp = temp->prev;
    }
    printf("NULL");
    printf("\n");
}
// Hàm giải phóng bộ nhớ
void freeLíst(Node* head){
    Node* temp ;

    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
// Hàm xóa phần tử cuối danh sách
Node* deleteNode(Node* head){
    // Kiểm tra danh sách rỗng
    if (head == NULL){
        printf("Danh sach rong");
        return NULL;
    }
    // Kiểm tra danh sách chỉ có 1 node
    if (head->next == NULL){
        return NULL;
    }
    Node* temp = head; // Lưu node hiện tại vào biến tạm
    head = (head)->next; // Cập nhật node
    // Kiểm tra danh sách chứa phần tử
    if (head != NULL){
        head->prev = NULL;
    }
    // Giải phóng
    free(temp);
    return head; // Trả về node mới
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

    printListReverse(head);
    //Xóa phần tử
    head = deleteNode(head);
    // In kết quả
    printListReverse(head);
    freeLíst(head);
    return 0;
}
