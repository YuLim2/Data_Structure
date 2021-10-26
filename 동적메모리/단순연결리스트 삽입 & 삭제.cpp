#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{	//리스트노드 구조체 정의 
   char data[4];
   struct listNode *link;
}listNode;



typedef struct {	//링크리스트 헤드 구조체 정의 
   listNode * head;
}linkedList_h;

// 공백 연결 리스트를 생성
linkedList_h *createLinkedList_h();
// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L);
// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h *L);
// 첫번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *L, char *x);
// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode( linkedList_h *L, listNode *pre, char *x);
// 마지막에 노드를 삽입하는 연산
void insertLastNode( linkedList_h *L, char *x);
// 리스트에서 x 노드를 탐색하기( page173, 175 )
linkedList_h *searchNode(linkedList_h *L, char *x);
int main(){
   linkedList_h * L;
   listNode * p;

   printf("(1) 공백리스트 생성하기! \n");
   L = createLinkedList_h();
   printList( L );
   
   printf("(2) 리스트 처음에 [수]노드 삽입하기! \n");
   insertFirstNode( L, "수");
   printList( L );
   
   printf("(3) 리스트 마지막에 [금]노드 삽입하기! \n");
   insertLastNode( L, "금");
   printList( L );
   
   printf("(4) 리스트 첫 번째에 [월]노드 삽입하기! \n");
   insertFirstNode( L, "월");
   printList( L );
   
   printf("(5) 리스트에서 [수] 노드를 찾아 그 뒤에 [목] 삽입하기! \n");
   p = searchNode( L, "수");
   if( p == NULL ) printf("찾는 데이터가 없습니다.\n");
   else    insertMiddleNode( L, p, "목");
   printList( L );
   
   printf("(6) 리스트 공간을 해제하여 공백 리스트로 만들기! \n");
   freeLinkedList_h(L);
   printList( L );
   return 0;
}
// 공백 연결 리스트를 생성
linkedList_h *createLinkedList_h(){
   linkedList_h* L;		//헤드 L 선언 
   L = (linkedList_h*)malloc(sizeof(linkedList_h)); 	//동적 메모리 할당 
   L -> head = NULL; 	//끝을 의미하는 NULL을 헤드에 삽입 
   return L;	//L 반환 
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L){
   listNode* p;		//노드 p 선언 
   while (L -> head != NULL) {		//노드의 끝일 때까지 
      p = L -> head;	//p는 노드의 헤드 
      L -> head = L -> head -> link;	//
      free(p);
      p = NULL;
   }
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h *L){
   listNode* p;		//노드 p 선언 
   printf ("L = (");	
   p = L -> head;	//p는 L의 헤드 
   while (p != NULL) {		//L의 끝까지 
      printf ("%s", p -> data);		//data 출력 
      p = p -> link;	//다음 노드로 이동 
      if (p != NULL) printf (", ");
   }
   printf (") \n");
}

// 첫번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *L, char *x){
   listNode* newnode;		//newnode라는 노드 선언 
   newnode = (listNode*)malloc(sizeof(listNode));	//동적 메모리 할당 
   strcpy(newnode -> data, x);		//newnode의 데이터 넣기 
   newnode -> link = L -> head;		//L->head의 주소를 newnode->link로 넣기 
   L -> head = newnode;		//L->head에 newnode 넣기 
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode( linkedList_h *L, listNode *pre, char *x){
   listNode* newNode;	//newnode라는 노드 선언
   newNode = (listNode*)malloc(sizeof(listNode));	//동적 메모리 할당 
   strcpy(newNode -> data, x);		//newnode의 데이터 넣기 
   if (L->head == NULL) {	//노드가 없다면 
      newNode -> link = NULL;	
      L -> head = newNode;
   }
   else if (pre == NULL) {	//pre가 마지막 노드라면 
      L -> head = newNode;
   }
   else {	//노드가 중간에 있다면 
      newNode -> link = pre -> link;	//본래 pre->link를 newnode에게 주고 
      pre -> link = newNode;	//pre에게newnode 주기 
   }
}
// 마지막에 노드를 삽입하는 연산
void insertLastNode( linkedList_h *L, char *x){
   listNode* newNode;	//newnode라는 노드 선언
   listNode* temp;		//temp라는 노드 선언 
   newNode = (listNode*)malloc(sizeof(listNode));	//동적 메모리 할당 
   strcpy(newNode -> data, x);	//newnode의 데이터 넣기 
   if (L -> head == NULL) {		//노드가 없다면 
      L -> head = newNode;		//바로 노드 추가 
      return;
   }
   
   temp = L -> head;	
   while (temp -> link != NULL) temp = temp -> link;	//temp->link가 끝이 아니라면 계속 이동 
   temp -> link = newNode;	//끝이라면 마지막에 노드 추가 
}   
// 리스트에서 x 노드를 탐색하기( page173, 175 )
linkedList_h *searchNode(linkedList_h *L, char *x){
   listNode *temp;		//temp라는 노드 선언 
   temp = L -> head;	//temp는 L의 head 
   while (temp != NULL) {	//노드가 NULL이 아닐 때까지 
      if (strcmp(temp -> data, x) == 0) return temp;	//temp의 데이터와 찾으려는 값을 비교하고 맞으면 temp의 값을 반환 
      else temp = temp -> link;		//뒤로 이동 
   }
   return temp;		//temp 반환 
}
