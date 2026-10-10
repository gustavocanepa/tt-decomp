typedef int s32;
typedef long long s64;

struct Table {
    char pad0[0xC];
    s32 count;
    s64 ids[1];
};

extern "C" s32 func_003F7B10(Table *t, s64 id) {
    s32 i;
    for (i = 0; i < t->count; i++) {
        if (t->ids[i] == id) {
            return i;
        }
    }
    return -1;
}
