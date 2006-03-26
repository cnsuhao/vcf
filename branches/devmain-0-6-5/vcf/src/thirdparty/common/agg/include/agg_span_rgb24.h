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
// class span_rgb24
//
//----------------------------------------------------------------------------

#ifndef AGG_SPAN_RGB24_INCLUDED
#define AGG_SPAN_RGB24_INCLUDED

#include "thirdparty/common/agg/include/agg_basics.h"

namespace agg
{

    //========================================================================
    template<class BaseRenderer> class span_rgb24 : public BaseRenderer
    {
    public:
        void render(unsigned char* ptr, 
                    int x, int y,
                    unsigned count, 
                    const unsigned char* covers, 
                    const typename BaseRenderer::attr_type& attr)
        {
            typename BaseRenderer::interpolator span = begin(x, y, count, attr);
            unsigned char* p = ptr + x + x + x;
            do
            {
                span.calculate();
                int alpha = (*covers++) * span.a();
                int r = p[0];
                int g = p[1];
                int b = p[2];
                *p++ = (((span.r() - r) * alpha) + (r << 16)) >> 16;
                *p++ = (((span.g() - g) * alpha) + (g << 16)) >> 16;
                *p++ = (((span.b() - b) * alpha) + (b << 16)) >> 16;
                span.step();
            }
            while(--count);
        }
    };
}


#endif