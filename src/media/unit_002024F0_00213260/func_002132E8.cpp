inline unsigned char rgb(float value) {
 if (value < 0.0f) return 0;
 if (value > 1.0f) return 255;
 return (unsigned int)(value * 255.0f);
}
extern "C" unsigned int func_002132E8(float* color) {
 unsigned char r=rgb(color[0]);
 unsigned int g=rgb(color[1]);
 unsigned int b=rgb(color[2]);
 unsigned char a=rgb(color[3]);
 return (r | (a<<24)) | ((b<<16) | (g<<8));
}
