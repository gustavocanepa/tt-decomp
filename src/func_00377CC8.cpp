/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner { char pad[0x18]; s32 f18; };
struct Self {
    char pad0[0xC];
    s32 fC;
    char pad10[4];
    void *f14;
    Inner *f18;
    s32 f1C;
    s32 f20;
    s32 f24;
};

extern "C" s32 RaceEventQueue__get(void *, s32, s32, s32);
extern "C" s32 PauseBase__checkTimeLimit(void *);
extern "C" void func_00377F28(void *);
extern "C" s32 func_002E3A60(void *, void *, s32);
extern "C" void func_0043BE20(void *, s32);
extern "C" void func_0043C0D8(void *, float);

extern "C" s32 RacePause__update(Self *self, s32 arg1, char *arg2) {
    if (arg2 != 0) {
        char *t = arg2 + 0xF4;
        if (RaceEventQueue__get(t, 0x16, 0, 1) != 0) {
            self->f20 = 1;
        }
        if (RaceEventQueue__get(t, 0x17, 0, 1) != 0) {
            self->f24 = 1;
        }
    }
    if (self->f20 != 0) return 3;
    if (self->f24 != 0) return 4;
    if (self->fC == 0) {
        self->fC = 1;
        if (self->f14 != 0) {
            if (self->f18 != 0) {
                func_0043BE20(self->f14, 0);
            }
        }
    }
    self->f1C = 1;
    s32 s2 = 0;
    if (self->f14 != 0) {
        func_0043C0D8(self->f14, 0x1.111110p-6f);
    }
    s32 r;
    Inner *q = self->f18;
    if (q != 0) {
        s2 = func_002E3A60(q, self->f14, arg1);
        q = self->f18;
        r = self->f1C;
        if (q != 0 && q->f18 != 0) {
            func_00377F28(self);
            self->fC = 0;
            return 3;
        }
    }
    else {
        r = self->f1C;
    }
    if (s2 == 0) {
        if (PauseBase__checkTimeLimit(self) != 0) {
            self->fC = 0;
            return 2;
        }
    } else {
        func_00377F28(self);
    }
    return r;
}
