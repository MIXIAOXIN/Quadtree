#include "geometry.h"

/**
 * TODO
 */
Geometry::Geometry(int _id, vector<vec2> _vertices, vector<int> _edges) :
  id(_id), vertices(_vertices), edges(_edges)
{
  bb = new BB(vec2(0.0f,0.0f), vec2(0.0f,0.0f)); // TODO: Initialize the BB correctly
}
