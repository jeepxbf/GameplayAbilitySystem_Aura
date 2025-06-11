// copyright jiaoyang


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilityComponentSystem = CreateDefaultSubobject<UAuraAbilitySystemComponent>(TEXT("AbilityComponentSystem"));
	AbilityComponentSystem->SetIsReplicated(true);
	AbilityComponentSystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet=CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CustomDepth_Red);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CustomDepth_Red);
}

void AAuraEnemy::UnhighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilityComponentSystem->InitAbilityActorInfo(this,this);
}
