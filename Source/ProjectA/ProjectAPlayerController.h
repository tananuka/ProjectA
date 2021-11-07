// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Navigation/PathFollowingComponent.h"

#include "ProjectAPlayerController.generated.h"

UCLASS()
class AProjectAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AProjectAPlayerController();

	virtual void PreInitializeComponents() override;

	

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	UPROPERTY(Transient)
	UPathFollowingComponent* PathFollowingComponent;
	
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result);
	
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};