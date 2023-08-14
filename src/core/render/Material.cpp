#include "Material.h"

#include <toml++/toml.h>

namespace Skruv 
{
    Material::Material(std::string& path) 
    {
        toml::table tbl;
        if(parse_toml_file(path, tbl)) 
        {
            // TODO: extract shader path to get its handle and properties
            // also extract material name and properties to apply to the shader.
            
            std::string name = tbl["name"].value<std::string>();
            std::string shader = tbl["shader"].value<std::string>();
            
            m_Name = name;
        }
    }
    
    bool parse_toml_file(std::string path, toml::table& table_ref) 
    {
        try
        {
            tbl = toml::parse_file(path);
            table_ref = tbl;
            return true;
        }
        catch (const toml::parse_error& err)
        {
            std::cerr << "Failed to parse TOML file: \n" << err << "\n";
            return false;
        }
    }
}