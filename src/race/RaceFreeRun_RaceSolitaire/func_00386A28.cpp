/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VEnt { s16 off; s16 pad; void *(*fn)(void *); };
struct VEntV { s16 off; s16 pad; void (*fn)(void *); };

struct Item;
struct Lst { s32 count; s32 unk4; Item **items; };
struct Obj60 { char pad[0x20]; char *vt; };
struct Org { char pad[0x60]; Obj60 *unk60; };
struct Lst2 { char pad[8]; Item **unk8; };
struct Org2 { char pad[0x60]; Lst2 *unk60; };

struct Self {
    char pad0[0x64];
    char *unk64;
    char pad68[4];
    Org *unk6C;
    char pad70[0xD8C - 0x70];
    u32 unkCC8;
};

extern s32 D_00584720;
extern "C" void AutomobileControlRecord__Manager__reset(void *);
extern "C" void func_0033CE68(void *, void *);
extern "C" void func_00369818(void *, void *, s32);

extern "C" void func_00386A28(Self *self, void *arg1) {
    VEntV *ve = (VEntV *)(self->unk64 + 0x508);
    ve->fn((char *)self + ve->off);
    func_0033CE68(self, arg1);
    if (self->unkCC8 < 2) {
        AutomobileControlRecord__Manager__reset((char *)self + 0xF164);
        AutomobileControlRecord__Manager__reset((char *)self + 0xF0F4);
    }
    *(s32 *)((char *)self + 0xF254) = 0;
    if (*(s32 *)((char *)self + 0xF260) == 0 && D_00584720 == 0) {
        Org *org = self->unk6C;
        Obj60 *o = org->unk60;
        VEnt *v1 = (VEnt *)(o->vt + 0x10);
        void *r = v1->fn((char *)o + v1->off);
        *(void **)((char *)self + 0xF260) = r;
        func_00369818(r, ((Org2 *)org)->unk60->unk8[0], 0);
        Obj60 *o2 = org->unk60;
        VEntV *v2 = (VEntV *)(o2->vt + 0x18);
        v2->fn((char *)o2 + v2->off);
    }
}
