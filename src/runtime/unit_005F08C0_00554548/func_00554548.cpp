/* compiler: ee-gcc2.96-no-strict-aliasing */
/* The lower bound goes through a const-reference comparison (the temporary for 0 is what
   leaves the unused 16-byte frame and the zero held in a register). */
static inline bool lt(const int &a, const int &b) { return a < b; }
extern "C" bool func_00554548(int x) {
    bool r = false;
    if (lt(0, x) && x < 3) r = true;
    return r;
}
