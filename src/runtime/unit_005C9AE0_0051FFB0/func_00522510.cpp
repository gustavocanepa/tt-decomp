typedef float f32;

extern "C" void *func_001AF2E0(void *, int);

extern "C" f32 func_00522510(void *arg0) {
    return *(f32 *)((char *)*(void **)func_001AF2E0(arg0, 1) + 0x10);
}
