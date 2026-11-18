inline unsigned char rgb(float value) {
 if (value < 0.0f) return 0;
 if (value > 1.0f) return 255;
 return (unsigned int)(value * 255.0f);
}
extern "C" unsigned int func_002134A8(float* color, float scale) {
 unsigned char r=rgb(color[0]);
 unsigned int g=rgb(color[1]);
 unsigned int b=rgb(color[2]);
 unsigned char a;
 if (color[3] < 0.0f) a=(unsigned int)(scale*0.0f);
 else if (color[3] > 1.0f) a=(unsigned int)(128.0f*scale);
 else a=(unsigned int)((color[3]*128.0f)*scale);
 return (r | (a<<24)) | ((b<<16) | (g<<8));
}
