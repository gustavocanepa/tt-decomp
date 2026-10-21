typedef int s32;
typedef unsigned int u32;

struct Entry {
    s32 value;
    s32 pad;
};

extern struct Entry D_0076CE70[];
extern char D_00602248[];

s32 func_00455930(u32 arg0) {
    if (arg0 < 0xCU) {
        return D_0076CE70[arg0].value;
    }
    return (s32)D_00602248;
}
