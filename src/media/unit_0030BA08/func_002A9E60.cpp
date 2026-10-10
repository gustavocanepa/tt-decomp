/* compiler: ee-gcc2.96-no-strict-aliasing */
/* A counted pair of words and an empty string (basic_string's default constructor: nilRep.grab()). */
typedef int s32;

struct Rep {
    s32 len;
    s32 res;
    s32 ref;
    s32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
};

extern "C" char *func_0050F0F0(Rep *r);
extern Rep D_005A4850;

inline char *Rep::grab() {
    if (selfish)
        return func_0050F0F0(this);
    ++ref;
    return data();
}

struct String {
    char *dat;
    String() : dat(D_005A4850.grab()) {}
};

struct func_002A9E60 {
    s32 m0;
    s32 m4;
    String str;
    func_002A9E60();
};

func_002A9E60::func_002A9E60() : m0(0), m4(1) {
}
