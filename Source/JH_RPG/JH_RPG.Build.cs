// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JH_RPG : ModuleRules
{
	public JH_RPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" ,
			"GameplayTags"
        });
	}
}
