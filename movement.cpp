#include "movement.hpp"

Action::Action(Type type):
  type_(type),
  x_(10 / 2 - 4 / 2),
  y_(0),
  angle_(0)
{}

void Action::init(SDL_Renderer *renderer)
{
  for (auto x = 0; x < 4; ++x)
    for (auto y = 0; y < 4; ++y)
      if (checkBlock(x, y))
      {
        SDL_Rect rect{(x + x_) * 660 / 2 / 10 + 1, (y + y_) * 660 / 2 / 10 + 1, 660 / 2 / 10 - 2, 660 / 2 / 10 - 2};
        SDL_RenderFillRect(renderer, &rect);
      }
}

void Action::move(int dx, int dy)
{
  x_ += dx;
  y_ += dy;
}
void Action::rotate()
{
  angle_ += 3;
  angle_ %= 4;
}

int Action::checkBlock(int x, int y) const
{
  static const char *Shapes[][4] = {
    {
      " *  "
      " *  "
      " *  "
      " *  ",
      "    "
      "****"
      "    "
      "    ",
      " *  "
      " *  "
      " *  "
      " *  ",
      "    "
      "****"
      "    "
      "    ",
    },
    {
      "  * "
      "  * "
      " ** "
      "    ",
      "    "
      "*   "
      "*** "
      "    ",
      " ** "
      " *  "
      " *  "
      "    ",
      "    "
      "    "
      "*** "
      "  * ",
    },
    {
      " *  "
      " *  "
      " ** "
      "    ",
      "    "
      "*** "
      "*   "
      "    ",
      " ** "
      "  * "
      "  * "
      "    ",
      "  * "
      "*** "
      "    "
      "    ",
    },
    {
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
      "    "
      " ** "
      " ** "
      "    ",
    },
    {
      "  * "
      " ** "
      " *  "
      "    ",
      "    "
      "**  "
      " ** "
      "    ",
      "  * "
      " ** "
      " *  "
      "    ",
      "    "
      "**  "
      " ** "
      "    ",
    },
    {
      " *  "
      " ** "
      " *  "
      "    ",
      "    "
      "*** "
      " *  "
      "    ",
      " *  "
      "**  "
      " *  "
      "    ",
      " *  "
      "*** "
      "    "
      "    ",
    },
    {
      " *  "
      " ** "
      "  * "
      "    ",
      "    "
      " ** "
      "**  "
      "    ",
      " *  "
      " ** "
      "  * "
      "    ",
      "    "
      " ** "
      "**  "
      "    ",
    },
  };
  return Shapes[type_][angle_][x + y * 4] == '*';
}
int Action::x() const
{
  return x_;
}
int Action::y() const
{
  return y_;
}
