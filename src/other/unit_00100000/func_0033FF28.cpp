typedef int s32;
typedef unsigned char u8;

struct Sub {
    char pad0[0x160];
    u8 c1;
    u8 c2;
    char pad162[3];
    char dirty;
};

struct Car {
    char pad0[0xFD8];
    Sub sub;
};

struct List {
    s32 count;
    char pad4[4];
    Car **items;
};

struct Mgr {
    char pad0[0x60];
    List *list;
    char pad64[0xC];
    s32 id;
};

struct Self {
    char pad0[0x6C];
    Mgr *mgr;
};

struct Buf {
    s32 w[8];
};

extern "C" s32 func_0040CFE0(Sub *arg0);
extern "C" s32 func_0040DE88(Sub *arg0);
extern "C" s32 func_0040DEC8(Sub *arg0);
extern "C" void func_0040E4A0(Sub *arg0, s32 arg1);
extern "C" s32 func_0040F0F8(s32 arg0);
extern "C" void func_00411E18(Buf *arg0);
extern "C" void func_00411E38(Buf *arg0, int arg1);
extern "C" s32 func_00411ED0(Buf *arg0, s32 arg1);
extern "C" s32 func_00412108(Buf *arg0, s32 arg1, s32 arg2);

extern "C" void func_0033FF28(Self *self) {
    Mgr *mgr = self->mgr;
    s32 mode = -1;
    s32 count;
    s32 i;
    Buf buf;

    switch (func_0040F0F8(mgr->id)) {
    case 2:
        mode = 11;
        break;
    case 3:
        mode = 12;
        break;
    }
    count = mgr->list->count;
    func_00411E18(&buf);
    for (i = 0; i < count; i++) {
        Sub *sub = &mgr->list->items[i]->sub;
        s32 c1;
        s32 c2;
        s32 t1;
        s32 t2;
        if (sub->dirty) {
            c1 = sub->c1;
            c2 = sub->c2;
        } else {
            c1 = func_0040DE88(sub);
            c2 = func_0040DEC8(sub);
        }
        if (mode == -1) {
            t1 = c1;
            t2 = c2;
        } else {
            t1 = t2 = mode;
        }
        if (c1 != t1 || c2 != t2 || sub->dirty) {
            sub->dirty = 0;
            if (func_00411ED0(&buf, func_0040CFE0(sub)) != 0) {
                s32 r = func_00412108(&buf, 0x19, t1);
                if (r != -1) {
                    func_0040E4A0(sub, r);
                }
                r = func_00412108(&buf, 0x1A, t2);
                if (r != -1) {
                    func_0040E4A0(sub, r);
                }
            }
        }
    }
    func_00411E38(&buf, 2);
}
