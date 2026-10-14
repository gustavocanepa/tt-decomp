extern "C" void func_0010C360(int sel, int *a, int *b) {
    *a = 0;
    *b = 0;
    switch (sel) {
    case 1:
        *b = 1;
        break;
    case 2:
        *a = 1;
        *b = 1;
        break;
    }
}
