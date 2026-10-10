extern "C" int func_002FED98(int b);
extern "C" void func_003AF120(int a, int b, int c);
extern "C" void func_003BFAE0(int a, int b, int c);

extern "C" void func_0032EEE8(int a, int b, int c)
{
    switch (func_002FED98(b)) {
    case 0:
        break;
    case 1:
        return func_003AF120(a, b, c);
    }
    return func_003BFAE0(a, b, c);
}
