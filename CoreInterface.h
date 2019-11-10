#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <optional>
#include <atomic>
#include <thread>
#include <future>
#include "ActionsConfig.h"

class CoreInterface {
public:
    virtual void NotifyFromUI(const std::optional<ActionsConfig::PlayerState> &)=0;
};
