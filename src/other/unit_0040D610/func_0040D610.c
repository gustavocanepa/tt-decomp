struct Info { int w[16]; };
extern void func_0040D428(void *, int, struct Info *);
int func_0040D610(void *a, int b)
{
    struct Info info;
    func_0040D428(a, b, &info);
    return info.w[9] & 0xFFFFFF;
}
