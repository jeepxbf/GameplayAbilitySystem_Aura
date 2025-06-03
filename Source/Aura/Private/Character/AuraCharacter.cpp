// copyright jiaoyang


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true; //自动面向移动的方向
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f); //旋转的速度，每秒400度
	GetCharacterMovement()->bConstrainToPlane = true; //限制只能在一个平面上移动
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	//角色不跟随控制器旋转
	//控制器方向也就是摄像机的方向，如果把bUseControllerRotationYaw=true，那么人物永远朝向摄像机的方向，
	//第一人称的游戏可以设置为true
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
