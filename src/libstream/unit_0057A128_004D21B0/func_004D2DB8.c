/* compiler: ee-gcc2.9-991111 */
struct MemBlock {
    unsigned int next;
    unsigned int used : 1;
    unsigned int addr : 31;
    unsigned int f8 : 1;
    unsigned int size : 31;
};

struct SysMem {
    int f0, f4;
    unsigned int f8;
    struct MemBlock *fC;
    unsigned int f10;
    unsigned int f14;
};

struct SysMemInfo {
    int addr;
    int size;
    unsigned int key;
    struct MemBlock *block;
};

extern struct SysMem D_0077A008;
extern int func_005038D8(void);
extern void func_00503928(void);

/* _sceErxGetSysMemoryInfo */
void func_004D2DB8(int mode, struct SysMemInfo *info)
{
    struct MemBlock *b, *p;
    int intr;

    intr = func_005038D8();
    if (mode != 0) {
        info->addr = D_0077A008.f10;
        info->block = (struct MemBlock *)((char *)D_0077A008.fC + 4);
        info->size = D_0077A008.f8;
        info->key = D_0077A008.f14;
    } else {
        if (info->key != D_0077A008.f14) {
            info->block = 0;
            info->addr = -1;
            info->size = -1;
        } else {
            b = info->block;
            if (b == 0) {
                info->addr = D_0077A008.f8;
                info->size = 1;
            } else {
                info->addr = b->addr << 8;
                info->size = b->size << 8;
                if (!b->used) {
                    info->size |= 1;
                } else {
                    for (p = D_0077A008.fC; p != 0; p = (struct MemBlock *)p->next) {
                        if ((int)p == info->addr) {
                            info->size |= 2;
                            break;
                        }
                    }
                }
                info->block = (struct MemBlock *)b->next;
                if (info->block->size == 0)
                    info->block = 0;
            }
        }
    }
    if (intr)
        func_00503928();
}
