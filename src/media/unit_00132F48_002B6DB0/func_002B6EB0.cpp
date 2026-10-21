typedef int s32;

struct Lst {
    char pad0[0x8];
    s32 *items;
    char pad1[0x8];
    s32 count;
};

struct Owner {
    char pad0[0x2C];
    Lst *lst;
};

extern "C" void func_002A7A30(void *a0);
extern "C" void func_002A75A8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002B6EB0(void *arg0, Owner *arg1) {
    s32 buf[4];
    Lst *s2;
    s32 *s1;

    func_002A7A30(buf);
    s2 = arg1->lst;
    s1 = &s2->items[s2->count];
    if (s1 != buf) {
        s32 v = buf[0];
        if (v != 0) {
            func_002C0FE8(v);
        }
        s32 old = *s1;
        if (old != 0) {
            func_002C1050(old);
        }
        *s1 = v;
    }
    s2->count = s2->count + 1;
    func_002A75A8(buf, 2);
}
