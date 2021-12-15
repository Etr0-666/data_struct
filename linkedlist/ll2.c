#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
typedef Node* node_ptr;

int NumNode(node_ptr L){
    node_ptr current;
    int i=1;
    for(current=L;current->next!=NULL;current=current->next){
        i++;
    }
    return i;
}

void createHead(node_ptr *L,int data){
    *L=(node_ptr)malloc(sizeof(Node));
    (*L)->next=NULL;
    (*L)->data=data;
}



int main(){
    node_ptr L;
    createHead(&L,0);
    node_ptr L2 = L;



    int num=NumNode(L);
    for(int j=0;j<num;j++){
        printf("Node[%d] = %d\n",j,L2->data);
        L2=L2->next;
    }
}
