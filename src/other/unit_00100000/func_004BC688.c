typedef int s32;

struct Obj { char pad[0x320]; s32 f320; char pad324[0xC0]; s32 f3E4; };
void func_004BC640(struct Obj *);
void func_004AEAF8(s32 *);

void func_004BC688(struct Obj *o) {
    while (func_004AEAF8(&o->f320), o->f3E4 != 0)
        func_004BC640(o);
}
