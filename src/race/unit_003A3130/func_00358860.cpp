typedef int s32;

struct Table;

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryV {
    short delta;
    short index;
    void (*fn)(void *, s32);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

struct VObjV {
    char pad0[4];
    VEntryV *vtbl;
};

extern "C" s32 RaceEventQueue__get(Table *t, s32 id, s32 *value, s32 remove);

static inline s32 vcall_1(char *o) {
    VEntry *e = &((VObj *)o)->vtbl[1];
    return e->fn(o + e->delta);
}

extern "C" s32 func_00358860(char *arg0, char *arg1) {
    s32 val;
    s32 r;

    r = RaceEventQueue__get((Table *)(arg1 + 0xF4), vcall_1(arg0), &val, 1);
    if (r != 0) {
        VEntryV *e = &((VObjV *)arg0)->vtbl[3];
        e->fn(arg0 + e->delta, val);
        return 1;
    }
    return r;
}
