extern void func_004F7B74(void *arg0, const char *arg1);
extern void func_004F7A30(void *arg0, void *arg1);

void *func_0041DB78(void *arg0, void *arg1, int arg2)
{
    const char *path;

    if (arg2 != 0) {
        path = "wheel/menu/";
    } else {
        path = "wheel/lod/";
    }
    func_004F7B74(arg1, path);
    func_004F7A30(arg1, arg0);
    return arg1;
}
