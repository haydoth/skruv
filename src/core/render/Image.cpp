#include "core/render/Image.h"

#include <stb_image.h>
#include <stb_image_write.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

namespace Skruv 
{
    Image::Image(std::string path) 
    {
        glGenTextures(1, &m_Handle);
        glBindTexture(GL_TEXTURE_2D, m_Handle);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        stbi_set_flip_vertically_on_load(true);
        
        unsigned char* data = stbi_load(FileSystem::getPath("resources/textures/container.jpg").c_str(), &m_Width, &m_Height, &m_ChannelCount, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            m_PixelData = data;
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }
    Image::Image(unsigned char* data, int nCols, int nRows, int nChannels) 
    {
        
    }
}