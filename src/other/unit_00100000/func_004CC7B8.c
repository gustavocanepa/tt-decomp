struct Slot { int id; void *buf; };
extern struct Slot D_00779F80[7];
void func_004CBBC8(void *buf);
void *func_004F6678(void *dst, int c, unsigned int n); /* func_004F6678 */

void func_004CC7B8(void)
{
    int i;

    for (i = 0; i < 7; i++)
        func_004CBBC8(D_00779F80[i].buf);
    func_004F6678(D_00779F80, 0, sizeof(D_00779F80));
}
