/* compiler: ee-gcc2.9-991111 */
struct Module {
    struct Module *next;
    char *name;
    unsigned short version;
    unsigned short attribute;
    int id;
    int f10, f14, f18;
    unsigned int entry;
    unsigned int gp;
    unsigned int text_start;
    unsigned int text_size;
    unsigned int data_size;
    unsigned int bss_size;
    unsigned int f34;
    unsigned int f38;
    unsigned int f3c;
    unsigned int f40;
};

struct ModuleStatus {
    char name[56];
    unsigned short version;
    unsigned short attribute;
    int id;
    unsigned int entry;
    unsigned int gp;
    unsigned int text_start;
    unsigned int text_size;
    unsigned int data_size;
    unsigned int bss_size;
    unsigned int f58;
    unsigned int f5c;
    unsigned int f60;
    unsigned int f64;
};

struct ErxInfo { char pad[0x18]; struct Module *modules; };

extern int D_005A0BB0;
extern struct ErxInfo *func_004D9DD8(int);
extern void func_004F8588(void *, void *, int);
extern int func_005038D8(void);
extern int func_00503928(void);

/* _sceErxReferModuleStatus */
int func_004D4298(int modid, struct ModuleStatus *status)
{
    struct Module *m;
    int intr;

    if (!D_005A0BB0)
        return 0x81058001;
    if (status == 0)
        return 0x8105000E;
    intr = func_005038D8();
    for (m = func_004D9DD8(0)->modules; m != 0; m = m->next) {
        if (modid != m->id)
            continue;
        status->name[0] = 0;
        if (m->name != 0)
            func_004F8588(status->name, m->name, 0x38);
        status->name[0x37] = 0;
        status->id = m->id;
        status->version = m->version;
        status->entry = m->entry;
        status->attribute = m->attribute;
        status->gp = m->gp;
        status->text_start = m->text_start;
        status->text_size = m->text_size;
        status->data_size = m->data_size;
        status->bss_size = m->bss_size;
        status->f58 = m->f34;
        status->f5c = m->f38;
        status->f60 = m->f3c;
        status->f64 = m->f40;
        if (intr)
            func_00503928();
        return 0;
    }
    if (intr)
        func_00503928();
    return 0x8105902D;
}
