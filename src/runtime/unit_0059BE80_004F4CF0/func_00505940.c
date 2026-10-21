/* compiler: ee-gcc2.9-991111 */
/* Replace the caller-owned 16-byte entry table under interrupt exclusion.
 * The previous table is returned to its owner; the replacement is cleared.
 * Callback register types and the final word remain provisional. */
struct Entry {
    void (*callback)(int, void *);
    void *argument;
    void *global_pointer;
    unsigned unknownC;
};
extern struct Entry *D_005A4130;
extern unsigned int D_005A4134;
extern int func_005038D8(void);
extern int func_00503928(void);
extern void *func_004F6678(void *, int, unsigned int);
struct Entry *func_00505940(struct Entry *table, unsigned int count) {
    int interrupts = func_005038D8();
    struct Entry *previous = D_005A4130;
    D_005A4130 = table;
    D_005A4134 = count;
    func_004F6678(table, 0, count * sizeof(struct Entry));
    if (interrupts) func_00503928();
    return previous;
}
