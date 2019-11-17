#pragma once
#include "ActionsConfig.h"

class CoreInterface {
public:

    virtual void NotifyFromUI(const std::optional<ActionsConfig::Action > &)=0;

};
