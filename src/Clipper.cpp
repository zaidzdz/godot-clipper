#include "Clipper.h"
#include "godot_cpp/core/class_db.hpp"

using namespace godot;
using namespace Clipper2Lib;

void Clipper::_bind_methods() {
    ClassDB::bind_method(D_METHOD("intersect_polygons", "subject", "clip"), &Clipper::intersect_polygons);
    ClassDB::bind_method(D_METHOD("union_polygons", "subject", "clip"), &Clipper::union_polygons);
    ClassDB::bind_method(D_METHOD("difference_polygons", "subject", "clip"), &Clipper::difference_polygons);
    ClassDB::bind_method(D_METHOD("xor_polygons", "subject", "clip"), &Clipper::xor_polygons);

}


Clipper::Clipper() {
}

Clipper::~Clipper() {
}



static PathsD packed_vector2_array_to_paths_d(const PackedVector2Array &arr)
{
    PathD path;


    for (int i = 0; i < arr.size(); i++)
    {
        path.push_back(PointD(arr[i].x,arr[i].y));    
    }
    PathsD newpath = {path};
    return newpath;
}
static Array paths_d_to_array_of_packed_vector2(const PathsD &arr)
{
    Array out;
    for (const PathD& path : arr)
    {
        PackedVector2Array poly;
        for (const PointD& pt : path)
        {
            poly.append(Vector2(pt.x, pt.y));
        }
        out.append(poly);
    }
    return out;
}

Array Clipper::intersect_polygons(PackedVector2Array subject, PackedVector2Array clip) {
    

    
    ClipperD clipper;
    PathsD subject2 = packed_vector2_array_to_paths_d(subject);
    PathsD clip2 = packed_vector2_array_to_paths_d(clip);
    clipper.AddSubject(subject2);
    clipper.AddClip(clip2);
    PathsD solution;
    bool success = clipper.Execute(ClipType::Intersection,FillRule::NonZero, solution);
    if (success == true) {
        return paths_d_to_array_of_packed_vector2(solution);
    }
    return PackedVector2Array();
}
Array Clipper::union_polygons(PackedVector2Array subject, PackedVector2Array clip) {
    

    
    
    ClipperD clipper;
    PathsD subject2 = packed_vector2_array_to_paths_d(subject);
    PathsD clip2 = packed_vector2_array_to_paths_d(clip);
    clipper.AddSubject(subject2);
    clipper.AddClip(clip2);
    PathsD solution;
    bool success = clipper.Execute(ClipType::Union,FillRule::NonZero, solution);
    if (success == true) {
        return paths_d_to_array_of_packed_vector2(solution);
    }
    return PackedVector2Array();
}
Array Clipper::difference_polygons(PackedVector2Array subject, PackedVector2Array clip) {
    

    
    
    ClipperD clipper;
    PathsD subject2 = packed_vector2_array_to_paths_d(subject);
    PathsD clip2 = packed_vector2_array_to_paths_d(clip);
    clipper.AddSubject(subject2);
    clipper.AddClip(clip2);
    PathsD solution;
    bool success = clipper.Execute(ClipType::Difference,FillRule::NonZero, solution);
    if (success == true) {
        return paths_d_to_array_of_packed_vector2(solution);
    }
    return PackedVector2Array();
}
Array Clipper::xor_polygons(PackedVector2Array subject, PackedVector2Array clip) {
    

    
    
    ClipperD clipper;
    PathsD subject2 = packed_vector2_array_to_paths_d(subject);
    PathsD clip2 = packed_vector2_array_to_paths_d(clip);
    clipper.AddSubject(subject2);
    clipper.AddClip(clip2);
    PathsD solution;
    bool success = clipper.Execute(ClipType::Xor,FillRule::NonZero, solution);
    if (success == true) {
        return paths_d_to_array_of_packed_vector2(solution);
    }
    return Array();
}
