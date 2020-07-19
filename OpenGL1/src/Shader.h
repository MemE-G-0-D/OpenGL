#pragma once
#include<unordered_map>
#include<string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct ShaderSource {
	std::string vSource;
	std::string fSource;
};
class Shader {
private:
	unsigned int m_RendererID;
	std::string m_filepath;
	std::unordered_map<std::string, int >m_UniformLocationCache;

	int GetUniformLocation(const std::string& name);
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	bool CompileShader();

	void setUniform1i(const std::string& name, int i0);
	void setUniform1f(const std::string& name, float v0);
	void setUniform2f(const std::string& name, float v0, float v1);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name ,float v0, float v1, float v2, float v3);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

	ShaderSource parseshader(const std::string& path);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);

	
};
