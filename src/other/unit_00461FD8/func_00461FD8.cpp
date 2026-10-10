typedef int s32;

extern "C" char D_00460A70[];
extern "C" char D_00460C48[];

extern "C" s32 func_00461AC8(s32 arg0, void *arg1, void *arg2, s32 arg3);

extern "C" s32 func_00461FD8(s32 arg0, s32 arg1, s32 arg2) {
    return func_00461AC8(arg0, D_00460A70, D_00460C48, arg2);
}
