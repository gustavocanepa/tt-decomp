extern "C" int func_004C9A88(void *dev, int reg);

extern "C" int func_004C9AB8(void *dev, int reg)
{
    int lo = func_004C9A88(dev, reg * 2);
    int hi = func_004C9A88(dev, reg * 2 + 1);
    return lo | (hi << 8);
}
