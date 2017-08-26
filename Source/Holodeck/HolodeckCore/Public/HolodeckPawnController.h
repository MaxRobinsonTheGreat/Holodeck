// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HolodeckServer.h"
#include "HolodeckGameInstance.h"
#include "AIController.h"
#include "HolodeckMessages.h"
#include "HolodeckPawnController.generated.h"

/**
 * 
 */
UCLASS()
class AHolodeckPawnController : public AAIController
{
	GENERATED_BODY()

public:
	AHolodeckPawnController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	~AHolodeckPawnController();

	void Possess(APawn* InPawn);
	void UnPossess();

	float* Subscribe(const FString& agent_name, const FString& sensor_name, int length);

	void GetServer();

private:
	UHolodeckServer* Server;
};