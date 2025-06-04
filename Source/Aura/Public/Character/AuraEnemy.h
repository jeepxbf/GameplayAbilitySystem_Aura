// copyright jiaoyang

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

	UPROPERTY(blueprintReadOnly)
	bool bHighlighted = false; //是否需要点亮 调试用
};
