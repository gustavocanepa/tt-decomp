typedef int s32;
typedef long long s64;
typedef unsigned char u8;

/* Looks up a record by its 64-bit id through func_0040B910 (the manager D_00585A30) and returns
   one byte of it, or -1 when the id is unset. */
struct Info { u8 pad[0x6]; u8 field; u8 pad2[0x9]; };
struct Self { char pad[0x90]; s64 id; };
extern char D_00585A30[];
extern "C" void func_0040B910(char *, s64, Info *);

extern "C" s32 func_0040E188(Self *self) {
    Info info;
    if (self->id == -1) return -1;
    func_0040B910(D_00585A30, self->id, &info);
    return info.field;
}
