/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x10];
    char lock[0x98];
    char listA8[8];
} Manager_004AC6F8;

typedef struct {
    char pad0[0x3C];
    char node[0xC];
} Item_004AC6F8;

extern Manager_004AC6F8 D_00773880;

void func_00481550(Item_004AC6F8 *item);
void func_004A4D68(void *lock);
void func_004A4DD8(void *lock);
void func_004AC838(void *list, void *node);

void func_00481630(Item_004AC6F8 *item) {
    Manager_004AC6F8 *m;
    func_00481550(item);
    m = &D_00773880;
    func_004A4D68(m->lock);
    func_004AC838(m->listA8, item->node);
    func_004A4DD8(m->lock);
}
