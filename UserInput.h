#pragma once

#include "ActionsConfig.h"
#include "CoreInterface.h"


class UserInput {
private:
    std::shared_ptr<CoreInterface> core_;
    ActionsConfig::PlayerState current_state_ = ActionsConfig::PlayerState::Start;

    static ActionsConfig::Action GetActionFromEvent(const sf::Event &event);

public:
    void SubscribeCore(std::shared_ptr<CoreInterface> core);

    void ProceedEvent(const sf::Event &event);

};