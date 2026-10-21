/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { char pad[0x10]; E *next; };
struct E2 { char pad[0x5454]; s32 key; };
struct N { N *next; s32 k4; s32 k8; void *e; };
struct L { char pad[0x14]; E *first; };
struct A1 { char pad[0x60]; L *l; char pad2[0xC]; void *f70; };
struct A0 { char pad[0x500]; N nodes[1]; };
extern "C" int func_0040F140(void *, s32);

struct Q { char pad[0x86C]; N *head; };

extern "C" void func_0037F578(Q *arg0, A1 *arg1, s32 flag) {
    s32 i = 0;
    arg0->head = 0;
    E *e = arg1->l->first;
    void *f70 = arg1->f70;
    if (e) {
        N *n = (N *)((char *)arg0 + 0x80C);
        do {
            s32 k = ((E2 *)e)->key;
            s32 r = func_0040F140(f70, i);
            n->k4 = k;
            s32 v = k + r;
            n->e = e;
            n->k8 = v;
            n->next = 0;
            s32 key = flag ? v : k;
            N *prev = 0;
            N *head = arg0->head;
            N *cur = head;
            while (cur) {
                s32 ck = flag ? cur->k8 : cur->k4;
                if (ck < key) break;
                prev = cur;
                cur = cur->next;
            }
            if (prev) {
                prev->next = n;
                n->next = cur;
            } else {
                n->next = head;
                arg0->head = n;
            }
            e = e->next;
            n++;
            i++;
        } while (e);
    }
}
