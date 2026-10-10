typedef int s32;

/* The base class; its constructor is func_004F44B8. Its vptr sits at 0x38. */
struct func_004F44B8 {
    char pad[0x2C];
    char *buf;
    s32 size;
    s32 m34;
    func_004F44B8();
    virtual ~func_004F44B8();
};

extern "C" s32 func_004F4138(s32 a, s32 b, s32 c);

/* Named after its vtable so the compiler-made vptr store _vt$10D_006897F8 resolves. */
struct D_005DB0A0 : func_004F44B8 {
    s32 m3C;
    s32 handle;
    char pad44[0x3C];
    char data[0x40];
    D_005DB0A0();
    virtual ~D_005DB0A0();
};

D_005DB0A0::D_005DB0A0() {
    buf = data;
    size = 0x40;
    m3C = 0;
    handle = func_004F4138(0, 0xFF, size);
}
