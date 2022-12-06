#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size, top, *s;
};

void create(struct stack *st)
{
    printf("Enter size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow..\n");
    else
    {
        st->s[++st->top] = x;
    }
}

int pop(struct stack *st)
{
    if(st->top==-1)
    {
        printf("Stack underflow..\n");
        return -1;
    }
    else
        return st->s[st->top--];
}

int peek(struct stack st, int index)
{
    if(st.top-index+1<0){
        printf("Invalid index..\n");
        return -1;
    }
    return st.s[st.top-index+1];
}

int isEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct stack st)
{
    if(st.top==st.size-1)
        return 1;
    return -1;
}

int stackTop(struct stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return 0;
}

int main()
{
    struct stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    // push(&st,50);

    display(st);
    
    printf("stack peek : %d\n",peek(st,1));

    // pop(&st);
    // display(st);

    // printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));
    // printf("%d \n",pop(&st));

    // push(&st,60);
    // display(st);

    return 0;
}
