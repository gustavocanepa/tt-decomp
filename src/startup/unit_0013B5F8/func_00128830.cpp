struct Obj { char pad[0x184]; int key; };
struct Handle;
extern "C" {
void func_00128470(Handle *h, void *src);
void func_00128418(Handle *h, int flags);
}
struct Handle {
    Obj *p;
    int pad[3];
    Handle(void *x) { func_00128470(this, x); }
    ~Handle() { func_00128418(this, 2); }
    Obj *operator->() { return p; }
};

extern "C" int func_00128830(void *x, void *y)
{
    Handle a(x);
    int ka = a->key;
    Handle b(y);
    return ka < b->key;
}
