typedef int s32;

struct Buf {
    s32 unk0;
    void *data;
    s32 size;
    s32 cap;
    s32 pad[4];
};

extern "C" s32 func_0019CEE0(void *, void *, Buf *, s32);
extern "C" void func_004A45D0(void *);

extern "C" bool func_0019D380(void *a, void *b) {
    Buf buf;
    buf.data = 0;
    buf.size = 0;
    buf.cap = 0;
    bool ok = func_0019CEE0(a, b, &buf, 0) == 0;
    if (buf.data != 0)
        func_004A45D0(buf.data);
    return ok;
}
