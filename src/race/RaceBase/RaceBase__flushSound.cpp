/* compiler: ee-gcc2.96-nogcse */
struct List {
    int count;
    int pad4;
    void **items;
};

struct World {
    char pad0[0x60];
    List *cars;
};

struct RaceBase {
    char pad0[0x6C];
    World *world;
};

extern "C" void func_00369670(void *car);

extern "C" void RaceBase__flushSound(RaceBase *self)
{
    World *w = self->world;
    int n = w->cars->count;
    for (int i = 0; i < n; i++)
        func_00369670(w->cars->items[i]);
}
