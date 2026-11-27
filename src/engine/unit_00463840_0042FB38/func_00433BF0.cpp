/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0042FD90(void *);
extern "C" float func_00433BF0(char *arg0, int arg1) {
    float r;
    char *p = arg0 + 0x104;
    signed char type = *(signed char *)(p + 0x486);
    if (type == 1 || (type == 2 || (r = 1.0f, *(unsigned char *)(p + 0x487) != 0))) {
        int base = *(int *)(arg0 + 0x10);
        int data = func_0042FD90(arg0 + 0x14);
        r = *(float *)(data + *(unsigned char *)(arg1 + base + 0xFDC) * 4 + 0xA8);
    }
    return r;
}
