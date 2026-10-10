/* A one-byte tag passed by value (an empty struct would be passed as a constant 0). */
struct Tag {
    char c;
};

struct Str {
    int h;
    Str(const Str &o) __asm__("func_00128400");
    ~Str();
};

struct Elem {
    Str s;
    int v;
};

/* Takes the element by value: the callee destroys its copy. */
extern "C" void func_00517C68(Elem *p, Elem e, Tag t);

extern "C" void func_00516850(Elem *first, Elem *last, int unused, Tag t) {
    for (; first != last; ++first)
        func_00517C68(first, *first, t);
}
