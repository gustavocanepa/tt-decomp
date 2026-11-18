/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;

struct VE {
    short adj;
    short pad;
    int (*fn)(char *, int, int);
};
struct VE1 {
    short adj;
    short pad;
    int (*fn)(char *);
};
struct VT {
    char pad[0x10];
    VE1 e10;
    char pad18[8];
    VE e20;
};
struct Buf {
    char pad0[8];
    u8 *data;
};
struct Fs {
    char pad0[4];
    void *cache;
    char pad8[0x50 - 8];
    u32 unk50;
    int unk54;
    char pad58[4];
    u32 unk5C;
    char pad60[4];
    int unk64;
    char pad68[0x74 - 0x68];
    u32 unk74;
    VT *vt;
};

extern "C" {
Buf *func_00487850(void *, u32) throw();
void func_00487968(void *, Buf *) throw();
}

extern "C" int func_0048B6C8(Fs *fs, int prev, u32 n)
{
    int res = -0x1C;
    int first = 0;
    int retry = 1;
    int cur = prev + 1;
    if (!(fs->unk74 >= n)) return res;
    for (;;) {
        u32 sect = (cur * 2) / fs->unk50;
        u32 off = (cur * 2) % fs->unk50;
        while (n != 0 && sect < fs->unk5C) {
            Buf *buf = func_00487850(fs->cache, fs->unk54 + sect);
            res = -5;
            if (buf == 0) {
                return res;
            }
            while (cur < fs->unk64 && off < fs->unk50) {
                u8 *p = buf->data + off;
                if ((p[1] << 8 | p[0]) == 0) {
                    if (prev != 0) {
                        VE *e = &fs->vt->e20;
                        if (e->fn((char *)fs + e->adj, prev, cur) < 0) {
                            continue;
                        }
                    }
                    prev = cur;
                    n--;
                    if (first == 0) {
                        first = prev;
                    }
                    fs->unk74--;
                    if (n == 0) {
                        break;
                    }
                }
                off += 2;
                cur++;
            }
            off = 0;
            func_00487968(fs->cache, buf);
            sect++;
        }
        cur = 2;
        if (n == 0 || --retry == -1) {
            break;
        }
    }
    res = -0x1C;
    if (first != 0) {
        VE1 *e1 = &fs->vt->e10;
        int t = e1->fn((char *)fs + e1->adj);
        VE *e2 = &fs->vt->e20;
        e2->fn((char *)fs + e2->adj, prev, t);
        res = first;
        return res;
    }
    return res;
}
