#ifndef GDCLIPPER_REGISTER_TYPES_H
#define GDCLIPPER_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_clipper(ModuleInitializationLevel p_level);
void uninitialize_clipper(ModuleInitializationLevel p_level);

#endif // GDCLIPPER_REGISTER_TYPES_H
