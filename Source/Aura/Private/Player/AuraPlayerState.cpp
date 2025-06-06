// copyright jiaoyang


#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilityComponentSystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilityCompontSystem"));
	AbilityComponentSystem->SetIsReplicated(true);
	AbilityComponentSystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet=CreateDefaultSubobject<UAttributeSet>("AttributeSet");
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilityComponentSystem;
}
