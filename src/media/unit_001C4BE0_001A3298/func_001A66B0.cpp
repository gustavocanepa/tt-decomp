typedef void (*Done)(void *arg, int ok, const char *msg);
struct Req {
    char pad[0x3C];
    int m3C;
    char pad2[0x48 - 0x40];
    int state;
    Done done;
    void *arg;
    char pad3[0x6C - 0x54];
    void *handle;
};
extern "C" int func_0050E8A0(void *h, int abort);
extern "C" char D_005E71C0[];
extern "C" char D_005E71C8[];

extern "C" void func_001A66B0(Req *r)
{
    const char *msg = 0;
    if (func_0050E8A0(r->handle, r->state != 2))
        msg = D_005E71C0;
    if (r->done)
        r->done(r->arg, 0, msg ? msg : D_005E71C8);
    r->m3C = 0;
    r->done = 0;
}
