/* compiler: ee-gcc2.96-nsa-as2004 */
struct Block {
    char pad0[4];
    int size;
    Block *next;
} __attribute__((packed));

struct Pool {
    char pad0[0xC];
    char queue[0xC];
    unsigned int flags;
    char pad1[0x34 - 0x1C];
    int total;
};

extern "C" int func_005038D8(void);
extern "C" int func_00503928(void);
extern "C" void func_004C27D8(void *, void *);

extern "C" void func_004C2AD8(Pool *pool, Block *block)
{
    if (pool->flags & 1) {
        func_005038D8();
        while (block) {
            pool->total += block->size + 0x10;
            block = block->next;
        }
        func_00503928();
        func_004C27D8(pool, pool->queue);
    }
}
