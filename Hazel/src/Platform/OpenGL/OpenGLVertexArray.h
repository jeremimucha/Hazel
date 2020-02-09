#pragma once

#include "Hazel/AssertionHandler.h"

#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/VertexArray.h"

namespace Hazel {
class OpenGLVertexArray : public VertexArray {
public:
    OpenGLVertexArray() noexcept;
    ~OpenGLVertexArray() override;
    OpenGLVertexArray& operator=(OpenGLVertexArray&&) = delete;

    void bind() const override;
    void unbind() const override;

    void addVertexBuffer(std::unique_ptr<VertexBuffer>) override;
    void setIndexBuffer(std::unique_ptr<IndexBuffer>) override;

    std::vector<std::unique_ptr<VertexBuffer>> const& getVertexBuffers() const noexcept override { return vertex_buffers_; }
    IndexBuffer const& getIndexBuffer() const noexcept override {
        HZ_ASSERT(index_buffer_ != nullptr, DefaultCoreHandler, Enforce, "Index buffer not set");
        return *index_buffer_;
    }

private:
    std::uint32_t renderer_id_{0};
    std::vector<std::unique_ptr<VertexBuffer>> vertex_buffers_{};
    std::unique_ptr<IndexBuffer> index_buffer_{nullptr};
};
}  // namespace Hazel
