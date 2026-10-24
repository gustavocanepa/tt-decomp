/* compiler: ee-gcc2.9-991111 */
/* gzip header: return the NUL-terminated comment field, or NULL on a bad header. */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_004D9B38(u8 *data, u8 **extra, u8 **name, u8 **comment, u16 *hcrc, u8 **end);

u8 *func_004D9CC0(u8 *data)
{
    u8 *name;
    if (func_004D9B38(data, 0, 0, &name, 0, 0) < 0)
        return 0;
    return name;
}
