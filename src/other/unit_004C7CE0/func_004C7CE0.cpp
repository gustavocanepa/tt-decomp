extern "C" void func_004C73F8(int val, int *ptr, int addr, int *stack_data, int arg4);

extern "C" int D_004C7928;

extern "C" void func_004C7CE0(int *arg0, int arg1, int arg2) {
    int buf[2];
    buf[0] = arg1;
    buf[1] = arg2;
    func_004C73F8(*arg0, arg0, (int)&D_004C7928, buf, 0);
}
