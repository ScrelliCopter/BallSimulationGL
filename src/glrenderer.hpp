#pragma once

#include "renderer.hpp"

typedef struct SDL_GLContextState* SDL_GLContext;

namespace gfx {
    class GLRenderer final : public Renderer {
        SDL_GLContext _glCtx = nullptr;
        int _glVersion = 0;

    public:
        GLRenderer(SDL_Window* window, const colorf& clear = colorf::black());
        virtual ~GLRenderer();

        constexpr bool init_ok() override { return _glCtx != nullptr && _glVersion != 0; }

        void viewport(int width, int height) override;

        void new_frame() override;

        Mesh create_mesh(std::span<const Vertex> vertices, std::span<const uint16_t> indices,
            PrimitiveType mode = PrimitiveType::TRIANGLES) override;
        void delete_mesh(Mesh& mesh) override;

        void draw_mesh(Mesh& mesh, const Instance& instance) override;
        void draw_mesh(Mesh& mesh, const std::span<const Instance> instances) override;
    };
}
