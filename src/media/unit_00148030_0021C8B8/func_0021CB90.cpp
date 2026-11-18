/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, int, float); };
struct Target { int word; char *vt; };
struct Obj {
    char pad0[0x4C];
    void *widget;
    Target *target;
    char pad1[8];
    float x, y, w, h, value;
};
extern "C" void func_00205C80(void *, float);
extern "C" void func_00205CE0(void *, float);
extern "C" void func_00205D40(void *, float);
extern "C" void func_00205DA0(void *, float);
extern "C" void func_0021CB90(Obj *o) {
    if (o->widget) {
        func_00205C80(o->widget, o->x);
        func_00205CE0(o->widget, o->y);
        func_00205D40(o->widget, o->w);
        func_00205DA0(o->widget, o->h);
    }
    Target *t = o->target;
    if (t) {
        VEntry *e = (VEntry *)(t->vt + 0x2A0);
        e->fn((char *)t + e->delta, -1, o->value);
    }
}
