#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <Hazel/Renderer/Shader.h>

namespace Hazel {
class OpenGLShader : public Shader {
public:
    OpenGLShader(const std::string& filepath);
    OpenGLShader(const std::string& name, const std::string& vertex_src, const std::string& fragment_src);
    OpenGLShader(OpenGLShader const&) noexcept = default;
    OpenGLShader(OpenGLShader&&) noexcept = default;
    OpenGLShader& operator=(OpenGLShader const&) noexcept = default;
    OpenGLShader& operator=(OpenGLShader&&) noexcept = default;
    ~OpenGLShader() noexcept override;

    void bind() const override;
    void unbind() const override;
    void setUniform(std::string const& name, int value) override;
    void setUniform(std::string const& name, const int* values, std::uint32_t count) override;
    void setUniform(std::string const& name, float value) override;
    void setUniform(std::string const& name, glm::vec2 const& values) override;
    void setUniform(std::string const& name, glm::vec3 const& values) override;
    void setUniform(std::string const& name, glm::vec4 const& values) override;
    void setUniform(std::string const& name, glm::mat3 const& uniform) override;
    void setUniform(std::string const& name, glm::mat4 const& uniform) override;

    const std::string& getName() const noexcept override { return name_; }

    void uploadUniform(std::string const& name, int value) const;
    void uploadUniform(std::string const& name, const int* values, std::uint32_t count) const;
    void uploadUniform(std::string const& name, float value) const;
    void uploadUniform(std::string const& name, glm::vec2 const& values) const;
    void uploadUniform(std::string const& name, glm::vec3 const& values) const;
    void uploadUniform(std::string const& name, glm::vec4 const& values) const;
    void uploadUniform(std::string const& name, glm::mat3 const& uniform) const;
    void uploadUniform(std::string const& name, glm::mat4 const& uniform) const;

private:
    std::string readFile(const std::string& filepath);
    std::unordered_map<GLenum, std::string> preProcess(const std::string shader_src);
    void compile(const std::unordered_map<GLenum, std::string>& shader_src);

    std::uint32_t renderer_id_;
    std::string name_;
};
}  // namespace Hazel
