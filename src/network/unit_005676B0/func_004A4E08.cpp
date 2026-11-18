/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; int id; int value; int count; int level; };
struct Lock { char pad[8]; Node *head; Node *tail; char pad10[8]; int owner; int value; int count; int level; };
extern "C" int func_004FA710();
extern "C" int func_005038D8();
extern "C" int func_004A4C20(Lock *, int) throw();
extern "C" void func_004A49F8(Lock *, int) throw();
extern "C" void func_004FA740();
static inline void restore_irq(int enabled) { if(enabled) __asm__ volatile("ei"); }
extern "C" void func_004A4E08(Lock *self) {
    Node node;
    int id=func_004FA710();
    int skip=0;
    int irq=func_005038D8();
    int count=self->count;
    if(count==0) skip=1;
    else if(id!=self->owner) skip=1;
    else {
        node.next=0;
        node.id=id;
        node.value=self->value;
        node.count=count;
        node.level=self->level;
        Node *tail=self->tail;
        if(tail) tail->next=&node;
        else self->head=&node;
        self->tail=&node;
        self->value=-1;
        self->count=1;
        self->level=-1;
    }
    restore_irq(irq);
    if(!skip) {
        if(func_004A4C20(self,0)==0) func_004FA740();
        func_004A49F8(self,0);
        self->value=node.value;
        self->count=node.count;
        self->level=node.level;
    }
}
