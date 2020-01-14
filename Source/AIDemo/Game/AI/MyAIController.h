// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class AIDEMO_API AMyAIController : public AAIController
{
   GENERATED_BODY()

protected:

   UPROPERTY(Transient)
   UBehaviorTreeComponent* BehaviorComp;

   UPROPERTY(Transient)
   UBlackboardComponent* BlackboardComp;

public:

   AMyAIController();

   void OnPossess(APawn* InPawn) override;

   uint8 EnemyKeyID;
};
