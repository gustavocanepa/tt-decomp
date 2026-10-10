/* compiler: ee-gcc2.9-991111 */
struct Ent {
    unsigned char kind;
    unsigned char val;
};

struct Queue {
    int head;
    int tail;
    struct Ent e[512];
};

extern struct Queue D_0078B928;
extern int D_0078B920;
extern int D_005A30C4;
extern void func_004FA850(int sema);

int func_004FB780(unsigned int c) {
    struct Queue *q;
    int i;
    if (c >= 0x80 || D_005A30C4 == 0)
        return -1;
    q = &D_0078B928;
    i = q->tail & 0x1FF;
    q->tail = i + 1;
    q->e[i].kind = 1;
    q->e[i].val = c;
    func_004FA850(D_0078B920);
    return c;
}
