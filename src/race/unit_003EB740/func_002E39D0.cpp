extern "C" unsigned int func_003EAF90(void *);
extern "C" int func_003EAEF8(void *, unsigned int);
extern "C" void func_0043CFD0(void *, int);
extern "C" int func_0043D0C8(void *, int);

extern "C" bool func_002E39D0(void *o, void *pad, unsigned int mask, int c)
{
    if (func_003EAF90(pad) & mask) {
        func_0043CFD0(o, c);
    } else if (func_003EAEF8(pad, mask)) {
        func_0043D0C8(o, c);
    } else {
        return false;
    }
    return true;
}
