// copyright jiaoyang


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//是一种强断言，用于开发调试阶段强制要求 AuraContext 不为空，否则直接报错退出，用于快速暴露程序逻辑漏洞。
	//Shipping 构建中会自动被移除，不影响性能
	check(AuraContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext,0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//结构体 FInputModeGameAndUI 是一种输入模式结构。如果使用这个输入模式，我们就可以同时使用键盘和鼠标输入来控制角色和与 UI
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}