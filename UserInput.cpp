#include "UserInput.h"


using  namespace std;

    void UserInput::SubscribeCore(shared_ptr<CoreInterface> core) {
        core_ = core;
    }

    void UserInput::RequestTerminate() {
        shouldTerminate_ = true;
    }

    ActionsConfig::Action UserInput::GetPressedButton(sf::Event event) {

        if (event.type == sf::Event::KeyPressed) {
            return ActionsConfig::Action::Nothing;
        }

        switch (event.key.code) {
            case sf::Keyboard::Num1 :
                return ActionsConfig::Action::FirstSkill;

            case sf::Keyboard::Left:
                return ActionsConfig::Action::MoveLeft;

            case sf::Keyboard::Right:
                return ActionsConfig::Action::MoveRight;

            case sf::Keyboard::Num2:
                return ActionsConfig::Action::SecondSkill;


            case sf::Keyboard::Num3:
                return ActionsConfig::Action::ThirdSkill;


            case sf::Keyboard::Num4:
                return ActionsConfig::Action::Ultimate;


            case sf::Keyboard::Down:
                return ActionsConfig::Action::Squat;


            case sf::Keyboard::Up:
                return ActionsConfig::Action::Jump;

        }
        return ActionsConfig::Action::Nothing;
    }

    void UserInput::Run(sf::Event &event) {
        ActionsConfig::State newState = ActionsConfig::GetState(stateNow, GetPressedButton(event));
        core_->NotifyFromUI(newState);
        stateNow = newState;
        this_thread::sleep_for(chrono::milliseconds(100));

    }

