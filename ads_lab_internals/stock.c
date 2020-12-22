#include<assert.h>
#include<stdint.h>
#include "stock.h"
#include "appconst.h"
#include<stddef.h>

Queue queue_new(int size){
    size = ( size > 0 && size < MAX_COMP ) ? size : MAX_COMP;
    Queue q1 =  { size, 0,0,0,{0} };
    return q1;
}

int queue_full(Queue *q){
    assert( q != NULL );
    return ( q->count == q->size );
}

int queue_empty(Queue *q){
    assert( q != NULL );
    return ( q->count == 0 );
}

Queue* queue_add(Queue *q, tradingQ share, QueueRes *res){
    assert( q != NULL );
    if ( q->count < q->size ){
        q->share1[q->rear] = share;
        q->rear = (q->rear+1)%q->size;
        ++q->count;
//        res->status = QUEUE_OK;
    }else{
        res->status = QUEUE_FULL;
    }
    return q;
}

Queue* queue_delete(Queue *q, QueueRes *res){
    assert( q != NULL );

    if (q->count != 0){
        res->data = q->data[q->front];
        q->front = (q->front+1)%q->size;
        --q->count;
        res->status = QUEUE_OK;
    }else{
        res->status = QUEUE_EMPTY;
    }
    return q;
}

int queue_length(Queue *q){
    assert( q != NULL );
    return q->count;
}

Queue* add_new_share(Queue *q, tradingQ share, QueueRes *res)
{
    if(q->count == MAX_COMP)
    {
       q = queue_delete(q,res);
    }
    else{
        q = queue_add(q,share,res);
    }
}

Queue* look_up(Queue * q, tradingQ share )
{
    assert(q != NULL);
    int i;
    for( int i= q->front; i <= MAX_COMP;i++)
    {
        if(q->share1->share_name == share->share_name)
            break;
    }
    return i;
}
Queue* topup(Queue *q, tradingQ share, int quantity)
{
    assert(q != NULL);
    int i;
    for(i= q->front; i <= MAX_COMP;i++)
    {
        if(q->share1->share_name == share->share_name)
            q->share1->quantity = q->share1->quantity + quantity ;
    }
    return i;

}
