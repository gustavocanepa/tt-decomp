/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char pad[16]; int size; };
struct Owner { char pad[8]; int extent; char padc[0x1c]; Block *block; };
extern "C" int func_0041DD08(Owner *, void *, int) throw();
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" Block *func_0041E158(Owner *p, int size) {
    int old = 0;
    if (p->block) old = p->block->size;
    Block *block = p->block;
    if (!block) block = (Block *)((char *)p + p->extent);
    p->block = 0;
    block = (Block *)(((unsigned int)block + 15) & ~15u);
    int grow = size - old;
    func_0041DD08(p, block, (grow + 15) & ~15);
    p->block = block;
    func_004F6678(block, 0, size);
    return p->block;
}
