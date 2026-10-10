/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf {
    int data;
    int size;
    int cap;
    int pos;
    int unk10;
    int unk14;
    virtual void v0();
    virtual void changed();
};

extern "C" int func_0042FA10(Buf *b);

extern "C" int func_0042FA28(Buf *b, int data, int size, int cap) {
    int old = func_0042FA10(b);
    b->data = data;
    b->size = size;
    b->cap = cap;
    b->pos = 0;
    b->changed();
    return old;
}
