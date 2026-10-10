struct Buffer {
    char data[0x3C];
};

struct DoubleBuffer {
    Buffer buf[2];
    int cur;
};

extern DoubleBuffer D_00579534;
extern "C" void func_002D5B98(Buffer *b, void *arg);

extern "C" void func_002D5BE8(void *arg)
{
    DoubleBuffer *db = &D_00579534;
    func_002D5B98(&db->buf[db->cur], arg);
    func_002D5B98(&db->buf[1 - db->cur], arg);
}
