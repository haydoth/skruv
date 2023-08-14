#include "Shader.h"

#include <fstream>
#include <sstream>

#include <glad/glad.h>

namespace Skruv 
{
    void checkCompileErrors(unsigned int shader, std::string type);
    
    ShaderSource Shader::ParseShaderSource(std::string& path) 
    {
        std::ifstream stream(path);
        
        std::string line;
        std::stringstream strStream[2];
        ShaderType type = ShaderType::NONE;
        
        while(getline(stream, line))
        {
            if(line.length() == 0){
                continue;
            }
            
            if(line.find("#section") != std::string::npos) 
            {
                if(line.find("vertex") != std::string::npos) 
                {
                    type = ShaderType::VERTEX;
                }
                else if(line.find("fragment") != std::string::npos) 
                {
                    type = ShaderType::FRAGMENT;
                }
            }
            else
            {
                if(type != ShaderType::NONE) {
                    strStream[(int)type] << line << '\n';
                }
            }
        }
        return { strStream[0].str(), strStream[1].str() };
    }
    
    Shader::Shader(ShaderSource src, ShaderProperties props) : m_Properties(props)
    {
        const char* vertexSource = src.VertexSource.c_str();
        const char* fragmentSource = src.FragmentSource.c_str();
        
        unsigned int vertex, fragment;
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertexSource, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragmentSource, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        m_Handle = glCreateProgram();
        glAttachShader(m_Handle, vertex);
        glAttachShader(m_Handle, fragment);
        glLinkProgram(m_Handle);
        checkCompileErrors(m_Handle, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
}