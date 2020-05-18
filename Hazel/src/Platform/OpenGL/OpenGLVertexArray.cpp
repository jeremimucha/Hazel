#include "OpenGLVertexArray.h"

#include <glad/glad.h>

#include "Hazel/Core/AssertionHandler.h"

namespace Hazel {
template <>
constexpr GLenum shaderDataTypeToPlatformType<GLenum>(ShaderDataType type) noexcept
{
    // clang-format off
    switch(type) {
        case ShaderDataType::None  :    return GL_NONE;
        case ShaderDataType::Float :    return GL_FLOAT;
        case ShaderDataType::Float2:    return GL_FLOAT;
        case ShaderDataType::Float3:    return GL_FLOAT;
        case ShaderDataType::Float4:    return GL_FLOAT;
        case ShaderDataType::Mat3  :    return GL_FLOAT;
        case ShaderDataType::Mat4  :    return GL_FLOAT;
        case ShaderDataType::Int   :    return GL_INT;
        case ShaderDataType::Int2  :    return GL_INT;
        case ShaderDataType::Int3  :    return GL_INT;
        case ShaderDataType::Int4  :    return GL_INT;
        case ShaderDataType::Bool  :    return GL_BOOL;
    }
    // clang-format on
    HZ_ASSERT(false, DefaultCoreHandler, Enforce, "Unknown ShaderDataType");
    return GL_NONE;
}

OpenGLVertexArray::OpenGLVertexArray() noexcept
{
    HZ_PROFILE_FUNCTION();
    glCreateVertexArrays(1, &renderer_id_);
}

OpenGLVertexArray::~OpenGLVertexArray()
{
    HZ_PROFILE_FUNCTION();
    glDeleteVertexArrays(1, &renderer_id_);
}

void OpenGLVertexArray::bind() const
{
    HZ_PROFILE_FUNCTION();
    glBindVertexArray(renderer_id_);
}

void OpenGLVertexArray::unbind() const
{
    HZ_PROFILE_FUNCTION();
    glBindVertexArray(0);
}

void OpenGLVertexArray::addVertexBuffer(Scope<VertexBuffer> p_vertex_buffer)
{
    HZ_PROFILE_FUNCTION();
    HZ_ASSERT(p_vertex_buffer != nullptr, DefaultCoreHandler, Enforce, "VertexBuffer* may not be nullptr");
    HZ_ASSERT(!p_vertex_buffer->getLayout().getElements().empty(), DefaultCoreHandler, Enforce,
              "VertexBuffer must have a layout set");

    glBindVertexArray(renderer_id_);
    p_vertex_buffer->bind();

    auto const& vb_layout{p_vertex_buffer->getLayout()};
    for (const auto& element : vb_layout) {
        glEnableVertexAttribArray(vertex_buffer_index_);
        glVertexAttribPointer(vertex_buffer_index_, componentCount(element.type),
                              shaderDataTypeToPlatformType<GLenum>(element.type),
                              element.normalized ? GL_TRUE : GL_FALSE, vb_layout.getStride(),
                              reinterpret_cast<const void*>(element.offset));
        ++vertex_buffer_index_;
    }

    vertex_buffers_.push_back(std::move(p_vertex_buffer));
}

void OpenGLVertexArray::setIndexBuffer(Scope<IndexBuffer> p_index_buffer)
{
    HZ_PROFILE_FUNCTION();
    glBindVertexArray(renderer_id_);
    p_index_buffer->bind();
    index_buffer_ = std::move(p_index_buffer);
}

}  // namespace Hazel
