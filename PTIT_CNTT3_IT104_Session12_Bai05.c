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
// Hàm xóa phần tử trùng với số mà người dùng đã nhập
Node* deleteNode(Node* head, int value){
   Node* temp = head; // Khởi con trỏ để duyệt danh sách
   // Duyệt danh sách
   while(temp != NULL){
       Node* newNode = temp->next; // Lưu node tiếp
       // Kiểm tra node hiện tại trùng với số mà người dùng đã nhập
       if(temp->data == value){
           // Kiểm tra node đầu trùng với số mà người dùng đã nhập
           if(temp->prev == NULL){
               head = temp->next; // Cập nhật head sang node tiếp
               // Kiểm tra danh sách không rỗng
               if (head){
                   head->prev = NULL; // Cập nhật node đầu
               }
           // Kiểm tra node giữa hoặc cuối trùng với số mà người dùng đã nhập
           }else{
               temp->prev->next = temp->next; // Cập nhật liên kết của node trước
               // Kiểm tra có node sau
               if(temp->next){
                   temp->next->prev = temp->prev; // Cập nhật liên kết của node sau
               }
               free(temp);
           }
       }
       // Di chuyển đến node tiếp
       temp = newNode;
   }
    return head; // Trả về con trỏ mới
}
int main(){
    Node* node1 = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(3);
    Node* node4 = createNode(2);
    Node* node5 = createNode(1);
    Node* node6 = createNode(5);
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
    // Nhập số muốn xóa
    int x;
    printf("Nhap so bat ky:");
    scanf("%d",&x);
    // Xóa số
    head = deleteNode(head,x);
    // In kết quả
    printList(head);
    freeLíst(head);
    return 0;
}
