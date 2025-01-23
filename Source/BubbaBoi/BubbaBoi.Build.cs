// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BubbaBoi : ModuleRules
{
	public BubbaBoi(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
