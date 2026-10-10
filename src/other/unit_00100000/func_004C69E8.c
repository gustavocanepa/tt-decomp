typedef int s32;

struct Obj { char pad[0x234]; s32 f234; };
extern char D_005A0B88[];
void func_004A4930(void *);
void func_004A4970(void *);

s32 func_004C69E8(struct Obj *o) {
    s32 *p = &o->f234;
    s32 r;
    func_004A4930(D_005A0B88);
    r = *p;
    func_004A4970(D_005A0B88);
    return r;
}
