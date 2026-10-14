/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; int (*fn)(void *, void *, int, int); };
struct Target { char pad[0x48]; unsigned short flags; short pad4a; char *vt; unsigned int ready() const { unsigned int f = flags; return (f >> 2) & 1; } };
struct Obj { char pad[0x30]; void *other; char pad34[0x648]; Target *target; int state; char pad684[0x18]; int count; };
extern "C" int func_0019B970(void *, void *);
extern "C" void func_00199148(Obj *o) {
    if (o->target) {
        if (func_0019B970(o->target, o->other)) {
            Target *t = o->target;
            if (t->ready()) o->state = 3;
            else {
                Entry *e = (Entry *)(t->vt + 0x28);
                o->state = e->fn((char *)t + e->delta, o->other, 0, 0);
            }
        } else o->state = 1;
    }
    o->count++;
}
