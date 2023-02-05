#include "UI.h"
#include <optional>

#include <iostream>
#include <string>

int main()
{
  /*  NumberUI ui;
    ui.run();*/

  auto n = CNumber {};
  n.setPolar(std::make_optional(22.36), std::make_optional(0.46));

  std::cout << n.getAsCartesian().x << " " << n.getAsCartesian().y << std::endl;
}
