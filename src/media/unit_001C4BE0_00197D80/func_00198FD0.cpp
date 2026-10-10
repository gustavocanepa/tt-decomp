struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

struct VObj {
    VEntry *vtbl;
};

static inline int vcall(VObj *o, int i) {
    VEntry *e = &o->vtbl[i];
    return e->fn((char *)o + e->delta);
}

struct func_00198FD0_Obj {
    char pad0[0x30];
    VObj *dev;
    char pad1[0x674 - 0x34];
    int x674;
    char pad2[0x684 - 0x678];
    int x684;
    int x688;
    int x68c;
    int x690;
    int pad694[2];
    int state;
    char pad3[0x6C8 - 0x6A0];
    int x6c8;
};

extern "C" {
int func_00198BD0(func_00198FD0_Obj *self);
void func_00198C98(func_00198FD0_Obj *self);
void func_004A58A0(int ticks);
void func_00199148(func_00198FD0_Obj *self);
void func_001991D8(func_00198FD0_Obj *self);
void func_00199480(func_00198FD0_Obj *self);
void func_001998E8(func_00198FD0_Obj *self);
}

extern "C" void func_00198FD0(func_00198FD0_Obj *self) {
    if (func_00198BD0(self)) {
        func_00198C98(self);
        self->x690 = vcall(self->dev, 4);
        return func_004A58A0(0x27100);
    }
    self->x68c = vcall(self->dev, 3);
    if (self->x68c == 0) {
        func_00198C98(self);
        return func_004A58A0(0x27100);
    }
    switch (self->state) {
    case 0:
        if (vcall(self->dev, 4)) {
            self->x690 = 1;
            self->state++;
            self->x6c8 = 0;
            self->x674 = 0;
        } else {
            self->x690 = 0;
            self->x674 = 0;
            self->x684 = 0;
            self->state = 6;
        }
        break;
    case 1:
        func_00199148(self);
        break;
    case 2:
        func_001991D8(self);
        break;
    case 3:
        func_00199480(self);
        break;
    case 4:
        self->state++;
        break;
    case 5:
        func_001998E8(self);
        break;
    case 6:
        break;
    }
}
