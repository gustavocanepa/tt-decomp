extern "C" void func_004A45D0(void *p);

struct Alloc {
    Alloc() {}
    Alloc(const Alloc &) {}
};

struct Buffer {
    Alloc alloc;
    char *start;
    char *finish;
    char *end_of_storage;
    Buffer(const Alloc &a = Alloc()) : alloc(a), start(0), finish(0), end_of_storage(0) {}
    ~Buffer() { if (start) func_004A45D0(start); }
    unsigned int size() const { return finish - start; }
};

extern "C" void func_0019EDC8(int arg0, int arg1, Buffer *buf);

extern "C" unsigned int func_0019ECE8(int arg0, int arg1) {
    Buffer buf;
    func_0019EDC8(arg0, arg1, &buf);
    return (buf.size() + 0x3FF) >> 10;
}
