#include <stdio.h>
#include <stdlib.h>

typedef struct node *ptrToNode;
typedef ptrToNode stack;
struct node
{
    char element;
    ptrToNode next;
};

int isAppropriate(char []);
int isEmpty(stack);
stack creatStack();
void printStack(stack);
void makeEmpty(stack);
void pop(stack);
char top(stack);
void push(char, stack);
void DisposeStack(stack);
int isItsClose(char , char );
int isEmpty(stack s){
    return s->next == NULL;
}

stack creatStack(){
    stack s;
    s = (ptrToNode)malloc(sizeof(struct node));
    if(s == NULL)
        printf("The memory is Full");
    else{
        s->next = NULL;
        makeEmpty(s);
    }
    return s;
}

void makeEmpty(stack s){

    if(s == NULL)
        printf("The memory is Full");
    else{
        while(!isEmpty(s)){
            pop(s);
        }
    }
}

void pop(stack s){
    ptrToNode p = s->next;
    if(isEmpty(s))
     printf("Empty stack");
    else{
        s->next = s->next->next;
        free(p);
    }
}

char getTop(stack s){
    if(!isEmpty(s))
        return s->next->element;
    printf("Empty stack");
        return 0;
}

void push(char x , stack s){
    ptrToNode p;
    p =  (ptrToNode)malloc(sizeof(struct node));
    if(p == NULL)
    printf("The memory is full");
    else{
         p->next = s->next;
        s->next = p;
        p->element = x;
    }
}

void DisposeStack( stack s ){
makeEmpty( s );
free( s );
}

void printStack(stack s){
    ptrToNode p = s->next;
    if (s->next == NULL || s == NULL)
    {
        printf("The list is empty");
    }
    else{
         while(p != NULL){
        printf("%c  ", p->element);
        p = p->next;
    }
    }
   
}

int main(){
    char c1[50] = {"<>{(})()"};
    printf("<>{(})() :               %d\n", isAppropriate(c1));
    char c2[50] = {"<>({<[]>})<>(){}"};
    printf("=========================== \n");
    printf("<>({<[]>})<>(){}  :      %d\n", isAppropriate(c2));
    char c3[50] = {"<>({<[]>})<>(){}("};
    printf("=========================== \n");
    printf("<>({<[]>})<>(){}(  :     %d\n", isAppropriate(c3));
    char c4[50] = {"<({<[]>})<>(){}()"};
    printf("=========================== \n");
    printf("<({<[]>})<>(){}(  :      %d\n", isAppropriate(c4));
    char c5[50] = {"<>({<[]>})<>(){}({)}"};
    printf("===========================\n");
    printf("<>({<[]>})<>(){}({)}  :  %d\n", isAppropriate(c5));
    char c6[50] = {"<>({<[]>})<>(){}({}){({<>})}"};
    printf("===========================\n");
    printf("<>({<[]>})<>(){}({}){({<>})}  :  %d\n", isAppropriate(c6));

    return 0;
}

int isAppropriate(char c [] ){
    stack s = creatStack();
    int i = 0;
    while(c[i] != '\0'){
        // Just to look out for the pracitce , if the user entetred any thing else the stasck won't gaf ;
        if(c[i] == ')' || c[i] == ']' || c[i] == '}' || c[i] == '>' || c[i] == '(' || c[i] == '[' || c[i] == '{' || c[i] == '<'){
            push(c[i],s);
             char c1 = c[i];
             if (c[i] == ')' || c[i] == ']' || c[i] == '}' || c[i] == '>'){
                 pop(s);
                 // if the sympole has it's close it will cmove on ;
                 if(isItsClose(getTop(s) , c1)){
                pop(s);
            }
                else
                break;
            }
        }
            i++;
    }
    return (isEmpty(s)) ? 1 : 0;
}
int isItsClose(char c1 , char c2){
    return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '<' && c2 == '>'))? 1 : 0;
}
