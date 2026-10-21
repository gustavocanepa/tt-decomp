/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; int id; int value; int zero; int result; };
struct Lock { Node *head; Node *tail; char pad[16]; int owner; int priority; int count; int level; };
extern "C" int func_004FA710();
extern "C" int func_004FA6B0(int,int);
extern "C" void func_004FA740();
extern "C" int func_005038D8();
extern "C" void func_004A49F8(Lock *self,int flag) {
    Node node;
    int neg=-1;
    int one=1;
    int id=func_004FA710();
    int prior, irq, wait, old;
    goto acquire;
    do {
        if(flag) func_004FA6B0(id,prior);
        func_004FA740();
acquire:
        prior=neg;
        if(flag) prior=func_004FA6B0(id,1);
        irq=func_005038D8();
        old=self->count;
        wait=0;
        if(old==0) {
            self->owner=id;
            self->count=one;
        } else if(id==self->owner) {
            self->count=old+1;
        } else {
            Node *tail=self->tail;
            node.next=0;
            node.id=id;
            node.value=neg;
            node.zero=0;
            node.result=neg;
            if(tail) tail->next=&node;
            else self->head=&node;
            self->tail=&node;
            wait=1;
        }
        if(flag && !wait && self->level<0) {
            self->level=old;
            self->priority=prior;
        }
        if(irq) __asm__ volatile("ei");
    } while(wait);
}
