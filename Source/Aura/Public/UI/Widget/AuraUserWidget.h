// copyright jiaoyang

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * Aura的widget基础类
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
protected:
	//BlueprintImplementableEvent需要在蓝图中实现，不能在c++中实现，但是可以在c++中调用
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
