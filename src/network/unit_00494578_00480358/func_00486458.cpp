/* The vowels "aiueo" (D_00605B48) copied to a local array, then searched. */
struct Vowels {
    char c[6];
};

extern "C" const Vowels D_00605B48;

extern "C" int func_00486458(int ch) {
    Vowels v = D_00605B48;
    for (int i = 0; i < 5; i++) {
        if (v.c[i] == ch)
            return i;
    }
    return -1;
}
