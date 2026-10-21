typedef unsigned char u8;
typedef int s32;

/* 8-byte element: the first word is copied by func_00128400, the float at +4 is func_005AE2E8 directly. */
struct Node {
    s32 h;
    float v;
};

/* Temporary at sp+0x10: its float lands at sp+0x14. */
struct Tmp {
    s32 h;
    float v;
};

/* 0x20-byte frame: tag byte at sp+0, temporary at sp+0x10, padding to the saves at sp+0x20. */
struct Frame {
    u8 tag;
    u8 pad0[0xF];
    Tmp t;
    s32 pad1[2];
};

extern "C" void func_00128400(Tmp *dst, Node *src);
extern "C" void func_00517800(Node *arg0, Tmp *arg1, u8 arg2);

extern "C" void func_005163B8(Node *first, Node *last, s32 unused, u8 tag) {
    Frame f;
    Node *p = first;

    f.tag = tag;
    if (p != last) {
        Tmp *pt = &f.t;
        do {
            func_00128400(pt, p);
            float v = p->v;
            Node *cur = p;
            p++;
            f.t.v = v;
            func_00517800(cur, pt, f.tag);
        } while (p != last);
    }
}
