#include "types.h"

extern "C" f32 D_00584064;
extern "C" void CourseData__evalVMMethods(void);

extern "C" void CourseData__render_course_for_renderer(f32 fparg0) {
    D_00584064 = fparg0;
    CourseData__evalVMMethods();
}
