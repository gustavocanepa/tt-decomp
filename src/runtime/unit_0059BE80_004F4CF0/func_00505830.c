/* compiler: ee-gcc2.9-991111 */
typedef struct Entry {
    struct Entry *next;
    volatile int id;
    int pad[2];
} Entry;
extern int func_00504BB8(int id);
extern Entry *D_00791BC0;

int func_00505830(int id)
{
    Entry *e = (Entry *)(((unsigned int)id >> 8) << 4);
    int r;
    if (id < 0 || ((id ^ e->id) & 0xFF) != 0)
        return 0x80008002;
    r = func_00504BB8(e->id);
    if (r == 0) {
        e->next = D_00791BC0;
        D_00791BC0 = e;
        e->id = 0;
    }
    return r;
}
