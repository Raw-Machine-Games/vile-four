#pragma once
#include "ActionsConfig.h"

class PlayerStateByAction {
private:
	ActionsConfig::PlayerState current_state_ = ActionsConfig::PlayerState::Start;

public:
	ActionsConfig::PlayerState GetNextState(ActionsConfig::Action action);
};
