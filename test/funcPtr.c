#include<stdio.h>
void test(int *a){
    *a=1;
}
int main(){
    int a;
    test(&a);
    printf("%d",a);
}