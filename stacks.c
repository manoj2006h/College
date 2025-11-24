#include<stdio.h>
#include<string.h>
#define SIZE 5
int item,top=-1,s[10];
void push() {
    if(top == SIZE-1) {
        printf("Overflow\n");
        return;
    }
    printf("Enter the item : \n");
    scanf("%d",&item);
    top++;
    s[top] = item;
}
int pop() {
    int item_del;
    if(top == -1) {
        return 0;
    }
    item_del = s[top];
    top--;
    return item_del;
}
void display() {
    int i;
    if(top == -1) {
        printf("Stack is empty\n");
    }else {
        for(i=top ; i>=0 ; i--) {
            printf("%d\n",s[i]);
        }
    }
}
int is_palin(char str[]) {
    char s[10],stk_item;
    int i,top1=-1;
    for(i=0 ; i<strlen(str) ; i++) {
        top++;
        s[top] = str[i];
    }
    for(i=0 ; i<strlen(str) ; i++) {
        stk_item = s[top];
        top--;
        if(stk_item != str[i]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char str[10];
    int ch,item_del;
    for(;;) {
        printf("1.push\n2.pop\n3.display\n4.palindrome\n");
        printf("Enter the choice \n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: push();
            break;
            case 2: item_del = pop();
            if(pop() == 0) {
                printf("Underflow\n");
            } else {
                printf("Item deleted is %d\n",item_del);
            }
            break;
            case 3: display();
            break;
            case 4: printf("Enter the string \n");
                    scanf("%s",str);
                    if(is_palin(str) == 1) {
                        printf("Palindrome\n");
                    }else {
                        printf("Not palindrome\n");
                    }
                    break;
            default : printf("Invalid choice \n");
            }
        }
        return 0;
    }