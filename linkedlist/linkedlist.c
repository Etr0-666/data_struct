#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
    int data;
    struct linknode *next;
}node;
typedef node *node_ptr;
/*
void printLinkedlist(node_ptr linkedlist){
    int count = NumNode(linkedlist);
    node_ptr current = linkedlist;
    for(int j=0;j<count;j++){
        printf("Node No.%d = %d\n",j,current->data);
        current=current->next;
    }
}
*/
//新建表头
node_ptr NewList(int data){
    node_ptr head = NULL;
    head = (node*)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
    return head;
}
//向后增加node
void addNode(node_ptr linkedlist,int data){
    node_ptr current;
    for(current=linkedlist;current->next!=NULL;current=current->next);
    node_ptr newNode = (node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    current->next=newNode;
}
//学霸题 数节点
int NumNode(node_ptr linkedlist){
    node_ptr current;
    int i=1;
    for(current=linkedlist;current->next!=NULL;current=current->next){
        i++;
    }
    return i;
}
//更改节点data
int changeData(node_ptr linkedlist,int i,int data){
    node_ptr current = linkedlist;
    int length = NumNode(linkedlist);
    if(i>length-1){return 0;}
    for(int j=0;j<i;j++){
        if(current->next!=NULL){
            current=current->next;
        }
        else{
            break;
        }
    }
    current->data=data;
}
//头部插入
void insertData_Head(node_ptr *linkedlist,int data){
    node_ptr newNode;
    newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=*linkedlist;
    *linkedlist=newNode;
}
/*
void insertData_End(node_ptr linkedlist,int data){
    node_ptr current,newNode;
    for(current=linkedlist;current->next!=NULL;current=current->next);
    newNode = (node*)malloc(sizeof(node));

} 这和addNode有什么区别
*/
//中部插入
int insertData_Mid(node_ptr linkedlist,int i,int data){
    int length=NumNode(linkedlist);
    if(i>length){return 0;}
    if(i==length){
        addNode(linkedlist,data);
        return 0;
    }
    node_ptr newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    node_ptr current = linkedlist;
    int j=0;
    for(j;j<i-1;j++){current=current->next;}
    newnode->next=current->next;
    current->next=newnode;
    current=current->next;
    return 0;
}

int Insert(node_ptr *linkedlist,int i,int data){
    if(i==0){
        node_ptr New=(node*)malloc(sizeof(node));
        New->data=data;
        New->next=*linkedlist;
        *linkedlist=New;
        return 1;
    }
    int j=0;
    node_ptr current=*linkedlist;
    while(current&&j<i-1){
        current=current->next;
        j++;
    }
    if(i>j){return 0;}
    if(current->next==NULL){
        node_ptr New=(node*)malloc(sizeof(node));
        New->data=data;
        New->next=NULL;
        current->next=New;
        return 1;
    }
    node_ptr New=(node*)malloc(sizeof(node));
    New->data=data;
    New->next=current->next;
    current->next=New;
    return 1;
}

int delete_node(node_ptr linkedlist,int i){
    int length=NumNode(linkedlist);
    if(i>length-1){return 0;}
    node_ptr current=linkedlist;
    int j=0;
    for(j;j<i-1;j++){
        current=current->next;
    }
    node_ptr pending = current->next;
    if(i==length-1){
        current->next=NULL;
    }else{
        current->next=pending->next;
    }
    free(pending);
    return 1;
}

int searchValue(node_ptr linkedlist,int value,int *i){
    int j=0;
    int length=NumNode(linkedlist);
    node_ptr current=linkedlist;
    for(j;j<length;j++){
        if(current->data==value){
            *i=j;
        }
        current=current->next;
    }
    if(current==NULL){return 0;}
    return 1;
}

int getValue(node_ptr linkedlist,int i,int *data){
    if((i<0)){return 0;}
    int j=0;
    node_ptr current=linkedlist;
    for(j;j<i;j++){
        current=current->next;
        if(current==NULL){return 0;}
    }
    *data=current->data;
    return 0;
}

void deleteLinkedlist(node_ptr linkedlist){
    node_ptr current=linkedlist;
    node_ptr nextNode=current->next;
    do{
        free(current);
        if(nextNode==NULL){break;}
        current=nextNode->next;
        if(current==NULL){break;}
        nextNode=current->next;
    }while(1);
}

int main(){
    int data=1;
    int data2=2;
    int i=2;
    int data3=3;
    node_ptr new = NewList(0);
    int status = Insert(&new,2,2);
    printf("%d\n",status);
    /*
    changeData(new,0,0);
    addNode(new,1);
    int ii;
    int status=searchValue(new,0,&ii);
    printf("%d\n",ii);
    status=getValue(new,11,&ii);
    printf("%d\n",status);
    */
    /*
    addNode(new,data2);
    insertData_Mid(new,2,3);
    //printLinkedlist(new);
    changeData(new,0,3);
    insertData_Mid(new,2,4);
    insertData_Mid(new,4,5);
    delete_node(new,3);
    */

    int count = NumNode(new);
    node_ptr new2 = new;
    for(int j=0;j<count;j++){
        printf("Node[%d] = %d\n",j,new2->data);
        new2=new2->next;
    }
    //deleteLinkedlist(new);
    /*
    addNode(new,data2);
    printf("%d\n",new->next->data);
    changeData(new,i,data3);
    printf("%d\n",new->next->data);
    */
}
