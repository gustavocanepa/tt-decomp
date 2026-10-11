struct Header {
    int magic;
};

struct Result {
    int err;
    int pad4[3];
    Header *data;
    int pad14[3];
};

struct Obj {
    Header *gpb1;
    Header *gpb2;
};

extern "C" void func_0045DA70(Obj *o, const char *name);
extern "C" void func_0047DB20(Result *r, const char *name, int flags);
extern "C" void func_0045D620(Header *h, int base);
extern "C" void func_0045D750(Header *h, int base);

extern "C" void func_0045D948(Obj *o, const char *name) {
    func_0045DA70(o, name);
    Result r;
    func_0047DB20(&r, name, 1);
    if (r.err == 0) {
        Header *h = r.data;
        if (h->magic == 0x31627067) {
            func_0045D620(h, (int)h);
            o->gpb2 = 0;
            o->gpb1 = h;
        }
        h = r.data;
        if (h->magic == 0x32627067) {
            func_0045D750(h, (int)h);
            o->gpb1 = 0;
            o->gpb2 = h;
        }
    }
}
