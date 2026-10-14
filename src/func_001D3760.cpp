/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Blob { char b[0x258]; };

struct NetConf {
    s32 pad0;
    void *vt;
    char pad8[8];
    Blob data;
    NetConf(const Blob &src);
};

extern char D_005B0238[];
extern "C" void func_002A7618(void *);

extern "C" int mNetConf__structor_1(NetConf *self, const Blob &src) {
    func_002A7618(self);
    self->vt = D_005B0238;
    self->data = src;
}
