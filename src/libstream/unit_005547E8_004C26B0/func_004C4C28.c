/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct { char b[24]; } Block24;

extern char D_005A0B88[];
extern void func_004A4930(void *lock);
extern void func_004A4970(void *lock);

void func_004C4C28(char *obj, Block24 *src) {
    func_004A4930(D_005A0B88);
    *(Block24 *)(obj + 0x1C) = *src;
    *(int *)(obj + 0x14) = 3;
    func_004A4970(D_005A0B88);
}
