typedef int s32;

struct Table {
    unsigned char pad0;
    unsigned char count;
    unsigned char pad2[0x12];
    unsigned char ids[1];
};

struct Slot {
    unsigned char idx[0x18];
};

struct Item {
    char data[0x1EC];
};

struct Data {
    char pad[0x454];
    Item items[6];
    Slot slots[1];
};

extern "C" Table *func_002FD378(Data *);

extern "C" Item *func_00308058(Data *self, s32 i, s32 j) {
    Table *t;
    unsigned char k;

    t = func_002FD378(self);
    k = 0;
    if (i < t->count) {
        k = t->ids[i];
    }
    return &self->items[self->slots[k].idx[j]];
}
