/* compiler: ee-gcc2.9-991111 */
struct Entry { char pad[8]; struct Entry *next; int unkC; char *name; unsigned short version; };
extern int D_005A0BB0;
extern struct Entry *D_0077A028;
extern int func_004A8268(const char *, const char *);
extern int func_005038D8(void);
extern int func_00503928(void);
struct Entry *func_004D4C68(const char *name, unsigned short version) {
    int intr;
    struct Entry *p;
    if (D_005A0BB0) {
        intr = func_005038D8();
        p = D_0077A028;
        for (; p; p = p->next) {
            if (func_004A8268(p->name, name) == 0) {
                if ((p->version >> 8) == (version >> 8)) {
                    if (intr) func_00503928();
                    return p;
                }
            }
        }
        if (intr) func_00503928();
    }
    return 0;
}
