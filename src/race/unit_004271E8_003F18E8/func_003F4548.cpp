extern char D_005D8588[];
extern "C" void func_0046F0F8(int code);

struct Obj {
    int a;
    void *vt;
    int b;
    int slots[8];
    int owner;
};

extern "C" void func_003F4548(Obj *self, int owner)
{
    self->owner = owner;
    self->a = 0;
    self->b = 0;
    self->vt = D_005D8588;
    for (int i = 7; i >= 0; i--)
        self->slots[i] = 0;
    if (self->owner == 0)
        func_0046F0F8(100);
}
