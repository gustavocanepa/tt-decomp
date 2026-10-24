int func_003205F8(float x) {
    int i = (int)(x * 5.0f);
    if (i < 1) i = 0;
    if (i >= 4) i = 4;
    return ((signed char *)0x583D40)[i];
}
