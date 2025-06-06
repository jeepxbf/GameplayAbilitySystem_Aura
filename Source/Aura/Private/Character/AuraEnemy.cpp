// copyright jiaoyang


#include "Character/AuraEnemy.h"

#include "AbilitySystemComponent.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilityComponentSystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilityCompontSystem"));
	AbilityComponentSystem->SetIsReplicated(true);
	AttributeSet=CreateDefaultSubobject<UAttributeSet>("AttributeSet");
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
