typedef int s32;

typedef struct S16 { char data[16]; } S16;

struct Obj_00450090 {
    char pad0[12];
    s32 unkC;
};

extern "C" s32 func_00418B08(struct Obj_00450090 *arg0, S16 *arg1) {
    s32 spare[4];
    s32 old;

    old = arg0->unkC;
    *(S16 *)arg0 = *arg1;
    arg0->unkC = old;
    return 1;
}
