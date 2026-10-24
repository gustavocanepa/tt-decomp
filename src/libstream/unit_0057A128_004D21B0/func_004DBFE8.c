/* compiler: ee-gcc2.9-991111 */
/* Operation 12 sends a bounded string and receives text through a separate
 * DMA buffer. The callback copies it to the caller's output, then signals
 * completion. Partial packet fields and operation meanings are provisional. */
struct Client { char unknown0[0x24]; void *server; };
struct Command {
    int argument0, argument1;
    char unknown8[8];
    char *response;
    char text[1024];
};
extern struct Client D_00782AC0;
extern struct Command D_00782B70;
extern char D_00783080[1024], D_00784080;
extern int D_005A0BF4, D_005A0BF0;
extern int func_004FA870(int);
extern int func_004FA840(int);
extern char *func_004F8588(char *, const char *, unsigned int);
extern void func_004FDAF8(void *, int);
extern void func_004DBF58(char *);
extern int func_004FE530(struct Client *, int, int, void *, int, void *, int,
    void (*)(char *), char *);
int func_004DBFE8(int argument0, int argument1, const char *text, char *output) {
    if (!D_00782AC0.server) return -100;
    if (func_004FA870(D_005A0BF4) < 0) return -200;
    if (!text || !*text) {
        func_004FA840(D_005A0BF4);
        return -210;
    }
    D_00782B70.argument0 = argument0;
    D_00782B70.argument1 = argument1;
    D_00782B70.response = D_00783080;
    func_004F8588(D_00782B70.text, text, 1023);
    D_00782B70.text[1023] = 0;
    func_004FDAF8(D_00783080, 1024);
    if (func_004FE530(&D_00782AC0, 12, 1, &D_00782B70, 1044,
                     &D_00784080, 4, func_004DBF58, output)) {
        func_004FA840(D_005A0BF4);
        return -91;
    }
    D_005A0BF0 = 12;
    return 0;
}
