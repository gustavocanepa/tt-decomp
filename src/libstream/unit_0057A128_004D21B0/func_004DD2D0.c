/* compiler: ee-gcc2.9-991111 */
typedef struct { int state; int f4; char pad[0xC]; char f14[0x320]; } Ent;
typedef struct { char p0[2]; unsigned char off; unsigned char len; int f4; char pad[0x14]; unsigned char data[1]; } Buf;
extern Ent D_007869D0[];
int func_004DD3A0(int);
int func_004DD638(int);
Buf *func_004DD6F8(int);
int func_004DD7C0(void *, void *);
void *func_004F64C4(void *, const void *, unsigned);

int func_004DD2D0(int arg0, void *arg1) {
    Buf *b;
    unsigned char len;
    func_004DD3A0(arg0);
    if (D_007869D0[arg0].f4 == 0 && func_004DD638(arg0) < 0) return -1;
    b = func_004DD6F8(arg0);
    len = b->len;
    if (len != 0) {
        unsigned char *cp = b->data;
        if (cp != 0) {
            func_004F64C4(arg1, (void *)((int)b->off + (int)b + 0x1C), len);
            func_004DD7C0(b->data + b->off, D_007869D0[arg0].f14);
        }
    }
    if (b->f4 == 0) return -1;
    return b->len;
}
