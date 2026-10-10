struct Buf { int m0, m4; unsigned char *data; };
struct Fs { int m0; void *dev; char pad[0x48]; unsigned int secSize; unsigned int start; };
extern "C" Buf *func_00487850(void *, unsigned int);
extern "C" void func_00487968(void *, Buf *);

extern "C" int func_0048B560(Fs *fs, unsigned int idx)
{
    idx *= 2;
    unsigned int sec = fs->start + idx / fs->secSize;
    unsigned int rem = idx % fs->secSize;
    Buf *b = func_00487850(fs->dev, sec);
    if (!b) return -5;
    int v = b->data[rem + 1] << 8 | b->data[rem];
    func_00487968(fs->dev, b);
    return v;
}
