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
#include "CoreInterface.h"


class UserInput {
private:
    std::shared_ptr<CoreInterface> core_;
    std::atomic_bool shouldTerminate_ = false;
    ActionsConfig::State stateNow = ActionsConfig::State::Start;
public:
    void SubscribeCore(std::shared_ptr<CoreInterface> core);
    void RequestTerminate();
    ActionsConfig::Action GetPressedButton(sf::Event event);
    void Run(sf::Event &event);

};