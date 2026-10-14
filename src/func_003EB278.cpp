/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;

struct Pkt { char b[0x20]; };

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Target {
    char *vtbl;
};

struct In {
    char pad0[3];
    s8 n3;
    char pad4[0xC];
    char data10[0x10];
};

struct Self {
    char padD0[0xD0];
    Target *tD0;
    char padD4[0x150 - 0xD4];
    Pkt s150;
    char pad170[0x1C8 - 0x170];
    s32 w1C8;
    s32 w1CC;
};

extern "C" void AutomobileControl__clearPacket(Pkt *);
extern "C" void *func_004F64C4(void *, const void *, u32);

typedef void (*Fn)(void *, Pkt *);

extern "C" void RaceInput__getAutomobileControl(Self *self, Pkt *out, In *in) {
    Pkt *p;
    AutomobileControl__clearPacket(out);
    if (self->w1CC != 0) {
        if (self->w1C8 != 0) {
            VEntry *e = (VEntry *)((char *)self->tD0 + 0x38);
            p = &self->s150;
            ((Fn)e->fn)((char *)self + e->delta, p);
        } else {
            if (in != 0) {
                s8 n = in->n3;
                self->s150.b[3] = n;
                if (n != 0) {
                    func_004F64C4(self->s150.b + 0x10, in->data10, n);
                }
            }
            {
                VEntry *e = (VEntry *)((char *)self->tD0 + 0x40);
                p = &self->s150;
                ((Fn)e->fn)((char *)self + e->delta, p);
            }
        }
        *out = *p;
    }
}
