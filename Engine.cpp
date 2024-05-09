#include "Engine.h"

Engine::Engine() {
  m_Window.create(VideoMode::getDesktopMode(), "Particle Generator");
}

void Engine::run() {
  Clock clock;
  clock.restart();
  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, {(int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2});
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;

  while (m_Window.isOpen()) {
    
    float dtAsSeconds = clock.restart().asSeconds();

    input();
    update(dtAsSeconds);
    draw();
  }
}

void Engine::input() {
  Event event;

  while (m_Window.pollEvent(event)) {
    if (event.type == Event::Closed) {
      m_Window.close();
    }
    if (event.type == Event::MouseButtonPressed) 
    {
      if (event.mouseButton.button == Mouse::Left) 
      {
        for (int i = 0; i < 5; i++) 
        {
          int points=rand() %26+25;
          
          m_particles.push_back(Particle(m_Window, points, Vector2i(event.mouseButton.x, event.mouseButton.y)));
          
        }
      }
    }
  }
}

void Engine::update(float dtAsSeconds){
  vector<Particle>::iterator iter;
  for (iter = m_particles.begin(); iter != m_particles.end();)
  {
    if (iter->getTTL() > 0.0)
    {
      iter->update(dtAsSeconds);
      ++iter;
    }
    else
    {
      iter = m_particles.erase(iter);
    } 
  }
}

void Engine::draw(){
  m_Window.clear();
  for (const auto& particle : m_particles){
    m_Window.draw(particle);
  }
  m_Window.display();
}
