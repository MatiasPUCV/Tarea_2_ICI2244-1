#ifndef LIST_H
#define LIST_H
typedef struct Node Node;

struct Node
{
  void *data;
  Node *next;
  Node *prev;
};

struct List
{
  Node *head;
  Node *tail;
  Node *current;
};

typedef struct List List;

List* createList(void);
void cleanList(List* list);

void* firstList(List* list);
void* nextList(List* list);
void* lastList(List* list);
void* prevList(List* list);

void pushFront(List* list, void* data);
void pushBack(List* list, void* data);
void pushCurrent(List* list, void* data);

void* popFront(List* list);
void* popBack(List* list);
void* popCurrent(List* list);

#endif // LIST_H