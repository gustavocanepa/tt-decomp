/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; int (*fn)(char *, int, int); };
struct VE2 { short adj; short pad; int (*fn)(char *, int); };
struct VT { char pad[0x38]; VE2 e38; VE e40; };
struct Obj { char pad[0xA4]; VT *vt; };
struct Node { Obj *obj; int pad; Node *next; };
extern Node *D_0058C588;
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern char D_0058C558[];
extern "C" int func_0047C6E8(int a0, int a1) {
    int r = 0;
    Node *n;
    func_004A4D68(D_0058C558);
    n = D_0058C588;
    if (n != 0) {
        do {
            Obj *o = n->obj;
            VE2 *e = &o->vt->e38;
            if (e->fn((char *)o + e->adj, a0) != 0) {
                VE *e2 = &o->vt->e40;
                r = e2->fn((char *)o + e2->adj, a0, a1);
                break;
            }
            n = n->next;
        } while (n != 0);
    }
    func_004A4DD8(D_0058C558);
    return r;
}
