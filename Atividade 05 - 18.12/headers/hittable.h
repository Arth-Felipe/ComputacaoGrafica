/**
 * @file hittable.h
 * @brief Classe abstrata para qualquer coisa que um raio possa atingir. Possui uma função hit responsável por determinar se um raio atinge o objeto e, se sim, fornecer informações sobre o ponto de interseção.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HITTABLE_H
#define HITTABLE_H

#include "../../Atividade 04 - 30.10/headers/ray.h"
#include "rtweekend.h"

class material;

class hit_record {
  public:
    point3 p;
    vec3 normal;
    shared_ptr<material> mat;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
  public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif
