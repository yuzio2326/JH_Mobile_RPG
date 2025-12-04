// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BasePacket.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPakcet_ClientConnect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Struct")
	int PacketTypeBufferLength = 100;

};

UCLASS()
class JH_RPG_API UBasePacket : public UDataTable
{
	GENERATED_BODY()

	/*Child*/
	virtual FString CustomGetData();

	/*Function*/
	TArray<uint8> StringToBytes(const FString& StringInput);

	/*Serialize*/
	virtual void CustomSerialize();
	virtual void CustomSerializeData();
	virtual void CustomSerializeHeader();
	
	/*DeSerialize*/
	void DeSerialize();
	void DeSerializeData();
	void DeSerializeHeader();

	/*Buffer*/
	TArray<uint8> GetBuffer();
	void AddBytesToBuffer(TArray<uint8> SourceArray);
	void ClearBuffer();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Var")
	TArray<uint8> Buffer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Var")
	TArray<FString> AddingFilePathes;

	//childSetting
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTag PacketType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PacketStrcut")
	FPakcet_ClientConnect Pakcet_ClientConnect;

};
