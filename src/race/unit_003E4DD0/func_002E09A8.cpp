extern "C" void *func_002E0A88(void *self, int *key);
extern "C" void func_002DE250(void *item, int *key);
struct Obj { char pad[0x10]; int max; };
extern "C" void *func_002E09A8(Obj *self, int *key)
{
    void *item = func_002E0A88(self, key);
    if (item == 0)
        return 0;
    func_002DE250(item, key);
    if (self->max < *key)
        self->max = *key;
    return item;
}
