struct Obj {
    char pad0[0x14];
    void *items[5];
};

extern "C" void func_0041F510(void *item, void *arg, int flag);

extern "C" void func_0041F700(Obj *self, void *arg)
{
    for (int i = 0; i < 5; i++)
        func_0041F510(self->items[i], arg, i == 2 || i == 3);
}
