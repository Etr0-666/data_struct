#include<stdio.h>
int *test(){
    int a=1;
    int *b=&a;
    return b;
}

int main(){
    int *b=test();
    printf("%d",*b);
}