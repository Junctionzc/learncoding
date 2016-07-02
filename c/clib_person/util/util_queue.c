#include <stdio.h>
#include <stdlib.h>

typedef unsigned char ElementType;

struct QueueRecord {
    int capacity;
	int front;
	int rear;
	int size;
	ElementType *p_array;	
};
typedef struct QueueRecord *Queue;

Queue create_queue(int max_elements);
void destroy_queue(Queue q);
void enqueue(Queue q, ElementType element);
ElementType dequeue(Queue q);
int is_empty(Queue q);
int is_full(Queue q);
ElementType front(Queue q);

int main()
{
	Queue q = create_queue(2);
	
	enqueue(q, 'a');
	enqueue(q, 'b');
	enqueue(q, 'c');
	
	printf("dequeue:%c\n", dequeue(q));
	printf("dequeue:%c\n", dequeue(q));
	printf("dequeue:%c\n", dequeue(q));
	
	destroy_queue(q);
	
	return 0;
}

Queue create_queue(int max_elements)
{
	if (max_elements < 1) {
		return NULL;
	}
	
	Queue q = (Queue)malloc(sizeof(struct QueueRecord));
	if (q == NULL) {
		printf("q malloc error\n");
		return NULL;
	}
	
	q->capacity = max_elements;
	q->size = 0;
	q->front = q->rear = 0;
	q->p_array = (ElementType *)malloc(sizeof(ElementType) * max_elements);
	if (q->p_array == NULL) {
		printf("q->p_array malloc error\n");
		return NULL;
	}
	
	return q;
}

void destroy_queue(Queue q)
{
	if (q == NULL) {
		return;
	}
	free(q->p_array);
	free(q);
}

void enqueue(Queue q, ElementType element)
{
	if (q == NULL) {
		return;
	}
	
	if (is_full(q)) {
		printf("queue is full\n");
		return;
	}
	
	q->p_array[q->rear] = element;
	q->size++;
	q->rear = (q->rear + 1) % q->capacity;
}

ElementType dequeue(Queue q)
{
	ElementType element;
	
	if (q == NULL) {
		return;
	}
	
	if (is_empty(q)) {
		printf("queue is empty\n");
		return;
	}
	
	element = front(q);
	
	q->size--;
	
	q->front = (q->front + 1) % q->capacity;
	
	return element;
}

int is_empty(Queue q)
{
	return (q->size <= 0);
}

int is_full(Queue q)
{
	return (q->size >= q->capacity);
}

ElementType front(Queue q)
{
	return q->p_array[q->front];
}