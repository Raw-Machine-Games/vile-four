#include "UserInput.h"

void UserInput::SubscribeCore(std::shared_ptr<CoreInterface> core) {

	core_ = core;

}

ActionsConfig::Action UserInput::GetActionFromEvent(const sf::Event &event) {

	if (event.type == sf::Event::KeyPressed) {
		return ActionsConfig::Action::Nothing;
	}

	switch (event.key.code) {

		case sf::Keyboard::Left:
			return ActionsConfig::Action::MoveLeft;

		case sf::Keyboard::Right:
			return ActionsConfig::Action::MoveRight;

		case sf::Keyboard::Down:
			return ActionsConfig::Action::Squat;

		case sf::Keyboard::Up:
			return ActionsConfig::Action::Jump;

		case sf::Keyboard::Num1 :
			return ActionsConfig::Action::FirstSkill;

		case sf::Keyboard::Num2:
			return ActionsConfig::Action::SecondSkill;

		case sf::Keyboard::Num3:
			return ActionsConfig::Action::ThirdSkill;

		case sf::Keyboard::Num4:
			return ActionsConfig::Action::Ultimate;

		default:
			return ActionsConfig::Action::Nothing;
	}

}

void UserInput::ProceedEvent(const sf::Event &event) {
	auto action = UserInput::GetActionFromEvent(event);
	if (action != ActionsConfig::Action::Nothing) {
		core_->NotifyFromUI(action);
	}
}
