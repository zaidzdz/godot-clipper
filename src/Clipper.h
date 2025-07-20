#ifndef CLIPPER_H
#define CLIPPER_H

#include "include/clipper2/clipper.engine.h"   // Notice "include/clipper2/..."

#include <godot_cpp/classes/polygon2d.hpp>
#include <godot_cpp/variant/packed_vector2_array.hpp>

namespace godot {

class Clipper : public Object {
    GDCLASS(Clipper, Object);

protected:
    static void _bind_methods();

public:
    Clipper();
    ~Clipper();

    Array intersect_polygons(PackedVector2Array subject, PackedVector2Array clip);
    Array union_polygons(PackedVector2Array subject, PackedVector2Array clip);
    Array difference_polygons(PackedVector2Array subject, PackedVector2Array clip);
    Array xor_polygons(PackedVector2Array subject, PackedVector2Array clip);
};

}

#endif
