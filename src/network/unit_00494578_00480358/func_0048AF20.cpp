/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Buf {
    char pad0[8];
    u8 *data;
};
struct Fs {
    char pad0[4];
    void *cache;
    char pad8[0x50 - 8];
    u32 unk50;
    s32 unk54;
    u32 unk58;
    s32 unk5C;
};

extern "C" {
Buf *func_00487850(void *, u32) throw();
void func_00487968(void *, void *) throw();
void func_00487A00(void *, void *) throw();
}

struct U16 { u16 v; } __attribute__((packed));
static inline void put16(u8 *p, u16 v) { ((U16 *)p)->v = v; }
static inline u32 get16(u8 *p) { return (p[1] << 8) | p[0]; }

extern "C" s32 func_0048AF20(Fs *fs, s32 n, u16 val)
{
    u32 i = 0;
    u32 off = n + n / 2;
    u32 sect = off / fs->unk50;
    u32 pos = off % fs->unk50;

    if (fs->unk58 != 0) {
        do {
            Buf *b = func_00487850(fs->cache, fs->unk54 + i * fs->unk5C + sect);
            Buf *b2;
            u8 *p;
            u8 *d;
            u32 hi;
            u16 cur;
            if (b == 0) {
                return -5;
            }
            b2 = 0;
            if (pos == fs->unk50 - 1) {
                b2 = func_00487850(fs->cache, fs->unk54 + (i * fs->unk5C + sect) + 1);
                if (b2 == 0) {
                    func_00487968(fs->cache, b);
                    return -5;
                }
                hi = *b2->data;
                cur = (hi << 8) | b->data[pos];
            } else {
                cur = get16(b->data + pos);
            }
            if (n & 1) {
                val <<= 4;
                val |= cur & 0xF;
            } else {
                val &= 0xFFF;
                val |= cur & 0xF000;
            }
            if (b2 != 0) {
                b->data[pos] = val;
                *b2->data = val >> 8;
                func_00487A00(fs->cache, b2);
            } else {
                put16(b->data + pos, val);
            }
            i++;
            func_00487A00(fs->cache, b);
        } while (i < fs->unk58);
    }
    return 0;
}
