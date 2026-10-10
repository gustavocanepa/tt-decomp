/* compiler: ee-gcc2.9-991111 */
struct SemaParam {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    unsigned int attr;
    unsigned int option;
};
extern char D_00617C30[];
extern char D_00617C40[];
extern int D_005A3198;
extern int D_005A319C;
int func_004FA820(struct SemaParam *p);

void func_00503940(void)
{
    struct SemaParam p1, p2;

    p1.max_count = 1;
    p1.init_count = 1;
    p1.option = (unsigned int)D_00617C30;
    p2.max_count = 1;
    p2.init_count = 1;
    p2.option = (unsigned int)D_00617C40;
    D_005A3198 = func_004FA820(&p1);
    D_005A319C = func_004FA820(&p2);
}
