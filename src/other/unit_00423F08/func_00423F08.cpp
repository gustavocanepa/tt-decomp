extern "C" char func_00423D98(int arg0);

extern "C" void func_00423F08(int arg0, char *arg1, int arg2) {
    int count;
    char *p;

    count = arg2;
    p = arg1;
    if (count != 0) {
        do {
            count -= 1;
            *p = func_00423D98(arg0);
            p += 1;
        } while (count != 0);
    }
}
