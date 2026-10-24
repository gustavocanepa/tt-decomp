/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk {
    int pad0;
    int end;
    Blk *prev;
    Blk *next;
};
struct Heap {
    char pad0[0xC];
    Blk *bins[1];
};
extern "C" int func_004ADE20(Heap *, int);
extern "C" void func_004ADCE0(Heap *h, Blk *b) {
    int size = b->end - (int)b;
    int idx = func_004ADE20(h, size);
    Blk *cur = h->bins[idx];
    Blk *prev = 0;
    while (cur != 0) {
        int sz = cur->end - (int)cur;
        if (size < sz) break;
        if (size == sz && b < cur) break;
        prev = cur;
        cur = cur->next;
    }
    if (prev != 0) prev->next = b;
    else h->bins[idx] = b;
    b->prev = prev;
    b->next = cur;
    if (cur != 0) cur->prev = b;
}
