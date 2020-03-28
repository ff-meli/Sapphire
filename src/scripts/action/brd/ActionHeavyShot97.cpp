#include <Script/NativeScriptApi.h>
#include <ScriptObject.h>
#include <Actor/Player.h>
#include <Action/Action.h>
#include <Math/CalcStats.h>

#include "StatusEffect/StatusEffect.h"

using namespace Sapphire;
using namespace Sapphire::StatusEffect;

const uint16_t STATUS_ID_STRAIGHT_SHOT_READY = 122;

class ActionHeavyShot97 :
  public ScriptAPI::ActionScript
{
public:
  ActionHeavyShot97() :
    ScriptAPI::ActionScript( 97 )
  {
  }

  void onExecute( Sapphire::World::Action::Action& action ) override
  {
    if( action.getSourceChara()->getLevel() >= 2 && Math::CalcStats::getRandomNumber0To99() < 20 )
    {
      auto pEffect = Sapphire::StatusEffect::make_StatusEffect( STATUS_ID_STRAIGHT_SHOT_READY, action.getSourceChara(), action.getSourceChara(), 10000, 3000 );
      action.getEffectbuilder()->applyStatusEffect( action.getSourceChara(), action.getSourceChara(), pEffect );
    }
  }
};

EXPOSE_SCRIPT( ActionHeavyShot97 );