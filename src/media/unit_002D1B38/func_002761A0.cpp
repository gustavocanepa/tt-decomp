/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Widget { char pad[0xDC]; float origin; };
struct Obj { int word; int horizontal; char p8[0xc]; float value; char p18[0x14]; Widget *parent; Widget *child; };
struct Event { char pad[0x20]; float x, y; };
extern "C" float func_00205D10(Widget *);
extern "C" float func_00205D70(Widget *);
extern "C" void func_002063E0(Widget *, float *, float *, float *, float *);
extern "C" float func_00276008(Obj *) throw();
extern "C" int func_002761A0(Obj *self, int unused, Event *ev) {
    float x, y, w, h;
    float base, delta;
    if (!self->parent) return 1;
    if (!self->child) return 1;
    {
        func_002063E0(self->parent, &x, &y, &w, &h);
        Widget *child = self->child;
        base = child->origin;
        float max;
        if (self->horizontal) {
            delta = ev->x - x;
            max = w - func_00205D10(child) + base;
        } else {
            delta = ev->y - y;
            max = h - func_00205D70(child) + base;
        }
        float v = delta;
        if (v < base) v = base;
        if (max < v) v = max;
        base = v - base;
        base /= func_00276008(self);
        self->value = base;
    }
    return 1;
}
