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

class ActionsConfig {
public:
    enum Action {
        MoveLeft, MoveRight, Jump, Squat, FirstSkill, SecondSkill, ThirdSkill, Ultimate, Nothing
    };

    enum State {
        Start, RageFirstStage, RageSecondStage, BerserkFirstStage, BerserkSecondStage, Strong, Healthy, Strongest, Error
    };

    static State GetState(const State &state, const Action &action);


private:
    static std::unordered_map<ActionsConfig::State, std::unordered_map<ActionsConfig::Action, ActionsConfig::State>> automata_;
};
