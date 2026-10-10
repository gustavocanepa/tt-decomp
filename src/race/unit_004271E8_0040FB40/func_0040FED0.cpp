typedef long long s64;
typedef unsigned long long u64;
struct Rec { char b[24]; };
extern char D_00585A30[];
extern "C" bool func_0040B940(void *db, int key, int type, Rec *out);

extern "C" bool func_0040FED0(u64 id, Rec *out) {
    Rec rec;
    if (!func_0040B940(D_00585A30, id & 0xFFFFFFFF, 0x22, &rec))
        return false;
    *out = rec;
    return true;
}
