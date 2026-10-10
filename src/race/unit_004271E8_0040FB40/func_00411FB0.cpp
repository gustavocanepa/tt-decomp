/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob {
    long long id;
    void *data;
    int size;
};

extern "C" void func_00412368(Blob *b);
extern "C" void *func_004A45F8(int size);
extern "C" void *func_004F64C4(void *dst, const void *src, int n);

extern "C" void func_00411FB0(Blob *b, const Blob *o)
{
    func_00412368(b);
    b->id = o->id;
    if (o->data) {
        b->data = func_004A45F8(o->size);
        func_004F64C4(b->data, o->data, o->size);
        b->size = o->size;
    }
}
