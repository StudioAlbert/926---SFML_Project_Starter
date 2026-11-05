add_executable(Starter main.cpp src/game.cc
        ../Box2D_Starter/main.cc)

target_link_libraries(Starter PUBLIC SFML::Graphics SFML::Audio)