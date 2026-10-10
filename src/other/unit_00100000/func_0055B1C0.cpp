typedef int s32;

struct Obj_005FBFB0 {
    char pad[0x3000];
    s32 unk3000;
};

extern "C" s32 func_0055B4F8(Obj_005FBFB0 *arg0, s32 arg1);
extern "C" s32 func_0055BC20(Obj_005FBFB0 *arg0);

extern "C" s32 func_0055B1C0(Obj_005FBFB0 *arg0, s32 arg1, s32 arg2) {
    s32 i = 0;

    if (arg2 <= 0) {
        return 1;
    }

    for (;;) {
        if (arg0->unk3000 == 0) {
            return 1;
        }
        if (func_0055B4F8(arg0, arg1) == 0) {
            return 0;
        }
        while (arg0->unk3000 == 0) {
            if (func_0055BC20(arg0) == 0) {
                break;
            }
        }
        i++;
        if (i >= arg2) {
            return 1;
        }
    }
}
