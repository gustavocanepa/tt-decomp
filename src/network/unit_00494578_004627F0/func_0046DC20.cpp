/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_0046DC20(char *p) {
    float *color = (float *)(p + 0xA60);
    func_004F6678(color, 0, 0x50);
    *color = 0x1.999998p-3f;
    *(float *)(p + 0xA64) = 0x1.999998p-3f;
    *(float *)(p + 0xA68) = 0x1.999998p-3f;
    *(float *)(p + 0xA6C) = 1.0f;
    *(float *)(p + 0xA70) = 0x1.999998p-1f;
    *(float *)(p + 0xA74) = 0x1.999998p-1f;
    *(float *)(p + 0xA78) = 0x1.999998p-1f;
    *(float *)(p + 0xA7C) = 1.0f;
    *(float *)(p + 0xA8C) = 1.0f;
    *(float *)(p + 0xA9C) = 1.0f;
    *(int *)(p + 0xC28) = 2;
    *(int *)(p + 0xC2C) = 3;
    p[6] = 0;
    *(float *)(p + 0xBA0) = 1.0f;
    *(float *)(p + 0xBA4) = 1.0f;
    *(float *)(p + 0xBA8) = 1.0f;
    *(float *)(p + 0xBAC) = 1.0f;
    *(float *)(p + 0xBB0) = 1.0f;
    *(float *)(p + 0xBB4) = 1.0f;
    *(float *)(p + 0xBB8) = 1.0f;
    *(float *)(p + 0xBBC) = 1.0f;
    *(int *)(p + 0xBC0) = 0;
    *(int *)(p + 0xBC4) = 0;
    *(int *)(p + 0xBC8) = 0;
    *(int *)(p + 0xBCC) = 0;
}
