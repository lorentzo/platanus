
#pragma once

#include "foundation/math/vector.h"

namespace renderer {

class Frame
{

  public:

    Frame();

    Frame(int frame_width, int frame_height);

    void save();

    int m_frame_width;
    int m_frame_height;
    foundation::Vector3d *m_frame_buffer;


};

} // namespace renderer