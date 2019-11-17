#pragma once

#include "ActionsConfig.h"
#include "CoreInterface.h"
#include <memory>
#include <SFML/Graphics.hpp>

class UserInput {
private:
	std::shared_ptr<CoreInterface> core_;

	static ActionsConfig::Action GetActionFromEvent(const sf::Event &event);

public:
	void SubscribeCore(std::shared_ptr<CoreInterface> core);

	void ProceedEvent(const sf::Event &event);

};