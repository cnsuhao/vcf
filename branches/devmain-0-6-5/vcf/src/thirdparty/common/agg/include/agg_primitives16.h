//----------------------------------------------------------------------------
// Anti-Grain Geometry - Version 2.0 
// Copyright (C) 2002 Maxim Shemanarev (McSeem)
//
// Permission to copy, use, modify, sell and distribute this software 
// is granted provided this copyright notice appears in all copies. 
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//
//----------------------------------------------------------------------------
// Contact: mcseem@antigrain.com
//          mcseemagg@yahoo.com
//          http://www.antigrain.com
//----------------------------------------------------------------------------
//
// Basic primitives for fast drawing regular (aliased) figures 
// Supports any 16-bit color buffer.
//
//----------------------------------------------------------------------------

#ifndef AGG_PRIMITIVES16_INCLUDED
#define AGG_PRIMITIVES16_INCLUDED

#include "thirdparty/common/agg/include/agg_basics.h"
#include "thirdparty/common/agg/include/agg_rendering_buffer.h"


namespace agg
{

    class primitives16
    {
    public:
        primitives16(rendering_buffer& rbuf) : m_rbuf(&rbuf) {}

        void pixel(int x, int y, unsigned c)
        {
            if(x >= m_rbuf->clip_box().x1 && y >= m_rbuf->clip_box().y1 && 
               x <= m_rbuf->clip_box().x2 && y <= m_rbuf->clip_box().y2)
            {
               *(((int16u*)m_rbuf->row(y)) + x) = int16u(c);
            }
        }

        void hor_line(int x1, int y, int x2, unsigned c)
        {
            const rect& cb = m_rbuf->clip_box();
            if(x1 > cb.x2) return;
            if(x2 < cb.x1) return;
            if(y  > cb.y2) return;
            if(y  < cb.y1) return;

            if(x1 < cb.x1) x1 = cb.x1;
            if(x2 > cb.x2) x2 = cb.x2;

            int16u* p     = ((int16u*)m_rbuf->row(y)) + x1;
            int16u* p_end = p + (x2 - x1);
            do 
            {
                *p++ = int16u(c);
            }
            while(p <= p_end);
        }


        void ver_line(int x, int y1, int y2, unsigned c)
        {
            const rect& cb = m_rbuf->clip_box();
            if(x  > cb.x2) return;
            if(x  < cb.x1) return;
            if(y1 > cb.y2) return;
            if(y2 < cb.y1) return;

            if(y1 < cb.y1) y1 = cb.y1;
            if(y2 > cb.y2) y2 = cb.y2;

            unsigned char* p = m_rbuf->row(y1) + (x << 1);
            int stride =  m_rbuf->row_bytes();   
            do 
            {
                *(int16u*)p = int16u(c);
                p += stride;
            }
            while(++y1 <= y2);
        }


        void solid_rectangle(int x1, int y1, int x2, int y2, unsigned c)
        {
            const rect& cb = m_rbuf->clip_box();
            if(x1 < cb.x1) x1 = cb.x1;
            if(y1 < cb.y1) y1 = cb.y1;
            if(x2 > cb.x2) x2 = cb.x2;
            if(y2 > cb.y2) y2 = cb.y2;
            if(x1 <= x2 && y1 <= y2)
            {
                unsigned char* py = m_rbuf->row(y1) + (x1 << 1);
                int stride =  m_rbuf->row_bytes();   
                do 
                {
                    int16u* px = (int16u*)py;
                    int16u* px_end = px + (x2 - x1);
                    do 
                    {
                        *px++ = int16u(c);
                    }
                    while(px <= px_end);
                    py += stride;
                }
                while(++y1 <= y2);
            }
        }

    protected:
        rendering_buffer* m_rbuf;
    };


}


#endif