/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Under the pool lock, takes a free record of the 48-entry table D_0059C0E0 (used == 0, set up by
   func_004C4D10); when none is free, recycles the one with the smallest age below 'limit'
   (func_004C4CB0 then func_004C4D10). Returns the record or 0. */
typedef int s32;
struct Rec { char pad0[0x14]; s32 used; char pad18[0xC]; s32 age; char pad28[0xC]; };
extern Rec D_0059C0E0[48];
extern char D_005A0B88[];
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);
extern "C" void func_004C4D10(Rec *);
extern "C" void func_004C4CB0(Rec *, s32);
extern "C" Rec *func_004C4FE8(s32 limit) {
    Rec *found = 0;
    Rec *tbl = D_0059C0E0;
    func_004A4930(D_005A0B88);
    s32 i = 0;
    Rec *p = tbl;
    while (i < 48) {
        i++;
        if (p->used == 0) {
            func_004C4D10(p);
            found = p;
            break;
        }
        p++;
    }
    if (!found) {
        p = tbl;
        s32 best = limit;
        for (s32 n = 47; n >= 0; n--, p++) {
            if (p->age < best) {
                best = p->age;
                found = p;
            }
        }
        if (found) {
            func_004C4CB0(found, 0);
            func_004C4D10(found);
        }
    }
    func_004A4970(D_005A0B88);
    return found;
}
