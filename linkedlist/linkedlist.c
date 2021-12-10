#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
    int data;
    struct linknode *next;
}node;
typedef node *node_ptr;
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
int countNode(node_ptr linkedlist){
    node_ptr current;
    int i=1;
    for(current=linkedlist;current->next!=NULL;current=current->next){
        i++;
    }
    return i;
}
//更改节点data
void changeData(node_ptr linkedlist,int i,int data){
    node_ptr current = linkedlist;
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

} 这和add有什么区别
*/
//中部插入
void insertData_Mid(node_ptr linkedlist,int i,int data){
    int length=countNode(linkedlist);
    if(i==length) addNode(linkedlist,data);
}

int main(){
    int data=1;
    int data2=2;
    int i=2;
    int data3=3;
    node_ptr new = NewList(data);
    addNode(new,data2);
    int count = countNode(new);
    node_ptr new2 = new;
    for(int j=0;j<count;j++){
        printf("Node No.%d = %d\n",j,new2->data);
        new2=new2->next;
    }
    /*
    addNode(new,data2);
    printf("%d\n",new->next->data);
    changeData(new,i,data3);
    printf("%d\n",new->next->data);
    */
}
