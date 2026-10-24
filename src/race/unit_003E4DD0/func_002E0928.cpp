/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Elem { Elem *next; char pad[0x5c]; };
struct Obj { Elem *elems; int count; int used; Elem *head; int max; };
extern "C" void func_002E0928(Obj *o) {
    o->max=-1;
    o->used=0;
    o->head=o->elems;
    for(int i=0; i<o->count-1; i++) {
        Elem *e = o->elems+i;
        e->next=e+1;
    }
    o->elems[o->count-1].next=0;
}
