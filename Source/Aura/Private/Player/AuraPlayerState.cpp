// copyright jiaoyang


#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
AAuraPlayerState::AAuraPlayerState()
{
	AbilityComponentSystem = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilityComponentSystem"));
	AbilityComponentSystem->SetIsReplicated(true);
	AbilityComponentSystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet=CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilityComponentSystem;
}
