struct StreamBase {
    int unk0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int flush();
};

struct Stream : StreamBase {
    int unk8;
    int binary;
};

extern "C" void func_004A9360(Stream *s);
extern "C" void func_004DFA98(int a);
extern "C" void func_004E01B8(int mode);
extern "C" void func_004A9380(Stream *s);

extern "C" void func_004A96C0(Stream *s) {
    int mode = s->binary ? 2 : 1;
    func_004A9360(s);
    func_004DFA98(0);
    func_004E01B8(mode);
    s->flush();
    func_004A9360(s);
    func_004DFA98(0);
    func_004E01B8(mode);
    func_004A9380(s);
}
