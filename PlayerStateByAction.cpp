#include "PlayerStateByAction.h"

ActionsConfig::PlayerState PlayerStateByAction::GetNextState(ActionsConfig::Action action){

	ActionsConfig::PlayerState new_state=ActionsConfig::GetNextState(current_state_, action);
	current_state_=new_state;
	return new_state;

}