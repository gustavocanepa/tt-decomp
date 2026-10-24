static inline bool in_name(int i) { return i < 80; }
extern "C" char *func_00488380(char *input, char *out) {
    int j = 0;
    int i = 0;
    while (input[i] == '/' || input[i] == '\\') i++;
    while (in_name(i) && input[i] != '/' && input[i] != '\\' && input[i] != 0) {
        if (j < 12) out[j++] = input[i];
        else return 0;
        i++;
    }
    out[j] = 0;
    while ((input[i] == '/' || input[i] == '\\') && in_name(i)) i++;
    if (in_name(i)) return input + i;
    return 0;
}
