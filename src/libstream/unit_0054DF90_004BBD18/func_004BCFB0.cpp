typedef int s32;

/* The base class; its constructor is func_004F44B8 (named after it so __13func_00578048
   resolves). Its vptr sits at 0x38. */
struct func_004F44B8 {
    char pad[0x2C];
    char *buf;
    s32 cap;
    s32 m34;
    func_004F44B8();
    virtual ~func_004F44B8();
};

/* The class is named after its vtable (no known name), so the compiler's own vptr store
   _vt$10D_006897B8 resolves to 0x006897B8. A real C++ constructor is needed for the
   original's instruction schedule (the same stores written in C come out in another order). */
struct D_005DB0D8 : func_004F44B8 {
    s32 m3C;
    char data[0x80];
    D_005DB0D8();
    virtual ~D_005DB0D8();
};

D_005DB0D8::D_005DB0D8() {
    buf = data;
    cap = 0x80;
}
