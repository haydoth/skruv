#section vertex

#version 330 core
layout (location = 0) in vec3 _position;
layout (location = 1) in vec2 _uv;
layout (location = 2) in vec3 _normal;
layout (location = 3) in vec3 _tangent;
layout (location = 4) in vec3 _bitangent;
layout (location = 5) in vec3 _color;

out vec3 tmpColor;

uniform vec3 u_Color;

void main()
{
    gl_Position = vec4(_position, 1.0);
    tmpColor = u_Color;
}

#section fragment

#version 330 core
out vec4 FragColor;

in vec3 tmpColor;

void main()
{
    FragColor = vec4(tmpColor, 1.0f);
}