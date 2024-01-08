/**
 * @file sphere.h
 * @brief Implementação específica da interface descrita acima (ou seja, ao herdar da classe hittable.h, ela garante que qualquer objeto da classe sphere possa ser tratado polimorficamente como um objeto hittable). Portanto, essa classe também teve que implementar a função hit, fornecendo uma lógica específica para determinar se um raio atinge uma esfera e calcular as informações de interseção necessárias.
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "../../Atividade 02 - 09.10/vec3.h"

class sphere : public hittable {
  public:
    sphere(point3 _center, double _radius, shared_ptr<material> _material)
      : center(_center), radius(_radius), mat(_material) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = r.origin() - center;
        auto a = r.direction().length_squared();
        auto half_b = dot(oc, r.direction());
        auto c = oc.length_squared() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (-half_b + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }

  private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
};

#endif
