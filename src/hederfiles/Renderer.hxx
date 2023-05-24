#pragma once

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void render() = 0;
};
