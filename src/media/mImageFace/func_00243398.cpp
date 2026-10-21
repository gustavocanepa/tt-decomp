typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_48 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct Self_BC {
    char pad0[0x124];
    VObj *bc;
};

extern "C" void func_00205E20(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_00243398(void *arg0, f32 *arg1, f32 *arg2) {
    Self_BC *self = (Self_BC *)arg0;
    VObj *o = self->bc;

    if (o != 0) {
        if (arg1 != 0) {
            VEntry_48 *e = (VEntry_48 *)(o->vtbl + 0x48);
            *arg1 = (f32)e->fn((char *)o + e->delta);
        }
        if (arg2 != 0) {
            VObj *o2 = self->bc;
            VEntry_48 *e2 = (VEntry_48 *)(o2->vtbl + 0x50);
            *arg2 = (f32)e2->fn((char *)o2 + e2->delta);
        }
    } else {
        func_00205E20(arg0, (s32)arg1, (s32)arg2);
    }
}
