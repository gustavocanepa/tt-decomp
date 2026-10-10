struct Group {
    char pad0[0x14];
    unsigned short count;
    short pad16;
    void **items;
};

extern "C" void func_003F5108(void *item, float t);

extern "C" void func_003F4B40(Group *g, float t)
{
    for (int i = 0; i < g->count; i++)
        func_003F5108(g->items[i], t);
}
