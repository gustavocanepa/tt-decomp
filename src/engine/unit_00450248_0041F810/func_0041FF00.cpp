typedef int s32;
typedef unsigned short u16;

struct Node {
    s32 unk0;
    s32 value;
};

struct Obj {
    char pad[0x2A];
    u16 count;
    char pad2C[0x58 - 0x2C];
    void *table;
};

extern "C" Node *func_005670D8(s32, void *, s32);

extern "C" s32 func_0041FF00(Obj *self, s32 key) {
    if (self->table == 0)
        return -1;
    Node *n = func_005670D8(key, self->table, self->count);
    if (n == 0)
        return -1;
    return n->value;
}
