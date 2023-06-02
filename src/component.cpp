#include "component.h"

std::vector<std::unique_ptr<_ComponentArray>> Components::component_arrays = std::vector<std::unique_ptr<_ComponentArray>>();
int Components::next_id = 0;