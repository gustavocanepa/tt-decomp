/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; };
struct Pool { Node *head; Node *tail; Node *x; Node **xp; char *cursor; int size,count; void *vt; };
extern char D_005DB400[];
extern "C" void *malloc(int) throw();
extern "C" void fpool__structor_0(Pool *self,int size,int count) {
 int stride=size+4;
 self->size=size; self->vt=D_005DB400; self->count=count;
 char *data=(char *)malloc(stride*count);
 self->head=0; int total=self->count; self->cursor=data; int i=0;
 self->tail=(Node *)self; self->x=0; self->xp=&self->x;
 if(total>0) do {
 Node *node=(Node *)self->cursor;
 node->next=0;
 self->tail->next=node;
 self->tail=node;
 self->cursor+=stride;
 i++;
 } while(i<self->count);
}
