// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MoveToPlayer.h"
#include "MyAIController.h"
#include "AIDemoCharacter.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
   AMyAIController* AI = Cast<AMyAIController>(OwnerComp.GetAIOwner());

   AAIDemoCharacter* Character = Cast<AAIDemoCharacter>(
      OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(AI->EnemyKeyID));

   if (Character)
   {
      AI->MoveToActor(Character, 5.0f, true, true, true, nullptr, true);
      return EBTNodeResult::Succeeded;
   }

   return EBTNodeResult::Failed;
}
