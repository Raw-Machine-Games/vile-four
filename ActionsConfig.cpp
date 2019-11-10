#include "ActionsConfig.h"

using State = ActionsConfig::PlayerState;
using Action = ActionsConfig::Action;

State ActionsConfig::GetNextState(const PlayerState &previous_state, const Action &current_action) {
    if (ActionsConfig::player_state_machine_.find(previous_state) != ActionsConfig::player_state_machine_.end()) {
        if (ActionsConfig::player_state_machine_.at(previous_state).find(current_action) !=
            ActionsConfig::player_state_machine_.at(previous_state).end())
            return ActionsConfig::player_state_machine_.at(previous_state).at(current_action);
    }
    return PlayerState::Error;
}

const std::unordered_map<State, std::unordered_map<Action, State>> ActionsConfig::player_state_machine_{
        {State::Start,              {{Action::FirstSkill, State::RageFirstStage},
                                            {Action::SecondSkill, State::Strong},
                                            {Action::ThirdSkill, State::Healthy},
                                            {Action::Ultimate, State::BerserkFirstStage}}
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
        {State::Healthy,            {{Action::FirstSkill, State::RageFirstStage},
                                            {Action::SecondSkill, State::Strong},
                                            {Action::ThirdSkill, State::Healthy},
                                            {Action::Ultimate, State::BerserkFirstStage}
                                    }
        },
        {State::Strongest,          {{Action::FirstSkill, State::Start},
                                            {Action::SecondSkill, State::Start},
                                            {Action::ThirdSkill, State::Start},
                                            {Action::Ultimate, State::Start}
                                    }
        }
};