typedef unsigned int u32;
struct Pool { u32 base; u32 size; u32 itemSize; u32 freeList; u32 unused10; u32 count; };
/* Threads 16-byte aligned items of itemSize bytes from the arena into a singly linked free list. */
extern "C" void func_0056EEE0(Pool *pool) {
    u32 base = pool->base;
    u32 alignMask = 15;
    u32 inv = -16;
    u32 stride0 = pool->itemSize;
    u32 item = (base + alignMask) & inv;
    u32 stride = (stride0 + alignMask) & inv;
    u32 limit = base + pool->size;
    u32 next = item + stride;
    u32 head = 0;
    pool->unused10 = 0;
    pool->count = 0;
    while (next <= limit) {
        *(u32 *)item = head;
        head = item;
        item = next;
        next += stride;
        pool->count++;
    }
    pool->freeList = head;
}
