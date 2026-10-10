typedef int s32;

struct Obj { char pad[0x48]; s32 f48; char pad4C[0x254]; s32 f2A0; };
void func_0011C0D0(struct Obj *);
void func_004AEAF8(s32 *);

void func_0011BC58(struct Obj *o) {
    while (func_004AEAF8(&o->f48), o->f2A0 == 0)
        func_0011C0D0(o);
}
