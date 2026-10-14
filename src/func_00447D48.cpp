/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct String3;
extern "C" void func_005685F0(String3 *str, u32 len, s32 force);

struct String3 {
    struct Rep {
        u32 len, res, ref, selfish;
        char *data() { return (char *)(this + 1); }
        char &operator[](u32 s) { return data()[s]; }
    };
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    u32 length() const { return rep()->len; }
    void alloc(u32 size, s32 save) { func_005685F0(this, size, save); }
    void unique() { if (rep()->ref > 1) alloc(length(), 1); }
    void selfish() { unique(); rep()->selfish = 1; }
    char &operator[](u32 pos) { selfish(); return (*rep())[pos]; }
    char *begin() { selfish(); return &(*this)[0]; }
    char *end() { selfish(); return &(*this)[length()]; }
};

extern "C" void func_00447D48(String3 *arg0) {
    for (char *p = arg0->begin(); p != arg0->end(); p++) {
        if ((*p & 0xE0) == 0x60) {
            *p -= 0x20;
        }
    }
}
