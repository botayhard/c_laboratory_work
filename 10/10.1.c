#include<stdio.h>
#include<stdlib.h>

typedef int data_t;

typedef struct list {
    data_t data;
    struct list *next;
} list;

void deleteList(list **head) {
    list *prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

int main() {
    list *p, *head = NULL;
    int i, t, s = 0, c = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (1) {
        i = scanf("%d", &t);
        if (EOF == i) break;
        p = (struct list *) malloc(sizeof(list));
        p->data = t;
        p->next = NULL;
        if (NULL == head) {
            head = p;
            continue;
        }
        list *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    list *r = head;
    while (NULL != r) {
        c++;
        s += r->data;
        r = r->next;
    }
    printf("%d", s / c);
    deleteList(&head);
    return 0;
}