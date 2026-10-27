add_library(optimize STATIC
        optimize.cpp
        fileHandler.cpp
)

target_include_directories(optimize PUBLIC
        ${PROJECT_SOURCE_DIR}
)
