// Fill out your copyright notice in the Description page of Project Settings.


#include "Server/Packet/BasePacket.h"


FString UBasePacket::CustomGetData()
{
	return FString();
}

TArray<uint8> UBasePacket::StringToBytes(const FString& StringInput)
{
	TArray<uint8> Local_OutPutBytes;

	FTCHARToUTF8 Converter(*StringInput);

	Local_OutPutBytes.Append(
		reinterpret_cast<const uint8*>(Converter.Get()),
		Converter.Length());

	return Local_OutPutBytes;
}

void UBasePacket::CustomSerialize()
{
	ClearBuffer();
	CustomSerializeData();
}

void UBasePacket::CustomSerializeData()
{
	CustomSerializeHeader();

}

void UBasePacket::CustomSerializeHeader()
{
	FString Local_FileBufferString;

	{
		FString TagString = PacketType.GetTagName().ToString();
		FTCHARToUTF8 Converter(*TagString);

		TArray<uint8> Local_TypeBuffer;
		Local_TypeBuffer.Append(
		reinterpret_cast<const uint8*>(Converter.Get()),
		Converter.Length());

		Local_TypeBuffer.SetNum(100);
	}

	{
		Local_FileBufferString;
		FTCHARToUTF8 Converter(CustomGetData());

		CustomGetData();
	}
	

	{
		for (FString Local_FilePath : AddingFilePathes)
		{
			TArray<uint8> OutBytes;
			OutBytes.Empty();

			if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*Local_FilePath))
			{
				 bool bSuccess = FFileHelper::LoadFileToArray(OutBytes, *Local_FilePath);

				 if (bSuccess)
				 {
					 AddBytesToBuffer(OutBytes);
				 }
			}
		}
	}
}

void UBasePacket::DeSerialize()
{
}

void UBasePacket::DeSerializeData()
{
}

void UBasePacket::DeSerializeHeader()
{
}

TArray<uint8> UBasePacket::GetBuffer()
{
	return Buffer;
}

void UBasePacket::AddBytesToBuffer(TArray<uint8> SourceArray)
{
	Buffer.Append(SourceArray);
}

void UBasePacket::ClearBuffer()
{
	if (!Buffer.IsEmpty())
	{
		Buffer.Reset();
	}
}
