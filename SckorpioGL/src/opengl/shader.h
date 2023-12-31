#ifndef SHADER_H
#define SHADER_H
#define GL_GLEXT_PROTOTYPES

#include <GL/glew.h>  
#include <GL/gl.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{

private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	
public:
	Shader();
	~Shader();
    void Gen(const std::string& filepath);
	void Bind() const;
	void UnBind() const;

	//set uniforms
	void SetUniform1i(const std::string& name, int value);
	void SetUniform1iv(const std::string& name, int count, int* value);
	void SetUniform1f(const std::string& name, float value);
	void SetUniform4f(const std::string& name,float v0,float v1,float v2,float v3);
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);
	void SetUniform3fv(const std::string& name, const glm::vec3& vec);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
	unsigned int GetUniformLocation(const std::string& name);
    
    unsigned int compileShaders(std::string shader, GLenum type);
    ShaderProgramSource ParseShader(const std::string& filepath);
    unsigned int linkProgram(unsigned int vertexShaderID, unsigned int fragmentShaderID);
    unsigned int CreateShaderProgram(float R,float G,float B,float A);
};


#endif // SHADER_H