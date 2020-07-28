
#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
};
int main(void)
{
    int n;
    struct Node *head=NULL;
    struct Node *p1,*p2;
    printf("ÇëÊäÈë£º");
    scanf("%d",&n);
    while(n)
    {
        p1=(struct Node *)malloc(sizeof(struct Node));
        if(head==NULL)
            head=p1;
        else
        {
            p2->next=p1;
        }
         p1->next=NULL;
         p2=p1;
         printf("ÇëÊäÈëÊý×Ö£º");
         scanf("%d",&p1->data);
        n--;
    }
    while(head)
    {
        printf("%d\n", head->data);
        head=head->next;
    }
    system("pause");
    return 0;
}