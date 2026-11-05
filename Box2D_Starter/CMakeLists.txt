add_executable(Box2D_Starter main.cc
        include/physical_object.hpp
        src/physical_object.cc
        include/Entity.hpp
        src/entity.cc
        include/constants.hpp
        src/sensor.cc
        include/sensor.hpp
        include/contacts.hpp)

target_link_libraries(Box2D_Starter PUBLIC SFML::Graphics SFML::Audio box2d::box2d)