struct Node { char pad0[8]; char *f8; };
struct Fs { char pad0[4]; int f4; char pad8[0x50 - 8]; unsigned int f50; };
extern "C" Node *func_00487850(int, int);
extern "C" void func_00487968(int, Node *);
extern "C" int func_004881A0(char *);
extern "C" int func_00488208(char *);
extern "C" int func_004E5700(char *, char *, int);

extern "C" int func_00488A88(Fs *fs, int base, unsigned int count, char *name, Node **out1, char **out2) {
    unsigned int i = 0;
    if (count != 0) {
        do {
            Node *n = func_00487850(fs->f4, base + i);
            if (n == 0) return -5;
            char *e = n->f8;
            if ((unsigned int)e < (unsigned int)(e + fs->f50)) {
                do {
                    if (*e == 0) {
                        func_00487968(fs->f4, n);
                        return -2;
                    }
                    if (func_00488208(e) == 0 && *e != -0x1B && (e[0xB] & 8) == 0 &&
                        func_004E5700(e, name, 0xB) == 0) {
                        *out1 = n;
                        *out2 = e;
                        return func_004881A0(e);
                    }
                    e += 0x20;
                } while ((unsigned int)e < (unsigned int)(n->f8 + fs->f50));
            }
            func_00487968(fs->f4, n);
            i++;
        } while (i < count);
    }
    return 0;
}
