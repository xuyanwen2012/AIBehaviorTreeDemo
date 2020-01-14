// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "MyCharacter.h"
#include "Engine/Engine.h"

AMyAIController::AMyAIController()
{
   BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
   BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AMyAIController::OnPossess(APawn* InPawn)
{
   Super::OnPossess(InPawn);

   GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "AMyAIController::OnPossess");


   AMyCharacter* AI = Cast<AMyCharacter>(InPawn);

   if (AI && AI->BehaviorTree)
   {
      GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green,
                                       "AMyAIController::OnPossess --- AI && AI->BehaviorTree");

      BlackboardComp->InitializeBlackboard(*AI->BehaviorTree->BlackboardAsset);

      EnemyKeyID = BlackboardComp->GetKeyID("Target");

      BehaviorComp->StartTree(*AI->BehaviorTree);
   }
}
