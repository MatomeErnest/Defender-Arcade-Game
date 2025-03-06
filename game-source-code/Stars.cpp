#include "Stars.h"

Stars::Stars()
{}
void Stars:: MakeStarField()
{
    StarVertices.setPrimitiveType(sf::Points);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < starCount; ++i) 
    {
        float x = static_cast<float>(rand() % dimensions.WindowWidth());
        float y = static_cast<float>(rand() % dimensions.WindowHeight());
        StarVertices.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue));

    }
}
void Stars::MoveRight()
{
      for(auto i=0;i<starCount;i++)
  {
       StarVertices[i].position.x += starSpeed; // Move stars to the left
      if (StarVertices[i].position.x < 0)
        {
            StarVertices[i].position.x = dimensions.WindowWidth();
            StarVertices[i].position.y = static_cast<float>(rand() % dimensions.WindowHeight());
        }
        else if (StarVertices[i].position.x > dimensions.WindowWidth())
        {
            StarVertices[i].position.x = 0;
            StarVertices[i].position.y = static_cast<float>(rand() % dimensions.WindowWidth());
        }
  }

}
void Stars::MoveLeft()
{
        for(auto i=0;i<starCount;i++)
    {
        StarVertices[i].position.x -= starSpeed; // Move stars to the right
       if (StarVertices[i].position.x < 0)
        {
            StarVertices[i].position.x = dimensions.WindowWidth();
            StarVertices[i].position.y = static_cast<float>(rand() % dimensions.WindowHeight());
        }
        else if (StarVertices[i].position.x > dimensions.WindowWidth())
        {
            StarVertices[i].position.x = 0;
            StarVertices[i].position.y = static_cast<float>(rand() % dimensions.WindowHeight());
        }
    }
}

sf::VertexArray Stars:: StarField()
{
    return StarVertices;
}
sf::VertexArray Stars:: StarVertices;