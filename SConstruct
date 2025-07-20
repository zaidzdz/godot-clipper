#!/usr/bin/env python
import os
from SCons.Script import Glob

# Initialize godot-cpp environment (adjust if your path differs)
env = SConscript("godot-cpp/SConstruct")

# Add include paths — the key part for Clipper2:
env.Append(CPPPATH=[
    "src",                           # Your own source files
    "src/Clipper2/CPP/Clipper2Lib", # << This is the root Clipper2Lib folder
])

# Add your own source files
sources = Glob("src/*.cpp")

# Add Clipper2Lib source files
sources += Glob("src/Clipper2/CPP/Clipper2Lib/src/*.cpp")

# Build the shared library (adjust as needed)
if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/libgdexample.{}.{}.framework/libgdexample.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.simulator.a".format(env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/bin/libgdexample.{}.{}.a".format(env["platform"], env["target"]),
            source=sources,
        )
else:  # Windows/Linux/etc
    library = env.SharedLibrary(
        "demo/bin/libgdexample{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
