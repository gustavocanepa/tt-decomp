typedef int s32;

extern "C" s32 func_00366130(s32 arg0);

extern "C" s32 func_002E3948(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_00366130(arg1);
    return (temp_v0 == 0) ? arg1 : temp_v0;
}
