/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct VEntry { short adj; short pad; void (*fn)(void *, int, void *); };
struct Ramp { int mode; int limit; int step; int value; };
struct Obj {
    int flags;
    char pad04[0x14];
    int current;          /* 0x18 */
    char pad1c[0x218];
    int callback;         /* 0x234 */
    char pad238[0x14];
    Ramp ramp;            /* 0x24C */
    char pad25c[0x0];
};
struct Owner { char pad00[0x60]; int active; char *vtable; };
extern "C" void func_004C5768(void *, void *);
extern "C" void func_004C6970(void *, int, void *);
extern "C" void func_004C66C8(Owner *o) {
    if (o->active != 0) {
        Ramp *r = (Ramp *)((char *)o + 0x24C);
        void *cb = (char *)o + 0x234;
        int mode = r->mode;
        if (mode != -1) {
            int value = r->value;
            switch (mode) {
            case 0:
                value += r->step;
                if (!(value < r->limit)) {
                    r->mode = -1;
                    value = r->limit;
                }
                break;
            case 1:
                value -= r->step;
                if (!(r->limit < value)) {
                    r->mode = -1;
                    value = r->limit;
                }
                break;
            case 2:
                value -= r->step;
                if (!(r->limit < value)) {
                    r->mode = -1;
                    if (*(int *)cb != 0) {
                        func_004C6970(o, 1, cb);
                    } else {
                        VEntry *e = (VEntry *)(o->vtable + 0x18);
                        e->fn((char *)o + e->adj, 1, cb);
                    }
                }
                break;
            }
            r->value = value;
            *(int *)((char *)o + 0x18) = value;
            *(int *)o |= 1;
            func_004C5768(o, o);
        }
    }
}
