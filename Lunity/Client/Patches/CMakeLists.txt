target_sources(Lunity PRIVATE
	"IPatch.cpp"
	"PatchManager.cpp"
)
add_subdirectory(Actor)
add_subdirectory(ClientInstance)
add_subdirectory(Global)
add_subdirectory(LocalPlayer)
add_subdirectory(MeshHelpers)
add_subdirectory(Player)
add_subdirectory(ScreenView)
# add_subdirectory(SurvivalMode)