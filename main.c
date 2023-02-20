#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF 100

typedef struct book
{
int *year;
char *title;
struct book *next;
}book;
char* input_string (char *message)
{
char *buff = (char*)malloc(BUFF*sizeof(char));
printf("input %s:\t", message); scanf("%s", buff);
char *result = (char*)malloc((strlen(buff)+1)*sizeof(char));
strcpy(result, buff);
free (buff);
return result;
}
book *init(char *title, int *year)
{
book *temp = (book *) malloc(sizeof(book));
temp->title = title;
temp->year = year;
temp->next = NULL;
return temp;
}




void print(book *h)
{
if(h == NULL)
{
return;
}
else
{
book *temp = h;
do
{
printf("%s", temp->title);
printf(" - %d\n", *(temp->year));
temp = temp->next;
}while(temp);
return ;
}
}

int keycmp(book *a, book *b)
{
if (*(a->year) < *(b->year)) return 1;
if(*(a->year) == *(b->year) &&(strcmp(a->title, b->title) < 0)) return 1;
return 0;
}


void add(char *title, int *year, book *h)
{
book *temp = (book*)malloc(sizeof(book));
    while(h->next!=NULL) h=h->next;
    h->next=temp;
    temp->title=title;
    temp->year=year;
    temp->next = NULL;
}


void is_sorted(book *h){
int a=1, d=1;
book *t = h;
while(h->next)
{
if(keycmp(t, h->next))
d=0;
else a=0;
h=h->next; t=t->next;
}
    if(a) printf("sorted in ascending order");
    else{ if(d) printf("sorted in descending order");
        else printf("not sorted");}
    printf("\n");
}



void delete_h(book **h)
{
if(h == NULL)
{
return;
}
else
{
book *t = *h;
*h = (*h)->next;
free(t->title);
free(t->year);
free(t);
}
}


void delete_all(book **h)
{
book *temp;
while(*h)
{
temp = (*h)->next;
free((*h)->title);
free((*h)->year);
free(*h);
*h = temp;
}
*h = NULL;
return;
}




int main()
{
int i, n;
printf("Number of books:\n");
scanf("%d", &n);
char *title;
int *year = (int*)malloc(sizeof(int));
title = input_string("title");
printf("input year:\t");
scanf("%d", year);
    
    book *h = init(title, year);
    
    for (i=1; i<n; i++)
        {
        title = input_string("title");
        printf("input year:\t");
        year = (int*)malloc(sizeof(int));
        scanf("%d", year);
        add(title, year, h);
        }
        printf("\n");
        print(h);
    for( ; ; ){
    printf("Select a command:\n 1-add an item to the tail\n 2-remove the head\n 3-check if items are ordered\n 4-print the entire list\n 5-delete all items\n");
    int q;
    scanf("%d", &q);
        if(q==1){
            title = input_string("title");
            printf("input year:\t");
            year = (int*)malloc(sizeof(int));
            scanf("%d", year);
            add(title, year, h);
            print(h);
            printf("\n");
        }
    if(q==2){delete_h(&h);
        print(h);
        printf("\n");
        
    }
    if(q==3){is_sorted(h);}
    if(q==4){print(h);
        printf("\n");}
    if(q==5){delete_all(&h);
        
    }
    }



return 0;
}
