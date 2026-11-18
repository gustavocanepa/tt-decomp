/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00206DF8(int);
extern "C" int func_0027B6B8(int, int, int) throw();
extern "C" int func_0027B848(int a, int b, int first, int last, int count) {
start:
        if (first == last) return first;
        int middle = first;
        int half = count / 2;
        int n = half;
        while (n > 0) {
            --n;
            middle = func_00206DF8(middle);
        }
        if (func_0027B6B8(a, b, middle)) {
            last = middle;
            count = half;
            goto start;
        } else {
            if (middle == first) return last;
            first = middle;
            count -= half;
            goto start;
        }
}
