/* compiler: ee-gcc2.9-991111 */
typedef struct Buf {
    char pad[0x7C];
    int stamp;
} Buf;

typedef struct Slot {
    char pad[0x10];
    Buf *bufs;
    char pad2[0x334 - 0x14];
} Slot;

extern Slot D_007869D0[];
extern void func_004FB118(void *start, void *end);

Buf *func_004DD690(int i)
{
    Buf *b[2];

    b[0] = D_007869D0[i].bufs;
    b[1] = (Buf *)((char *)b[0] + 0x80);
    func_004FB118(b[0], (char *)b[0] + 0xFF);
    return b[b[0]->stamp < b[1]->stamp];
}
