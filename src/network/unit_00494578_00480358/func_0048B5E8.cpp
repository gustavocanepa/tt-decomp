/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj {
    char pad0[4];
    void *unk4;
    char pad8[0x48];
    u32 unk50;
    u32 unk54;
    u32 unk58;
    u32 unk5C;
};
struct Ent { char pad[8]; char *unk8; };
extern "C" Ent *func_00487850(void *, u32) throw();
extern "C" void func_00487A00(void *, Ent *) throw();
struct U16 { u16 v; } __attribute__((packed));
static inline void put16(char *p, u16 v) { ((U16 *)p)->v = v; }
extern "C" s32 func_0048B5E8(Obj *arg0, u32 arg1, u16 arg2) {
    u32 q = (arg1 * 2) / arg0->unk50;
    u32 r = (arg1 * 2) % arg0->unk50;
    u32 i = 0;
    int result = 0;
    if (__builtin_expect((int)arg0->unk58, 0)) {
        do {
            Ent *e = func_00487850(arg0->unk4, arg0->unk54 + i * arg0->unk5C + q);
            i++;
            result = -5;
            if (e == 0) return result;
            char *p = e->unk8 + r;
            put16(p, arg2);
            func_00487A00(arg0->unk4, e);
            result = 0;
        } while (i < arg0->unk58);
    }
    return result;
}
