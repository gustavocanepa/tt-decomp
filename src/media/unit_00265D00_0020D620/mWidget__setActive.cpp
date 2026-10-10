extern "C" void func_0020D860(void *node, void *arg);
extern "C" int func_0020D610(void *node);
extern "C" void *func_00206DD8(void *node);

extern "C" void mWidget__setActive(void *node, void *arg)
{
    func_0020D860(node, arg);
    if (func_0020D610(node)) {
        func_0020D860(node, arg);
        if (func_00206DD8(node))
            mWidget__setActive(func_00206DD8(node), arg);
    }
}
