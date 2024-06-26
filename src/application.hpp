#pragma once

#include "world.hpp"
#include "renderer.hpp"
#include <memory>

typedef struct GLFWwindow GLFWwindow;

class Application final {
    GLFWwindow* window = nullptr;
    std::unique_ptr<gfx::Renderer> renderer;

    int frameWidth, frameHeight;
    vec2d contentScale;

    BallSimulator::World world = BallSimulator::World(1024, 1024);
    unsigned ballMesh = 0;
    int lastTimeBase = 0;
    int frames = 0;
    double fps = 60.0;
    double lastFrameTime = 0.0;

    static unsigned generate_filled_circle(gfx::Renderer& render, float radius = 1.0f);
    static void render_quadtree_bounds(gfx::Renderer& render, const BallSimulator::CollisionQuadtree& tree);

    bool init();
    void quit();

    void render();

    void resize();
    void mouse(int button, int action);

public:
    Application() = default;
    ~Application() = default;

    int run();
};
