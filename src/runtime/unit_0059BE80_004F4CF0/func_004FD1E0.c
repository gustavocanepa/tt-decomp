/* compiler: ee-gcc2.9-991111 */
/* vsprintf-style wrapper over the shared formatter (newlib vsprintf.c shape): the sink context
   carries the destination buffer; func_004FD0E8 stores each produced character. */
typedef char *va_list;

typedef struct Ctx {
    char *buf;
    int pad[3];
} Ctx;

extern int func_004FD0E8();
extern int func_004FC3D0(int (*)(), Ctx *, const char *, int, va_list);

int func_004FD1E0(char *buf, const char *fmt, int x, va_list args) {
    Ctx ctx;
    ctx.buf = buf;
    return func_004FC3D0(func_004FD0E8, &ctx, fmt, x, args);
}
