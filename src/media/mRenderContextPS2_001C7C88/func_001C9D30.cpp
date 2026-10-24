/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; void (*fn)(void *); };
struct Rect { char pad0[8]; int width; int padC; int x, y, dx, dy; };
struct Obj { int first; Entry *vtbl; char pad[0x1D58-8]; Rect rect; char pad2[0x1C]; int enabled; };
extern "C" int func_001C7860(Obj *) throw();
extern "C" Rect *func_001C7088(int) throw();
extern "C" int func_00104E00(Rect *);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_001C9D30(Obj *self) {
    if (self->enabled != 0) {
        Entry *e = (Entry *)((char *)self->vtbl + 0x268);
        e->fn((char *)self + e->delta);
        Rect *r = func_001C7088(func_001C7860(self));
        float width = (float)r->width;
        float height = (float)func_00104E00(r);
        Rect *rect = &self->rect;
        func_00474520(0.0f, 0.0f, width, height, (float)rect->x, (float)rect->y, (float)(rect->x + rect->dx), (float)(rect->y + rect->dy));
    }
}
