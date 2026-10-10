struct Info {
    int w[8];
};

extern "C" void *func_00408B58(void *o);
extern "C" void *func_0040CFE0(void *p);
extern "C" int func_004107B0(void *p, Info *info);
extern "C" int func_00410920(Info *info);
extern "C" int func_00406B70(void *o, int id);

extern "C" bool func_0012D798(void *o) {
    Info info;
    if (!func_004107B0(func_0040CFE0(func_00408B58(o)), &info))
        return false;
    bool r;
    if (func_00410920(&info))
        r = true;
    else
        r = func_00406B70(o, 0x1C) == 1;
    return r;
}
