#include "ActionsConfig.h"


using PlayerState=ActionsConfig::PlayerState;
using Action=ActionsConfig::Action;

PlayerState ActionsConfig::GetNextState(const PlayerState &previous_state, const Action &current_action) {
	if (player_state_machine_.find(previous_state) != player_state_machine_.end()) {
		if (player_state_machine_.at(previous_state).find(current_action) !=
			player_state_machine_.at(previous_state).end()) {
			return player_state_machine_.at(previous_state).at(current_action);
		}
	}
	return PlayerState::Error;
}

const std::unordered_map<PlayerState, std::unordered_map<Action, PlayerState>> ActionsConfig::player_state_machine_{
		{PlayerState::Start,              {{Action::FirstSkill, PlayerState::RageFirstStage},
												  		{Action::SecondSkill, PlayerState::Strong},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkFirstStage},
												  		{Action::MoveLeft, PlayerState ::MoveLft},
												  		{Action ::MoveRight, PlayerState ::MoveRght},
												  		{Action ::Jump, PlayerState ::Jmp},
												  		{Action ::Squat, PlayerState ::Sqt}
										  		 }
		},
		{PlayerState::MoveRght,            {{Action::FirstSkill, PlayerState::RageFirstStage},
										   				{Action::SecondSkill, PlayerState::Strong},
										   				{Action::ThirdSkill, PlayerState::Healthy},
										   				{Action::Ultimate, PlayerState::BerserkFirstStage},
										   				{Action::MoveLeft, PlayerState ::MoveLft},
										   				{Action ::MoveRight, PlayerState ::MoveRght},
										   				{Action ::Jump, PlayerState ::Jmp},
										   				{Action ::Squat, PlayerState ::Sqt}
										   		  }
		},
		 {PlayerState::MoveLft,            {{Action::FirstSkill, PlayerState::RageFirstStage},
											 			{Action::SecondSkill, PlayerState::Strong},
											 			{Action::ThirdSkill, PlayerState::Healthy},
											 			{Action::Ultimate, PlayerState::BerserkFirstStage},
											 			{Action::MoveLeft, PlayerState ::MoveLft},
											 			{Action ::MoveRight, PlayerState ::MoveRght},
											 			{Action ::Jump, PlayerState ::Jmp},
											 			{Action ::Squat, PlayerState ::Sqt}
		 										  }
		 },
		  {PlayerState::Jmp,            {{Action::FirstSkill, PlayerState::RageFirstStage},
											  			{Action::SecondSkill, PlayerState::Strong},
											 		 	{Action::ThirdSkill, PlayerState::Healthy},
											  			{Action::Ultimate, PlayerState::BerserkFirstStage},
											  			{Action::MoveLeft, PlayerState ::MoveLft},
											  			{Action ::MoveRight, PlayerState ::MoveRght},
											  			{Action ::Jump, PlayerState ::Jmp},
											  			{Action ::Squat, PlayerState ::Sqt}
		  									   }
		  },
		   {PlayerState::Sqt,            {{Action::FirstSkill, PlayerState::RageFirstStage},
											   			{Action::SecondSkill, PlayerState::Strong},
											   			{Action::ThirdSkill, PlayerState::Healthy},
											   			{Action::Ultimate, PlayerState::BerserkFirstStage},
											   			{Action::MoveLeft, PlayerState ::MoveLft},
											   			{Action ::MoveRight, PlayerState ::MoveRght},
											   			{Action ::Jump, PlayerState ::Jmp},
											   			{Action ::Squat, PlayerState ::Sqt}
		   									    }
		   },

		{PlayerState::RageFirstStage,     {{Action::FirstSkill, PlayerState::RageSecondStage},
												  		{Action::SecondSkill, PlayerState::RageSecondStage},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkFirstStage}
										 		 }
		},

		{PlayerState::RageSecondStage,    {{Action::FirstSkill, PlayerState::RageSecondStage},
												  		{Action::SecondSkill, PlayerState::Strongest},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkSecondStage}
										  		 }
		},
		{PlayerState::BerserkFirstStage,  {{Action::FirstSkill, PlayerState::BerserkSecondStage},
												  		{Action::SecondSkill, PlayerState::Strongest},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkSecondStage}
										  		 }
		},
		{PlayerState::BerserkSecondStage, {{Action::FirstSkill, PlayerState::BerserkSecondStage},
												  		{Action::SecondSkill, PlayerState::Strongest},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkSecondStage}
										  		 }
		},
		{PlayerState::Strong,             {{Action::FirstSkill, PlayerState::RageFirstStage},
									 					{Action::SecondSkill, PlayerState::Strongest},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkFirstStage}
										  		 }
		},
		{PlayerState::Healthy,            {{Action::FirstSkill, PlayerState::RageFirstStage},
												  		{Action::SecondSkill, PlayerState::Strong},
												  		{Action::ThirdSkill, PlayerState::Healthy},
												  		{Action::Ultimate, PlayerState::BerserkFirstStage}
										  		 }
		},
		{PlayerState::Strongest,          {{Action::FirstSkill, PlayerState::Start},
												  		{Action::SecondSkill, PlayerState::Start},
												  		{Action::ThirdSkill, PlayerState::Start},
												  		{Action::Ultimate, PlayerState::Start}
										  		 }
		}

};