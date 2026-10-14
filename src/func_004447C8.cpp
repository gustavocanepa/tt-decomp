void func_004447C8(void *arg0, float f) {
    int i = (int)(f * 128.0f);
    if (i < 0) i = 0;
    if (i >= 0x100) i = 0xFF;
    *((signed char *)arg0 + 0x47) = (signed char)i;
}
