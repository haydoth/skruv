#include "core/Skruv.h"

int main()
{
    Skruv::State state = Skruv::State();
    
    // entity memory is owned by the state!! :)))
    Skruv::Entity guy = state.scene->CreateEntity("guy");
    std::cout << guy.GetComponent<Skruv::NameComponent>().Name << "\n";
    
    std::string basicShaderString = "src/shaders/Basic.shader";
    Skruv::ShaderSource src = Skruv::Shader::ParseShaderSource(basicShaderString);
    
    std::cout << "vertex" << "\n";
    std::cout << src.VertexSource << "\n";
    
    std::cout << "fragment" << "\n";
    std::cout << src.FragmentSource << "\n";
    
    // maybe shaders should also be owned by the state?
    // also holy shit make a cleaner solution for adding shader props
    
    std::string u_Color = "u_Color";
    Skruv::ShaderProperties shaderProps = Skruv::ShaderProperties({{u_Color, Skruv::ShaderProperty<glm::vec3>(u_Color)}});
    
    Skruv::Shader basicShader(src, shaderProps);
    state.shaderLibrary->AddShader("Basic", basicShader);
    
    state.Run();
    
    return 0;
}
