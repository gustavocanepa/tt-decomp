struct Item {
    char pad[0x1C];
};

struct Obj {
    char pad[0x68];
    Item items[16];
};

extern "C" void func_004C5D50(Item *);

extern "C" void func_00574880(Obj *self) {
    for (int i = 0; i < 16; i++)
        func_004C5D50(&self->items[i]);
}
