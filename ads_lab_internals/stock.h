#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include "appconst.h"

typedef struct tradingQ tradingQ;
struct tradingQ
{
    char share_name[30];
    char date[20];
    int  price;
    int quantity;
};
typedef struct _queue_ Queue;
struct _queue_ {
    int size;
    int count;
    int rear;
    int front;
    tradingQ share1[MAX_COMP];
};
typedef struct _queue_res_ QueueRes;
struct _queue_res
{
    tradingQ share;
    int status;
};

Queue queue_new(int size);
int queue_full(Queue *q);
int queue_empty(Queue *q);
Queue* queue_add(Queue *q, tradingQ share, QueueRes *res);
Queue* queue_delete(Queue *q, QueueRes *res);
Queue* look_up(Queue * q, tradingQ share );
Queue* topup(Queue *q, tradingQ share, int quantity);
int queue_length(Queue *q);
Queue* add_new_share(Queue *q, tradingQ share, QueueRes *res);
#endif // STOCK_H_INCLUDED
