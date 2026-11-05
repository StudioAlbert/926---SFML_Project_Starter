#include <cstdlib>
#include <print>
#include <box2d/box2d.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "include/constants.hpp"
#include "include/entity.hpp"
#include "include/physical_object.hpp"

int main() {

   b2WorldDef def = b2DefaultWorldDef();
   def.gravity = {0.f, 9.81f};          // vers le bas, en m/s²

   b2WorldId monde = b2CreateWorld(&def);

   sf::RenderWindow window(sf::VideoMode({1200, 800}), "Physics", sf::Style::Default);
   window.setFramerateLimit(240);

   constexpr double kPas = 1000.f / 60.f;
   constexpr int kSousPas = 4;
   double accumulateur_ = 0.0f;

   sf::Clock clock;
   double dt;

   Entity mario;
   mario.Setup(sf::Color::Red, {30,30});
   mario.SetupPhysics(monde, b2_dynamicBody, {1,1});

   Entity platform;
   platform.Setup(sf::Color::Yellow, {200,30});
   platform.SetupPhysics(monde, b2_staticBody, {1,10});

   while (window.isOpen()) {

      dt = clock.restart().asMilliseconds();
      accumulateur_ += dt;

      while (const std::optional event = window.pollEvent()) {
         if (event->is<sf::Event::Closed>()) {
            window.close();
         }
      }

      while (accumulateur_ >= kPas)
      {
         b2World_Step(monde, kPas / 1000.f, kSousPas);
         accumulateur_ -= kPas;
      }

      mario.Update();
      platform.Update();
      // falling.Update();
      // platform.Update();

      window.clear(sf::Color::Black);
      window.draw(mario);
      window.draw(platform);
      window.display();

   }

   return EXIT_SUCCESS;
}
