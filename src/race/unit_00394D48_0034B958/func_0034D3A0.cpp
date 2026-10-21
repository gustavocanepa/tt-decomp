typedef int s32;
typedef float f32;

extern "C" s32 CourseData__evalVMMethods(void *arg0);
extern "C" void func_00422730(s32 arg0, s32 *arg1, s32 arg2);

extern s32 D_00584060;
extern f32 D_00584064;

struct Obj7C {
    char pad[0x7C];
    s32 *p7C;
};

struct func_0034D3A0_arg0 {
    char pad0[4];
    Obj7C *unk4;
    char pad8[0xC];
    Obj7C *unk14;
    char pad18[0xC];
    Obj7C *unk24;
    char pad28[0x2C];
    Obj7C *unk54;
    Obj7C *unk58;
};

extern "C" void func_0034D3A0(struct func_0034D3A0_arg0 *arg0, f32 fparg0) {
    D_00584064 = fparg0;
    D_00584060 += (s32)(fparg0 * 0x1.F4p+9f);
    CourseData__evalVMMethods(arg0);
    {
        Obj7C *v = arg0->unk4;
        if (v != 0) {
            s32 *q = v->p7C;
            func_00422730(*q, q, 0);
        }
    }
    {
        Obj7C *v = arg0->unk54;
        if (v != 0) {
            s32 *q = v->p7C;
            func_00422730(*q, q, 0);
        }
    }
    {
        Obj7C *v = arg0->unk58;
        if (v != 0) {
            s32 *q = v->p7C;
            func_00422730(*q, q, 0);
        }
    }
    {
        Obj7C *v = arg0->unk14;
        if (v != 0) {
            s32 *q = v->p7C;
            func_00422730(*q, q, 0);
        }
    }
    {
        Obj7C *v = arg0->unk24;
        if (v != 0) {
            s32 *q = v->p7C;
            func_00422730(*q, q, 0);
        }
    }
}
