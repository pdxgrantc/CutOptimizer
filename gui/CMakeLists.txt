add_library(gui STATIC
        gui.cpp
        gui.h
)

target_link_libraries(gui PUBLIC
        Qt6::Widgets
        optimize
)

target_include_directories(gui PUBLIC
        ${PROJECT_SOURCE_DIR}
)