#include "ActionsConfig.h"

ActionsConfig::State ActionsConfig::GetState(const State &state, const Action &action) {
    if (automata_.find(state) != automata_.end()) {
        if (automata_[state].find(action) != automata_[state].end())
            return automata_[state][action];
    }
    return State::Error;
}
std::unordered_map<ActionsConfig::State, std::unordered_map<ActionsConfig::Action, ActionsConfig::State>> ActionsConfig::automata_{
        {Start,              {{Action::FirstSkill, State::RageFirstStage},
                                     {Action::SecondSkill, State::Strong},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkFirstStage}
                             }
        },

        {State::RageFirstStage,     {{Action::FirstSkill, State::RageSecondStage},
                                     {Action::SecondSkill, State::RageSecondStage},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkFirstStage},
                             }
        },

        {State::RageSecondStage,    {{Action::FirstSkill, State::RageSecondStage},
                                     {Action::SecondSkill, State::Strongest},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkSecondStage}

                             }
        },
        {State::BerserkFirstStage,  {{Action::FirstSkill, State::BerserkSecondStage},
                                     {Action::SecondSkill, State::Strongest},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkSecondStage}
                             }
        },
        {State::BerserkSecondStage, {{Action::FirstSkill, State::BerserkSecondStage},
                                     {Action::SecondSkill, State::Strongest},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkSecondStage}
                             }
        },
        {State::Strong,             {{Action::FirstSkill, State::RageFirstStage},
                                     {Action::SecondSkill, State::Strongest},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkFirstStage}
                             }
        },
        {State::Healthy, {{Action::FirstSkill, State::RageFirstStage},
                                     {Action::SecondSkill, State::Strong},
                                     {Action::ThirdSkill, State::Healthy},
                                     {Action::Ultimate, State::BerserkFirstStage}
                             }
        },
        {State::Strongest, {{Action::FirstSkill, State::Start},
                                     {Action::SecondSkill, State::Start},
                                     {Action::ThirdSkill, State::Start},
                                     {Action::Ultimate, State::Start}
                             }
        }
};