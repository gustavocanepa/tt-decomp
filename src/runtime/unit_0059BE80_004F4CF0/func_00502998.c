/* compiler: ee-gcc2.9-991111 */
extern char D_0078F728[];
extern char D_005A30B8[];
extern char *D_005A3178;
int func_004A81B8(const char *, const char *, int);

int func_00502998(void)
{
    char *b = D_005A30B8;
    char *a = D_0078F728;
    return func_004A81B8(a, b, 4) && func_004A81B8(a, D_005A3178, 4) && func_004A81B8(b, D_005A3178, 4);
}
