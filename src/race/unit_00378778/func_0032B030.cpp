/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
typedef long long s64;

struct Inner { char pad[0x18]; void *unk18; };
struct Arg1 { char pad[0x10]; Inner *unk10; };
struct Obj {
    char pad0[0xE8];
    s32 mE8;
    s32 mEC;
    char pad1[0x148 - 0xF0];
    s32 m148;
    char pad2[0x168 - 0x14C];
    s64 m168;
    char pad3[0x184 - 0x170];
    s32 m184;
    s32 m188;
    s32 m18C;
};

extern "C" void func_00321898(void *) throw();
extern "C" s32 func_0032B128(Obj *, void *, s32, f32);
extern "C" s32 func_0032B590(Obj *, void *, s32, f32);
extern "C" s32 func_0032BAA8(Obj *, void *);

extern "C" void func_0032B030(Obj *self, Arg1 *a1, s32 a2, s32 a3, s32 kind, f32 f) {
    func_00321898(self);
    self->m184 = a2;
    self->m148 = 10;
    if (a2 != 0) {
        void *p = a1->unk10->unk18;
        s32 r;
        switch (kind) {
        case 0:
            r = func_0032B128(self, p, a3, f);
            break;
        case 1:
            r = func_0032B590(self, p, a3, f);
            break;
        case 2:
        default:
            r = func_0032BAA8(self, p);
            break;
        }
        self->m188 = kind;
        self->m18C = r;
    }
    self->mE8 = 0;
    self->mEC = 0;
    self->m168 = (self->m168 & ~(0xFFLL << 16)) | (1LL << 16);
}
