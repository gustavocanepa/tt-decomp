/* compiler: ee-gcc2.9-991111 */
struct Entry { int a, b, c; struct Entry *next; char *name; unsigned short version, flags; int x18, x1c; };
struct G { char pad[0x14]; struct Entry *head; };
extern int D_005A0BB0;
extern struct G D_0077A028;
void func_004D55E0(struct Entry *);
int func_004D5718(struct Entry *);
int func_004D57B8(struct Entry *);
void func_004D9EF0(struct Entry *, unsigned);
void func_004FAAA0(int);
void func_004FD2D0(const char *, ...);
int func_005038D8(void);
int func_00503928(void);
/* Preserve the full SDK callee-saved registers. Repeat s0 to work around
   the 991111 attribute-list overwrite, as in adjacent SDK functions. */
int func_004D5118(struct Entry *start, unsigned bytes, int mode)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_004D5118(struct Entry *start, unsigned bytes, int mode) {
    int n = bytes >> 2;
    struct Entry *p;
    int intr, result;
    if (!D_005A0BB0) return 0x81058001;
    p = start;
    intr = func_005038D8();
    result = 0;
    for (; n > 0; p++, n -= 8) {
        if (func_004D5718(p) < 0) { result = 0x81059039; break; }
        if ((p->flags & 2) && ((*(unsigned *)&p->version & 0x30000) != 0x20000)) continue;
        if (func_004D57B8(p) == 1) {
            if (mode) p->flags |= 8;
        } else if (mode) {
            func_004D55E0(p);
            p->flags |= 0xC;
            p->next = D_0077A028.head;
            D_0077A028.head = p;
        } else {
            unsigned v = p->version;
            func_004FD2D0("link failed: \"%s\" (%d.%d)\n", p->name, v >> 8, v & 255);
            func_004D9EF0(start, bytes);
            if (intr) func_00503928();
            return 0x81059037;
        }
    }
    func_004FAAA0(2);
    if (intr) func_00503928();
    return result;
}
