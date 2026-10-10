typedef int s32;

struct Key {
    s32 a, b;
};

struct Obj {
    char pad[0x2408];
    s32 flag;
};

extern "C" void *func_004F4E58(const void *, const void *, s32, s32, s32 (*)(const void *, const void *));
extern "C" s32 func_003F6328(const void *, const void *);

extern "C" s32 func_003F6350(Obj *self, Key key, void *table, s32 count) {
    if (self->flag != 0)
        return 1;
    return func_004F4E58(&key, table, count, 8, func_003F6328) != 0;
}
