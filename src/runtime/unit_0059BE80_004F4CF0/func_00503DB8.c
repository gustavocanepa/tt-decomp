/* compiler: ee-gcc2.9-991111 */
extern char *D_005A44B8;
struct Args { int x; int y; };
extern struct Args D_005A3960;
extern int func_00503DA8(int, int);
extern int func_00503D68(void *, const void *, int);
extern int func_004A8368(const char *);
char *func_00503DB8(const char *name, int argc, const char **argv) {
    char *table = D_005A44B8;
    struct Args *config = &D_005A3960;
    char *out = table + 0x40;
    char *end = out;
    int len;
    const char **arg;
    func_00503DA8(config->x, config->y);
    if (argc >= 16) argc = 15;
    func_00503D68(table, &out, 4);
    table += 4;
    len = func_004A8368(name) + 1;
    func_00503D68(out, name, len);
    out += len;
    if (argc > 0) {
        arg = argv;
        do {
            func_00503D68(table, &out, 4);
            table += 4;
            argc--;
            len = func_004A8368(*arg) + 1;
            func_00503D68(out, *arg, len);
            arg++;
            out += len;
        } while (argc != 0);
    }
    return end;
}
