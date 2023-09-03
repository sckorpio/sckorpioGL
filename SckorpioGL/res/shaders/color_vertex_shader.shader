#shader vertex
#version 330 core
layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vCol;
out vec3 eachcol;

void main()
{
	gl_Position = vec4(vPos.x, vPos.y, vPos.z , 1.0);
	eachcol = vCol;
}

#shader fragment
#version 330 core
out vec4 FragColor;
in vec3 eachcol;
void main()
{
	FragColor = vec4(eachcol,1.0f);
}
