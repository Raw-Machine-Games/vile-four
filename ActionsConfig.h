#pragma once
#include <unordered_map>

class ActionsConfig {
public:
    ActionsConfig() = delete;

    ActionsConfig(const ActionsConfig &) = delete;

    ActionsConfig(ActionsConfig &&) = delete;

    ~ActionsConfig() = delete;


    enum Action {
        MoveLeft,
        MoveRight,
        Jump,
        Squat,
        FirstSkill,
        SecondSkill,
        ThirdSkill,
        Ultimate,
        Nothing
    };

    enum PlayerState {
        Start,
		MoveLft,
		MoveRght,
		Jmp,
		Sqt,
        RageFirstStage,
        RageSecondStage,
        BerserkFirstStage,
        BerserkSecondStage,
        Strong,
        Healthy,
        Strongest,
        Error
    };

    static PlayerState GetNextState(const PlayerState &previous_state, const Action &current_action);


private:
    const static std::unordered_map<ActionsConfig::PlayerState, std::unordered_map<ActionsConfig::Action, ActionsConfig::PlayerState>> player_state_machine_;

};
