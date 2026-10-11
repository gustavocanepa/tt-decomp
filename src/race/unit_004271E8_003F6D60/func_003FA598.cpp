struct Item {
    char pad[0x238];
};

struct ItemList {
    int pad0;
    Item *items;
    int count;
};

extern "C" void func_003F9B40(Item *item);
extern "C" void func_003F9A88(Item *item);

extern "C" void func_003FA598(ItemList *l, Item *items, int count, int selected) {
    l->items = items;
    l->count = count;
    for (int i = 0; i < l->count; i++) {
        if (i == selected)
            func_003F9B40(&l->items[i]);
        else
            func_003F9A88(&l->items[i]);
    }
}
