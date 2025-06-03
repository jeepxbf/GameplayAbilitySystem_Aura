// copyright jiaoyang

/*
 * 我们在UE的引擎中新建了InputAction和InputMappingContext，那么我们就需要在代码中绑定这两个对象才行
 * 在UE中x中是向前，Y是向右，Z是向上 Yaw（偏航角）绕Z的旋转 Pitch（俯仰角），Roll（翻滚角）
 * 
 */
#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
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
	//绑定input的上下文
	Subsystem->AddMappingContext(AuraContext,0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	//结构体 FInputModeGameAndUI 是一种输入模式结构。如果使用这个输入模式，我们就可以同时使用键盘和鼠标输入来控制角色和与 UI
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	//第一个参数是 `MoveAction`，第二个参数是 `ETriggerEvent`。也就是说我们希望在什么时候触发 `Move`：开始触发、持续触发，还是释放触发？
	//我们这里希望是持续触发（Triggered），即当键盘持续按下时，持续调用 `Move`。接下来是绑定的对象，也就是 `this` 当前 Player Controller
	//实例，最后是回调函数地址，我们用 `&AAuraPlayerController::Move
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);
	
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation(); //获取朝向
	const FRotator YawRotation(0.f,Rotation.Yaw,0.f);
	//FRotationMatrix 转换为旋转矩阵，GetUnitAxis 提取x轴的向量
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		//InputAxisVector.Y 里面的Y是输入轴的Y，Y是前后，X是左右，想想2D的坐标系
		//ForwardDirection 这个是人物的局部坐标系的forward方向，也就是X方向
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
		
	}
}
