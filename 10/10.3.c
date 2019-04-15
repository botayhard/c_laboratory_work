#include<stdio.h>
#include<stdlib.h>

typedef int data_t;

typedef struct list {
    data_t data;
    struct list *next;
} list;

/*void pushforward(list **head, int dat) {
    list *tmp = (list*) malloc(sizeof(list));
    tmp->data = dat;
    tmp->next = (*head);
    (*head) = tmp;
}

void pushmiddle(list *prev, int dat) {
    list *tmp = NULL;
    tmp = (list*) malloc(sizeof(list));
    tmp->data = dat;
    tmp->next = prev->next;
    prev->next = tmp;
}

list* getLast(list *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void pushBack(list *head, int value) {
    list *last = getLast(head);
    list *tmp = (list*) malloc(sizeof(list));
    tmp->data = value;
    tmp->next = NULL;
    last->next = tmp;
}*/

void push(list **head, list **prev, int dat) {
    list *tmp = NULL;
    tmp = (list *) malloc(sizeof(list));
    tmp->data = dat;//0)
    if (NULL != *prev) {
        tmp->next = (*prev)->next;
        (*prev)->next = tmp;
    } else {
        tmp->next = (*head);
        (*head) = tmp;
    }
}

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
        list *temp = head, *prev = NULL;
        while (temp->data < t) {
            prev = temp;
            temp = temp->next;
            if(!temp) break;
        }
        if (NULL != temp) {
            if (t == (temp->data)) continue;
        }
        push(&head, &prev, t);

    }

    list *r = head;
    while (NULL != r) {
        printf("%d ", r->data);
        r = r->next;
    }
    deleteList(&head);
    return 0;
}