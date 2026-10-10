typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

struct Obj {
    char pad[0x98];
    s64 key;
};

struct Rec {
    char pad[0x6];
    u8 value;
    char tail[0x9];
};

extern char D_00585A30[];
extern "C" void func_0040B910(void *, s64, void *);

extern "C" s32 func_0040E1C8(Obj *self) {
    Rec rec;
    if (self->key == -1)
        return -1;
    func_0040B910(D_00585A30, self->key, &rec);
    return rec.value;
}
