typedef unsigned int u32;
extern "C" void func_004AFA40(float *hue, float *sat, float *val, float r, float g, float b);
/* Unpacks 0x00BBGGRR into [0,1] floats and converts to HSV. */
extern "C" void func_004AFB90(u32 rgb, float *hue, float *sat, float *val) {
    float r = (float)(rgb & 0xFF) / 255.0f;
    float g = (float)((rgb >> 8) & 0xFF) / 255.0f;
    float b = (float)((rgb >> 16) & 0xFF) / 255.0f;
    func_004AFA40(hue, sat, val, r, g, b);
}
