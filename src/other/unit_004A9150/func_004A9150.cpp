typedef int s32;

extern "C" s32 func_004A90E8(s32 arg0);
extern "C" void func_004A9078(s32 arg0);

extern "C" s32 func_004A9150(s32 arg0) {
    s32 temp_s1 = func_004A90E8(arg0);
    func_004A9078(arg0);
    return temp_s1;
}
