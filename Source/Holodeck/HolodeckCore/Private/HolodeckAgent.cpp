// Fill out your copyright notice in the Description page of Project Settings.

#include "Holodeck.h"
#include "HolodeckAgent.h"

const char REWARD_KEY[] = "Reward";
const int REWARD_SIZE = 1;
const char TERMINAL_KEY[] = "Terminal";
const int TERMINAL_SIZE = 1;

AHolodeckAgent::AHolodeckAgent() : AgentName("") {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	AddTickPrerequisiteActor(GetController());
	AgentName = "";
}

void AHolodeckAgent::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogHolodeck, Log, TEXT("Initializing HolodeckAgent"));
	HolodeckController = static_cast<AHolodeckPawnController*>(Controller);

	if (HolodeckController == nullptr) {
		UE_LOG(LogHolodeck, Warning, TEXT("Couldn't find controller for HolodeckAgent"));
	} else {
		RewardPtr = static_cast<float*>(HolodeckController->Subscribe(AgentName, REWARD_KEY, REWARD_SIZE, sizeof(float)));
		TerminalPtr = static_cast<bool*>(HolodeckController->Subscribe(AgentName, TERMINAL_KEY, TERMINAL_SIZE, sizeof(bool)));
		if (RewardPtr != nullptr)
			*RewardPtr = 0.0;
		if (TerminalPtr != nullptr)
			*TerminalPtr = false;
		HolodeckController->GetActionBuffer(AgentName);
		UE_LOG(LogHolodeck, Log, TEXT("HolodeckAgent begin play successful"));
	}
}

void AHolodeckAgent::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}
