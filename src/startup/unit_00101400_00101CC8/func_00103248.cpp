extern void func_004F7B74(void *arg0, const char *arg1);
extern void func_004F7A30(void *arg0, const char *arg1);
extern const char *D_00579420;
extern const char D_005DD210[];
extern const char D_00623D88[];

void *func_00103248(void *str, const char *name)
{
    func_004F7B74(str, D_00579420);
    func_004F7A30(str, name);
    func_004F7A30(str, D_005DD210);
    func_004F7A30(str, D_00623D88);
    return str;
}
