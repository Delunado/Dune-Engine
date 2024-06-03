﻿#pragma once
#include <vector>

#include "Shape.h"
#include "../../../math/Vec2.h"

struct PolygonShape : public Shape
{
public:
    PolygonShape() = default;
    PolygonShape(const std::vector<Vec2>& vertices);
    virtual ~PolygonShape();

    ShapeType GetType() const override;
    float GetMomentOfInertia() const override;

    /**
     * @brief Updates the vertices of the shape from local space to world space.
     * 
     * @param position The position of the body.
     * @param rotation The rotation of the body.
     */
    void UpdateVertices(const Vec2& position, float rotation);

    PolygonShape* Clone() const override;

    std::vector<Vec2> localVertices;
    std::vector<Vec2> worldVertices;
};
