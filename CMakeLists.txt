
# CMake config.

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(platanus)

# Compile flags.

set (CMAKE_CXX_STANDARD 11)

# Source files.

set (SOURCES
	${PROJECT_SOURCE_DIR}/sandbox/test/test_scenes/scene1/scene1.cpp

	${PROJECT_SOURCE_DIR}/src/platanus/foundation/image/imagewriter.h
	${PROJECT_SOURCE_DIR}/src/platanus/foundation/math/intersection/raysphere.h
	${PROJECT_SOURCE_DIR}/src/platanus/foundation/math/vector.h
	${PROJECT_SOURCE_DIR}/src/platanus/foundation/math/ray.h

	${PROJECT_SOURCE_DIR}/src/platanus/renderer/kernel/intersection/intersector.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/kernel/intersection/intersector.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/kernel/rendering/renderframe.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/kernel/shading/shadingengine.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/kernel/shading/shadingengine.cpp

	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/camera/pinholecamera.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/camera/pinholecamera.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/frame/frame.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/frame/frame.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/material/bsdf/bsdf.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/material/bsdf/phongdiffuse.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/material/bsdf/phongdiffuse.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/material/material.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/material/material.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/object/object.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/object/sphereobject.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/object/sphereobject.cpp
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/scene/scene.h
	${PROJECT_SOURCE_DIR}/src/platanus/renderer/modeling/scene/scene.h
)

# Product.

add_executable(platanus ${SOURCES})	
