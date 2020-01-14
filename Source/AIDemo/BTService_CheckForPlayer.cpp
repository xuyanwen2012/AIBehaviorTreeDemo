// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_CheckForPlayer.h"
#include "Game/AI/MyAIController.h"
#include "Game/AI/MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include <AIDemoCharacter.h>

UBTService_CheckForPlayer::UBTService_CheckForPlayer()
{
   bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
   AMyAIController* AI = Cast<AMyAIController>(OwnerComp.GetAIOwner());

   if (AI)
   {
      AAIDemoCharacter* Character = Cast<AAIDemoCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());

      if (Character)
      {
         // Set Value
         OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(AI->EnemyKeyID, Character);
      }
   }
}
