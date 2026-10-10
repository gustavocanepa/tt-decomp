typedef int s32;
typedef unsigned int u32;

struct Stream_0033A7D0 {
    s32 m0;
    u32 pos;
    u32 end;
};

struct Saved_0033A7D0 {
    char data[0x10];
};

extern "C" void func_004242C0(Saved_0033A7D0 *s, Stream_0033A7D0 *st);
extern "C" void func_004243E0(Saved_0033A7D0 *s, Stream_0033A7D0 *st);
extern "C" void func_002DC588(Stream_0033A7D0 *st, Saved_0033A7D0 *s, void *x);

extern "C" bool func_002DC9B0(Stream_0033A7D0 *st, void *x) {
    Saved_0033A7D0 s;
    func_004242C0(&s, st);
    func_002DC588(st, &s, x);
    func_004243E0(&s, st);
    Stream_0033A7D0 *r = (st->end > st->pos) ? 0 : st;
    return r != 0;
}
