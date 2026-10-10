/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Queue {
    int pad0[3];
    int size;
    int tail;
    int pad14;
    int count;
    int pad1C;
    int sema;
};

extern int D_00598410;
extern void func_004FA860(int sema);
extern void func_004FA840(int sema);

void func_004CDD08(struct Queue *q) {
    func_004FA860(q->sema);
    if (++q->count == q->size) {
        if (D_00598410 == 0)
            D_00598410 = 1;
    }
    q->tail = q->tail + 1 == q->size ? 0 : q->tail + 1;
    func_004FA840(q->sema);
}
