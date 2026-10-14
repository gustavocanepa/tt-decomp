/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int offset; unsigned int size; char data[1]; };
struct Header {
    int a;
    Header *self;
    char pad8[8];
    unsigned short rows,cols;
    char pad14[12];
    Block *blocks[1];
};
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void func_0041ED48(Header *h, char *dst, int row) {
    if(h != h->self) return;
    if(row < 0 || row >= h->rows) return;
    Block **p = &h->blocks[row*h->cols];
    int i=0;
    goto test;
body:
    {
        Block *b=*p++;
        if(b) func_004F64C4(dst+b->offset,b->data,b->size);
    }
test:
    int more = i < h->cols;
    i++;
    if(more) goto body;
}
