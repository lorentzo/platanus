
#include "frame.h"

#include "./../../../foundation/image/imagewriter.h"

Frame::Frame(
    int frame_width, 
    int frame_height)
  : m_frame_width(frame_width)
  , m_frame_height(frame_height)
{
    m_frame_buffer = new Vector3d[m_frame_width * m_frame_height];
}

void Frame::save()
{
  save_image_ppm(m_frame_buffer, m_frame_width, m_frame_height);
  delete [] m_frame_buffer;
}