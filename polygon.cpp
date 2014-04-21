#include "polygon.h"

Polygon::Polygon()
{
  printf("Polygon created\n");
  _verts = new vector<vec2>();
}

Polygon::~Polygon()
{
  printf("Polygon deconstructed\n");
  delete _verts;
}

/**
 * Determine if two line segments intersect. If they do, returns point of
 * intersection. TODO: Otherwise what?
 */
/*
vec2 Polygon::intersectLineSegments(vec2 a_1, vec2 a_2, vec2 b_1, vec2 b_2)
{
  // TODO: https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
}
*/

/**
 * Determine if point p lies in the left half of the halfplanes separated by
 * the axis-aligned vector (b - a).
 *
 * Returns:
 *  1  if left
 *  -1 if right
 *  0  if colinear
 */
int Polygon::onLeftSide(vec2 a, vec2 b, vec2 p)
{
  vec2 axis = b - a;
  //printf("a: <%f, %f>\n", a[0], a[1]);
  //printf("b: <%f, %f>\n", b[0], b[1]);
  //printf("p: <%f, %f>\n", p[0], p[1]);
  vec2 v = p - b;
  //printf("axis: <%f, %f>\n", axis[0], axis[1]);
  //printf("v: <%f, %f>\n", v[0], v[1]);
  // 2D cross product
  float x_prod = axis[0] * v[1] - axis[1] * v[0];
  //printf("cross: %f\n", x_prod);
  if (x_prod < 0) return -1;
  else return (x_prod > 0);
}

/**
 * Mutate this polygon's vertex list so that it is clipped with respect to the
 * clipping box.
 */
void Polygon::clip(const Polygon& clip_box)
{
  // TODO
}

/**
 * Mutate the given polygon so that it is clipped with respect to the line
 * defined by a->b which divides the plane into "left" and "right" half spaces
 * (where "up" would be the direction of vector a->b).
 */
void Polygon::clipOneSide(vec2 a, vec2 b)
{
  // TODO
}

/**
 * Return the area of this simple polygon. Follows technique described in
 * Graphic Gems II, pg 7.
 */
float Polygon::area()
{
  const vector<vec2>& verts = *_verts;
  int n = verts.size();
  assert(n > 2);

  // Calculate product sum term
  float prod_sum  = 0.0f;
  for (int i = 0; i < n-1; ++i)
  {
    prod_sum += (verts[i][0] * verts[i+1][1]);
  }

  // Calculate product difference term
  float prod_diff = 0.0f;
  for (int i = 0; i < n-1; ++i)
  {
    prod_diff -= (verts[i][1] * verts[i+1][0]);
  }

  return 0.5 * (prod_sum + prod_diff);
}
