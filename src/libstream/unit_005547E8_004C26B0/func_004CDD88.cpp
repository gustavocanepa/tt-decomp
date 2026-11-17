/* Current func_005AE2E8 position of a stream buffer: 0 without a handle or when func_004CDC38 reports a
   problem, else base + idx * size func_005AE2E8 under the buffer's semaphore. func_004CDC38 is declared
   throw(): otherwise reorg sees $v0 live after the first test and annuls its slot (beql). */
struct Buf { int base; int pad4; int size; int padc; int pad10; int idx; int count; int handle; int sema; };
extern "C" int func_004CDC38(Buf *) throw();
extern "C" int func_004FA860(int), func_004FA840(int);
extern "C" int func_004CDD88(Buf *b) {
    if (b->handle == -1 || func_004CDC38(b)) return 0;
    func_004FA860(b->sema);
    int r = b->base + b->idx * b->size;
    func_004FA840(b->sema);
    return r;
}