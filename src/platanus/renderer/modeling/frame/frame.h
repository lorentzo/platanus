
#include "./../../../foundation/math/vector.h"

class Frame
{

  public:

    Frame(int frame_width, int frame_height);

    void save();

    int m_frame_width;
    int m_frame_height;
    Vector3d *m_frame_buffer;


};