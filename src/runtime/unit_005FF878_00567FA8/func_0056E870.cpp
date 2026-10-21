typedef int s32;

typedef struct {
    char b[16];
    s32 w;
} Tail_0060A890;

typedef struct {
    char pad0[0x84];
    Tail_0060A890 tail;
} Dst_0060A890;

void func_0056E870(Dst_0060A890 *arg0, const Tail_0060A890 *arg1) {
    arg0->tail = *arg1;
}
