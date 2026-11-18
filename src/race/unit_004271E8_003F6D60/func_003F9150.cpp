struct Rec { int w[11]; };
extern "C" void func_003F8FB8(Rec *, int);
extern "C" void func_003F9150(Rec *arr, unsigned idx) {
    if (idx < 10) {
        int i = idx;
        if (i < 9) {
            do {
                arr[i] = arr[i + 1];
                i++;
            } while (i < 9);
        }
        func_003F8FB8(arr + 9, i);
    }
}
