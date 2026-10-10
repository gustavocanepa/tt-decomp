/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Reader {
    const u8 *p;
    u8 get() { return *p++; }
};

struct Track {
    char pad0[0x28];
    unsigned long time;
    int pad30;
    int status;
    char pad38[0x20];
    Reader in;
};

extern "C" void func_005745F0(Track *t, int ch, int key, int vel);
extern "C" void func_004C54A0(Track *t, unsigned long time, int ch, int key, int vel);

/* Note event: a velocity of 0 is a note off. */
extern "C" void func_004C5F30(Track *t)
{
    int ch = t->status & 0xF;
    u8 key = t->in.get();
    u8 vel = t->in.get();
    if (vel != 0)
        return func_005745F0(t, ch, key, vel);
    func_004C54A0(t, t->time, ch, key, 0);
}
