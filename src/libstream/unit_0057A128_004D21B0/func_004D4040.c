/* compiler: ee-gcc2.9-991111 */
struct Lib { int a, b; struct Lib *next; void *clients; char *name; };
struct Module { struct Module *next; int f4, f8, fC; unsigned int text_start; unsigned int text_size; };
struct G { struct Lib *libs; int f4; char pad[0x10]; struct Module *modules; int count; };
extern struct G D_0077A028;
extern void func_004FD2D0(const char *, ...);
extern int func_005038D8(void);
extern int func_00503928(void);

/* _sceErxReleaseModule */
void func_004D4040(struct Module *mod)
{
    struct Lib *lib;
    struct Module *prev, *m;
    int intr;

    if (mod == 0)
        return;
    intr = func_005038D8();
    for (lib = D_0077A028.libs; lib != 0; lib = lib->next) {
        if ((unsigned int)lib >= mod->text_start && (unsigned int)lib < mod->text_start + mod->text_size) {
            func_00503928();
            func_004FD2D0("liberx: PANIC!! a library still remained in unloading module(%08x,%s)\n", lib, lib->name);
            while (1)
                ;
        }
    }
    prev = (struct Module *)&D_0077A028.modules;
    while (prev->next != 0) {
        m = prev->next;
        if (m == mod) {
            prev->next = m->next;
            D_0077A028.count--;
            if (intr)
                func_00503928();
            return;
        }
        prev = m;
    }
    if (!intr)
        return;
    func_00503928();
}
