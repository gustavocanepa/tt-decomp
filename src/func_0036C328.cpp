/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Link { short next; short time; int key; };
struct Table { union { Link links[1]; struct { int pad[2]; int head; int func_00575DA0; } h; } u; };
extern "C" void func_0036C328(Table *t) {
    int i = t->u.h.head;
    int prev = -1;
    while (i >= 0) {
        Link *p = &t->u.links[i];
        if (--p->time == 0) {
            if (prev >= 0) {
                t->u.links[prev].next = p->next;
            } else {
                t->u.h.head = p->next;
            }
            p->next = t->u.h.func_00575DA0;
            t->u.h.func_00575DA0 = i;
        } else {
            prev = i;
        }
        i = t->u.links[i].next;
    }
}
