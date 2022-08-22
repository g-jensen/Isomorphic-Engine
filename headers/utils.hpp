#pragma once

#define WINDOW_X 800
#define WINDOW_Y 600

#define origin_x WINDOW_X/2
#define origin_y WINDOW_Y/2

#define M_7PI_6 3.66519142919f
#define cos_7PI_6 -0.86602540378f
#define sin_7PI_6 -0.5f

#define M_PI_6 0.52359877559f
#define cos_PI_6 0.86602540378f
#define sin_PI_6 0.5f

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <math.h>

// Converts 3D world coordinates to 2D screen coordinates
sf::Vector2f world_to_screen(sf::Vector3f pos);

// Returns the euclidean distance between two 3D vectors
float distance(sf::Vector3f v1, sf::Vector3f v2);