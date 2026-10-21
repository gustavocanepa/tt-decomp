/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Node { char pad[0x38]; void *u38; char pad3C[0xC]; s32 u48; };
struct Owner { char pad[0xA8]; char *uA8; char *uAC; };
extern "C" void func_00481508(void *);
extern "C" Node *func_00481598(void);
extern "C" s32 func_004816B0(s32);
extern "C" s32 func_004816D0(s32);
extern "C" void func_004816F0(s32);
extern "C" void func_0047CB90(void *, void *);
extern "C" void func_0047E3E8(s32, void *);
extern "C" void func_0047E4B8(s32, s32);
extern "C" s32 func_0047E208(void *, void *);
extern "C" s32 func_004A8368(const char *) throw();
extern "C" Node *func_00480370(Owner *o, char *name, Node *n) {
    if (n == 0) {
        n = func_00481598();
        if (n == 0) return n;
    } else {
        func_00481508(n);
    }
    n->u38 = o;
    s32 len = func_004A8368(o->uA8);
    s32 blk = func_004816B0(len + func_004A8368(name) + 2);
    n->u48 = blk;
    s32 x = func_004816D0(blk);
    func_0047E3E8(x, o->uA8);
    func_0047E4B8(x, func_0047E208(o->uAC, name));
    func_004816F0(blk);
    func_0047CB90(o, n);
    return n;
}
