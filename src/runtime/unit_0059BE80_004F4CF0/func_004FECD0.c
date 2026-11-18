/* compiler: ee-gcc2.9-991111 */
/* Count live descriptors while owning the table semaphore. The table has
 * 32 sixteen-byte records; the backend handle is distinct from occupancy. */
struct Entry { int handle, occupied, unknown8, unknownC; };
extern struct Entry D_0078F200[32];
extern int D_005A3168;
extern void func_004FEC60(void);
extern int func_004FA860(int);
extern int func_004FA840(int);
int func_004FECD0(void) {
    struct Entry *entry;
    int count = 0;
    func_004FEC60();
    func_004FA860(D_005A3168);
    for (entry = D_0078F200; entry < D_0078F200 + 32; ++entry)
        if (entry->occupied) ++count;
    func_004FA840(D_005A3168);
    return count;
}
