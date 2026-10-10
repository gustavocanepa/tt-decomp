/* compiler: ee-gcc2.9-991111 */
typedef struct Node {
    struct Node *next;
    int data[3];
} Node;

extern Node D_007917C0[64];
extern Node *D_00791BC0;

int func_005054B8(void) {
    int i;
    D_00791BC0 = D_007917C0;
    for (i = 63; i >= 0; i--)
        D_007917C0[i].next = &D_007917C0[i + 1];
    D_007917C0[63].next = 0;
    return 0;
}
