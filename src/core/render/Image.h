/* date = August 24th 2023 4:58 pm */
#include <string>

#ifndef _IMAGE_H
#define _IMAGE_H

namespace Skruv 
{
    class Image 
    {
        public:
        Image(std::string path);
        Image(unsigned char* data, int nCols, int nRows, int nChannels);
        Image();
        ~Image();
        
        Image( const Image& );
        Image& operator=( const Image& );
        
        private:
        int m_Width, m_Height, m_ChannelCount;
        unsigned int m_Handle;
    };
}

#endif //_IMAGE_H
